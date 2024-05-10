#ifndef FONT_ba6eb94d_2bc3_4cdf_9fc0_d34230eb95a1
#define FONT_ba6eb94d_2bc3_4cdf_9fc0_d34230eb95a1

#include "IFont.h"
#include <wx/defs.h>

namespace WXWidgets {

    /**
     * The Font class implements font.
     */
    class Font : public wxFont, public IFont {
    public:
        /**
         * Creates a font.
         */
        static IFontSharedPtr Make(
            int size = 10,
            wxFontFamily family = wxFONTFAMILY_DEFAULT,
            wxFontStyle style = wxFONTSTYLE_NORMAL,
            wxFontWeight weight = wxFONTWEIGHT_NORMAL,
            bool underlined = false,
            const wxString& face = wxEmptyString,
            wxFontEncoding encoding = wxFONTENCODING_DEFAULT);

        /**
         * The Font constructor.
         */
        Font(
            int size = 10,
            wxFontFamily family = wxFONTFAMILY_DEFAULT,
            wxFontStyle style = wxFONTSTYLE_NORMAL,
            wxFontWeight weight = wxFONTWEIGHT_NORMAL,
            bool underlined = false,
            const wxString& face = wxEmptyString,
            wxFontEncoding encoding = wxFONTENCODING_DEFAULT);

        /**
         * The Font destructor.
         */
        virtual ~Font();

        /**
         * Makes the font bold.
         */
        virtual IFont& MakeBold() override;

        /**
         * Makes font italic.
         */
        virtual IFont& MakeItalic() override;

        /**
         * Returns whether font is fine.
         */
        virtual bool IsFine() const override;

        /**
         * Gets a native font.
         */
        virtual const wxFont& AsFont() const override;
    };

} // namespace WXWidgets

#endif // FONT_ba6eb94d_2bc3_4cdf_9fc0_d34230eb95a1
