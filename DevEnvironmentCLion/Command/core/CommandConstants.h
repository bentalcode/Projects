#ifndef COMMAND_CONSTANTS_H_153e383c_762e_4d0e_baee_ee98cdc5b9d5
#define COMMAND_CONSTANTS_H_153e383c_762e_4d0e_baee_ee98cdc5b9d5

namespace command {

    /**
     * The CommandConstants interface defines constants of a command.
     */
    class CommandConstants final
    {
    public:
        static const std::string manifestResourceName;

        static const std::string shortNamedParameterPrefix;
        static const std::string longNamedParameterPrefix;
        static const std::string namedParameterSeparator;

        static const std::string trueValue;

        static const std::string helpShortName;
        static const std::string helpLongName;

        static const int helpParameterSetIndex;

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        CommandConstants() = delete;
        ~CommandConstants() = delete;
    };
}

#endif // I_COMMAND_CONSTANTS_H_153e383c_762e_4d0e_baee_ee98cdc5b9d5
