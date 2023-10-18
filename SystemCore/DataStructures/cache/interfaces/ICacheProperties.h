#ifndef I_CACHE_PROPERTIES_H_72aacd13_da6e_4436_84b1_e0d1cc9a403e
#define I_CACHE_PROPERTIES_H_72aacd13_da6e_4436_84b1_e0d1cc9a403e

#include <string>
#include <memory>

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
             * The Copy/move constructors.
             */
            ICacheProperties(const ICacheProperties&) = delete;
            ICacheProperties(ICacheProperties&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            ICacheProperties& operator=(const ICacheProperties&) = delete;
            ICacheProperties& operator=(ICacheProperties&&) = delete;

            /**
             * Gets a capacity of a cache.
             */
            virtual size_t GetCapacity() const = 0;

            /**
             * Gets the number ofitems for making available space in the cache.
             */
            virtual size_t GetNumberOfItemsForMakingAvailableSpace() const = 0;
        };

        /**
         * Defines the SharedPtr ofCache Properties.
         */
        using ICachePropertiesSharedPtr = std::shared_ptr<ICacheProperties>;
    }
}

#endif // I_CACHE_PROPERTIES_H_72aacd13_da6e_4436_84b1_e0d1cc9a403e
