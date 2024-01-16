#ifndef COMMAND_CONSTANTS_H_153e383c_762e_4d0e_baee_ee98cdc5b9d5
#define COMMAND_CONSTANTS_H_153e383c_762e_4d0e_baee_ee98cdc5b9d5

#include <string>

namespace Command {

    /**
     * The CommandConstants interface defines constants of a command.
     */
    class CommandConstants final
    {
    public:
        static const std::wstring MANIFEST_RESOURCE_NAME;

        static const std::wstring SHORT_NAMED_PARAMETER_PREFIX;
        static const std::wstring LONG_NAMED_PARAMETER_PREFIX;
        static const std::wstring NAMED_PARAMETER_SEPARATOR;

        static const std::wstring TRUE_VALUE;

        static const std::wstring HELP_SHORT_NAME;
        static const std::wstring HELP_LONG_NAME;

        static const int HELP_PARAMETER_SET_INDEX;

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        CommandConstants() = delete;
        ~CommandConstants() = delete;
    };

} // namespace Command

#endif // I_COMMAND_CONSTANTS_H_153e383c_762e_4d0e_baee_ee98cdc5b9d5
