#include "IndexedParameterMetadata.h"

using namespace command;

/**
 * Creates a parameter meta-data.
 */
IIndexedParameterMetadataSharedPtr IndexedParameterMetadata::Make(
    const std::wstring& name,
    const std::wstring& description)
{
    return std::make_shared<IndexedParameterMetadata>(
        name,
        description);
}

/**
 * The IndexedParameterMetadata constructor.
 */
IndexedParameterMetadata::IndexedParameterMetadata(
    const std::wstring& name,
    const std::wstring& description) :
    ParameterMetadata(name, description)
{
}

/**
 * The IndexedParameterMetadata destructor.
 */
IndexedParameterMetadata::~IndexedParameterMetadata()
{
}

/**
 * Gets parameter metadata.
 */
const IParameterMetadata& IndexedParameterMetadata::GetParameterMetadata() const
{
    return *this;
}
