#ifndef I_PARAMETER_SET_METADATA_H_H_31a8df57_dd05_4fae_81d9_88273fdb5832
#define I_PARAMETER_SET_METADATA_H_H_31a8df57_dd05_4fae_81d9_88273fdb5832

#include "IIndexedParameterMetadata.h"
#include "INamedParameterMetadata.h"
#include "IIterable.h"

namespace command {

    /**
     * The IParameterSetMetadata interface defines a metadata of a parameter set.
     */
    class IParameterSetMetadata : public base::IIterable<const IParameterMetadata*>
    {
    public:
        /**
         * The constructor.
         */
        IParameterSetMetadata() = default;

        /**
         * The destructor.
         */
        virtual ~IParameterSetMetadata() = default;

        /**
         * The copy/move constructors.
         */
        IParameterSetMetadata(const IParameterSetMetadata&) = delete;
        IParameterSetMetadata(IParameterSetMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IParameterSetMetadata& operator=(const IParameterSetMetadata&) = delete;
        IParameterSetMetadata& operator=(IParameterSetMetadata&&) = delete;

        /**
         * Gets indexed parameters of a parameter-set.
         */
        virtual void getIndexedParameters(std::vector<IIndexedParameterMetadataPtr>& parameters) const = 0;

        /**
         * Gets named parameters of a parameter-set.
         */
        virtual void getNamedParameters(std::vector<INamedParameterMetadataPtr>& parameters) const = 0;
    };

    using IParameterSetMetadataPtr = std::shared_ptr<IParameterSetMetadata>;
}

#endif // I_PARAMETER_SET_METADATA_H_H_31a8df57_dd05_4fae_81d9_88273fdb5832
