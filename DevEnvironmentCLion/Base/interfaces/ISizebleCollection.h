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
        ISizebleCollection() = default;
        virtual ~ISizebleCollection() = default;

        /**
         * Gets the size of the collection.
         */
        virtual int size() const = 0;

        /**
         * Checks whether the collection is empty.
         */
        virtual bool empty() const = 0;
    };
}

#endif // I_SIZABLE_COLLECTION_H_23a3a9d8_08fa_4113_a784_9f7fb35f7132
