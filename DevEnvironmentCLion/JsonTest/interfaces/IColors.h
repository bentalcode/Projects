#ifndef I_COLORS_H_153c5195_ca81_413e_90a8_9206b10d720f
#define I_COLORS_H_153c5195_ca81_413e_90a8_9206b10d720f

#include "IColor.h"

using namespace json;

namespace test {
    namespace json
    {
        /**
         * The IColors interface defines properties of colors.
         */
        class IColors : public IJsonSerialization
        {
        public:
            /**
             * The constructor.
             */
            IColors() = default;

            /**
             * The destructor.
             */
            virtual ~IColors() = default;

            /**
             * The copy/move constructors.
             */
            IColors(const IColors&) = delete;
            IColors(IColors&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IColors& operator=(const IColors&) = delete;
            IColors& operator=(IColors&&) = delete;

            /**
             * Gets the category of a color.
             */
            virtual const std::string& getCategory() const = 0;

            /**
             * Gets the colors.
             */
            virtual void getColors(std::vector<IColor>& colors) const = 0;
        };

        //
        // Defines the SharedPtr of Colors...
        //
        using IColorsSharedPtr = std::shared_ptr<IColors>;
    }
}

#endif // I_COLORS_H_153c5195_ca81_413e_90a8_9206b10d720f
