#ifndef I_SIZABLE_COLLECTION_H_23a3a9d8_08fa_4113_a784_9f7fb35f7132
#define I_SIZABLE_COLLECTION_H_23a3a9d8_08fa_4113_a784_9f7fb35f7132

#include "ICollection.h"

namespace base
{
    /**
     * The ISizableCollection interface defines a sizable collection.
     */
    class ISizebleCollection : public ICollection
    {
    public:
        /**
         * The constructor.
         */
        ISizebleCollection() = default;

        /**
         * The destructor.
         */
        virtual ~ISizebleCollection() = default;

        /**
         * The copy/move constructors.
         */
        ISizebleCollection(const ISizebleCollection&) = delete;
        ISizebleCollection(ISizebleCollection&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ISizebleCollection& operator=(const ISizebleCollection&) = delete;
        ISizebleCollection& operator=(ISizebleCollection&&) = delete;

        /**
         * Gets the size of the collection.
         */
        virtual std::size_t size() const = 0;

        /**
         * Checks whether the collection is empty.
         */
        virtual bool empty() const = 0;
    };
}

#endif // I_SIZABLE_COLLECTION_H_23a3a9d8_08fa_4113_a784_9f7fb35f7132
