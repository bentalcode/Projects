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
         * Gets an element from the front.
         */
        virtual const T& front() const = 0;

        /**
         * Gets an element from the back.
         */
        virtual const T& back() const = 0;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& get(std::size_t index) const = 0;

        /**
         * Adds an element to the back of the list.
         */
        virtual void addBack(const T& element) = 0;

        /**
         * Adds an element to the front of the list.
         */
        virtual void addFront(const T& element) = 0;

        /**
         * Removes an element from the back of the list.
         */
        virtual void removeBack() = 0;

        /**
         * Removes an element from the front of the list.
         */
        virtual void removeFront() = 0;
    };
}

#endif // I_LIST_H_79a36442_d5f3_4550_a0f2_a5fbb452dede
