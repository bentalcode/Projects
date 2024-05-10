#include "WindowsPath.h"
#include "PathBuilder.h"
#include "Strings.h"
#include "InvalidArgumentException.h"
#include <stack>
#include <experimental/filesystem>

using namespace base;
using namespace base::environment::windows;
const std::wstring::value_type WindowsPath::SEPARATOR = L'\\';
const std::wstring WindowsPath::DIRECTORY_SEPARATOR = std::wstring(1, SEPARATOR);
const std::wstring::value_type WindowsPath::EXTENSION_SEPARATOR = L'.';
const std::wstring WindowsPath::CURRENT_DIRECTORY = L".";
const std::wstring WindowsPath::PARENT_DIRECTORY = L"..";

/**
 * Creates a new windows path.
 */
IPathSharedPtr WindowsPath::Make(const std::wstring& path)
{
    return std::make_shared<WindowsPath>(path);
}

/**
 * The WindowsPath constructor.
 */
WindowsPath::WindowsPath(const std::wstring& path) :
    AbstractPath(
        path,
        DIRECTORY_SEPARATOR,
        EXTENSION_SEPARATOR)
{
}

/**
 * The WindowsPath destructor.
 */
WindowsPath::~WindowsPath()
{
}

/**
 * Gets seperator.
 */
std::wstring::value_type WindowsPath::Seperator()
{
    return SEPARATOR;
}

/**
 * Gets directory seperator.
 */
std::wstring WindowsPath::DirectorySeperator()
{
    return DIRECTORY_SEPARATOR;
}

/**
 * Gets current directory.
 */
std::wstring WindowsPath::CurrentDirectory()
{
    return CURRENT_DIRECTORY;
}

/**
 * Gets parent directory.
 */
std::wstring WindowsPath::ParentDirectory()
{
    return PARENT_DIRECTORY;
}

/**
 * Validates a path.
 */
void WindowsPath::ValidatePath(const std::wstring& path) const
{
    if (path.empty()) {
        throw InvalidArgumentException(L"The input path can not be empty.");
    }
}

/**
 * Makes an absolute path.
 */
std::wstring WindowsPath::MakeAbsolutePath(const std::wstring& path) const
{
    return MakeAbsolute(path);
}

/**
 * Makes a canonical path.
 */
std::wstring WindowsPath::MakeCanonicalPath(const std::wstring& path) const
{
    return MakeCanonical(path);
}

/**
 * Makes an absolute path.
 */
std::wstring WindowsPath::MakeAbsolute(const std::wstring& path)
{
    return MakeCanonical(path);
}

/**
 * Makes a canonical path.
 */
std::wstring WindowsPath::MakeCanonical(const std::wstring& path)
{
    //
    // Split tokens by directory seperator...
    //
    std::vector<std::wstring> tokens;
    Strings::SplitString(path, DirectorySeperator(), tokens);

    //
    // Process the tokens with a stack...
    //
    std::stack<std::wstring> stack;

    for (const std::wstring& token : tokens) {
        if (token == ParentDirectory())
        {
            stack.pop();
        }
        else if (!token.empty() && token != CurrentDirectory())
        {
            stack.push(token);
        }
    }

    //
    // Create the list of finalize component...
    //
    std::list<std::wstring> components;

    while (!stack.empty()) {
        std::wstring component = stack.top();
        stack.pop();
        components.push_front(component);
    }

    //
    // Assemble the path...
    //
    PathBuilder pathBuilder;

    for (const std::wstring& component : components) {
        pathBuilder.AddComponent(component);
    }

    return pathBuilder.Build();
}

/**
 * Checks whether a path is absolute.
 */
bool WindowsPath::IsAbsolute(const std::wstring& path) const
{
    return !IsRelative(path);
}

/**
 * Checks whether a path is relative.
 */
bool WindowsPath::IsRelative(const std::wstring& path) const
{
    std::experimental::filesystem::path systemPath(path);
    return systemPath.is_relative();
}
