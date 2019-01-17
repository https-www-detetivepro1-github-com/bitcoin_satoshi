///////////////////////////////////////////////////////////////////////////////
// Name:        wx/motif/menuitem.h
// Purpose:     wxMenuItem class
// Author:      Vadim Zeitlin
// Modified by:
// Created:     11.11.97
// RCS-ID:      $Id: menuitem.h 48053 2007-08-13 17:07:01Z JS $
// Copyright:   (c) 1998 Vadim Zeitlin <zeitlin@dptmaths.ens-cachan.fr>
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_MOTIF_MENUITEM_H
#define _WX_MOTIF_MENUITEM_H

#include "wx/bitmap.h"

class WXDLLEXPORT wxMenuBar;

// ----------------------------------------------------------------------------
// wxMenuItem: an item in the menu, optionally implements owner-drawn behaviour
// ----------------------------------------------------------------------------

class WXDLLIMPEXP_CORE wxMenuItem : public wxMenuItemBase
{
public:
    // ctor & dtor
    wxMenuItem(wxMenu *parentMenu = (wxMenu *)NULL,
               int id = wxID_SEPARATOR,
               const wxString& text = wxEmptyString,
               const wxString& help = wxEmptyString,
               wxItemKind kind = wxITEM_NORMAL,
               wxMenu *subMenu = (wxMenu *)NULL);
    virtual ~wxMenuItem();

    // accessors (some more are inherited from wxOwnerDrawn or are below)
    virtual void SetText(const wxString& label);
    virtual void Enable(bool enable = true);
    virtual void Check(bool check = true);
    // included SetBitmap and GetBitmap as copied from the GTK include file
    // I'm not sure if this works but it silences the linker in the
    // menu sample.
    //     JJ
    virtual void SetBitmap(const wxBitmap& bitmap) { m_bitmap = bitmap; }
    virtual const wxBitmap& GetBitmap() const { return m_bitmap; }

    // implementation from now on
    void CreateItem (WXWidget menu, wxMenuBar * menuBar, wxMenu * topMenu,
                     size_t index);
    void DestroyItem(bool full);

    WXWidget GetButtonWidget() const { return m_buttonWidget; }

    wxMenuBar* GetMenuBar() const { return m_menuBar; }
    void SetMenuBar(wxMenuBar* menuBar) { m_menuBar = menuBar; }

    wxMenu* GetTopMenu() const { return m_topMenu; }
    void SetTopMenu(wxMenu* menu) { m_topMenu = menu; }

private:
    WXWidget    m_buttonWidget;
    wxMenuBar*  m_menuBar;
    wxMenu*     m_topMenu;        // Top-level menu e.g. popup-menu
    wxBitmap  m_bitmap; // Bitmap for menuitem, if any

    DECLARE_DYNAMIC_CLASS(wxMenuItem)

public:

#if wxABI_VERSION >= 20805
    // return the item label including any mnemonics and accelerators.
    // This used to be called GetText.
    wxString GetItemLabel() const { return GetText(); }
#endif

};

#endif  // _WX_MOTIF_MENUITEM_H
