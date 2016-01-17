/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2004 Jean-Pierre Charras, jaen-pierre.charras@gipsa-lab.inpg.com
 * Copyright (C) 1992-2011 KiCad Developers, see AUTHORS.txt for contributors.
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
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */
 
#include "widgets/widget_size_ctrl.h"

/*******************/
/* WIDGET_SIZE_CTRL */
/*******************/
WIDGET_SIZE_CTRL::WIDGET_SIZE_CTRL( wxWindow* parent, const wxString& title,
                              const wxSize& size_to_edit, EDA_UNITS_T aUnit,
                              wxBoxSizer* aBoxSizer ) :
    WIDGET_POSITION_CTRL( parent, title, wxPoint( size_to_edit.x, size_to_edit.y ),
                       aUnit, aBoxSizer )
{
}


wxSize WIDGET_SIZE_CTRL::GetValue()
{
    wxPoint pos = WIDGET_POSITION_CTRL::GetValue();
    wxSize  size;

    size.x = pos.x;
    size.y = pos.y;
    return size;
}
