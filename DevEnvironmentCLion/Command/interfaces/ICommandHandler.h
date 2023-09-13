#ifndef I_COMMAND_HANDLER_H_abff03ab_9fa0_46af_b8e2_2360be28d365
#define I_COMMAND_HANDLER_H_abff03ab_9fa0_46af_b8e2_2360be28d365

#include "ICommand.h"

namespace command {

    /**
     * The ICommandHandler interface defines a command handler for running commands.
     */
    class ICommandHandler
    {
    public:
        /**
         * The constructor.
         */
        ICommandHandler() = default;

        /**
         * The destructor.
         */
        virtual ~ICommandHandler() = default;

        /**
         * The copy/move constructors.
         */
        ICommandHandler(const ICommandHandler&) = delete;
        ICommandHandler(ICommandHandler&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ICommandHandler& operator=(const ICommandHandler&) = delete;
        ICommandHandler& operator=(ICommandHandler&&) = delete;

        /**
         * Runs a command and returns the exit status.
         */
        virtual int run(ICommand& command, int argc, char *argv[]) = 0;
    };

    //
    // Defines the SharedPtr of Command Handler...
    //
    using ICommandHandlerSharedPtr = std::shared_ptr<ICommandHandler>;
}

#endif // I_COMMAND_HANDLER_H_abff03ab_9fa0_46af_b8e2_2360be28d365
