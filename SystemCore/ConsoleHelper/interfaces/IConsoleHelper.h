#ifndef I_CONSOLE_HELPER_H_dc082e11_b70f_42ab_9726_78cf2fb5c221
#define I_CONSOLE_HELPER_H_dc082e11_b70f_42ab_9726_78cf2fb5c221

#include <memory>

namespace console_helper
{
    /**
     * The IConsoleHelper interface defines a Console Helper command.
     */
    class IConsoleHelper
    {
    public:
        /**
         * The constructor.
         */
        IConsoleHelper() = default;

        /**
         * The destructor.
         */
        virtual ~IConsoleHelper() = default;

        /**
         * The copy/move constructors.
         */
        IConsoleHelper(const IConsoleHelper&) = delete;
        IConsoleHelper(IConsoleHelper&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IConsoleHelper& operator=(const IConsoleHelper&) = delete;
        IConsoleHelper& operator=(IConsoleHelper&&) = delete;

        /**
         * Gets the command.
         */
        virtual command::ICommand& GetCommand() = 0;
    };

    //
    // Defines the SharedPtr of Console Helper...
    //
    using IConsoleHelperSharedPtr = std::shared_ptr<IConsoleHelper>;

} // namespace console_helper

#endif // I_CONSOLE_HELPER_H_dc082e11_b70f_42ab_9726_78cf2fb5c221
