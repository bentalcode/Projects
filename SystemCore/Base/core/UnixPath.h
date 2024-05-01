#ifndef UNIX_PATH_H_46863f75_d971_45b1_b0d1_27df36937d47
#define UNIX_PATH_H_46863f75_d971_45b1_b0d1_27df36937d47

#include "AbstractPath.h"

namespace base {

    namespace environment {

        namespace unix {

            /**
             * The UnixPath class implements a Unix' path.
             */
            class UnixPath final : public AbstractPath
            {
            public:
                /**
                 * Creates a new unix path.
                 */
                static IPathSharedPtr Make(const std::wstring& path);

                /**
                 * The UnixPath constructor.
                 */
                explicit UnixPath(const std::wstring& path);

                /**
                 * The UnixPath destructor.
                 */
                virtual ~UnixPath();

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

                /**
                 * Checks whether a path is absolute.
                 */
                virtual bool IsAbsolute(const std::wstring& path) const override;

                /**
                 * Checks whether a path is relative.
                 */
                virtual bool IsRelative(const std::wstring& path) const override;

            private:
                static const std::wstring::value_type SEPARATOR;
                static const std::wstring DIRECTORY_SEPARATOR;
                static const std::wstring::value_type EXTENSION_SEPARATOR;
                static const std::wstring CURRENT_DIRECTORY;
                static const std::wstring PARENT_DIRECTORY;
                static const std::wstring HOME_DIRECTORY;

                /**
                 * Makes an absolute path.
                 */
                static std::wstring MakeAbsolute(const std::wstring& path);

                /**
                 * Makes a canonical path.
                 */
                static std::wstring MakeCanonical(const std::wstring& path);
            };

        } // namespace unix

    } // namespace environment

} // namespace base

#endif // UNIX_PATH_H_46863f75_d971_45b1_b0d1_27df36937d47
