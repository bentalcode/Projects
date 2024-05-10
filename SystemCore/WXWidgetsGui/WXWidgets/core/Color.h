#ifndef COLOR_d377be7e_67c0_4a7d_8e71_cefe0ef2aca0
#define COLOR_d377be7e_67c0_4a7d_8e71_cefe0ef2aca0

#include "IColor.h"
#include <map>

namespace WXWidgets {

    /**
     * The Color class implements a color.
     */
    class Color : public IColor {
    public:
        /**
         * Creates a color.
         */
        static IColorSharedPtr Make(ColorType type);

        /**
         * The Color constructor.
         */
        explicit Color(ColorType type);

        /**
         * The App destructor.
         */
        virtual ~Color();

        /**
         * Gets type of color.
         */
        virtual const ColorType GetType() const override;

        /**
         * Gets a native color.
         */
        virtual const wxColour& AsColor() const override;

    private:
        //
        // Defines the mapping between a type to it's color...
        //
        using TypeToColorMap = std::map<ColorType, const wxColour*>;

        /**
         * Gets a color.
         */
        const wxColour& GetColor(ColorType Type) const;

        /**
         * Gets the Type -> Color map.
         */
        const TypeToColorMap& GetTypeToColorMap() const;

        /**
         * Initializes the Type -> Color map.
         */
        static void InitializeTypeToColorMap(TypeToColorMap& map);

        ColorType m_type;
        wxColour m_color;
    };

} // namespace WXWidgets

#endif // COLOR_d377be7e_67c0_4a7d_8e71_cefe0ef2aca0
