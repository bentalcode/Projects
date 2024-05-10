#ifndef I_FONT_f288c1f7_aed6_4e40_861b_ab37d99ca3ad
#define I_FONT_f288c1f7_aed6_4e40_861b_ab37d99ca3ad

#include <memory>
#include <wx/font.h>

namespace WXWidgets {

    /**
     * The IFont interface defines a font.
     */
    class IFont {
    public:
        IFont() = default;
        virtual ~IFont() = default;

        /**
         * Makes font bold.
         */
        virtual IFont& MakeBold() = 0;

        /**
         * Makes font italic.
         */
        virtual IFont& MakeItalic() = 0;

        /**
         * Returns whether font is fine.
         */
        virtual bool IsFine() const = 0;

        /**
         * Gets a native font.
         */
        virtual const wxFont& AsFont() const = 0;
    };

    //
    // Defines the Shared Ptr of Font.
    //
    using IFontSharedPtr = std::shared_ptr<IFont>;

} // namespace WXWidgets

#endif // I_FONT_f288c1f7_aed6_4e40_861b_ab37d99ca3ad
