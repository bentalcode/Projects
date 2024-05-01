#ifndef I_PATH_H_045c532b_93d4_47b1_9701_3278e944e052
#define I_PATH_H_045c532b_93d4_47b1_9701_3278e944e052

#include <string>
#include <memory>
#include "IPathDecomposition.h"

namespace base {

    /**
     * The IPath interface defines a path.
     */
    class IPath {
    public:
        /**
         * The IPath constructor.
         */
        IPath() = default;

        /**
         * The IPath destructor.
         */
        virtual ~IPath() = default;

        /**
         * Gets a path.
         */
        virtual const std::wstring& GetPath() const = 0;

        /**
         * Checks whether a path is empty.
         */
        virtual bool Empty() const = 0;

        /**
         * Gets an absolute path.
         */
        virtual std::wstring GetAbsolutePath() const = 0;

        /**
         * Gets a canonical path.
         */
        virtual std::wstring GetCanonicalPath() const = 0;

        /**
         * Checks whether a path is absolute.
         */
        virtual bool IsAbsolute() const = 0;

        /**
         * Checks whether a path is relative.
         */
        virtual bool IsRelative() const = 0;

        /**
         * Gets a path decomposition.
         */
        virtual const IPathDecomposition& PathDecomposition() const = 0;
    };

    /**
     * Defines the Shared Ptr of Path.
     */
    using IPathSharedPtr = std::shared_ptr<IPath>;

    /**
     * Writes statistics information to an output stream.
     */
    inline std::wostream& operator<<(std::wostream& stream, const IPath& path)
    {
        stream << path.GetPath();
        return stream;
    }

}  // namespace base

#endif // I_PATH_H_045c532b_93d4_47b1_9701_3278e944e052
