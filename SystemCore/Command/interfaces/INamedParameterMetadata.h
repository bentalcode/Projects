#ifndef I_NAMED_PARAMETER_METADATA_H_edf0365e_d4b5_460f_9be2_c0535206213a
#define I_NAMED_PARAMETER_METADATA_H_edf0365e_d4b5_460f_9be2_c0535206213a

#include "IParameterMetadata.h"

namespace command {

    /**
     * The INamedParameterMetadata interface defines meta-data of a named parameter.
     */
    class INamedParameterMetadata
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
         * Gets parameter metadata.
         */
        virtual const IParameterMetadata& GetParameterMetadata() const = 0;

        /**
         * Gets a short name of the parameter.
         */
        virtual const std::wstring& GetShortName() const = 0;

        /**
         * Gets a long name of the parameter.
         */
        virtual const std::wstring& GetLongName() const = 0;

        /**
         * Gets a short name key of the parameter.
         */
        virtual const std::wstring& GetShortNameKey() const = 0;

        /**
         * Gets a long name key of the parameter.
         */
        virtual const std::wstring& GetLongNameKey() const = 0;

        /**
        * Returns whether the parameter is optional.
        */
        virtual bool Optional() const = 0;

        /**
         * Gets the default value.
         */
        virtual const std::wstring& GetDefaultValue() const = 0;
    };

} // namespace command

#endif // I_NAMED_PARAMETER_METADATA_H_edf0365e_d4b5_460f_9be2_c0535206213a
