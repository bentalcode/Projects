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
            explicit CacheException(const std::string& errorMessage) :
                DataStructureException(errorMessage)
            {
            }

            CacheException(
                const std::string& errorMessage,
                std::exception& innerException) :
                DataStructureException(errorMessage, innerException)
            {
            }
        };
    }
};


#endif // CACHE_EXCEPTION_H_6d4bdcf6_b12c_46a1_a76d_e95f12c2abff
