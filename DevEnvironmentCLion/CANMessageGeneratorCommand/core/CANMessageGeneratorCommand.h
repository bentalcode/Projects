#ifndef CAN_MESSAGE_GENERATOR_COMMAND_H_6eb4837a_75b1_4c10_adf0_84b6bbe679f2
#define CAN_MESSAGE_GENERATOR_COMMAND_H_6eb4837a_75b1_4c10_adf0_84b6bbe679f2

#include "AbstractCommand.h"
#include "ICommand.h"

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

        };

    }
}

#endif // CAN_MESSAGE_GENERATOR_COMMAND_H_6eb4837a_75b1_4c10_adf0_84b6bbe679f2
