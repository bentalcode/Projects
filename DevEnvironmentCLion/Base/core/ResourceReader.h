#ifndef RESOURCE_READER_H_59b3d34b_4203_4314_bc30_f2e0ffc0904f
#define RESOURCE_READER_H_59b3d34b_4203_4314_bc30_f2e0ffc0904f

#include "IResourceReader.h"
#include <fstream>

namespace base {

    /**
     * The ResourceReader implements a resource reader.
     */
    class ResourceReader final : public IResourceReader
    {
    public:
        /**
         * Creates a new resource reader.
         */
        static IResourceReaderPtr make(const std::string path);

        /**
         * The ResourceReader constructor.
         */
        ResourceReader(const std::string& path);

        /**
         * The ResourceReader destructor.
         */
        virtual ~ResourceReader();

        /**
         * The copy/move constructors.
         */
        ResourceReader(const ResourceReader&) = delete;
        ResourceReader(ResourceReader&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ResourceReader& operator=(const ResourceReader&) = delete;
        ResourceReader& operator=(ResourceReader&&) = delete;

        /**
         * Gets a stream of a resource.
         * Use this API when reading binary streams.
         */
        virtual std::ifstream& getStream() override;

        /**
         * Reads a string.
         * The stream will reach the end after this method is invoked.
         */
        virtual std::string readString() override;

        /**
         * Loads a string.
         */
        static std::string loadString(const std::string& path);

    private:
        /**
         * Opens a stream.
         */
        static void open(std::ifstream& stream, const std::string& path);

        /**
         * Resolves a path of a resource.
         */
        static std::string resolvePath(const std::string& path);


        std::string m_path;
        std::ifstream m_stream;
    };
}

#endif // RESOURCE_READER_H_59b3d34b_4203_4314_bc30_f2e0ffc0904f
