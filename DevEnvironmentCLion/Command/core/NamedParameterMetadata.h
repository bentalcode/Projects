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
        static INamedParameterMetadataPtr make(
            const std::string& name,
            const std::string& shortName,
            const std::string& longName,
            const std::string& description);

        /**
         * Creates an optional parameter meta-data.
         */
        static INamedParameterMetadataPtr makeOptional(
            const std::string& name,
            const std::string& shortName,
            const std::string& longName,
            const std::string& description,
            const std::string& defaultValue);

        /**
         * The NamedParameterMetadata constructor.
         */
        NamedParameterMetadata(
            const std::string& name,
            const std::string& shortName,
            const std::string& longName,
            const std::string& description,
            bool optional,
            const std::string& defaultValue);

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
         * Gets a short name of the parameter.
         */
        virtual const std::string& getShortName() const;

        /**
         * Gets a long name of the parameter.
         */
        virtual const std::string& getLongName() const;

        /**
         * Gets a short name key of the parameter.
         */
        virtual const std::string& getShortNameKey() const;

        /**
         * Gets a long name key of the parameter.
         */
        virtual const std::string& getLongNameKey() const;

        /**
        * Returns whether the parameter is optional.
        */
        virtual bool optional() const;

        /**
         * Gets the default value.
         */
        virtual const std::string& getDefaultValue() const;

    private:
        std::string m_shortName;
        std::string m_longName;
        std::string m_shortNameKey;
        std::string m_longNameKey;
        bool m_optional;
        std::string m_defaultValue;
    };
}

#endif // NAMED_PARAMETER_METADATA_H_b2cddf38_a9c6_44c8_a2ff_9ebc28031ae3
