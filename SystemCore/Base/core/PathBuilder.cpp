#include "PathBuilder.h"

#include "WindowsPath.h"

using namespace base;

/**
 * Creates a new path builder.
 */
IPathBuilderSharedPtr Make()
{
    return std::make_shared<PathBuilder>();
}

/**
 * The PathBuilder constructor.
 */
PathBuilder::PathBuilder(const std::wstring& rootDirectory) :
    AbstractPathBuilder(
        rootDirectory,
        environment::windows::WindowsPath::DirectorySeperator())
{
}

/**
 * The PathBuilder destructor.
 */
PathBuilder::~PathBuilder()
{
}
