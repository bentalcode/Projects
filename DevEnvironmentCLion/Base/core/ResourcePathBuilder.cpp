#include "PreCompiled.h"
#include "ResourcePathBuilder.h"

using namespace base;

const std::string ResourcePathBuilder::defaultRootDirectory;
const std::string ResourcePathBuilder::defaultSeparator = "/";

/**
 * The ResourcePathBuilder constructor.
 */
ResourcePathBuilder::ResourcePathBuilder(
    const std::string& rootDirectory,
    const std::string& separator) :
    AbstractPathBuilder(rootDirectory, separator)
{
}

/**
 * The ResourcePathBuilder Destructor.
 */
ResourcePathBuilder::~ResourcePathBuilder()
{
}