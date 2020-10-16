#ifndef I_CAN_MESSAGE_NAME_H_0f5383a3_fe96_4551_9953_dda12baabd01
#define I_CAN_MESSAGE_NAME_H_0f5383a3_fe96_4551_9953_dda12baabd01

#include <memory>
#include <vector>

namespace controllerareanetweok {
    namespace messagegenerator {

        /**
         * The ICANMessageName interface defines a name of a message of a controller area network.
         */
        class ICANMessageName {
        public:
            /**
             * The constructor.
             */
            ICANMessageName() = default;

            /**
             * The destructor.
             */
            virtual ~ICANMessageName() = default;

            /**
             * The copy/move constructors.
             */
            ICANMessageName(const ICANMessageName&) = delete;
            ICANMessageName(ICANMessageName&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ICANMessageName &operator=(const ICANMessageName&) = delete;
            ICANMessageName &operator=(ICANMessageName&&) = delete;

            /**
             * Gets the name of a CAN message.
             * The name must be unique, 1-32 characters and may contain [A-z], digits and underscores.
             */
            virtual std::vector<std::string::value_type> getName() const = 0;

            /**
             * Gets the string representation of this instance.
             */
            virtual std::string toString() const = 0;
        };

        using ICANMessageNamePtr = std::shared_ptr<ICANMessageName>;
    }
}

#endif // I_CAN_MESSAGE_NAME_H_0f5383a3_fe96_4551_9953_dda12baabd01
