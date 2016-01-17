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

#include "widgets/widget_value_ctrl.h"
 
/**************************************************************/
/* Class to display and edit a dimension INCHES, MM, or other */
/**************************************************************/
WIDGET_VALUE_CTRL::WIDGET_VALUE_CTRL( wxWindow* parent, const wxString& title,
                                int value, EDA_UNITS_T user_unit, wxBoxSizer* BoxSizer )
{
    wxString label = title;

    m_UserUnit = user_unit;
    m_Value = value;
    label  += ReturnUnitSymbol( m_UserUnit );

    m_Text = new wxStaticText( parent, -1, label );

    BoxSizer->Add( m_Text, 0, wxGROW | wxLEFT | wxRIGHT | wxTOP, 5 );

    wxString stringvalue = StringFromValue( m_UserUnit, m_Value );
    m_ValueCtrl = new wxTextCtrl( parent, -1, stringvalue );

    BoxSizer->Add( m_ValueCtrl,
                   0,
                   wxGROW | wxALIGN_CENTER_VERTICAL | wxLEFT | wxRIGHT | wxBOTTOM,
                   5 );
}


WIDGET_VALUE_CTRL::~WIDGET_VALUE_CTRL()
{
    delete m_ValueCtrl;
    delete m_Text;
}


int WIDGET_VALUE_CTRL::GetValue()
{
    int      coord;
    wxString txtvalue = m_ValueCtrl->GetValue();

    coord = ValueFromString( m_UserUnit, txtvalue );
    return coord;
}


void WIDGET_VALUE_CTRL::SetValue( int new_value )
{
    wxString buffer;

    m_Value = new_value;

    buffer = StringFromValue( m_UserUnit, m_Value );
    m_ValueCtrl->SetValue( buffer );
}


void WIDGET_VALUE_CTRL::Enable( bool enbl )
{
    m_ValueCtrl->Enable( enbl );
    m_Text->Enable( enbl );
}
