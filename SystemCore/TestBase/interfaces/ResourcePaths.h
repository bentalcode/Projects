#ifndef RESOURCE_PATHS_H_0a298836_1a88_40c8_a3b8_4041bd7b2d5a
#define RESOURCE_PATHS_H_0a298836_1a88_40c8_a3b8_4041bd7b2d5a

#include "PathBuilder.h"

namespace test {
    namespace base {

        /**
         * The ResourcePaths class implements an assertion.
         */
        class ResourcePaths final
        {
        public:
            /**
             * Creates a path of a resource.
             */
            static std::string create(
                const std::string& rootDirectory,
                const std::string& subDirectory);

            /**
             * Creates a path of a resource.
             */
            static std::string create(
                const std::string& rootDirectory,
                const std::string& subDirectory,
                const std::string& resourceName);

            /**
             * Creates a path of a resource.
             */
            static std::string create(
                const std::string& rootDirectory,
                const std::string& subDirectory1,
                const std::string& subDirectory2,
                const std::string& resourceName);

        private:
            /**
             * This is a static class - Disables the default constructor and destructor.
             */
            ResourcePaths() = delete;
            ~ResourcePaths() = delete;
        };

        /**
         * Creates a path of a resource.
         */
        std::string ResourcePaths::create(
            const std::string& rootDirectory,
            const std::string& subDirectory)
        {
            ::base::PathBuilder pathBuilder;

            std::string path = pathBuilder
                .addComponent(rootDirectory)
                .addComponent(subDirectory)
                .Build();

            return path;
        }

        /**
         * Creates a path of a resource.
         */
        std::string ResourcePaths::create(
            const std::string& rootDirectory,
            const std::string& subDirectory,
            const std::string& resourceName)
        {
            ::base::PathBuilder pathBuilder;

            std::string path = pathBuilder
                .addComponent(rootDirectory)
                .addComponent(subDirectory)
                .addComponent(resourceName)
                .Build();

            return path;
        }

        /**
         * Creates a path of a resource.
         */
        std::string ResourcePaths::create(
            const std::string& rootDirectory,
            const std::string& subDirectory1,
            const std::string& subDirectory2,
            const std::string& resourceName)
        {
            ::base::PathBuilder pathBuilder;

            std::string path = pathBuilder
                .addComponent(rootDirectory)
                .addComponent(subDirectory1)
                .addComponent(subDirectory2)
                .addComponent(resourceName)
                .Build();

            return path;
        }

    }
}

#endif // RESOURCE_PATHS_H_0a298836_1a88_40c8_a3b8_4041bd7b2d5a
