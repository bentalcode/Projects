#ifndef ABSTRACT_PATH_BUILDER_H_b8643dbf_3a34_4e7a_abfc_25645946c527
#define ABSTRACT_PATH_BUILDER_H_b8643dbf_3a34_4e7a_abfc_25645946c527

#include "IPathBuilder.h"

namespace base {

    /**
     * The AbstractPathBuilder base class implements an abstract builder of a path.
     */
    class AbstractPathBuilder : public IPathBuilder
    {
    protected:
        /**
         * The AbstractPathBuilder Constructor.
         */
        AbstractPathBuilder(
            const std::string& rootDirectory,
            const std::string& separator);

    public:
        /**
         * The AbstractPathBuilder Destructor.
         */
        virtual ~AbstractPathBuilder() = 0;

        /**
         * The copy/move constructors.
         */
        AbstractPathBuilder(const AbstractPathBuilder&) = delete;
        AbstractPathBuilder(AbstractPathBuilder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        AbstractPathBuilder& operator=(const AbstractPathBuilder&) = delete;
        AbstractPathBuilder& operator=(AbstractPathBuilder&&) = delete;

        /**
         * Gets a root directory.
         */
        virtual const std::string& getRootDirectory() const override;

        /**
         * Gets a separator of a path.
         */
        virtual const std::string& getSeparator() const override;

        /**
         * Adds a new component to a path.
         */
        virtual IPathBuilder& addComponent(const std::string& component) override;

        /**
         * Sets an extension of a path.
         */
        virtual IPathBuilder& setExtension(const std::string& extension) override;

        /**
         * Builds the resultant path.
         */
        virtual std::string build() override;

    private:
        std::string m_rootDirectory;
        std::string m_separator;
        std::vector<std::string> m_components;
        std::string m_extension;
    };
}

#endif // ABSTRACT_PATH_BUILDER_H_b8643dbf_3a34_4e7a_abfc_25645946c527
