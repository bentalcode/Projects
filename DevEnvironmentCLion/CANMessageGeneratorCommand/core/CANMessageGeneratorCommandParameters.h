#ifndef CAN_MESSAGE_GENERATOR_COMMAND_PARAMETERS_H_10d30a3b_2602_4f3c_95ea_a8a0cc8907e0
#define CAN_MESSAGE_GENERATOR_COMMAND_PARAMETERS_H_10d30a3b_2602_4f3c_95ea_a8a0cc8907e0

#include "ICANMessageGeneratorCommandParameters.h"

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
             * Creates a new command parameters.
             */
            static ICANMessageGeneratorCommandParametersPtr make(
                base::DurationPtr duration,
                const std::vector<std::pair<std::string, size_t>>& messagesFrequencies);

            /**
             * The CANMessageGeneratorCommandParameters Constructor.
             */
            CANMessageGeneratorCommandParameters(
                base::DurationPtr duration,
                const std::vector<std::pair<std::string, size_t>>& messagesFrequencies);

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
            base::DurationPtr m_duration;
            std::vector<std::pair<std::string, size_t>> m_messagesFrequencies;
        };

        using CANMessageGeneratorCommandParametersPtr = std::shared_ptr<CANMessageGeneratorCommandParameters>;
    }
}

#endif // CAN_MESSAGE_GENERATOR_COMMAND_PARAMETERS_H_10d30a3b_2602_4f3c_95ea_a8a0cc8907e0
