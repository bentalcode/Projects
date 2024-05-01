#ifndef I_PATH_DECOMPOSITON_H_9d6a2e43_5cc2_4589_a5e4_008a6322b36b
#define I_PATH_DECOMPOSITON_H_9d6a2e43_5cc2_4589_a5e4_008a6322b36b

#include <string>
#include <memory>

namespace base {

    /**
     * The IPathDecomposition interface defines Decomposition API for path components.
     */
    class IPathDecomposition {
    public:
        /**
         * The IPathDecomposition constructor.
         */
        IPathDecomposition() = default;

        /**
         * The IPathDecomposition destructor.
         */
        virtual ~IPathDecomposition() = default;

        /**
         * Returns the root-name of the path, if present.
         */
        virtual std::wstring GetRootName() const = 0;

        /**
         * Returns the root directory of the path, if present
         */
        virtual std::wstring GetRootDirectory() const = 0;

        /**
         * Returns the root path of the path, if present.
         */
        virtual std::wstring GetRootPath() const = 0;

        /**
         * Returns path relative to the root path.
         */
        virtual std::wstring GetRelativePath() const = 0;

        /**
         * Returns the path of the parent path.
         */
        virtual std::wstring GetParentPath() const = 0;

        /**
         * Returns the filename path component.
         */
        virtual std::wstring GetFileName() const = 0;

        /**
         * Returns the stem path component (filename without the final extension).
         */
        virtual std::wstring GetStem() const = 0;

        /**
         * Returns the file extension path component.
         */
        virtual std::wstring GetExtension() const = 0;

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
    };

    /**
     * Defines the Shared Ptr of Path Decomposition.
     */
    using IPathDecompositionSharedPtr = std::shared_ptr<IPathDecomposition>;

}  // namespace base

#endif // I_PATH_DECOMPOSITON_H_9d6a2e43_5cc2_4589_a5e4_008a6322b36b
