#ifndef I_COMMAND_H_7331e91c_6adf_416a_b19e_3180f8f9b285
#define I_COMMAND_H_7331e91c_6adf_416a_b19e_3180f8f9b285

#include "ICommandParameters.h"
#include "IMessageWriter.h"

namespace Command {

    /**
     * The ICommand interface defines a command.
     */
    class ICommand
    {
    public:
        /**
         * The constructor.
         */
        ICommand() = default;

        /**
         * The destructor.
         */
        virtual ~ICommand() = default;

        /**
         * The copy/move constructors.
         */
        ICommand(const ICommand&) = delete;
        ICommand(ICommand&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ICommand& operator=(const ICommand&) = delete;
        ICommand& operator=(ICommand&&) = delete;

        /**
         * Sets parameters of a command.
         */
        virtual void SetParameters(ICommandParametersSharedPtr parameters) = 0;

        /**
         * Gets parameters of a command.
         */
        virtual const ICommandParameters& GetParameters() const = 0;

        /**
         * Sets a message writer of a command.
         */
        virtual void SetMessageWriter(base::IMessageWriterSharedPtr messageWriter) = 0;

        /**
         * Gets a message writer of a command.
         */
        virtual base::IMessageWriter& GetMessageWriter() = 0;

        /**
         * Runs the logic of a command.
         */
        virtual void Run() = 0;
    };

    //
    // Defines the SharedPtr of Command...
    //
    using ICommandSharedPtr = std::shared_ptr<ICommand>;

} // namespace Command

#endif // I_COMMAND_H_7331e91c_6adf_416a_b19e_3180f8f9b285
