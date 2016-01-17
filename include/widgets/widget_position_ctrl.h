/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2010 Jean-Pierre Charras, jaen-pierre.charras@gipsa-lab.inpg.com
 * Copyright (C) 1992-2012 KiCad Developers, see AUTHORS.txt for contributors.
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
 
#ifndef  WIDGET_POSITION_CTRL_H_
#define  WIDGET_POSITION_CTRL_H_

#include <wx/gdicmn.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/window.h>

#include "base_units.h"

/**************************************************************************/
/* Class to edit/enter a coordinate (pair of values) ( INCHES or MM ) in  */
/* dialog boxes,                                                          */
/**************************************************************************/
class WIDGET_POSITION_CTRL
{
public:
    EDA_UNITS_T   m_UserUnit;
    wxPoint       m_Pos_To_Edit;

    wxTextCtrl*   m_FramePosX;
    wxTextCtrl*   m_FramePosY;
private:
    wxStaticText* m_TextX, * m_TextY;

public:
    WIDGET_POSITION_CTRL( wxWindow* parent, const wxString& title,
                       const wxPoint& pos_to_edit, EDA_UNITS_T user_unit, wxBoxSizer* BoxSizer );

    ~WIDGET_POSITION_CTRL();

    void    Enable( bool x_win_on, bool y_win_on );
    void    SetValue( int x_value, int y_value );
    wxPoint GetValue();
};


#endif