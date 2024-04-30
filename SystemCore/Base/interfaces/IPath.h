#ifndef I_PATH_H_045c532b_93d4_47b1_9701_3278e944e052
#define I_PATH_H_045c532b_93d4_47b1_9701_3278e944e052

#include <string>
#include <memory>

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
         * Gets an absolute path.
         */
        virtual std::wstring GetAbsolutePath() const = 0;

        /**
         * Gets a canonical path.
         */
        virtual std::wstring GetCanonicalPath() const = 0;
    };

    /**
     * Defines the Shared Ptr of Path.
     */
    using IPathSharedPtr = std::shared_ptr<IPath>;

}  // namespace base

#endif // I_PATH_H_045c532b_93d4_47b1_9701_3278e944e052
