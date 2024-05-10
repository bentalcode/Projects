#ifndef I_COLOR_80669883_9b12_4138_8065_fb420f9fa437
#define I_COLOR_80669883_9b12_4138_8065_fb420f9fa437

#include "wx/colour.h"
#include <memory>

namespace wxwidgets {

    /**
     * Defines the various color names.
     */
    enum class ColorType {
        WHITE,
        GREEN,
        RED,
        YELLOW,
        LIGHT_GREY,
        BLUE,
        CYAN,
        BLACK
    };

    /**
     * The IColor interface defines a color.
     */
    class IColor {
    public:
        IColor() = default;
        virtual ~IColor() = default;

        /**
         * Gets type of color.
         */
        virtual const ColorType GetType() const = 0;

        /**
         * Gets a native color.
         */
        virtual const wxColour& AsColor() const = 0;
    };

    //
    // Defines the Shared Ptr of Color.
    //
    using IColorSharedPtr = std::shared_ptr<IColor>;

} // namespace wxwidgets

#endif // I_COLOR_80669883_9b12_4138_8065_fb420f9fa437

