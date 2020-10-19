#ifndef I_JITTER_MESSAGE_DATA_H_3d7ff458_39ed_4dae_b4a1_440027e25bd4
#define I_JITTER_MESSAGE_DATA_H_3d7ff458_39ed_4dae_b4a1_440027e25bd4

#include "Duration.h"
#include "DateTime.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The IJitterMessageData interface defines the message data for Jitter.
         */
        class IJitterMessageData
        {
        public:
            /**
             * The constructor.
             */
            IJitterMessageData() = default;

            /**
             * The destructor.
             */
            virtual ~IJitterMessageData() = default;

            /**
             * The copy/move constructors.
             */
            IJitterMessageData(const IJitterMessageData&) = delete;
            IJitterMessageData(IJitterMessageData&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IJitterMessageData &operator=(const IJitterMessageData&) = delete;
            IJitterMessageData &operator=(IJitterMessageData&&) = delete;

            /**
             * Gets the transmitting time.
             */
            virtual base::DurationPtr getTransmittingTime() const = 0;

            /**
             * Gets the last sending time of a message.
             */
            virtual base::DateTimePtr getMessageLastSendingTime() const = 0;

            /**
             * Sets the last sending time of a message.
             */
            virtual void setMessageLastSendingTime(base::DateTimePtr time) = 0;

            /**
             * Gets the number of messages sent.
             */
            virtual size_t getNumberOfMessagesSent() const = 0;

            /**
             * Gets the number of messages received.
             */
            virtual size_t getNumberOfMessagesReceived() const = 0;

            /**
             * Increments the number of messages sent.
             */
            virtual void incrementNumberOfMessagesSent() = 0;

            /**
             * Increments the number of messages received.
             */
            virtual void incrementNumberOfMessagesReceived() = 0;

            /**
             * Gets the Jitter deviation.
             */
            virtual double getDeviation() const = 0;

            /**
             * Sets the Jitter deviation.
             */
            virtual void setDeviation(double deviation) = 0;

            /**
             * Gets the string representation of this instance.
             */
            virtual std::string toString() const = 0;
        };

        using IJitterMessageDataPtr = std::shared_ptr<IJitterMessageData>;
    }
}

#endif // I_JITTER_MESSAGE_DATA_H_3d7ff458_39ed_4dae_b4a1_440027e25bd4
