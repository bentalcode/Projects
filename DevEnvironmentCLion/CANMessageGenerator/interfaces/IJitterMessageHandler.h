#ifndef I_JITTER_MESSAGE_HANDLER_H_fc9a196e_441f_473c_9e13_3c2102416156
#define I_JITTER_MESSAGE_HANDLER_H_fc9a196e_441f_473c_9e13_3c2102416156

#include "IJitterMessageData.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The IJitterMessageHandler interface defines a Jitter Message Handler.
         */
        class IJitterMessageHandler
        {
        public:
            /**
             * The constructor.
             */
            IJitterMessageHandler() = default;

            /**
             * The destructor.
             */
            virtual ~IJitterMessageHandler() = default;

            /**
             * The copy/move constructors.
             */
            IJitterMessageHandler(const IJitterMessageHandler&) = delete;
            IJitterMessageHandler(IJitterMessageHandler&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IJitterMessageHandler &operator=(const IJitterMessageHandler&) = delete;
            IJitterMessageHandler &operator=(IJitterMessageHandler&&) = delete;

            /**
             * Registers a message.
             */
            virtual void registerMessage(
                const std::string& messageName,
                base::DurationPtr transmittingTime) = 0;

            /**
             * Unregisters a message.
             *
             * Returns true if the message got unregistered successfully from the Jitter Handler.
             * Returns false if the message is not currently registered with the Jitter Handler.
             */
            virtual bool unregisterMessage(const std::string& messageName) = 0;

            /**
             * Sets the sending time of a message.
             */
            virtual void setMessageSendingTime(
                const std::string& messageName,
                base::DateTimePtr time) = 0;

            /**
             * Sets the receiving time of a message.
             */
            virtual void setMessageReceivingTime(
                const std::string& messageName,
                base::DateTimePtr time) = 0;

            /**
             * Gets the jitter deviation.
             * J(i) = J(i-1) + (|D(i-1,i)| - J(i-1))/16
             */
            virtual double getDeviation(const std::string& messageName) = 0;

            /**
             * Gets the message data.
             */
            virtual IJitterMessageDataPtr getMessageData(const std::string& messageName) = 0;
        };

        using IJitterMessageHandlerPtr = std::shared_ptr<IJitterMessageHandler>;
        using IJitterMessageHandlerUniquePtr = std::unique_ptr<IJitterMessageHandler>;
    }
}

#endif // I_JITTER_MESSAGE_HANDLER_H_fc9a196e_441f_473c_9e13_3c2102416156
