#ifndef I_COLLECTION_H_9c390d7c_57d1_11ee_8c99_0242ac120002
#define I_COLLECTION_H_9c390d7c_57d1_11ee_8c99_0242ac120002

#include "IIterable.h"

namespace base {

    /**
     * The ICollection interface defines a collection.
     */
    template <typename T>
    class ICollection : public IIterable<T> {
    public:
        ICollection() = default;
        virtual ~ICollection() = default;
    };

    /**
     * Defines the Shared Ptr of Collection.
     */
    template <typename T>
    using ICollectionSharedPtr = std::shared_ptr<ICollection<T>>;

} // namespace base

#endif // I_COLLECTION_H_9c390d7c_57d1_11ee_8c99_0242ac120002
