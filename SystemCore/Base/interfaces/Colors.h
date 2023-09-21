#ifndef COLORS_H_71a6f2a6_57cf_11ee_8c99_0242ac120002
#define COLORS_H_71a6f2a6_57cf_11ee_8c99_0242ac120002

#include <iosfwd>
#include <string>

namespace base {

    /**
     * Defines colors.
     */
    namespace Colors {

        /**
         * Foreground Colors.
         */
        enum class FGColor {
            BLACK = 30,
            RED = 31,
            GREEN = 32,
            YELLOW = 33,
            BLUE = 34,
            MAGENTA = 35,
            CAYAN = 36,
            WHITE = 37,
            BRIGHT_BLACK = 90,
            BRIGHT_RED = 91,
            BRIGHT_GREEN = 92,
            BRIGHT_YELLOW = 93,
            BRIGHT_BLUE = 94,
            BRIGHT_MAGENTA = 95,
            BRIGHT_CAYAN = 96,
            BRIGHT_WHITE = 97
        };

        /**
         * Background Colors.
         */
        enum class BGColor {
            BLACK = 40,
            RED = 41,
            GREEN = 42,
            YELLOW = 43,
            BLUE = 44,
            MAGENTA = 45,
            CAYAN = 46,
            WHITE = 47,
            BRIGHT_BLACK = 100,
            BRIGHT_RED = 101,
            BRIGHT_GREEN = 102,
            BRIGHT_YELLOW = 103,
            BRIGHT_BLUE = 104,
            BRIGHT_MAGENTA = 105,
            BRIGHT_CAYAN = 106,
            BRIGHT_WHITE = 107
        };

        /**
         * The FGColorModifier class implements a foreground color modifier.
         */
        class FGColorModifier final {
        public:
            /**
             * The FGColorModifier constructor.
             */
            explicit FGColorModifier(FGColor fgColor);

            /**
             * Get code.
             */
            int GetCode() const;

        private:
            FGColor m_fgColor;
        };

        /**
         * The FGColorModifier constructor.
         */
        FGColorModifier::FGColorModifier(FGColor fgColor) :
            m_fgColor(fgColor)
        {
        }

        /**
         * Get code.
         */
        int FGColorModifier::GetCode() const
        {
            return static_cast<int>(m_fgColor);
        }

        /**
         * Writes color to an output stream.
         */
        inline std::wostream& operator<<(std::wostream& stream, const FGColorModifier& modifier)
        {
            std::wstring format = L"\0" + std::to_wstring(modifier.GetCode()) + L"[32m";
            stream << format;
            return stream;
        }

    } // namespace Colors

} // namespace base

#endif // namespace COLORS_H_71a6f2a6_57cf_11ee_8c99_0242ac120002
