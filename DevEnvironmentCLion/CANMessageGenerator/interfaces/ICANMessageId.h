#ifndef I_CAN_MESSAGE_ID_H_f0a4208e_4024_4578_8f7a_e0c06d280346
#define I_CAN_MESSAGE_ID_H_f0a4208e_4024_4578_8f7a_e0c06d280346

#include <memory>

namespace controllerareanetweok {
    namespace messagegenerator {

        /**
         * The ICANMessageId interface defines an id of a controller area network message.
         */
        class ICANMessageId
        {
        public:
            /**
             * The constructor.
             */
            ICANMessageId() = default;

            /**
             * The destructor.
             */
            virtual ~ICANMessageId() = default;

            /**
             * The copy/move constructors.
             */
            ICANMessageId(const ICANMessageId&) = delete;
            ICANMessageId(ICANMessageId&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ICANMessageId &operator=(const ICANMessageId&) = delete;
            ICANMessageId &operator=(ICANMessageId&&) = delete;

            /**
             * Gets the main id. Bits: {28, 27, 26, ... 0}.
             */
            virtual unsigned int getMainId() const = 0;

            /**
             * Gets the extended id. Bits: {31, 30, 29}.
             */
            virtual unsigned int getExtendedId() const = 0;

            /**
             * Gets the id.
             */
            virtual unsigned int getId() const = 0;

            /**
             * Gets the string representation of this instance.
             */
            virtual std::string toString() const = 0;
        };

        using ICANMessageIdPtr = std::shared_ptr<ICANMessageId>;
    }
}

#endif // I_CAN_MESSAGE_ID_H_f0a4208e_4024_4578_8f7a_e0c06d280346
