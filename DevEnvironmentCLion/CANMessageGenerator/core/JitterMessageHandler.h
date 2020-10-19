#ifndef JITTER_MESSAGE_HANDLER_H_0437f66c_2e4a_4bfa_8916_e1cd58f1ce4e
#define JITTER_MESSAGE_HANDLER_H_0437f66c_2e4a_4bfa_8916_e1cd58f1ce4e

#include "IJitterMessageHandler.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The JitterMessageHandler class implements a Jitter Message Handler.
         */
        class JitterMessageHandler final : public IJitterMessageHandler
        {
        public:
            /**
             * The JitterMessageHandler constructor.
             */
            JitterMessageHandler();

            /**
             * The JitterMessageHandler destructor.
             */
            virtual ~JitterMessageHandler();

            /**
             * The copy/move constructors.
             */
            JitterMessageHandler(const JitterMessageHandler&) = delete;
            JitterMessageHandler(JitterMessageHandler&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            JitterMessageHandler& operator=(const JitterMessageHandler&) = delete;
            JitterMessageHandler& operator=(JitterMessageHandler&&) = delete;

            /**
             * Registers a message.
             */
            virtual void registerMessage(
                const std::string& messageName,
                base::DurationPtr transmittingTime) override;

            /**
             * Unregisters a message.
             *
             * Returns true if the message got unregistered successfully from the Jitter Handler.
             * Returns false if the message is not currently registered with the Jitter Handler.
             */
            virtual bool unregisterMessage(const std::string& messageName) override;

            /**
             * Sets the sending time of a message.
             */
            virtual void setMessageSendingTime(
                const std::string& messageName,
                base::DateTimePtr time) override;

            /**
             * Sets the receiving time of a message.
             */
            virtual void setMessageReceivingTime(
                const std::string& messageName,
                base::DateTimePtr time) override;

            /**
             * Gets the jitter deviation.
             * J(i) = J(i-1) + (|D(i-1,i)| - J(i-1))/16
             */
            virtual double getDeviation(const std::string& messageName) override;

            /**
             * Gets the message data.
             */
            virtual IJitterMessageDataPtr getMessageData(const std::string& messageName) override;

        private:
            using MessageDataMap = std::map<std::string, IJitterMessageDataPtr>;
            MessageDataMap m_messageDataMap;
        };

    }
}

#endif // JITTER_MESSAGE_HANDLER_H_0437f66c_2e4a_4bfa_8916_e1cd58f1ce4e
