#ifndef COMMAND_PARAMETERS_H_772e5f14_fafb_4eb7_ba0b_95c46c28817e
#define COMMAND_PARAMETERS_H_772e5f14_fafb_4eb7_ba0b_95c46c28817e

#include "ICommandParameters.h"

namespace command {

    /**
     * The CommandParameters class implements the parameters of the Command.
     */
    class CommandParameters final : public ICommandParameters
    {
    public:
        /**
         * Creates a new command parameters.
         */
        static ICommandParametersPtr make(IParameterSetPtr parameterSet);

        /**
         * The CommandParameters Constructor.
         */
        explicit CommandParameters(IParameterSetPtr parameterSet);

        /**
         * The CommandParameters destructor.
         */
        virtual ~CommandParameters();

        /**
         * The copy/move constructors.
         */
        CommandParameters(const CommandParameters&) = delete;
        CommandParameters(CommandParameters&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        CommandParameters& operator=(const CommandParameters&) = delete;
        CommandParameters& operator=(CommandParameters&&) = delete;

        /**
         * Gets the parameter-set of the command.
         */
        virtual const IParameterSet& getParameterSet() const override;

    private:
        IParameterSetPtr m_parameterSet;
    };
}

#endif // COMMAND_PARAMETERS_H_772e5f14_fafb_4eb7_ba0b_95c46c28817e
