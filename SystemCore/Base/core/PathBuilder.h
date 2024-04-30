#ifndef PATH_BUILDER_H_0b9818b5_5cf1_4398_8f83_95997290729b
#define PATH_BUILDER_H_0b9818b5_5cf1_4398_8f83_95997290729b

#include "AbstractPathBuilder.h"

namespace base {

    /**
     * The PathBuilder base class implements a builder of a path.
     */
    class PathBuilder final : public AbstractPathBuilder
    {
    public:
        /**
         * Creates a new path builder.
         */
        static IPathBuilderSharedPtr Make();

        /**
         * The constructor.
         */
        explicit PathBuilder(const std::wstring& rootDirectory = L"");

        /**
         * The destructor.
         */
        virtual ~PathBuilder();
    };

} // namespace base

#endif // PATH_BUILDER_H_0b9818b5_5cf1_4398_8f83_95997290729b
