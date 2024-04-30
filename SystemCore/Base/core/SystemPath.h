#ifndef SYSTEM_PATH_H_dad4a35d_0ceb_42a1_ab7a_72e4fce5404e
#define SYSTEM_PATH_H_dad4a35d_0ceb_42a1_ab7a_72e4fce5404e

#include "ISystemPath.h"

namespace base {

    /**
     * The SystemPath class implements a system path.
     */
    class SystemPath final : public ISystemPath {
    public:
        /**
         * Creates a new instance of a system path.
         */
        static ISystemPathSharedPtr Make(const std::wstring& path);

        /**
         * The SystemPath constructor.
         */
        explicit SystemPath(const std::wstring& path);

        /**
         * The SystemPath destructor.
         */
        virtual ~SystemPath();

        /**
         * Assigns a new path.
         */
        virtual void Assign(const std::wstring& path) override;

        /**
         * Decomposition API...
         */

        /**
         * Returns the root-name of the path, if present.
         */
        virtual std::shared_ptr<ISystemPath> GetRootName() const override;

        /**
         * Returns the root directory of the path, if present
         */
        virtual std::shared_ptr<ISystemPath> GetRootDirectory() const override;

        /**
         * Returns the root path of the path, if present.
         */
        virtual std::shared_ptr<ISystemPath> GetRootPath() const override;

        /**
         * Returns path relative to the root path.
         */
        virtual std::shared_ptr<ISystemPath> GetRelativePath() const override;

        /**
         * Returns the path of the parent path.
         */
        virtual std::shared_ptr<ISystemPath> GetParentPath() const override;

        /**
         * Returns the filename path component.
         */
        virtual std::shared_ptr<ISystemPath> GetFileName() const override;

        /**
         * Returns the stem path component (filename without the final extension).
         */
        virtual std::shared_ptr<ISystemPath> GetStem() const override;

        /**
         * Returns the file extension path component.
         */
        virtual std::shared_ptr<ISystemPath> GetExtension() const override;

        /**
         * Query API...
         */

        /**
         * Checks whether a path is empty.
         */
        virtual bool Empty() const override;

        /**
         * Checks whether a path has a root path.
         */
        virtual bool HasRootPath() const override;

        /**
         * Checks whether a path has a root name.
         */
        virtual bool HasRootName() const override;

        /**
         * Checks whether a path has a root directory.
         */
        virtual bool HasRootDirectory() const override;

        /**
         * Checks whether a path has a relative path.
         */
        virtual bool HasRelativePath() const override;

        /**
         * Checks whether a path has a parent path.
         */
        virtual bool HasParentPath() const override;

        /**
         * Checks whether a path has a file name.
         */
        virtual bool HasFileName() const override;

        /**
         * Checks whether a path has a stem.
         */
        virtual bool HasStem() const override;

        /**
         * Checks whether a path has an extension.
         */
        virtual bool HasExtension() const override;

        /**
         * Checks whether a path is absolute.
         */
        virtual bool IsAbsolute() const override;

        /**
         * Checks whether a path is relative.
         */
        virtual bool IsRelative() const override;

        /**
         * Gets a string representation of this instance.
         */
        virtual std::wstring ToString() const override;

    private:
        std::wstring GetSeparator();

        std::wstring m_path;
    };

} // namespace base

#endif // namespace SYSTEM_PATH_H_dad4a35d_0ceb_42a1_ab7a_72e4fce5404e
