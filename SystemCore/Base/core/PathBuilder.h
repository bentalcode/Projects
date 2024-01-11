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
         * The constructor.
         */
        explicit PathBuilder(const std::wstring& rootDirectory = ROOT_DIRECTORY);

        /**
         * The destructor.
         */
        virtual ~PathBuilder();

    private:
        static const std::wstring ROOT_DIRECTORY;
        static const std::wstring SEPARATOR;
    };

} // namespace base

#endif // PATH_BUILDER_H_0b9818b5_5cf1_4398_8f83_95997290729b
