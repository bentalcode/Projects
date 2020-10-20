#ifndef I_CAN_MESSAGE_GENERATOR_COMMAND_PARAMETERS_H_55c62eef_2357_4990_8650_0a809fb596b8
#define I_CAN_MESSAGE_GENERATOR_COMMAND_PARAMETERS_H_55c62eef_2357_4990_8650_0a809fb596b8

#include "Duration.h"

namespace controllerareanetwork {
    namespace messagegeneratorcommand {

        /**
         * The ICANMessageGeneratorCommandParameters interface defines the parameters of the command.
         */
        class ICANMessageGeneratorCommandParameters
        {
        public:
            /**
             * The constructor.
             */
            ICANMessageGeneratorCommandParameters() = default;

            /**
             * The destructor.
             */
            virtual ~ICANMessageGeneratorCommandParameters() = default;

            /**
             * The copy/move constructors.
             */
            ICANMessageGeneratorCommandParameters(const ICANMessageGeneratorCommandParameters&) = delete;
            ICANMessageGeneratorCommandParameters(ICANMessageGeneratorCommandParameters&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ICANMessageGeneratorCommandParameters &operator=(const ICANMessageGeneratorCommandParameters&) = delete;
            ICANMessageGeneratorCommandParameters &operator=(ICANMessageGeneratorCommandParameters&&) = delete;

            /**
             * Gets the duration of a drive session.
             */
            virtual const base::Duration& getDriveSessionDuration() const = 0;

            /**
             * Gets the messages frequencies.
             */
            virtual const std::vector<std::pair<std::string, size_t>>& getMessagesFrequencies() const = 0;
        };

        using ICANMessageGeneratorCommandParametersPtr = std::shared_ptr<ICANMessageGeneratorCommandParameters>;
        using ICANMessageGeneratorCommandParametersUniquePtr = std::unique_ptr<ICANMessageGeneratorCommandParameters>;
    }
}

#endif // I_CAN_MESSAGE_GENERATOR_COMMAND_PARAMETERS_H_55c62eef_2357_4990_8650_0a809fb596b8
