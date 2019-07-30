/**********************************************************************************************
    Copyright (C) 2019 Henri Hornburg hrnbg@t-online.de

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

**********************************************************************************************/

#include "CSearchExplanationDialog.h"

CSearchExplanationDialog::CSearchExplanationDialog(QWidget *parent)
{
    setupUi(this);
    setWindowFlag(Qt::Tool, true);
    setWindowFlag(Qt::WindowStaysOnTopHint, true);
    //connect(buttonBox, &QDialogButtonBox::accepted, this, &CGeoSearchConfigDialog::slotAccepted);
    QString explanation = tr("<p>The underlying syntax of the search is \"Property Comparison Value\", i.e. \"name contains water\". "
                             "However there are measures in place to make searching more intuitive. (see below)</p>"
                             "<p>The searches are always exclusive, thus for a track \"elevation under 500m\" only shows "
                             "tracks that are completly under 500m meters.</p>"
                             "<p>Following assumptions are made:</p>"
                             "<ul>"
                             "<li>If only one of two given numbers has a unit, the unit is assumed for both</li>"
                             "<li>Speed units result in average speed, km and mi result in distance, m and ft in elevation, times in time moving, dates in date.</li>"
                             "<li>'Date equals' matches everything that is within 24h from the given date, thus normally the day typed.</li>"
                             "<li>If you enter no unit the default unit (what you see when viewing the property of the item) is used.</li>"
                             "</ul>"
                             );

    explanation += tr("<p>You can write Dates in the following formats:</p>");
    explanation += "<ul>";
    explanation += "<li>" + QLocale::system().dateTimeFormat(QLocale::LongFormat) + "</li>";
    explanation += "<li>" + QLocale::system().dateTimeFormat(QLocale::ShortFormat) + "</li>";
    explanation += "<li>" + QLocale::c().dateTimeFormat(QLocale::LongFormat) + "</li>";
    explanation += "<li>" + QLocale::c().dateTimeFormat(QLocale::ShortFormat) + "</li>";
    explanation += "</ul>";
    explanation += tr("<p>The search can only convert following units:</p>");
    explanation += "<p>"+IUnit::getUnits().join(", ") + "</p>";
    explanation += tr("<p>The regex search uses this syntax: https://perldoc.perl.org/perlre.html</p>");
    explanation += tr("<p>Following keywords are available for searching:</p>");
    labelExplanation->setText(explanation);
    for(QString property : CSearch::getSearchTypeKeywords())
    {
        QListWidgetItem* item = new QListWidgetItem(property);
        item->setToolTip(CSearch::getSearchTypeExample(property));
        listWidgetComparison->addItem(item);
    }
    for(QString property : CSearch::getSearchPropertyKeywords())
    {
        QListWidgetItem* item = new QListWidgetItem(property);
        item->setToolTip(CSearch::getSearchPropertyMeaning(property));
        listWidgetProperties->addItem(item);
    }
    adjustSize();
}