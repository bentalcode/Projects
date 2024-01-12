#ifndef INDEXED_PARAMETER_METADATA_H_7b8f2e24_b7aa_4f01_9b3e_0640bb825003
#define INDEXED_PARAMETER_METADATA_H_7b8f2e24_b7aa_4f01_9b3e_0640bb825003

#include "IIndexedParameterMetadata.h"
#include "ParameterMetadata.h"

namespace command {

    /**
     * The IndexedParameterMetadata class implements meta-data of an indexed parameter.
     */
    class IndexedParameterMetadata final : public ParameterMetadata, public IIndexedParameterMetadata
    {
    public:
        /**
         * Creates an indexed parameter meta-data.
         */
        static IParameterMetadataSharedPtr Make(
            const std::wstring& name,
            const std::wstring& description);

        /**
         * The IndexedParameterMetadata constructor.
         */
        IndexedParameterMetadata(
            const std::wstring& name,
            const std::wstring& description);

        /**
         * The destructor.
         */
        virtual ~IndexedParameterMetadata();

        /**
         * The copy/move constructors.
         */
        IndexedParameterMetadata(const IndexedParameterMetadata&) = delete;
        IndexedParameterMetadata(IndexedParameterMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IndexedParameterMetadata& operator=(const IndexedParameterMetadata&) = delete;
        IndexedParameterMetadata& operator=(IndexedParameterMetadata&&) = delete;

        /**
         * Gets parameter metadata.
         */
        virtual const IParameterMetadata& GetParameterMetadata() const override;
    };

} // namespace command

#endif // INDEXED_PARAMETER_METADATA_H_7b8f2e24_b7aa_4f01_9b3e_0640bb825003
