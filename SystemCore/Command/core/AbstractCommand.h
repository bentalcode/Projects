#ifndef ABSTRACT_COMMAND_H_adb4b1ac_1907_42b1_8dae_f9e0c3a69523
#define ABSTRACT_COMMAND_H_adb4b1ac_1907_42b1_8dae_f9e0c3a69523

#include "ICommand.h"

namespace command {

    /**
     * The AbstractCommand class implements an abstract Command.
     */
    class AbstractCommand : public ICommand
    {
    protected:
        /**
         * The AbstractCommand Constructor.
         */
        AbstractCommand();

    public:
        /**
         * The AbstractCommand Destructor.
         */
        virtual ~AbstractCommand();

        /**
         * The copy/move constructors.
         */
        AbstractCommand(const AbstractCommand&) = delete;
        AbstractCommand(AbstractCommand&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        AbstractCommand& operator=(const AbstractCommand&) = delete;
        AbstractCommand& operator=(AbstractCommand&&) = delete;

        /**
         * Sets parameters of a command.
         */
        virtual void SetParameters(ICommandParametersSharedPtr parameters) override;

        /**
         * Gets parameters of a command.
         */
        virtual const ICommandParameters& GetParameters() const override;

        /**
         * Sets a message writer of a command.
         */
        virtual void SetMessageWriter(base::IMessageWriterSharedPtr messageWriter) override;

        /**
         * Gets a message writer of a command.
         */
        virtual base::IMessageWriter& GetMessageWriter() override;

    private:
        ICommandParametersSharedPtr m_parameters;
        base::IMessageWriterSharedPtr m_messageWriter;
    };

} // namespace command

#endif // ABSTRACT_COMMAND_H_adb4b1ac_1907_42b1_8dae_f9e0c3a69523
