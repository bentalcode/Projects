#ifndef PATH_BUILDER_H_2cc50849_e00e_4ec1_abfe_03fc016f0bb4
#define PATH_BUILDER_H_2cc50849_e00e_4ec1_abfe_03fc016f0bb4

#include "AbstractPathBuilder.h"

namespace base {

    /**
     * The PathBuilder class implements a builder of a path.
     */
    class PathBuilder final : public AbstractPathBuilder
    {
    public:
        /**
         * The PathBuilder constructor.
         */
        PathBuilder(
            const std::string& rootDirectory = defaultRootDirectory,
            const std::string& separator = defaultSeparator);

        /**
         * The PathBuilder Destructor.
         */
        virtual ~PathBuilder();

    private:
        static const std::string defaultRootDirectory;
        static const std::string defaultSeparator;
    };

}

#endif // PATH_BUILDER_H_2cc50849_e00e_4ec1_abfe_03fc016f0bb4
