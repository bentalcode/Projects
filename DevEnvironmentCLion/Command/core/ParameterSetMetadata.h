#ifndef PARAMETER_SET_METADATA_H_40e83007_4577_40d7_99f7_8230a17ad6c0
#define PARAMETER_SET_METADATA_H_40e83007_4577_40d7_99f7_8230a17ad6c0

#include "IParameterSetMetadata.h"
#include "IIndexedParameterMetadata.h"
#include "INamedParameterMetadata.h"

namespace command {

    /**
     * The ParameterSetMetadata class implements a metadata of a parameter-set.
     */
    class ParameterSetMetadata final : public IParameterSetMetadata
    {
    public:
        /**
         * Creates help parameter-set.
         */
        static IParameterSetMetadataPtr createHelpParameterSet();

        /**
         * The ParameterSetMetadata constructor.
         */
        ParameterSetMetadata(
            const std::vector<IIndexedParameterMetadataPtr> indexedParameters,
            const std::vector<INamedParameterMetadataPtr> namedParameters);

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
        virtual void getIndexedParameters(std::vector<IIndexedParameterMetadataPtr>& parameters) const override;

        /**
         * Gets named parameters of a parameter-set.
         */
        virtual void getNamedParameters(std::vector<INamedParameterMetadataPtr>& parameters) const override;

        /**
         * Gets the iterator.
         */
        virtual base::IIteratorPtr<const IParameterMetadata*> getIterator() const override;

    private:
        std::vector<IIndexedParameterMetadataPtr> m_indexedParameters;
        std::vector<INamedParameterMetadataPtr> m_namedParameters;
        std::vector<const IParameterMetadata*> m_parameters;
    };
}

#endif // PARAMETER_SET_METADATA_H_40e83007_4577_40d7_99f7_8230a17ad6c0
