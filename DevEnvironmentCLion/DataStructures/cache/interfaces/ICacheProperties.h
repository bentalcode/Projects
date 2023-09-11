#ifndef I_CACHE_PROPERTIES_H_72aacd13_da6e_4436_84b1_e0d1cc9a403e
#define I_CACHE_PROPERTIES_H_72aacd13_da6e_4436_84b1_e0d1cc9a403e

namespace datastructures {
    namespace cache {

        /**
         * The ICacheProperties interface defines properties of a cache.
         */
        class ICacheProperties
        {
        public:
            /**
             * The ICacheProperties constructor.
             */
            ICacheProperties() = default;

            /**
             * The ICacheProperties destructor.
             */
            virtual ~ICacheProperties() = default;

            /**
             * The copy/move constructors.
             */
            ICacheProperties(const ICacheProperties&) = delete;
            ICacheProperties(ICacheProperties&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ICacheProperties& operator=(const ICacheProperties&) = delete;
            ICacheProperties& operator=(ICacheProperties&&) = delete;

            /**
             * Gets a capacity of a cache.
             */
            virtual size_t getCapacity() const = 0;

            /**
             * Gets the number of items for making available space in the cache.
             */
            virtual size_t getNumberOfItemsForMakingAvailableSpace() const = 0;
        };

        using ICachePropertiesPtr = std::shared_ptr<ICacheProperties>;
    }
}

#endif // I_CACHE_PROPERTIES_H_72aacd13_da6e_4436_84b1_e0d1cc9a403e
