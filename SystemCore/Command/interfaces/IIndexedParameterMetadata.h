#ifndef I_INDEXED_PARAMETER_METADATA_H_5bb1cdf8_1336_41eb_854a_c2550e0cb9b7
#define I_INDEXED_PARAMETER_METADATA_H_5bb1cdf8_1336_41eb_854a_c2550e0cb9b7

#include "IParameterMetadata.h"

namespace command {

    /**
     * The IIndexedParameterMetadata interface defines metadata of an index parameter.
     */
    class IIndexedParameterMetadata : public virtual IParameterMetadata
    {
    public:
        /**
         * The constructor.
         */
        IIndexedParameterMetadata() = default;

        /**
         * The destructor.
         */
        virtual ~IIndexedParameterMetadata() = default;

        /**
         * The copy/move constructors.
         */
        IIndexedParameterMetadata(const IIndexedParameterMetadata&) = delete;
        IIndexedParameterMetadata(IIndexedParameterMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IIndexedParameterMetadata& operator=(const IIndexedParameterMetadata&) = delete;
        IIndexedParameterMetadata& operator=(IIndexedParameterMetadata&&) = delete;

        /**
         * Gets parameter metadata.
         */
        virtual const IParameterMetadata& GetParameterMetadata() const = 0;
    };

    //
    // Defines the SharedPtr of Indexed Parameter Metadata...
    //
    using IIndexedParameterMetadataSharedPtr = std::shared_ptr<IIndexedParameterMetadata>;

} // namespace command

#endif // I_INDEXED_PARAMETER_METADATA_H_5bb1cdf8_1336_41eb_854a_c2550e0cb9b7
