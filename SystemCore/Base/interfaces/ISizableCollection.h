#ifndef I_SIZABLE_COLLECTION_H_cdc62ca4_57d0_11ee_8c99_0242ac120002
#define I_SIZABLE_COLLECTION_H_cdc62ca4_57d0_11ee_8c99_0242ac120002

#include "ICollection.h"

namespace base {

    /**
     * The ISizableCollection interface defines a sizable collection.
     */
    template <typename T>
    class ISizableCollection : public ICollection<T> {
    public:
        ISizableCollection() = default;
        virtual ~ISizableCollection() = default;

        /**
         * Gets Size of a collection.
         */
        virtual size_t Size() const = 0;

        /**
         * Checks whether a collection is Empty.
         */
        virtual bool Empty() const = 0;
    };

}  // namespace base

#endif // I_SIZABLE_COLLECTION_H_cdc62ca4_57d0_11ee_8c99_0242ac120002
