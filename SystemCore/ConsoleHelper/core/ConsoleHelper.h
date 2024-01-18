#ifndef CONSOLE_HELPER_H_5460031e_9873_4a92_88c3_7d6dfa549d40
#define CONSOLE_HELPER_H_5460031e_9873_4a92_88c3_7d6dfa549d40

#include "AbstractCommand.h"
#include "IConsoleHelper.h"
#include "IConsoleHelperParameters.h"

namespace console_helper {

    /**
     * The ConsoleHelper class implements a Console Helper command.
     */
    class ConsoleHelper final : public command::AbstractCommand, public IConsoleHelper
    {
    public:
        /**
         * Creates a Console Helper.
         */
         static IConsoleHelperSharedPtr Make();

        /**
         * The ConsoleHelper constructor.
         */
        ConsoleHelper();

        /**
         * The ConsoleHelper destructor.
         */
        virtual ~ConsoleHelper();

        /**
         * Runs the command.
         */
        virtual void Run() override;

        /**
         * Gets the command.
         */
        virtual command::ICommand& GetCommand() override;

    private:
        /**
         * Initializes the command.
         */
        void Initialize();

        //
        // The parameters of command...
        //
        IConsoleHelperParametersSharedPtr m_parameters;
    };

} // namespace console_helper

#endif // CONSOLE_HELPER_H_5460031e_9873_4a92_88c3_7d6dfa549d40
