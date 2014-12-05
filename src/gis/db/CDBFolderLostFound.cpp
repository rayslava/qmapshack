/**********************************************************************************************
    Copyright (C) 2014 Oliver Eichler oliver.eichler@gmx.de

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

#include "gis/db/CDBFolderLostFound.h"

CDBFolderLostFound::CDBFolderLostFound(QSqlDatabase& db, QTreeWidget *parent)
    : IDBFolder(false, db, eTypeLostFound, 0, parent)
{
    setToolTip(eColumnName, QObject::tr("All your data grouped by folders."));
    setIcon(eColumnCheckbox, QIcon("://icons/32x32/DeleteMultiple.png"));
    setText(eColumnName, QObject::tr("Lost & Found"));
}

CDBFolderLostFound::~CDBFolderLostFound()
{

}

