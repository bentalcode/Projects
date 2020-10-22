#ifndef CAN_MESSAGE_GENERATOR_COMMAND_H_6eb4837a_75b1_4c10_adf0_84b6bbe679f2
#define CAN_MESSAGE_GENERATOR_COMMAND_H_6eb4837a_75b1_4c10_adf0_84b6bbe679f2

#include "AbstractCommand.h"
#include "ICANMessageGeneratorCommandParameters.h"
#include "ICANRuleGenerator.h"
#include "ICANMessageRule.h"
#include "IJitterMessageHandler.h"

using namespace controllerareanetwork::messagegenerator;

namespace controllerareanetwork {
    namespace messagegeneratorcommand {

        /**
         * The CANMessageGeneratorCommand class implements a command for a controller area network.
         */
        class CANMessageGeneratorCommand final : public command::AbstractCommand
        {
        public:
            /**
             * Creates a new command.
             */
            static command::ICommandPtr make();

            /**
             * The CANMessageGeneratorCommand Constructor.
             */
            CANMessageGeneratorCommand();

            /**
             * The CANMessageGeneratorCommand destructor.
             */
            virtual ~CANMessageGeneratorCommand();

            /**
             * The copy/move constructors.
             */
            CANMessageGeneratorCommand(const CANMessageGeneratorCommand&) = delete;
            CANMessageGeneratorCommand(CANMessageGeneratorCommand&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CANMessageGeneratorCommand& operator=(const CANMessageGeneratorCommand&) = delete;
            CANMessageGeneratorCommand& operator=(CANMessageGeneratorCommand&&) = delete;

            /**
             * Runs the logic of a command.
             */
            virtual void run() override;

        private:
            static const std::string messagesDeviationText;
            static const std::string messageNameText;

            /**
             * Generates the specified messages.
             */
            void generateMessages(
                const base::Duration& driveSessionDuration,
                const std::vector<std::pair<std::string, size_t>>& messages);

            /**
             * Processes the messages.
             */
            bool processMessages(
                const std::string& messageName,
                size_t numberOfMessages,
                const base::Duration& timeout,
                base::IMessageWriter& messageWriter);

            /**
             * Processes the message.
             */
            void processMessage(
                const std::string& messageName,
                base::IMessageWriter& messageWriter);

            /**
             * Displays the Jitter information of the messages.
             */
            void displayMessagesJitterInformation(
                const std::vector<std::pair<std::string, size_t>>& messages,
                base::IMessageWriter& messageWriter);

            /**
             * Displays the Jitter information of the message.
             */
            void displayMessageJitterInformation(
                const std::string& messageName,
                base::IMessageWriter& messageWriter);

            /**
             * Registers the messages with the Jitter.
             */
            void registerMessagesWithJitter(const std::vector<std::pair<std::string, size_t>>& messages);

            /**
             * Checks whether the session is active.
             */
            static bool sessionActive(const base::DateTime& startTime, const base::Duration& timeout);

            /**
             * Initializes the command.
             */
            void initialize();

            ICANMessageGeneratorCommandParametersUniquePtr m_parameters;
            ICANRuleGeneratorUniquePtr<ICANMessageRulePtr> m_messageRuleGenerator;
            IJitterMessageHandlerUniquePtr m_messageHandler;
        };

    }
}

#endif // CAN_MESSAGE_GENERATOR_COMMAND_H_6eb4837a_75b1_4c10_adf0_84b6bbe679f2
