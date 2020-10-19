#ifndef I_PARAMETER_b9351446_1760_4431_9260_ae23a3d040bf
#define I_PARAMETER_b9351446_1760_4431_9260_ae23a3d040bf

#include "Duration.h"

namespace command {

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
         * Gets the name of the parameter.
         */
        virtual const std::string& getName() const = 0;

        /**
         * Checks whether the value of the parameter is defined.
         */
        virtual bool isDefined() const = 0;

        /**
         * Gets a boolean value of a parameter.
         */
        virtual bool getBooleanValue() const = 0;

        /**
         * Gets a short value of a parameter.
         */
        virtual short getShortValue() const = 0;

        /**
         * Gets an integer value of a parameter.
         */
        virtual int getIntegerValue() const = 0;

        /**
         * Gets a long value of a parameter.
         */
        virtual long getLongValue() const = 0;

        /**
         * Gets a float value of a parameter.
         */
        virtual float getFloatValue() const = 0;

        /**
         * Gets a double value of a parameter.
         */
        virtual double getDoubleValue() const = 0;

        /**
         * Gets a character value of a parameter.
         */
        virtual char getCharacterValue() const = 0;

        /**
         * Gets a string value of a parameter.
         */
        virtual const std::string& getStringValue() const = 0;

        /**
         * Gets a duration value of a parameter.
         */
        virtual base::DurationPtr getDurationValue() const = 0;

        /**
         * Gets a string array value of a parameter.
         */
        virtual void getStringArrayValue(std::vector<std::string>& result) const = 0;
    };

    using IParameterPtr = std::shared_ptr<IParameter>;
}

#endif // I_PARAMETER_b9351446_1760_4431_9260_ae23a3d040bf
