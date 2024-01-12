#ifndef NAMED_PARAMETER_METADATA_H_b2cddf38_a9c6_44c8_a2ff_9ebc28031ae3
#define NAMED_PARAMETER_METADATA_H_b2cddf38_a9c6_44c8_a2ff_9ebc28031ae3

#include "INamedParameterMetadata.h"
#include "ParameterMetadata.h"

namespace command {

    /**
     * The NamedParameterMetadata class implements meta-data of a named parameter.
     */
    class NamedParameterMetadata final : public ParameterMetadata, public INamedParameterMetadata
    {
    public:
        /**
         * Creates a parameter meta-data.
         */
        static IParameterMetadataSharedPtr Make(
            const std::wstring& name,
            const std::wstring& shortName,
            const std::wstring& longName,
            const std::wstring& description);

        /**
         * Creates an Optional parameter meta-data.
         */
        static IParameterMetadataSharedPtr MakeOptional(
            const std::wstring& name,
            const std::wstring& shortName,
            const std::wstring& longName,
            const std::wstring& description,
            const std::wstring& defaultValue);

        /**
         * The NamedParameterMetadata constructor.
         */
        NamedParameterMetadata(
            const std::wstring& name,
            const std::wstring& shortName,
            const std::wstring& longName,
            const std::wstring& description,
            bool optional,
            const std::wstring& defaultValue);

        /**
         * The destructor.
         */
        virtual ~NamedParameterMetadata();

        /**
         * The copy/move constructors.
         */
        NamedParameterMetadata(const NamedParameterMetadata&) = delete;
        NamedParameterMetadata(NamedParameterMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        NamedParameterMetadata& operator=(const NamedParameterMetadata&) = delete;
        NamedParameterMetadata& operator=(NamedParameterMetadata&&) = delete;

        /**
         * Gets parameter metadata.
         */
        const IParameterMetadata& GetParameterMetadata() const override;

        /**
         * Gets a short name of the parameter.
         */
        virtual const std::wstring& GetShortName() const override;

        /**
         * Gets a long name of the parameter.
         */
        virtual const std::wstring& GetLongName() const override;

        /**
         * Gets a short name key of the parameter.
         */
        virtual const std::wstring& GetShortNameKey() const override;

        /**
         * Gets a long name key of the parameter.
         */
        virtual const std::wstring& GetLongNameKey() const override;

        /**
        * Returns whether the parameter is Optional.
        */
        virtual bool Optional() const override;

        /**
         * Gets the default value.
         */
        virtual const std::wstring& GetDefaultValue() const override;

    private:
        std::wstring m_shortName;
        std::wstring m_longName;
        std::wstring m_shortNameKey;
        std::wstring m_longNameKey;
        bool m_optional;
        std::wstring m_defaultValue;
    };

} // namespace command

#endif // NAMED_PARAMETER_METADATA_H_b2cddf38_a9c6_44c8_a2ff_9ebc28031ae3
