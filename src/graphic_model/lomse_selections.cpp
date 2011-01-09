//---------------------------------------------------------------------------------------
//  This file is part of the Lomse library.
//  Copyright (c) 2010-2011 Lomse project
//
//  Lomse is free software; you can redistribute it and/or modify it under the
//  terms of the GNU General Public License as published by the Free Software Foundation,
//  either version 3 of the License, or (at your option) any later version.
//
//  Lomse is distributed in the hope that it will be useful, but WITHOUT ANY
//  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
//  PARTICULAR PURPOSE.  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with Lomse; if not, see <http://www.gnu.org/licenses/>.
//
//  For any comment, suggestion or feature request, please contact the manager of
//  the project at cecilios@users.sourceforge.net
//
//---------------------------------------------------------------------------------------

#include "lomse_selections.h"

#include "lomse_gm_basic.h"


namespace lomse
{

//=======================================================================================
// SelectionSet implementation
//=======================================================================================
SelectionSet::SelectionSet()
{
}

//---------------------------------------------------------------------------------------
SelectionSet::~SelectionSet()
{
    m_objects.clear();
}

//---------------------------------------------------------------------------------------
void SelectionSet::add(GmoObj* pGmo, unsigned flags)
{
    m_objects.push_back(pGmo);
    pGmo->set_selected(true);
}

//---------------------------------------------------------------------------------------
bool SelectionSet::contains(GmoObj* pGmo)
{
    std::list<GmoObj*>::iterator it;
    for (it = m_objects.begin(); it != m_objects.end(); ++it)
    {
        if (*it == pGmo)
            return true;
    }
    return false;
}

//---------------------------------------------------------------------------------------
void SelectionSet::clear()
{
    std::list<GmoObj*>::iterator it;
    for (it = m_objects.begin(); it != m_objects.end(); ++it)
    {
        (*it)->set_selected(false);
    }
    m_objects.clear();
}



}  //namespace lomse