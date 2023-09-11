#ifndef I_PARAMETER_METADATA_H_fbec8048_3517_4c85_ab1e_585d55896b41
#define I_PARAMETER_METADATA_H_fbec8048_3517_4c85_ab1e_585d55896b41

namespace command {

    /**
     * The IParameterMetadata interface defines metadata of a parameter.
     */
    class IParameterMetadata
    {
    public:
        /**
         * The constructor.
         */
        IParameterMetadata() = default;

        /**
         * The destructor.
         */
        virtual ~IParameterMetadata() = default;

        /**
         * The copy/move constructors.
         */
        IParameterMetadata(const IParameterMetadata&) = delete;
        IParameterMetadata(IParameterMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IParameterMetadata& operator=(const IParameterMetadata&) = delete;
        IParameterMetadata& operator=(IParameterMetadata&&) = delete;

        /**
         * Gets name of a parameter.
         */
        virtual const std::string& getName() const = 0;

        /**
         * Gets description of a parameter.
         */
        virtual const std::string& getDescription() const = 0;
    };

    using IParameterMetadataPtr = std::shared_ptr<IParameterMetadata>;
}

#endif // I_PARAMETER_METADATA_H_fbec8048_3517_4c85_ab1e_585d55896b41
