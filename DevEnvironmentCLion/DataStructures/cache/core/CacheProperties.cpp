#include "PreCompiled.h"
#include "CacheProperties.h"
#include "CacheException.h"

using namespace datastructures::cache;

/**
 * Creates properties of a cache.
 */
ICachePropertiesSharedPtr CacheProperties::make(
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
        std::string errorMessage = "The number of items for making available space can not exceed the cache capacity.";
        throw CacheException(errorMessage);
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
size_t CacheProperties::getCapacity() const
{
    return m_capacity;
}

/**
 * Gets the number of items for making available space in the cache.
 */
size_t CacheProperties::getNumberOfItemsForMakingAvailableSpace() const
{
    return m_numberOfItemsForMakingAvailableSpace;
}
