#ifndef CACHE_EXCEPTION_H_6d4bdcf6_b12c_46a1_a76d_e95f12c2abff
#define CACHE_EXCEPTION_H_6d4bdcf6_b12c_46a1_a76d_e95f12c2abff

#include "DataStructureException.h"

namespace datastructures {
    namespace cache {

        /**
         * The CacheException captured errors in the cache module.
         */
        class CacheException : public DataStructureException
        {
        public:
            /**
             * The CacheException Constructor.
             */
            CacheException(
                long statusCode,
                const std::wstring& errorMessage) :
                DataStructureException(
                    statusCode,
                    errorMessage)
            {
            }

        };
    }
};


#endif // CACHE_EXCEPTION_H_6d4bdcf6_b12c_46a1_a76d_e95f12c2abff
