#ifndef I_VOLUME_H_5dd27b0b_9f39_4992_a612_a7c432aa0910
#define I_VOLUME_H_5dd27b0b_9f39_4992_a612_a7c432aa0910

#include <memory>

namespace tlogging {

    /**
     * The IVolume interface defines a volume.
     * A Volume is a three-dimensional measure of space that comprises a length, a width, and a height.
     */
    template <typename T>
    class IVolume {
    public:
        IVolume() = default;
        virtual ~IVolume() = default;

        /**
         * Gets length.
         */
        virtual T GetLength() const = 0;

        /**
         * Gets width.
         */
        virtual T GetWidth() const = 0;

        /**
         * Gets height.
         */
        virtual T GetHeight() const = 0;
    };

    /**
     * Defines the Shared Ptr of Volume.
     */
    template <typename T>
    using IVolumeSharedPtr = std::shared_ptr<IVolume<T>>;

} // namespace tlogging

#endif // I_VOLUME_H_5dd27b0b_9f39_4992_a612_a7c432aa0910

