#ifndef ABSTRACT_PATH_BUILDER_H_2913f53f_48ea_4b98_b9b5_aed33a5a2f54
#define ABSTRACT_PATH_BUILDER_H_2913f53f_48ea_4b98_b9b5_aed33a5a2f54

#include "IPathBuilder.h"
#include <list>

namespace base {

    /**
     * The AbstractPathBuilder base class implements an abstract builder of a path.
     */
    class AbstractPathBuilder : public IPathBuilder, public IBuilder<std::wstring>
    {
    public:
        /**
         * The constructor.
         */
        AbstractPathBuilder(
            const std::wstring& rootDirectory,
            const std::wstring& separator);

        /**
         * The destructor.
         */
        virtual ~AbstractPathBuilder();

        /**
         * The Copy/move constructors.
         */
        AbstractPathBuilder(const AbstractPathBuilder&) = delete;
        AbstractPathBuilder(AbstractPathBuilder&&) = delete;

        /**
         * The Copy/move assignment operators.
         */
        AbstractPathBuilder& operator=(const AbstractPathBuilder&) = delete;
        AbstractPathBuilder& operator=(AbstractPathBuilder&&) = delete;

        /**
         * Gets a root directory.
         */
        virtual const std::wstring& GetRootDirectory() const override;

        /**
         * Gets a separator of a path.
         */
        virtual const std::wstring& GetSeparator() const override;

        /**
         * Adds a new component to a path.
         */
        virtual void AddComponent(const std::wstring& component) override;

        /**
         * Sets an extension of a path.
         */
        virtual void SetExtension(const std::wstring& extension) override;

        /**
         * Gets a builder of path.
         */
        virtual const IBuilder<std::wstring>& GetBuilder() const override;

        /**
         * Builds the resultant path.
         */
        virtual std::wstring Build() override;

    private:
        std::wstring m_rootDirectory;
        std::wstring m_separator;
        std::list<std::wstring> m_components;
        std::wstring m_extension;
    };

} // namespace base

#endif // ABSTRACT_PATH_BUILDER_H_2913f53f_48ea_4b98_b9b5_aed33a5a2f54
