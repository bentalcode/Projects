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
            static ICachePropertiesSharedPtr Make(
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
             * The Copy/move constructors.
             */
            CacheProperties(const CacheProperties&) = delete;
            CacheProperties(CacheProperties&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            CacheProperties& operator=(const CacheProperties&) = delete;
            CacheProperties& operator=(CacheProperties&&) = delete;

            /**
             * Gets a capacity of a cache.
             */
            virtual size_t GetCapacity() const override;

            /**
             * Gets the number ofitems for making available space in the cache.
             */
            virtual size_t GetNumberOfItemsForMakingAvailableSpace() const override;

        private:
            size_t m_capacity;
            size_t m_numberOfItemsForMakingAvailableSpace;
        };

    }
}

#endif // CACHE_PROPERTIES_H_699ba959_a953_4641_bab9_ae565c2a8cbb

