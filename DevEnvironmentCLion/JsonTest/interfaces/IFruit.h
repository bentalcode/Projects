#ifndef I_FRUIT_H_0b3e006c_2608_4d0d_bae9_1046cfbb7d7e
#define I_FRUIT_H_0b3e006c_2608_4d0d_bae9_1046cfbb7d7e

#include "IJsonSerialization.h"

using namespace json;

namespace test {
    namespace json
    {
        /**
         * The IFruit interface defines properties of a fruit.
         */
        class IFruit : public IJsonSerialization
        {
        public:
            /**
             * The constructor.
             */
            IFruit() = default;

            /**
             * The destructor.
             */
            virtual ~IFruit() = default;

            /**
             * The copy/move constructors.
             */
            IFruit(const IFruit&) = delete;
            IFruit(IFruit&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IFruit& operator=(const IFruit&) = delete;
            IFruit& operator=(IFruit&&) = delete;

            /**
             * Gets the kind of a fruit.
             */
            virtual const std::string& getKind() const = 0;

            /**
             * Gets size of a fruit.
             */
            virtual int getSize() const = 0;

            /**
             * Gets color of a fruit.
             */
            virtual std::string getColor() const = 0;

            /**
             * Gets price of a fruit.
             */
            virtual double getPrice() const = 0;
        };

        using IFruitPtr = std::shared_ptr<IFruit>;
    }
}

#endif // I_FRUIT_H_0b3e006c_2608_4d0d_bae9_1046cfbb7d7e
