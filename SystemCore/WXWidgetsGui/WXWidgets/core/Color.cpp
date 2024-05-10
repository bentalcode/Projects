#include "Color.h"
#include "wx\gdicmn.h"

using namespace wxwidgets;

/**
 * Creates a color.
 */
IColorSharedPtr Color::Make(ColorType type)
{
    return std::make_shared<Color>(type);
}

/**
 * The Color constructor.
 */
Color::Color(ColorType type) : 
    m_type(type), 
    m_color(GetColor(type)) 
{
}

/**
 * The Color destructor.
 */
Color::~Color() 
{
}

/**
 * Gets type of color.
 */
const ColorType Color::GetType() const 
{
    return m_type;
}

/**
 * Gets a native color.
 */
const wxColour& Color::AsColor() const
{
    return m_color;
}

/**
 * Gets a color.
 */
const wxColour& Color::GetColor(ColorType type) const 
{
    const Color::TypeToColorMap& colorMap = GetTypeToColorMap();
    TypeToColorMap::const_iterator colorIterator = colorMap.find(type);
    return *colorIterator->second;
}

/**
 * Gets the Type -> Color map.
 */
const Color::TypeToColorMap& Color::GetTypeToColorMap() const 
{
    static std::unique_ptr<TypeToColorMap> mapPtr;

    if (!mapPtr) {
        mapPtr.reset(new TypeToColorMap);
        InitializeTypeToColorMap(*mapPtr);
    }
    
    return *mapPtr;
}

/**
 * Initializes the Type -> Color map.
 */
void Color::InitializeTypeToColorMap(TypeToColorMap& map) 
{
    map.insert(std::make_pair(ColorType::WHITE, wxWHITE));
    map.insert(std::make_pair(ColorType::GREEN, wxGREEN));
    map.insert(std::make_pair(ColorType::RED, wxRED));
    map.insert(std::make_pair(ColorType::YELLOW, wxYELLOW));
    map.insert(std::make_pair(ColorType::LIGHT_GREY, wxLIGHT_GREY));
    map.insert(std::make_pair(ColorType::BLUE, wxBLUE));
    map.insert(std::make_pair(ColorType::CYAN, wxCYAN));
    map.insert(std::make_pair(ColorType::BLACK, wxBLACK));
}
