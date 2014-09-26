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

#ifndef CMOUSEEDITLINE_H
#define CMOUSEEDITLINE_H

#include "mouse/IMouse.h"
#include <QPolygonF>
#include <QPointer>

class CGisDraw;
class CCanvas;
class CGisItemTrk;
class CScrOptPoint;
class CScrOptEditLine;
class CScrOptRange;

class CMouseEditLine  : public IMouse
{
    Q_OBJECT
    public:
        CMouseEditLine(CGisItemTrk &trk, CGisDraw * gis, CCanvas * parent);
        virtual ~CMouseEditLine();

        void draw(QPainter& p,  bool needsRedraw, const QRect &rect);
        void mousePressEvent(QMouseEvent * e);
        void mouseMoveEvent(QMouseEvent * e);
        void mouseReleaseEvent(QMouseEvent *e);
        void wheelEvent(QWheelEvent * e);

    private slots:
        void slotDeletePoint();
        void slotSelectRange();
        void slotDeleteRange();
        void slotMovePoint();


        void slotAbort();
        void slotCopyToOrig();
        void slotCopyToNew();

    private:
        void drawPointOfFocus(QPainter& p);
        void drawBullets(QPainter& p);
        void drawHighlight1(QPainter& p);
        void drawHighlight2(QPainter& p);
        int getPointCloseBy(const QPoint& screenPos);
        QString     key;
        QPolygonF   coords1;
        QPolygonF   coords2;
        QPolygonF   line;

        enum state_e
        {
             eStateIdle
            ,eStatePointSelected
            ,eStateSelectRange
            ,eStateRangeSelected
            ,eStateMovePoint

        };

        state_e state;
        qint32 idxFocus;
        qint32 idxStart;
        qint32 idxStop;

        QPointer<CScrOptPoint> scrOptPoint;
        QPointer<CScrOptRange> scrOptRange;
        CScrOptEditLine * scrOptEditLine;
};

#endif //CMOUSEEDITLINE_H


