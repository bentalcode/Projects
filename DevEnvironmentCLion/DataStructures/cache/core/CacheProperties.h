#ifndef CACHE_PROPERTIES_H_699ba959_a953_4641_bab9_ae565c2a8cbb
#define CACHE_PROPERTIES_H_699ba959_a953_4641_bab9_ae565c2a8cbb

#include "ICacheProperties.h"

namespace datastructures {
    namespace cache {

        /**
         * The CacheProperties class implements properties of a cache.
         */
        class CacheProperties final : public ICacheProperties
        {
        public:
            /**
             * Creates properties of a cache.
             */
            static ICachePropertiesPtr make(
                size_t capacity,
                size_t numberOfItemsForMakingAvailableSpace);

            /**
             * The CacheProperties constructor.
             */
            CacheProperties(
                size_t capacity,
                size_t numberOfItemsForMakingAvailableSpace);

            /**
             * The CacheProperties destructor.
             */
            virtual ~CacheProperties();

            /**
             * The copy/move constructors.
             */
            CacheProperties(const CacheProperties&) = delete;
            CacheProperties(CacheProperties&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            CacheProperties& operator=(const CacheProperties&) = delete;
            CacheProperties& operator=(CacheProperties&&) = delete;

            /**
             * Gets a capacity of a cache.
             */
            virtual size_t getCapacity() const override;

            /**
             * Gets the number of items for making available space in the cache.
             */
            virtual size_t getNumberOfItemsForMakingAvailableSpace() const override;

        private:
            size_t m_capacity;
            size_t m_numberOfItemsForMakingAvailableSpace;
        };

    }
}

#endif // CACHE_PROPERTIES_H_699ba959_a953_4641_bab9_ae565c2a8cbb

