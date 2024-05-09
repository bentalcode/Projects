#ifndef VOLUME_H_3e87f30a_0794_421c_8525_3bbd335e2e27
#define VOLUME_H_3e87f30a_0794_421c_8525_3bbd335e2e27

#include "IVolume.h"

namespace tlogging {

    /**
     * The Volume class implements a volume.
     * A Volume is a three-dimensional measure of space that comprises a length, a width, and a height.
     */
    template <typename T>
    class Volume final : public IVolume<T> {
    public:
        /**
         * Creates a Volume.
         */
        static IVolumeSharedPtr<T> Make(T length, T width, T height);

        /**
         * The Volume constructor.
         */
        Volume(T length, T width, T height);

        /**
         * The Volume destructor.
         */
        virtual ~Volume();

        /**
         * Gets length.
         */
        virtual T GetLength() const override;

        /**
         * Gets width.
         */
        virtual T GetWidth() const override;

        /**
         * Gets height.
         */
        virtual T GetHeight() const override;

    private:
        T m_length;
        T m_width;
        T m_height;
    };

    /**
     * Creates a Volume.
     */
    template <typename T>
    IVolumeSharedPtr<T> Volume<T>::Make(T length, T width, T height)
    {
        return std::make_shared<Volume>(length, width, height);
    }

    /**
     * The Volume constructor.
     */
    template <typename T>
    Volume<T>::Volume(T length, T width, T height) :
        m_length(length),
        m_width(width),
        m_height(height)
    {
    }

    /**
     * The Volume destructor.
     */
    template <typename T>
    Volume<T>::~Volume()
    {
    }

    /**
     * Gets length.
     */
    template <typename T>
    T Volume<T>::GetLength() const
    {
        return m_length;
    }

    /**
     * Gets width.
     */
    template <typename T>
    T Volume<T>::GetWidth() const
    {
        return m_width;
    }

    /**
     * Gets height.
     */
    template <typename T>
    T Volume<T>::GetHeight() const
    {
        return m_height;
    }

} // namespace tlogging

#endif // VOLUME_H_3e87f30a_0794_421c_8525_3bbd335e2e27
