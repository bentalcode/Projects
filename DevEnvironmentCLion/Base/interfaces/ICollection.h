#ifndef I_COLLECTION_H_77e06e44_ddc5_4be3_8a80_6ddc4fd0ec4a
#define I_COLLECTION_H_77e06e44_ddc5_4be3_8a80_6ddc4fd0ec4a

namespace base
{
    /**
     * The ICollection interface defines a abstract collection.
     */
    class ICollection
    {
    public:
        /**
         * The constructor.
         */
        ICollection() = default;

        /**
         * The destructor.
         */
        virtual ~ICollection() = default;

        /**
         * The copy/move constructors.
         */
        ICollection(const ICollection&) = delete;
        ICollection(ICollection&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ICollection& operator=(const ICollection&) = delete;
        ICollection& operator=(ICollection&&) = delete;
    };
}

#endif // I_COLLECTION_H_77e06e44_ddc5_4be3_8a80_6ddc4fd0ec4a
