#ifndef ABSTRACT_PATH_H_5bfdf721_45cb_4c7f_8683_f38b9241797e
#define ABSTRACT_PATH_H_5bfdf721_45cb_4c7f_8683_f38b9241797e

#include "IPath.h"

namespace base {

    /**
     * The AbstractPath class implements an abstract path.
     */
    class AbstractPath : public IPath
    {
    protected:
        /**
         * The constructor.
         */
        AbstractPath(
            const std::wstring& path,
            const std::wstring& seperator,
            std::wstring::value_type extensionSeperator);

    public:
        /**
         * The destructor.
         */
        virtual ~AbstractPath();

        /**
         * The Copy/move constructors.
         */
        AbstractPath(const AbstractPath&) = delete;
        AbstractPath(AbstractPath&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        AbstractPath& operator=(const AbstractPath&) = delete;
        AbstractPath& operator=(AbstractPath&&) = delete;

        /**
         * Gets a path.
         */
        virtual const std::wstring& GetPath() const override;

        /**
         * Checks whether a path is empty.
         */
        virtual bool Empty() const override;

        /**
         * Gets an absolute path.
         */
        virtual std::wstring GetAbsolutePath() const override;

        /**
         * Gets a canonical path.
         */
        virtual std::wstring GetCanonicalPath() const override;

        /**
         * Checks whether a path is absolute.
         */
        virtual bool IsAbsolute() const override;

        /**
         * Checks whether a path is relative.
         */
        virtual bool IsRelative() const override;

        /**
         * Gets a path decomposition.
         */
        virtual const IPathDecomposition& PathDecomposition() const override;

    protected:
        /**
         * Validates a path.
         */
        virtual void ValidatePath(const std::wstring& path) const = 0;

        /**
         * Makes an absolute path.
         */
        virtual std::wstring MakeAbsolutePath(const std::wstring& path) const = 0;

        /**
         * Makes a canonical path.
         */
        virtual std::wstring MakeCanonicalPath(const std::wstring& path) const = 0;

        /**
         * Checks whether a path is absolute.
         */
        virtual bool IsAbsolute(const std::wstring& path) const = 0;

        /**
         * Checks whether a path is relative.
         */
        virtual bool IsRelative(const std::wstring& path) const = 0;

    private:
        /**
         * Initializes a path.
         */
        void Initialize(
            const std::wstring& path,
            const std::wstring& seperator,
            std::wstring::value_type extensionSeperator);

        std::wstring m_path;
        std::wstring m_seperator;
        std::wstring::value_type m_extensionSeparator;
        mutable IPathDecompositionSharedPtr m_pathDecomposition;
    };

} // namespace base

#endif // ABSTRACT_PATH_H_5bfdf721_45cb_4c7f_8683_f38b9241797e
