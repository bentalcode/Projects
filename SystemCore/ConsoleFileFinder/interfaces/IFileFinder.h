#ifndef I_FILE_FINDER_H_d4181e6f_7c22_4c0d_b069_ba50180876a4
#define I_FILE_FINDER_H_d4181e6f_7c22_4c0d_b069_ba50180876a4

#include <memory>
#include <filesystem>
#include <vector>
#include <list>
#include <string>

namespace consolefilefinder
{
    /**
     * The IFileFinder interface defines a file finder.
     */
    class IFileFinder
    {
    public:
        /**
         * The constructor.
         */
        IFileFinder() = default;

        /**
         * The destructor.
         */
        virtual ~IFileFinder() = default;

        /**
         * The copy/move constructors.
         */
        IFileFinder(const IFileFinder&) = delete;
        IFileFinder(IFileFinder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IFileFinder& operator=(const IFileFinder&) = delete;
        IFileFinder& operator=(IFileFinder&&) = delete;

        /**
         * Finds matching files based on patterns.
         */
        virtual void FindFiles(
            const std::wstring& dir,
            const std::vector<std::wstring>& patterns,
            std::list<std::wstring>& files) = 0;
    };

    //
    // Defines the SharedPtr of File Finder...
    //
    using IFileFinderSharedPtr = std::shared_ptr<IFileFinder>;

} // namespace base

#endif // I_FILE_FINDER_H_d4181e6f_7c22_4c0d_b069_ba50180876a4
