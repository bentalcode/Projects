#include "PathBuilder.h"

using namespace base;

const std::wstring PathBuilder::ROOT_DIRECTORY;
const std::wstring PathBuilder::SEPARATOR = L"\\";

/**
 * The PathBuilder constructor.
 */
PathBuilder::PathBuilder(const std::wstring& rootDirectory) :
    AbstractPathBuilder(
        rootDirectory,
        SEPARATOR)
{
}

/**
 * The PathBuilder destructor.
 */
PathBuilder::~PathBuilder()
{
}
