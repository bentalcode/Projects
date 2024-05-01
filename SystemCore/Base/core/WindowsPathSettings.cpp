#include "WindowsPathSettings.h"

#include "PathBuilder.h"
#include "WindowsPath.h"

using namespace base;
using namespace base::environment::windows;

/**
 * The WindowsPathSettings constructor.
 */
WindowsPathSettings::WindowsPathSettings() {
}

/**
 * The WindowsPathSettings destructor.
 */
WindowsPathSettings::~WindowsPathSettings()
{
}

/**
 * Creates a path separator.
 */
std::wstring WindowsPathSettings::GetPathSeparator() const
{
    return WindowsPath::DirectorySeperator();
}

/**
 * Creates a path.
 */
IPathSharedPtr WindowsPathSettings::CreatePath(const std::wstring& path) const
{
    return WindowsPath::Make(path);
}

/**
 * Creates a path builder.
 */
IPathBuilderSharedPtr WindowsPathSettings::CreatePathBuilder() const
{
    return PathBuilder::Make();
}
