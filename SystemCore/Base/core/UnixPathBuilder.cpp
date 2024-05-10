#include "UnixPathBuilder.h"

#include "UnixPath.h"

using namespace base;

/**
 * Creates a new path builder.
 */
IPathBuilderSharedPtr UnixPathBuilder::Make()
{
    return std::make_shared<UnixPathBuilder>();
}

/**
 * The UnixPathBuilder constructor.
 */
UnixPathBuilder::UnixPathBuilder(const std::wstring& rootDirectory) :
    AbstractPathBuilder(
        rootDirectory,
        environment::unix::UnixPath::DirectorySeperator())
{
}

/**
 * The UnixPathBuilder destructor.
 */
UnixPathBuilder::~UnixPathBuilder()
{
}
