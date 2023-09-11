#include "PreCompiled.h"
#include "PathBuilder.h"

using namespace base;

const std::string PathBuilder::defaultRootDirectory;
const std::string PathBuilder::defaultSeparator = "\\";

/**
 * The PathBuilder constructor.
 */
PathBuilder::PathBuilder(
    const std::string& rootDirectory,
    const std::string& separator) :
    AbstractPathBuilder(rootDirectory, separator)
{
}

/**
 * The PathBuilder Destructor.
 */
PathBuilder::~PathBuilder()
{
}