#ifndef I_COMMAND_PARAMETERS_H_c3c9c854_be81_40a0_82fc_8c3422abb36b
#define I_COMMAND_PARAMETERS_H_c3c9c854_be81_40a0_82fc_8c3422abb36b

#include "IParameterSet.h"

namespace command {

    /**
     * The ICommandParameters interface defines parameters of the command.
     */
    class ICommandParameters
    {
    public:
        /**
         * The constructor.
         */
        ICommandParameters() = default;

        /**
         * The destructor.
         */
        virtual ~ICommandParameters() = default;

        /**
         * The copy/move constructors.
         */
        ICommandParameters(const ICommandParameters&) = delete;
        ICommandParameters(ICommandParameters&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ICommandParameters& operator=(const ICommandParameters&) = delete;
        ICommandParameters& operator=(ICommandParameters&&) = delete;

        /**
         * Gets the parameter-set of command.
         */
        virtual const IParameterSet& GetParameterSet() const = 0;
    };

    //
    // Defines the SharedPtr of Command Parameters...
    //
    using ICommandParametersSharedPtr = std::shared_ptr<ICommandParameters>;

} // namespace command

#endif // I_COMMAND_PARAMETERS_H_c3c9c854_be81_40a0_82fc_8c3422abb36b
