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
         * Creates a new parameter.
         */
        static IParameterSharedPtr make(
            const std::wstring& name,
            const std::wstring& value,
            bool defined);

        /**
         * The Parameter constructor.
         */
        Parameter(
            const std::wstring& name,
            const std::wstring& value,
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
        virtual const std::wstring& GetName() const override;

        /**
         * Checks whether the value of the parameter is defined.
         */
        virtual bool IsDefined() const override;

        /**
         * Gets a boolean value of a parameter.
         */
        virtual bool GetBooleanValue() const override;

        /**
         * Gets a short value of a parameter.
         */
        virtual short GetShortValue() const override;

        /**
         * Gets an integer value of a parameter.
         */
        virtual int GetIntegerValue() const override;

        /**
         * Gets a long value of a parameter.
         */
        virtual long GetLongValue() const override;

        /**
         * Gets a float value of a parameter.
         */
        virtual float GetFloatValue() const override;

        /**
         * Gets a size_t value of a parameter.
         */
        virtual size_t GetSizeTValue() const override;

        /**
         * Gets a double value of a parameter.
         */
        virtual double GetDoubleValue() const override;

        /**
         * Gets a character value of a parameter.
         */
        virtual wchar_t GetCharacterValue() const override;

        /**
         * Gets a string value of a parameter.
         */
        virtual const std::wstring& GetStringValue() const override;

        /**
         * Gets a duration value of a parameter.
         */
        virtual base::DurationSharedPtr GetDurationValue() const override;

        /**
         * Gets a string array value of a parameter.
         */
        virtual void GetStringArrayValue(std::vector<std::wstring>& result) const override;

    private:
        std::wstring m_name;
        std::wstring m_value;
        bool m_defined;
    };

    //
    // Defines the SharedPtr of Parameter...
    //
    using IParameterSharedPtr = std::shared_ptr<IParameter>;

} // namespace command

#endif // PARAMETER_H_8af139ca_12c8_4a9a_ba9a_49cf7970f7c4
