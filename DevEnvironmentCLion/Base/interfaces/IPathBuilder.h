#ifndef I_PATH_BUILDER_H_bed6caa1_4360_4918_85de_39b46a66818f
#define I_PATH_BUILDER_H_bed6caa1_4360_4918_85de_39b46a66818f

#include "IBuilder.h"

namespace base
{
    /**
     * The IPathBuilder interface defines a builder of a path.
     */
    class IPathBuilder : public IBuilder<std::string>
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
        virtual const std::string& getRootDirectory() const = 0;

        /**
         * Gets a separator of a path.
         */
        virtual const std::string& getSeparator() const = 0;

        /**
         * Adds a new component to a path.
         */
        virtual IPathBuilder& addComponent(const std::string& component) = 0;

        /**
         * Sets an extension of a path.
         */
        virtual IPathBuilder& setExtension(const std::string& extension) = 0;
    };

    //
    // Defines the SharedPtr of Path Builder...
    //
    using IPathBuilderPtr = std::shared_ptr<IPathBuilder>;
}

#endif // I_PATH_BUILDER_H_bed6caa1_4360_4918_85de_39b46a66818f
