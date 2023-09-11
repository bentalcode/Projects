#ifndef RESOURCE_PATH_BUILDER_H_803d1954_fc2e_486c_b16a_ac87d2dd0ee8
#define RESOURCE_PATH_BUILDER_H_803d1954_fc2e_486c_b16a_ac87d2dd0ee8

#include "AbstractPathBuilder.h"

namespace base {

    /**
     * The ResourcePathBuilder class implements a builder of a resource path.
     */
    class ResourcePathBuilder final : public AbstractPathBuilder
    {
    public:
        /**
         * The ResourcePathBuilder constructor.
         */
        ResourcePathBuilder(
            const std::string& rootDirectory = defaultRootDirectory,
            const std::string& separator = defaultSeparator);

        /**
         * The ResourcePathBuilder Destructor.
         */
        virtual ~ResourcePathBuilder();

    private:
        static const std::string defaultRootDirectory;
        static const std::string defaultSeparator;
    };

}

#endif // RESOURCE_PATH_BUILDER_H_803d1954_fc2e_486c_b16a_ac87d2dd0ee8
