#ifndef I_LIST_H_f1e8f87d_6913_44a3_8d12_f084f71f7492
#define I_LIST_H_f1e8f87d_6913_44a3_8d12_f084f71f7492

#include "ISizebleCollection.h"
#include "IIterable.h"
#include <vector>

namespace base
{
    /**
     * The IList interface defines a generic list.
     */
    template <typename T>
    class IList : public ISizebleCollection, public IIterable<T>
    {
    public:
        /**
         * The IList constructor.
         */
        IList() = default;

        /**
         * The IList destructor.
         */
        virtual ~IList() = default;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& get(std::size_t index) const = 0;

        /**
         * Sets an element at a specified position.
         */
        virtual void set(std::size_t index, const T& element) = 0;

        /**
         * Adds an element.
         */
        virtual void add(const T& element) = 0;

        /**
         * Gets a const element at a specified position.
         */
        virtual const T& operator[](int index) const = 0;

        /**
         * Gets an element at a specified position.
         */
        virtual T& operator[](int index) = 0;
    };
}

#endif // I_LIST_H_f1e8f87d_6913_44a3_8d12_f084f71f7492
