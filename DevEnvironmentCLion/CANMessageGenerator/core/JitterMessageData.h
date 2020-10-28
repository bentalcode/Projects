#ifndef JITTER_MESSAGE_DATA_H_55d6891e_ddc6_4738_b1d5_8cf7284cd576
#define JITTER_MESSAGE_DATA_H_55d6891e_ddc6_4738_b1d5_8cf7284cd576

#include "IJitterMessageData.h"

namespace controllerareanetwork {
    namespace messagegenerator {

        /**
         * The JitterMessageData class implements the jitter message data.
         */
        class JitterMessageData final : public IJitterMessageData
        {
        public:
            /**
             * Creates a new message data.
             */
            static IJitterMessageDataPtr make(base::DurationPtr transmittingTime) {
                return std::make_shared<JitterMessageData>(transmittingTime);
            }

            /**
             * The JitterMessageData constructor.
             */
            explicit JitterMessageData(base::DurationPtr transmittingTime);

            /**
             * The JitterMessageData destructor.
             */
            virtual ~JitterMessageData();

            /**
             * The copy/move constructors.
             */
            JitterMessageData(const JitterMessageData&) = delete;
            JitterMessageData(JitterMessageData&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            JitterMessageData& operator=(const JitterMessageData&) = delete;
            JitterMessageData& operator=(JitterMessageData&&) = delete;

            /**
             * Gets the transmitting time.
             */
            virtual base::DurationPtr getTransmittingTime() const override;

            /**
             * Gets the last sending time of a message.
             */
            virtual base::DateTimePtr getMessageLastSendingTime() const override;

            /**
             * Sets the last sending time of a message.
             */
            virtual void setMessageLastSendingTime(base::DateTimePtr time) override;

            /**
             * Gets the number of messages sent.
             */
            virtual size_t getNumberOfMessagesSent() const override;

            /**
             * Gets the number of messages received.
             */
            virtual size_t getNumberOfMessagesReceived() const override;

            /**
             * Increments the number of messages sent.
             */
            virtual void incrementNumberOfMessagesSent() override;

            /**
             * Increments the number of messages received.
             */
            virtual void incrementNumberOfMessagesReceived() override;

            /**
             * Gets the Jitter deviation.
             */
            virtual float getDeviation() const override;

            /**
             * Sets the Jitter deviation.
             */
            virtual void setDeviation(float deviation) override;

            /**
             * Gets the string representation of this instance.
             */
            virtual std::string toString() const override;

        private:
            static const std::string transmittingTimeText;
            static const std::string deviationText;
            static const std::string numberOfMessagesSentText;
            static const std::string numberOfMessagesReceivedText;

            base::DurationPtr m_transmittingTime;
            base::DateTimePtr m_lastSendingTime;
            size_t m_numberOfMessagesSent;
            size_t m_numberOfMessagesReceived;
            float m_deviation;
        };

    }
}

#endif // JITTER_MESSAGE_DATA_H_55d6891e_ddc6_4738_b1d5_8cf7284cd576
