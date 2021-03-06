#ifndef ABSTRACT_COMMAND_H_adb4b1ac_1907_42b1_8dae_f9e0c3a69523
#define ABSTRACT_COMMAND_H_adb4b1ac_1907_42b1_8dae_f9e0c3a69523

#include "ICommand.h"

namespace command {

    /**
     * The AbstractCommand class implements an abstract command.
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
        virtual void setParameters(ICommandParametersPtr parameters) override;

        /**
         * Gets parameters of a command.
         */
        virtual const ICommandParameters& getParameters() const override;

        /**
         * Sets a message writer of a command.
         */
        virtual void setMessageWriter(base::IMessageWriterPtr messageWriter) override;

        /**
         * Gets a message writer of a command.
         */
        virtual base::IMessageWriter& getMessageWriter() override;

    private:
        ICommandParametersPtr m_parameters;
        base::IMessageWriterPtr m_messageWriter;
    };
}

#endif // ABSTRACT_COMMAND_H_adb4b1ac_1907_42b1_8dae_f9e0c3a69523
