#ifndef PATH_DECOMPOSITION_H_889bef74_f72b_4e6e_9f38_4b90e70327f9
#define PATH_DECOMPOSITION_H_889bef74_f72b_4e6e_9f38_4b90e70327f9

#include "IPathDecomposition.h"

namespace base {

    /**
     * The IPathDecomposition class implements API for path decomposition.
     */
    class PathDecomposition final : public IPathDecomposition {
    public:
        /**
         * Creates a new instance of a path decomposition.
         */
        static IPathDecompositionSharedPtr Make(
           const std::wstring& path,
           const std::wstring& separator,
           std::wstring::value_type extensionSeparator);

        /**
         * The PathDecomposition constructor.
         */
        PathDecomposition(
            const std::wstring& path,
            const std::wstring& separator,
            std::wstring::value_type extensionSeparator);

        /**
         * The PathDecomposition destructor.
         */
        virtual ~PathDecomposition();

        /**
         * Returns the root-name of the path, if present.
         */
        virtual std::wstring GetRootName() const override;

        /**
         * Returns the root directory of the path, if present
         */
        virtual std::wstring GetRootDirectory() const override;

        /**
         * Returns the root path of the path, if present.
         */
        virtual std::wstring GetRootPath() const override;

        /**
         * Returns path relative to the root path.
         */
        virtual std::wstring GetRelativePath() const override;

        /**
         * Returns the path of the parent path.
         */
        virtual std::wstring GetParentPath() const override;

        /**
         * Returns the filename path component.
         */
        virtual std::wstring GetFileName() const override;

        /**
         * Returns the stem path component (filename without the final extension).
         */
        virtual std::wstring GetStem() const override;

        /**
         * Returns the file extension path component.
         */
        virtual std::wstring GetExtension() const override;

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

    private:
        std::wstring m_path;
        std::wstring m_separator;
        std::wstring::value_type m_extensionSeparator;
    };

} // namespace base

#endif // namespace PATH_DECOMPOSITION_H_889bef74_f72b_4e6e_9f38_4b90e70327f9
