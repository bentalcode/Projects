#include "FileFinder.h"
#include <vector>

using namespace consolefilefinder;

int main()
{
    std::wstring path(L"C:\\Chess");
    std::vector<std::wstring> patterns;
    std::list<std::wstring> files;

    FileFinder fileFinder;
    fileFinder.FindFiles(path, patterns, files);

    return 0;
}
