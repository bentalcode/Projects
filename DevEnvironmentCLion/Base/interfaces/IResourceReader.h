#ifndef I_RESOURCE_READER_H_daebde72_07e6_4f9c_9261_becfcd505d5b
#define I_RESOURCE_READER_H_daebde72_07e6_4f9c_9261_becfcd505d5b

namespace base
{
    /**
     * The IResourceReader interface defines a resource reader.
     */
    class IResourceReader
    {
    public:
        /**
         * The constructor.
         */
        IResourceReader() = default;

        /**
         * The destructor.
         */
        virtual ~IResourceReader() = default;

        /**
         * The copy/move constructors.
         */
        IResourceReader(const IResourceReader&) = delete;
        IResourceReader(IResourceReader&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IResourceReader& operator=(const IResourceReader&) = delete;
        IResourceReader& operator=(IResourceReader&&) = delete;

        /**
         * Gets a stream of a resource.
         * Use this API when reading binary streams.
         */
        virtual std::ifstream& getStream() = 0;

        /**
         * Reads a string.
         * The stream will reach the end after this method is invoked.
         */
        virtual std::string readString() = 0;
    };

    using IResourceReaderPtr = std::shared_ptr<IResourceReader>;
}

#endif // I_RESOURCE_READER_H_daebde72_07e6_4f9c_9261_becfcd505d5b
