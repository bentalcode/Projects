#ifndef WINDOWS_PATH_H_a43a36f4_3abe_4a14_a19a_3b45b0af0230
#define WINDOWS_PATH_H_a43a36f4_3abe_4a14_a19a_3b45b0af0230

#include "AbstractPath.h"

namespace base {

    /**
     * The WindowsPath class implements a Windows' path.
     */
    class WindowsPath final : public AbstractPath
    {
    public:
        /**
         * Creates a new windows path.
         */
        static IPathSharedPtr Make(const std::wstring& path);

        /**
         * The WindowsPath constructor.
         */
        explicit WindowsPath(const std::wstring& path);

        /**
         * The WindowsPath destructor.
         */
        virtual ~WindowsPath();

        /**
         * Gets seperator.
         */
        static std::wstring::value_type Seperator();

        /**
         * Gets directory seperator.
         */
        static std::wstring DirectorySeperator();

        /**
         * Gets current directory.
         */
        static std::wstring CurrentDirectory();

        /**
         * Gets parent directory.
         */
        static std::wstring ParentDirectory();

    protected:
        /**
         * Validates a path.
         */
        virtual void ValidatePath(const std::wstring& path) const override;

        /**
         * Makes an absolute path.
         */
        virtual std::wstring MakeAbsolutePath(const std::wstring& path) const override;

        /**
         * Makes a canonical path.
         */
        virtual std::wstring MakeCanonicalPath(const std::wstring& path) const override;

    private:
        static const std::wstring::value_type SEPARATOR;
        static const std::wstring DIRECTORY_SEPARATOR;
        static const std::wstring CURRENT_DIRECTORY;
        static const std::wstring PARENT_DIRECTORY;

        /**
         * Makes an absolute path.
         */
        static std::wstring MakeAbsolute(const std::wstring& path);

        /**
         * Makes a canonical path.
         */
        static std::wstring MakeCanonical(const std::wstring& path);
    };

} // namespace base

#endif // WINDOWS_PATH_H_a43a36f4_3abe_4a14_a19a_3b45b0af0230
