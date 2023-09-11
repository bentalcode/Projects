#ifndef I_NAMED_PARAMETER_METADATA_H_edf0365e_d4b5_460f_9be2_c0535206213a
#define I_NAMED_PARAMETER_METADATA_H_edf0365e_d4b5_460f_9be2_c0535206213a

#include "IParameterMetadata.h"

namespace command {

    /**
     * The INamedParameterMetadata interface defines meta-data of a named parameter.
     */
    class INamedParameterMetadata : public virtual IParameterMetadata
    {
    public:
        /**
         * The constructor.
         */
        INamedParameterMetadata() = default;

        /**
         * The destructor.
         */
        virtual ~INamedParameterMetadata() = default;

        /**
         * The copy/move constructors.
         */
        INamedParameterMetadata(const INamedParameterMetadata&) = delete;
        INamedParameterMetadata(INamedParameterMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        INamedParameterMetadata& operator=(const INamedParameterMetadata&) = delete;
        INamedParameterMetadata& operator=(INamedParameterMetadata&&) = delete;

        /**
         * Gets a short name of the parameter.
         */
        virtual const std::string& getShortName() const = 0;

        /**
         * Gets a long name of the parameter.
         */
        virtual const std::string& getLongName() const = 0;

        /**
         * Gets a short name key of the parameter.
         */
        virtual const std::string& getShortNameKey() const = 0;

        /**
         * Gets a long name key of the parameter.
         */
        virtual const std::string& getLongNameKey() const = 0;

        /**
        * Returns whether the parameter is optional.
        */
        virtual bool optional() const = 0;

        /**
         * Gets the default value.
         */
        virtual const std::string& getDefaultValue() const = 0;
    };

    using INamedParameterMetadataPtr = std::shared_ptr<INamedParameterMetadata>;

}

#endif // I_NAMED_PARAMETER_METADATA_H_edf0365e_d4b5_460f_9be2_c0535206213a
