#ifndef I_SYSTEM_PATH_H_ed0dd546_e659_4210_a1c0_717e76c271de
#define I_SYSTEM_PATH_H_ed0dd546_e659_4210_a1c0_717e76c271de

#include <string>
#include <memory>

namespace base {

    /**
     * The ISystemPath interface defines a system path.
     * Objects of type path represent paths on a file system.
     * Only syntactic aspects of paths are handled: the pathname may represent a non-existing path
     * or even one that is not allowed to exist on the current file system or OS.
     */
    class ISystemPath {
    public:
        /**
         * The ISystemPath constructor.
         */
        ISystemPath() = default;

        /**
         * The ISystemPath destructor.
         */
        virtual ~ISystemPath() = default;

        /**
         * Assigns a new path.
         */
        virtual void Assign(const std::wstring& path) = 0;

        /**
         * Decomposition API...
         */

        /**
         * Returns the root-name of the path, if present.
         */
        virtual std::shared_ptr<ISystemPath> GetRootName() const = 0;

        /**
         * Returns the root directory of the path, if present
         */
        virtual std::shared_ptr<ISystemPath> GetRootDirectory() const = 0;

        /**
         * Returns the root path of the path, if present.
         */
        virtual std::shared_ptr<ISystemPath> GetRootPath() const = 0;

        /**
         * Returns path relative to the root path.
         */
        virtual std::shared_ptr<ISystemPath> GetRelativePath() const = 0;

        /**
         * Returns the path of the parent path.
         */
        virtual std::shared_ptr<ISystemPath> GetParentPath() const = 0;

        /**
         * Returns the filename path component.
         */
        virtual std::shared_ptr<ISystemPath> GetFileName() const = 0;

        /**
         * Returns the stem path component (filename without the final extension).
         */
        virtual std::shared_ptr<ISystemPath> GetStem() const = 0;

        /**
         * Returns the file extension path component.
         */
        virtual std::shared_ptr<ISystemPath> GetExtension() const = 0;

        /**
         * Query API...
         */

        /**
         * Checks whether a path is empty.
         */
        virtual bool Empty() const = 0;

        /**
         * Checks whether a path has a root path.
         */
        virtual bool HasRootPath() const = 0;

        /**
         * Checks whether a path has a root name.
         */
        virtual bool HasRootName() const = 0;

        /**
         * Checks whether a path has a root directory.
         */
        virtual bool HasRootDirectory() const = 0;

        /**
         * Checks whether a path has a relative path.
         */
        virtual bool HasRelativePath() const = 0;

        /**
         * Checks whether a path has a parent path.
         */
        virtual bool HasParentPath() const = 0;

        /**
         * Checks whether a path has a file name.
         */
        virtual bool HasFileName() const = 0;

        /**
         * Checks whether a path has a stem.
         */
        virtual bool HasStem() const = 0;

        /**
         * Checks whether a path has an extension.
         */
        virtual bool HasExtension() const = 0;

        /**
         * Checks whether a path is absolute.
         */
        virtual bool IsAbsolute() const = 0;

        /**
         * Checks whether a path is relative.
         */
        virtual bool IsRelative() const = 0;

        /**
         * Gets the string representation of this instance.
         */
        virtual std::wstring ToString() const = 0;
    };

    /**
     * Defines the Shared Ptr of System Path.
     */
    using ISystemPathSharedPtr = std::shared_ptr<ISystemPath>;

}  // namespace base

#endif // I_SYSTEM_PATH_H_ed0dd546_e659_4210_a1c0_717e76c271de
