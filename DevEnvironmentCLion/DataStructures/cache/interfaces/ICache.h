#ifndef I_CACHE_H_13d098ed_c353_40db_b3bc_40685b173c4e
#define I_CACHE_H_13d098ed_c353_40db_b3bc_40685b173c4e

#include "ISizableCollection.h"
#include "IIterable.h"
#include "IReverseIterable.h"
#include "IKeyIterable.h"
#include "IKeyReverseIterable.h"
#include "IValueIterable.h"
#include "IValueReverseIterable.h"
#include "IKeyValueNode.h"

namespace datastructures {
    namespace cache {

        class ICacheProperties;

        /**
         * The ICache interface defines a cache.
         */
        template <typename TKey, typename TValue>
        class ICache :
            public base::ISizableCollection,
            public base::IIterable<node::IKeyValueNodePtr<TKey, TValue>>,
            public base::IReverseIterable<node::IKeyValueNodePtr<TKey, TValue>>,
            public base::IKeyIterable<TKey>,
            public base::IKeyReverseIterable<TKey>,
            public base::IValueIterable<TValue>,
            public base::IValueReverseIterable<TValue>
        {
        public:
            /**
             * The ICache constructor.
             */
            ICache() = default;

            /**
             * The ICache destructor.
             */
            virtual ~ICache() = default;

            /**
             * The copy/move constructors.
             */
            ICache(const ICache&) = delete;
            ICache(ICache&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            ICache& operator=(const ICache&) = delete;
            ICache& operator=(ICache&&) = delete;

            /**
             * Gets properties of a cache.
             */
            virtual const ICacheProperties& getProperties() const = 0;

            /**
             * Set a new key in the cache.
             * Complexity: O(1)
             */
            virtual void set(const TKey& key, const TValue& value) = 0;

            /**
             * Gets a value of a specific key in the cache.
             * Complexity: O(1)
             */
            virtual const TValue& get(const TKey& key) = 0;

            /**
             * Deletes a key and it's associated value from the cache.
             *
             * Returns true if the key has been removed successfully from the cache.
             * Returns false if the key is not in the cache.
             *
             * Complexity: O(1)
             */
            virtual bool deleteKey(const TKey& key) = 0;

            /**
             * Checks whether a key is set in the cache.
             * Complexity: O(1)
             */
            virtual bool has(const TKey& key) const = 0;
        };

        template <typename TKey, typename TValue>
        using ICachePtr = std::shared_ptr<ICache<TKey, TValue>>;
    }
}

#endif // I_CACHE_H_13d098ed_c353_40db_b3bc_40685b173c4e
