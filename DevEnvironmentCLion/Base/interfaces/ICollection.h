#ifndef I_COLLECTION_H_c08c0b13_cda5_4791_a6ff_8d42e75f1fe6
#define I_COLLECTION_H_c08c0b13_cda5_4791_a6ff_8d42e75f1fe6

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

#endif // I_COLLECTION_H_c08c0b13_cda5_4791_a6ff_8d42e75f1fe6
