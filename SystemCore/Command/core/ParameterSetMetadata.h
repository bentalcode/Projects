#ifndef PARAMETER_SET_METADATA_H_40e83007_4577_40d7_99f7_8230a17ad6c0
#define PARAMETER_SET_METADATA_H_40e83007_4577_40d7_99f7_8230a17ad6c0

#include "IParameterSetMetadata.h"
#include "IIndexedParameterMetadata.h"
#include "INamedParameterMetadata.h"

namespace Command {

    /**
     * The ParameterSetMetadata class implements a metadata of a parameter-set.
     */
    class ParameterSetMetadata final : public IParameterSetMetadata
    {
    public:
        /**
         * Creates parameter set metadata.
         */
        static IParameterSetMetadataSharedPtr Make(
            const std::vector<IParameterMetadataSharedPtr> indexedParameters,
            const std::vector<IParameterMetadataSharedPtr> namedParameters);

        /**
         * Creates help parameter-set metadata.
         */
        static IParameterSetMetadataSharedPtr CreateHelpMetadata();

        /**
         * The ParameterSetMetadata constructor.
         */
        ParameterSetMetadata(
            const std::vector<IParameterMetadataSharedPtr> indexedParameters,
            const std::vector<IParameterMetadataSharedPtr> namedParameters);

        /**
         * The destructor.
         */
        virtual ~ParameterSetMetadata();

        /**
         * The copy/move constructors.
         */
        ParameterSetMetadata(const ParameterSetMetadata&) = delete;
        ParameterSetMetadata(ParameterSetMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ParameterSetMetadata& operator=(const ParameterSetMetadata&) = delete;
        ParameterSetMetadata& operator=(ParameterSetMetadata&&) = delete;

        /**
         * Gets indexed parameters of a parameter-set.
         */
        virtual void GetIndexedParameters(std::vector<IParameterMetadataSharedPtr>& parameters) const override;

        /**
         * Gets named parameters of a parameter-set.
         */
        virtual void GetNamedParameters(std::vector<IParameterMetadataSharedPtr>& parameters) const override;

        /**
         * Gets the iterator.
         */
        virtual base::IIteratorSharedPtr<IParameterMetadataSharedPtr> GetIterator() const override;

    private:
        std::vector<IParameterMetadataSharedPtr> m_indexedParameters;
        std::vector<IParameterMetadataSharedPtr> m_namedParameters;
        std::vector<IParameterMetadataSharedPtr> m_parameters;
    };

} // namespace Command

#endif // PARAMETER_SET_METADATA_H_40e83007_4577_40d7_99f7_8230a17ad6c0
