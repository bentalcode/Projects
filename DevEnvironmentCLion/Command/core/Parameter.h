#ifndef PARAMETER_H_8af139ca_12c8_4a9a_ba9a_49cf7970f7c4
#define PARAMETER_H_8af139ca_12c8_4a9a_ba9a_49cf7970f7c4

#include "IParameter.h"

namespace command {

    /**
     * The Parameter class implements a parameter.
     */
    class Parameter final : public IParameter
    {
    public:
        /**
         * Creates a help parameter.
         */
        static IParameterPtr createHelpParameter();

        /**
         * Creates a new parameter.
         */
        static IParameterPtr make(
            const std::string& name,
            const std::string& value,
            bool defined);

        /**
         * The Parameter constructor.
         */
        Parameter(
            const std::string& name,
            const std::string& value,
            bool defined);

        /**
         * The destructor.
         */
        virtual ~Parameter();

        /**
         * The copy/move constructors.
         */
        Parameter(const Parameter&) = delete;
        Parameter(Parameter&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        Parameter& operator=(const Parameter&) = delete;
        Parameter& operator=(Parameter&&) = delete;

        /**
         * Gets the name of the parameter.
         */
        virtual const std::string& getName() const override;

        /**
         * Checks whether the value of the parameter is defined.
         */
        virtual bool isDefined() const override;

        /**
         * Gets a boolean value of a parameter.
         */
        virtual bool getBooleanValue() const override;

        /**
         * Gets a short value of a parameter.
         */
        virtual short getShortValue() const override;

        /**
         * Gets an integer value of a parameter.
         */
        virtual int getIntegerValue() const override;

        /**
         * Gets a long value of a parameter.
         */
        virtual long getLongValue() const override;

        /**
         * Gets a float value of a parameter.
         */
        virtual float getFloatValue() const override;

        /**
         * Gets a double value of a parameter.
         */
        virtual double getDoubleValue() const override;

        /**
         * Gets a character value of a parameter.
         */
        virtual char getCharacterValue() const override;

        /**
         * Gets a string value of a parameter.
         */
        virtual const std::string& getStringValue() const override;

        /**
         * Gets a duration value of a parameter.
         */
        virtual base::DurationPtr getDurationValue() const override;

        /**
         * Gets a string array value of a parameter.
         */
        virtual void getStringArrayValue(std::vector<std::string>& result) const override;

    private:
        std::string m_name;
        std::string m_value;
        bool m_defined;
    };

    using IParameterPtr = std::shared_ptr<IParameter>;
}

#endif // PARAMETER_H_8af139ca_12c8_4a9a_ba9a_49cf7970f7c4
