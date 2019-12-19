#ifndef I_COLLECTION_H_359f99e7_020a_4ec9_9a2e_e61de1228e31
#define I_COLLECTION_H_359f99e7_020a_4ec9_9a2e_e61de1228e31

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

#endif // I_COLLECTION_H_359f99e7_020a_4ec9_9a2e_e61de1228e31
