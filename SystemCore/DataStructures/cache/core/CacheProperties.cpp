#include "CacheProperties.h"
#include "CacheException.h"

using namespace datastructures::cache;

/**
 * Creates properties of a cache.
 */
ICachePropertiesSharedPtr CacheProperties::Make(
    size_t capacity,
    size_t numberOfItemsForMakingAvailableSpace) {

    return std::make_shared<CacheProperties>(capacity, numberOfItemsForMakingAvailableSpace);
}

/**
 * The CacheProperties constructor.
 */
CacheProperties::CacheProperties(
    size_t capacity,
    size_t numberOfItemsForMakingAvailableSpace) :
        m_capacity(capacity),
        m_numberOfItemsForMakingAvailableSpace(numberOfItemsForMakingAvailableSpace)
{
    if (numberOfItemsForMakingAvailableSpace > capacity)
    {
        long statusCode = base::ErrorCodes::OUT_OF_RANGE;
        std::wstring errorMessage =
            L"The number ofitems for making available space can not exceed the cache capacity.";

        throw CacheException(statusCode, errorMessage);
    }
}

/**
 * The CacheProperties destructor.
 */
CacheProperties::~CacheProperties()
{
}

/**
 * Gets a capacity of a cache.
 */
size_t CacheProperties::GetCapacity() const
{
    return m_capacity;
}

/**
 * Gets the number ofitems for making available space in the cache.
 */
size_t CacheProperties::GetNumberOfItemsForMakingAvailableSpace() const
{
    return m_numberOfItemsForMakingAvailableSpace;
}
