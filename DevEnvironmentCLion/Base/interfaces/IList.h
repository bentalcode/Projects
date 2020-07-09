#ifndef I_LIST_H_79a36442_d5f3_4550_a0f2_a5fbb452dede
#define I_LIST_H_79a36442_d5f3_4550_a0f2_a5fbb452dede

#include "ISizableCollection.h"
#include "IIterable.h"
#include <vector>

namespace base
{
    /**
     * The IList interface defines a generic list.
     */
    template <typename T>
    class IList : public ISizableCollection, public IIterable<T>
    {
    public:
        /**
         * The constructor.
         */
        IList() = default;

        /**
         * The destructor.
         */
        virtual ~IList() = default;

        /**
         * The copy/move constructors.
         */
        IList(const IList&) = delete;
        IList(IList&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IList& operator=(const IList&) = delete;
        IList& operator=(IList&&) = delete;

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

#endif // I_LIST_H_79a36442_d5f3_4550_a0f2_a5fbb452dede
