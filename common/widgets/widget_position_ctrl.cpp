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

#include "widgets/widget_position_ctrl.h"
 
/********************************************************/
/* Class to display and edit a coordinated INCHES or MM */
/********************************************************/
WIDGET_POSITION_CTRL::WIDGET_POSITION_CTRL( wxWindow*       parent,
                                      const wxString& title,
                                      const wxPoint&  pos_to_edit,
                                      EDA_UNITS_T     user_unit,
                                      wxBoxSizer*     BoxSizer )
{
    wxString text;

    m_UserUnit = user_unit;

    if( title.IsEmpty() )
        text = _( "Pos " );
    else
        text = title;

    text   += _( "X" ) + ReturnUnitSymbol( m_UserUnit );
    m_TextX = new wxStaticText( parent, -1, text );

    BoxSizer->Add( m_TextX, 0, wxGROW | wxLEFT | wxRIGHT | wxTOP, 5 );
    m_FramePosX = new wxTextCtrl( parent, -1, wxEmptyString, wxDefaultPosition );

    BoxSizer->Add( m_FramePosX, 0, wxGROW | wxLEFT | wxRIGHT | wxBOTTOM, 5 );


    if( title.IsEmpty() )
        text = _( "Pos " );
    else
        text = title;
    text   += _( "Y" ) + ReturnUnitSymbol( m_UserUnit );

    m_TextY = new wxStaticText( parent, -1, text );

    BoxSizer->Add( m_TextY, 0, wxGROW | wxLEFT | wxRIGHT | wxTOP, 5 );

    m_FramePosY = new wxTextCtrl( parent, -1, wxEmptyString );

    BoxSizer->Add( m_FramePosY, 0, wxGROW | wxLEFT | wxRIGHT | wxBOTTOM, 5 );

    SetValue( pos_to_edit.x, pos_to_edit.y );
}


WIDGET_POSITION_CTRL::~WIDGET_POSITION_CTRL()
{
    delete m_TextX;
    delete m_TextY;
    delete m_FramePosX;
    delete m_FramePosY;
}


/* Returns (in internal units) to coordinate between (in user units)
 */
wxPoint WIDGET_POSITION_CTRL::GetValue()
{
    wxPoint coord;

    coord.x = ValueFromString( m_UserUnit, m_FramePosX->GetValue() );
    coord.y = ValueFromString( m_UserUnit, m_FramePosY->GetValue() );

    return coord;
}


void WIDGET_POSITION_CTRL::Enable( bool x_win_on, bool y_win_on )
{
    m_FramePosX->Enable( x_win_on );
    m_FramePosY->Enable( y_win_on );
}


void WIDGET_POSITION_CTRL::SetValue( int x_value, int y_value )
{
    wxString msg;

    m_Pos_To_Edit.x = x_value;
    m_Pos_To_Edit.y = y_value;

    msg = StringFromValue( m_UserUnit, m_Pos_To_Edit.x );
    m_FramePosX->Clear();
    m_FramePosX->SetValue( msg );

    msg = StringFromValue( m_UserUnit, m_Pos_To_Edit.y );
    m_FramePosY->Clear();
    m_FramePosY->SetValue( msg );
}