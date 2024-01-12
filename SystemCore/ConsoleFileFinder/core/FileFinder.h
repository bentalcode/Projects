#ifndef FILE_FINDER_H_4b83d98d_0af2_4c2e_ba3f_c90d98fa5755
#define FILE_FINDER_H_4b83d98d_0af2_4c2e_ba3f_c90d98fa5755

#include "IFileFinder.h"

namespace consolefilefinder {

    /**
     * The FileFinder class implements a file finder.
     */
    class FileFinder final : public IFileFinder
    {
    public:
        /**
         * Creates a file finder.
         */
        static IFileFinderSharedPtr Make();

        /**
         * The FileFinder constructor.
         */
        FileFinder();

        /**
         * The FileFinder destructor.
         */
        virtual ~FileFinder();

        /**
         * Finds matching files based on patterns.
         */
        virtual void FindFiles(
            const std::wstring& path,
            const std::vector<std::wstring>& filePatterns,
            std::list<std::wstring>& resultantPaths) override;

    private:
        /**
         * Finds matching files based on patterns and sub directories.
         */
        void FindFilesAndSubDirectories(
            const std::wstring& path,
            const std::vector<std::wstring>& filePatterns,
            std::list<std::wstring>& subDirectories,
            std::list<std::wstring>& resultantPaths);

        /**
         * Checks whether a file name is matching specified patterns.
         */
        static bool isMatchingFileName(
            const std::wstring& name,
            const std::vector<std::wstring>& patterns);

        /**
         * Checks whether a file name is an upper directory.
         */
        static bool IsFileUpperDirectory(const std::wstring& name);

        /**
         * Checks whether a path is a directory.
         */
        static bool IsDirectory(const std::wstring& path);

        /**
         * Creates a path.
         */
        static std::wstring CreatePath(
            const std::wstring& left,
            const std::wstring& right);
    };

} // namespace consolefilefinder

#endif // FILE_FINDER_H_4b83d98d_0af2_4c2e_ba3f_c90d98fa5755
