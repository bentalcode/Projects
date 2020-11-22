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
        static IIndexedParameterMetadataPtr make(
            const std::string& name,
            const std::string& description);

        /**
         * The IndexedParameterMetadata constructor.
         */
        IndexedParameterMetadata(
            const std::string& name,
            const std::string& description);

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
    };
}

#endif // INDEXED_PARAMETER_METADATA_H_7b8f2e24_b7aa_4f01_9b3e_0640bb825003
