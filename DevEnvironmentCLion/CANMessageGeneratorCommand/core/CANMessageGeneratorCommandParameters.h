#ifndef CAN_MESSAGE_GENERATOR_COMMAND_PARAMETERS_H_10d30a3b_2602_4f3c_95ea_a8a0cc8907e0
#define CAN_MESSAGE_GENERATOR_COMMAND_PARAMETERS_H_10d30a3b_2602_4f3c_95ea_a8a0cc8907e0

#include "ICANMessageGeneratorCommandParameters.h"
#include "CommandParameters.h"

namespace controllerareanetwork {
    namespace messagegeneratorcommand {

        /**
         * The CANMessageGeneratorCommandParameters class implements the parameters of 
         * the CAN Message Generator Command.
         */
        class CANMessageGeneratorCommandParameters final : public ICANMessageGeneratorCommandParameters
        {
        public:
            /**
             * The CANMessageGeneratorCommandParameters Constructor.
             */
            CANMessageGeneratorCommandParameters(const command::ICommandParameters& parameters);

            /**
             * The CANMessageGeneratorCommandParameters destructor.
             */
            virtual ~CANMessageGeneratorCommandParameters();

            /**
             * The copy/move constructors.
             */
            CANMessageGeneratorCommandParameters(const CANMessageGeneratorCommandParameters&) = delete;
            CANMessageGeneratorCommandParameters(CANMessageGeneratorCommandParameters&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CANMessageGeneratorCommandParameters& operator=(const CANMessageGeneratorCommandParameters&) = delete;
            CANMessageGeneratorCommandParameters& operator=(CANMessageGeneratorCommandParameters&&) = delete;

            /**
             * Gets the duration of a drive session.
             */
            virtual const base::Duration& getDriveSessionDuration() const override;

            /**
             * Gets the messages frequencies.
             */
            virtual const std::vector<std::pair<std::string, size_t>>& getMessagesFrequencies() const override;

        private:
            static const size_t defaultSessionDurationInSeconds;

            /**
             * Parses the message frequencies.
             */
            static void parseMessageFrequencies(
                const std::vector<std::string>& messagesFrequenciesStrings,
                std::vector<std::pair<std::string, size_t>>& result);

            base::DurationPtr m_duration;
            std::vector<std::pair<std::string, size_t>> m_messagesFrequencies;
        };

        using CANMessageGeneratorCommandParametersPtr = std::unique_ptr<CANMessageGeneratorCommandParameters>;
    }
}

#endif // CAN_MESSAGE_GENERATOR_COMMAND_PARAMETERS_H_10d30a3b_2602_4f3c_95ea_a8a0cc8907e0
