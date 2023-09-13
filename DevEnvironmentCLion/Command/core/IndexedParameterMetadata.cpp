#include "PreCompiled.h"
#include "IndexedParameterMetadata.h"

using namespace command;

/**
 * Creates a parameter meta-data.
 */
IIndexedParameterMetadataSharedPtr IndexedParameterMetadata::make(
    const std::string& name,
    const std::string& description)
{
    return std::make_shared<IndexedParameterMetadata>(
        name,
        description);
}

/**
 * The IndexedParameterMetadata constructor.
 */
IndexedParameterMetadata::IndexedParameterMetadata(
    const std::string& name,
    const std::string& description) :
    ParameterMetadata(name, description)
{
}

/**
 * The IndexedParameterMetadata destructor.
 */
IndexedParameterMetadata::~IndexedParameterMetadata()
{
}
