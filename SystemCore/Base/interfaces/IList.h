#ifndef I_LIST_H_b0e2cac0_57d0_11ee_8c99_0242ac120002
#define I_LIST_H_b0e2cac0_57d0_11ee_8c99_0242ac120002

#include "ISizableCollection.h"

namespace base {

    /**
     * The IList interface defines a list.
     */
    template <typename T>
    class IList : public ISizableCollection<T> {
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
         * Gets an element from the Front.
         */
        virtual const T& Front() const = 0;

        /**
         * Gets an element from the Back.
         */
        virtual const T& Back() const = 0;

        /**
         * Gets an element at a specified position.
         */
        virtual const T& Get(std::size_t index) const = 0;

        /**
         * Adds an element to the Back of the list.
         */
        virtual void AddBack(const T& element) = 0;

        /**
         * Adds an element to the Front of the list.
         */
        virtual void AddFront(const T& element) = 0;

        /**
         * Removes an element from the Back of the list.
         */
        virtual void RemoveBack() = 0;

        /**
         * Removes an element from the Front of the list.
         */
        virtual void RemoveFront() = 0;
    };

} // namespace base

#endif // I_LIST_H_b0e2cac0_57d0_11ee_8c99_0242ac120002
