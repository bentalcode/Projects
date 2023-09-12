#include "PreCompiled.h"
#include "ResourceReader.h"
#include "ResourcePathBuilder.h"

using namespace base;

/**
 * Creates a new resource reader.
 */
IResourceReaderSharedPtr ResourceReader::make(const std::string& path)
{
    return std::make_shared<ResourceReader>(path);
}

/**
 * The ResourceReader constructor.
 */
ResourceReader::ResourceReader(const std::string& path) :
    m_path(path)
{
    open(m_stream, path);
}

/**
 * The ResourceReader destructor.
 */
ResourceReader::~ResourceReader()
{
    m_stream.close();
}

/**
 * Gets a stream of a resource.
 * Use this API when reading binary streams.
 */
std::ifstream& ResourceReader::getStream()
{
    return m_stream;
}

/**
 * Reads a string.
 * The stream will reach the end after this method is invoked.
 */
std::string ResourceReader::readString()
{
    if (!m_stream.is_open())
    {
        std::string errorMessage = "The resource: " + m_path + " is not opened.";
        throw BaseException(errorMessage);
    }

    std::stringstream content;

    std::string currLine;
    while (getline(m_stream, currLine))
    {
        content << currLine << std::endl;
    }

    return content.str();
}

/**
 * Loads a string.
 */
std::string ResourceReader::loadString(const std::string& path)
{
    ResourceReader reader(path);
    return reader.readString();
}

/**
 * Opens a stream.
 */
void ResourceReader::open(std::ifstream& stream, const std::string& path)
{
    std::string resolvedPath = resolvePath(path);
    stream.open(resolvedPath);

    if (!stream.is_open())
    {
        std::string errorMessage = "The resource: " + resolvedPath + " has failed to get opened for reading.";
        throw BaseException(errorMessage);
    }
}

/**
 * Resolves a path of a resource.
 */
std::string ResourceReader::resolvePath(const std::string& path)
{
    std::string basePath;

    base::ResourcePathBuilder builder;
    std::string result = builder
        .addComponent(path)
        .build();

    return result;
}
