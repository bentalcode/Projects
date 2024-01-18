#ifndef CONSOLE_HELPER_CONSTANTS_H_4dc7d795_f2cf_4bea_bccb_580bd8b22359
#define CONSOLE_HELPER_CONSTANTS_H_4dc7d795_f2cf_4bea_bccb_580bd8b22359

#include <string>

namespace console_helper {

    /**
     * The ConsoleHelperConstants class implements constants of Console Helper.
     */
    class ConsoleHelperConstants final
    {
    public:
        static const std::wstring CONSOLE_TITLE;
        static const std::wstring CONSOLE_TITLE_SHORT_NAME;
        static const std::wstring CONSOLE_TITLE_LONG_NAME;
        static const std::wstring CONSOLE_TITLE_DESCRIPTION;

        static const std::wstring PIPE_NAME;
        static const std::wstring PIPE_NAME_SHORT_NAME;
        static const std::wstring PIPE_NAME_LONG_NAME;
        static const std::wstring PIPE_NAME_DESCRIPTION;

    private:
        ConsoleHelperConstants() = delete;
        ~ConsoleHelperConstants() = delete;
    };

} // namespace console_helper

#endif // CONSOLE_HELPER_CONSTANTS_H_4dc7d795_f2cf_4bea_bccb_580bd8b22359
