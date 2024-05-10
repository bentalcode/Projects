#include "Font.h"

using namespace wxwidgets;

/**
 * Creates a font.
 */
IFontSharedPtr Font::Make(
    int size, 
    wxFontFamily family, 
    wxFontStyle style,
    wxFontWeight weight, 
    bool underlined,
    const wxString& face, 
    wxFontEncoding encoding)
{
    return std::make_shared<Font>(
        size,
        family,
        style,
        weight, 
        underlined, 
        face,
        encoding);
}

/**
 * The Font constructor.
 */
Font::Font(
    int size, 
    wxFontFamily family, 
    wxFontStyle style, 
    wxFontWeight weight, 
    bool underlined, 
    const wxString& face,
    wxFontEncoding encoding) : 
        wxFont(
            size, 
            family, 
            style, 
            weight, 
            underlined, 
            face, 
            encoding)
{
}

/**
 * The Font destructor.
 */
Font::~Font() 
{
}

/**
 * Makes font bold.
 */
IFont& Font::MakeBold() 
{
    wxFont::MakeBold();
    return *this;
}

/**
 * Makes font italic.
 */
IFont& Font::MakeItalic()
{
    wxFont::MakeItalic();
    return *this;
}

/**
 * Returns whether font is fine.
 */
bool Font::IsFine() const 
{
    return wxFont::IsOk();
}

/**
 * Gets a native font.
 */
const wxFont& Font::AsFont() const 
{
    return *this;
}
