#ifndef PARAMETER_METADATA_H_44292319_2df4_4668_97a8_53704e85b8bf
#define PARAMETER_METADATA_H_44292319_2df4_4668_97a8_53704e85b8bf

#include "IParameterMetadata.h"

namespace Command {

    /**
     * The ParameterMetadata abstract base class implements meta-data of a parameter.
     */
    class ParameterMetadata : public virtual IParameterMetadata
    {
    public:
        /**
         * The ParameterMetadata constructor.
         */
        ParameterMetadata(
            const std::wstring& name,
            const std::wstring& description);

        /**
         * The ParameterMetadata destructor.
         */
        virtual ~ParameterMetadata() = 0;

        /**
         * The copy/move constructors.
         */
        ParameterMetadata(const ParameterMetadata&) = delete;
        ParameterMetadata(ParameterMetadata&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ParameterMetadata& operator=(const ParameterMetadata&) = delete;
        ParameterMetadata& operator=(ParameterMetadata&&) = delete;

        /**
         * Gets name of a parameter.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Gets description of a parameter.
         */
        virtual const std::wstring& GetDescription() const override;

        /**
         * Try to parse value.
         */
        virtual bool TryParseValue(
            const std::map<std::wstring, std::wstring>& parameters,
            std::wstring& value) const override;

    private:
        std::wstring m_name;
        std::wstring m_description;
    };

} // namespace Command

#endif // PARAMETER_METADATA_H_44292319_2df4_4668_97a8_53704e85b8bf
