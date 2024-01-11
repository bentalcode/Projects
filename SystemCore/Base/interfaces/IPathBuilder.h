#ifndef I_PATH_BUILDER_H_411d8040_1257_4748_ab30_3ef0e29e51e8
#define I_PATH_BUILDER_H_411d8040_1257_4748_ab30_3ef0e29e51e8

#include "IBuilder.h"
#include <string>
#include <memory>

namespace base
{
    /**
     * The IPathBuilder interface defines a builder of a path.
     */
    class IPathBuilder
    {
    public:
        /**
         * The constructor.
         */
        IPathBuilder() = default;

        /**
         * The destructor.
         */
        virtual ~IPathBuilder() = default;

        /**
         * The copy/move constructors.
         */
        IPathBuilder(const IPathBuilder&) = delete;
        IPathBuilder(IPathBuilder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IPathBuilder& operator=(const IPathBuilder&) = delete;
        IPathBuilder& operator=(IPathBuilder&&) = delete;

        /**
         * Gets a root directory.
         */
        virtual const std::wstring& GetRootDirectory() const = 0;

        /**
         * Gets a separator of a path.
         */
        virtual const std::wstring& GetSeparator() const = 0;

        /**
         * Adds a new component to a path.
         */
        virtual void AddComponent(const std::wstring& component) = 0;

        /**
         * Sets an extension of a path.
         */
        virtual void SetExtension(const std::wstring& extension) = 0;

        /**
         * Gets a builder of path.
         */
        virtual const IBuilder<std::wstring>& GetBuilder() const = 0;
    };

    //
    // Defines the SharedPtr of Path Builder...
    //
    using IPathBuilderSharedPtr = std::shared_ptr<IPathBuilder>;

} // namespace base

#endif // I_PATH_BUILDER_H_411d8040_1257_4748_ab30_3ef0e29e51e8
