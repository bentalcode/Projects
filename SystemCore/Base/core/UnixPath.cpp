#include "UnixPath.h"
#include "PathBuilder.h"
#include "Strings.h"
#include "InvalidArgumentException.h"
#include "NotImplementedException.h"
#include <stack>

using namespace base;
using namespace base::environment::unix;
const std::wstring::value_type UnixPath::SEPARATOR = L'/';
const std::wstring UnixPath::DIRECTORY_SEPARATOR = std::wstring(1, SEPARATOR);
const std::wstring::value_type UnixPath::EXTENSION_SEPARATOR = L'.';
const std::wstring UnixPath::CURRENT_DIRECTORY = L".";
const std::wstring UnixPath::PARENT_DIRECTORY = L"..";
const std::wstring UnixPath::HOME_DIRECTORY = L"~";

/**
 * Creates a new unix path.
 */
IPathSharedPtr UnixPath::Make(const std::wstring& path)
{
    return std::make_shared<UnixPath>(path);
}

/**
 * The UnixPath constructor.
 */
UnixPath::UnixPath(const std::wstring& path) :
    AbstractPath(
        path,
        DIRECTORY_SEPARATOR,
        EXTENSION_SEPARATOR)
{
}

/**
 * The UnixPath destructor.
 */
UnixPath::~UnixPath()
{
}

/**
 * Gets seperator.
 */
std::wstring::value_type UnixPath::Seperator()
{
    return SEPARATOR;
}

/**
 * Gets directory seperator.
 */
std::wstring UnixPath::DirectorySeperator()
{
    return DIRECTORY_SEPARATOR;
}

/**
 * Gets current directory.
 */
std::wstring UnixPath::CurrentDirectory()
{
    return CURRENT_DIRECTORY;
}

/**
 * Gets parent directory.
 */
std::wstring UnixPath::ParentDirectory()
{
    return PARENT_DIRECTORY;
}

/**
 * Validates a path.
 */
void UnixPath::ValidatePath(const std::wstring& path) const
{
    if (path.empty()) {
        throw InvalidArgumentException(L"The input path can not be empty.");
    }
}

/**
 * Makes an absolute path.
 */
std::wstring UnixPath::MakeAbsolutePath(const std::wstring& path) const
{
    return MakeAbsolute(path);
}

/**
 * Makes a canonical path.
 */
std::wstring UnixPath::MakeCanonicalPath(const std::wstring& path) const
{
    return MakeCanonical(path);
}

/**
 * Makes an absolute path.
 */
std::wstring UnixPath::MakeAbsolute(const std::wstring& path)
{
    throw NotImplementedException(L"UnixPath::MakeAbsolute()");
}

/**
 * Makes a canonical path.
 */
std::wstring UnixPath::MakeCanonical(const std::wstring& path)
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
bool UnixPath::IsAbsolute(const std::wstring& path) const
{
    return !IsRelative(path);
}

/**
 * Checks whether a path is relative.
 */
bool UnixPath::IsRelative(const std::wstring& path) const
{
    throw NotImplementedException(L"UnixPath::IsRelative()");
}
