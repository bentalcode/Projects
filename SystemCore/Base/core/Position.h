#ifndef POSITION_H_d1a67643_c4a0_4e21_aec8_193ec87aa152
#define POSITION_H_d1a67643_c4a0_4e21_aec8_193ec87aa152

#include "IPosition.h"

namespace base {

    /**
     * The Position class implements a position.
     */
    template <typename T>
    class Position : public IPosition<T> {
    public:
        /**
         * Creates a Position.
         */
        static IPositionSharedPtr<T> Make(T x, T y);

        /**
         * The Position constructor.
         */
        Position(T x, T y);

        /**
         * The Position destructor.
         */
        virtual ~Position();

        /**
         * Gets an X corrdinate.
         */
        virtual T GetX() const override;

        /**
         * Gets a Y corrdinate.
         */
        virtual T GetY() const override;

    private:
        T m_x;
        T m_y;
    };

    /**
     * Creates a Position.
     */
    template <typename T>
    IPositionSharedPtr<T> Position<T>::Make(T x, T y)
    {
        return std::make_shared<Position>(x, y);
    }

    /**
     * The Position constructor.
     */
    template <typename T>
    Position<T>::Position(T x, T y) :
        m_x(x),
        m_y(y)
    {
    }

    /**
     * The Position destructor.
     */
    template <typename T>
    Position<T>::~Position()
    {
    }

    /**
     * Gets an X coordinate.
     */
    template <typename T>
    T Position<T>::GetX() const
    {
        return m_x;
    }

    /**
     * Gets a Y coordinate.
     */
    template <typename T>
    T Position<T>::GetY() const
    {
        return m_y;
    }

} // namespace base

#endif // namespace POSITION_H_d1a67643_c4a0_4e21_aec8_193ec87aa152
