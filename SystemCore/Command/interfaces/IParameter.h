#ifndef I_PARAMETER_b9351446_1760_4431_9260_ae23a3d040bf
#define I_PARAMETER_b9351446_1760_4431_9260_ae23a3d040bf

#include "Duration.h"
#include <vector>

namespace Command {
    class IParameterMetadata;

    /**
     * The IParameter interface defines a parameter.
     */
    class IParameter
    {
    public:
        /**
         * The constructor.
         */
        IParameter() = default;

        /**
         * The destructor.
         */
        virtual ~IParameter() = default;

        /**
         * The copy/move constructors.
         */
        IParameter(const IParameter&) = delete;
        IParameter(IParameter&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IParameter& operator=(const IParameter&) = delete;
        IParameter& operator=(IParameter&&) = delete;

        /**
         * Gets metadata of the parameter.
         */
        virtual const IParameterMetadata& GetMetadata() const = 0;

        /**
         * Checks whether the value of the parameter is defined.
         */
        virtual bool IsDefined() const = 0;

        /**
         * Gets a boolean value of a parameter.
         */
        virtual bool GetBooleanValue() const = 0;

        /**
         * Gets a short value of a parameter.
         */
        virtual short GetShortValue() const = 0;

        /**
         * Gets an integer value of a parameter.
         */
        virtual int GetIntegerValue() const = 0;

        /**
         * Gets a long value of a parameter.
         */
        virtual long GetLongValue() const = 0;

        /**
         * Gets a size_t value of a parameter.
         */
        virtual size_t GetSizeTValue() const = 0;

        /**
         * Gets a float value of a parameter.
         */
        virtual float GetFloatValue() const = 0;

        /**
         * Gets a double value of a parameter.
         */
        virtual double GetDoubleValue() const = 0;

        /**
         * Gets a character value of a parameter.
         */
        virtual wchar_t GetCharacterValue() const = 0;

        /**
         * Gets a string value of a parameter.
         */
        virtual const std::wstring& GetStringValue() const = 0;

        /**
         * Gets a duration value of a parameter.
         */
        virtual base::DurationSharedPtr GetDurationValue() const = 0;

        /**
         * Gets a string array value of a parameter.
         */
        virtual void GetStringArrayValue(std::vector<std::wstring>& value) const = 0;
    };

    //
    // Defines the SharedPtr of Parameter...
    //
    using IParameterSharedPtr = std::shared_ptr<IParameter>;

} // namespace Command

#endif // I_PARAMETER_b9351446_1760_4431_9260_ae23a3d040bf
