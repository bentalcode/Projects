#ifndef CONSOLE_FILE_FINDER_COMMAND_CONSTANTS_H_52dbe3bd_89b3_4e76_bc32_141661a6ad7d
#define CONSOLE_FILE_FINDER_COMMAND_CONSTANTS_H_52dbe3bd_89b3_4e76_bc32_141661a6ad7d

#include <string>

namespace consolefilefinder {

    /**
     * The ConsoleFileFinderCommandConstants class implements constants of Console File Finder Command.
     */
    class ConsoleFileFinderCommandConstants final
    {
    public:
        static const std::wstring PARAMETER_PATH_NAME;
        static const std::wstring PARAMETER_PATH_SHORT_NAME;
        static const std::wstring PARAMETER_PATH_LONG_NAME;
        static const std::wstring PARAMETER_PATH_DESCRIPTION;

        static const std::wstring PARAMETER_FILE_PATTERNS_NAME;
        static const std::wstring PARAMETER_FILE_PATTERNS_SHORT_NAME;
        static const std::wstring PARAMETER_FILE_PATTERNS_LONG_NAME;
        static const std::wstring PARAMETER_FILE_PATTERNS_DESCRIPTION;

    private:
        ConsoleFileFinderCommandConstants() = delete;
        ~ConsoleFileFinderCommandConstants() = delete;
    };

} // namespace consolefilefinder

#endif // CONSOLE_FILE_FINDER_COMMAND_CONSTANTS_H_52dbe3bd_89b3_4e76_bc32_141661a6ad7d
