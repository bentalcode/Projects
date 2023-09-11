#ifndef PARAMETER_METADATA_H_44292319_2df4_4668_97a8_53704e85b8bf
#define PARAMETER_METADATA_H_44292319_2df4_4668_97a8_53704e85b8bf

#include "IParameterMetadata.h"

namespace command {

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
            const std::string& name,
            const std::string& description);

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
        virtual const std::string& getName() const override;

        /**
         * Gets description of a parameter.
         */
        virtual const std::string& getDescription() const override;

    private:
        std::string m_name;
        std::string m_description;
    };
}

#endif // PARAMETER_METADATA_H_44292319_2df4_4668_97a8_53704e85b8bf
