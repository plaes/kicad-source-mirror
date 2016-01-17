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
 
#ifndef  WIDGET_GRAPHIC_TEXT_CTRL_H_
#define  WIDGET_GRAPHIC_TEXT_CTRL_H_

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/window.h>

#include "base_units.h"

/**
 * Class WIDGET_GRAPHIC_TEXT_CTRL
 * is a custom text edit control to edit/enter Kicad dimensions ( INCHES or MM )
 */
class WIDGET_GRAPHIC_TEXT_CTRL
{
public:
    EDA_UNITS_T   m_UserUnit;

    wxTextCtrl*   m_FrameText;
    wxTextCtrl*   m_FrameSize;
private:
    wxStaticText* m_Title;

public:
    WIDGET_GRAPHIC_TEXT_CTRL( wxWindow* parent, const wxString& Title,
                           const wxString& TextToEdit, int textsize,
                           EDA_UNITS_T user_unit, wxBoxSizer* BoxSizer, int framelen = 200 );

    ~WIDGET_GRAPHIC_TEXT_CTRL();

    const wxString  GetText() const;
    int             GetTextSize();
    void            Enable( bool state );
    void            SetTitle( const wxString& title );

    void            SetFocus() { m_FrameText->SetFocus(); }
    void            SetValue( const wxString& value );
    void            SetValue( int value );

    /**
     * Function FormatSize
     * formats a string containing the size in the desired units.
     */
    static wxString FormatSize( EDA_UNITS_T user_unit, int textSize );

    static int      ParseSize( const wxString& sizeText, EDA_UNITS_T user_unit );
};

#endif