#ifndef I_SIZABLE_COLLECTION_H_800f841b_1439_43aa_b203_0a3e04b5906a
#define I_SIZABLE_COLLECTION_H_800f841b_1439_43aa_b203_0a3e04b5906a

#include "ICollection.h"

namespace base
{
    /**
     * The ISizableCollection interface defines a sizable collection.
     */
    template <typename T>
    class ISizableCollection : public ICollection<T>
    {
    public:
        /**
         * The constructor.
         */
        ISizableCollection() = default;

        /**
         * The destructor.
         */
        virtual ~ISizableCollection() = default;

        /**
         * The copy/move constructors.
         */
        ISizableCollection(const ISizableCollection&) = delete;
        ISizableCollection(ISizableCollection&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ISizableCollection& operator=(const ISizableCollection&) = delete;
        ISizableCollection& operator=(ISizableCollection&&) = delete;

        /**
         * Gets the size of the collection.
         */
        virtual size_t Size() const = 0;

        /**
         * Checks whether the collection is Empty.
         */
        virtual bool Empty() const = 0;
    };
}

#endif // I_SIZABLE_COLLECTION_H_800f841b_1439_43aa_b203_0a3e04b5906a
