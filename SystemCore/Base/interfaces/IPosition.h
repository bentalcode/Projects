#ifndef I_POSITION_92585b0c_ccdf_4bf0_a1f9_4170f5b31806
#define I_POSITION_92585b0c_ccdf_4bf0_a1f9_4170f5b31806

#include <memory>

namespace base {

    /**
     * The IPosition interface defines a 2-dimensional position.
     */
    template <typename T>
    class IPosition {
    public:
        IPosition() = default;
        virtual ~IPosition() = default;

        /**
         * Gets an X coordinate.
         */
        virtual T GetX() const = 0;

        /**
         * Gets a Y coordinate.
         */
        virtual T GetY() const = 0;
    };

    /**
     * Defines the Shared Ptr of I2DPosition.
     */
    template <typename T>
    using IPositionSharedPtr = std::shared_ptr<IPosition<T>>;

} // namespace base

#endif // I_POSITION_92585b0c_ccdf_4bf0_a1f9_4170f5b31806
