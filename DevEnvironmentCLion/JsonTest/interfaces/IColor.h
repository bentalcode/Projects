#ifndef I_COLOR_H_47586b01_dc08_4912_b5eb_d4c2147afc6b
#define I_COLOR_H_47586b01_dc08_4912_b5eb_d4c2147afc6b

#include "IJsonSerialization.h"

using namespace json;

namespace test {
    namespace json
    {
        /**
         * The IColor interface defines properties of a color.
         */
        class IColor : public IJsonSerialization
        {
        public:
            /**
             * The constructor.
             */
            IColor() = default;

            /**
             * The destructor.
             */
            virtual ~IColor() = default;

            /**
             * The copy/move constructors.
             */
            IColor(const IColor&) = delete;
            IColor(IColor&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IColor& operator=(const IColor&) = delete;
            IColor& operator=(IColor&&) = delete;

            /**
             * Gets the name of a color.
             */
            virtual std::string getName() const = 0;

            /**
             * Gets the hex of a color.
             */
            virtual std::string getHex() const = 0;

            /**
             * Gets the rgb of a color.
             */
            virtual std::string getRgb() const = 0;
        };

        using IColorPtr = std::shared_ptr<IColor>;
    }
}

#endif // I_COLOR_H_47586b01_dc08_4912_b5eb_d4c2147afc6b
