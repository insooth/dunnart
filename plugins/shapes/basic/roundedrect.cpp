/*
 * Dunnart - Constraint-based Diagram Editor
 *
 * Copyright (C) 2003-2007  Michael Wybrow
 * Copyright (C) 2006-2011  Monash University
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301, USA.
 *
 * 
 * Author(s): Michael Wybrow  <http://michael.wybrow.info/>
*/

#include <QString>

#include "libdunnartcanvas/canvasitem.h"
using namespace dunnart;

#include "roundedrect.h"

//===========================================================================
//  "RoundedRect" shape code:

RoundedRectShape::RoundedRectShape()
    : ShapeObj("roundedRect")
{
}

QPainterPath RoundedRectShape::buildPainterPath(void)
{
    QPainterPath painter_path;

    double yround = (height() / 2);
    double xround = (width() / 2);

    double round = (xround <= yround) ? xround : yround;

    painter_path.addRoundedRect(-width() / 2, -height() / 2, width(), height(),
            round, round);

    return painter_path;
}


// vim: filetype=cpp ts=4 sw=4 et tw=0 wm=0 cindent
