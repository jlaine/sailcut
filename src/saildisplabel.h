/*
 * Copyright (C) Robert Lainé & Jeremy Lainé
 * See AUTHORS file for a full list of contributors.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef SAILDISPLABEL_H
#define SAILDISPLABEL_H

#include <QLabel>
#include "saildisp.h"

class QGridLayout;


/** A wireframe display area for a sail, based on a QLabel.
 *
 * @see CSailDispGL
 */
class CSailDispLabel : public QLabel, public CSailDisp
{
public:
    CSailDispLabel(QWidget *parent);

    void redraw();

protected:
    void mousePressEvent ( QMouseEvent * );
    void paintEvent( QPaintEvent * );
    void resizeEvent( QResizeEvent * );
    void wheelEvent( QWheelEvent *event);

private:
    /** Has the area been resized since last redraw */
    bool wasResized;
};

#endif
