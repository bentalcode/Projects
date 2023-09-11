#ifndef I_PROPERTY_TYPE_H_920e0871_878b_4dd1_880e_66e9dbc6f107
#define I_PROPERTY_TYPE_H_920e0871_878b_4dd1_880e_66e9dbc6f107

#include "IJsonSerialization.h"

using namespace json;

namespace test {
    namespace json
    {
        /**
         * The IPropertyType interface defines various types of a property.
         */
        class IPropertyType : public IJsonSerialization
        {
        public:
            /**
             * The constructor.
             */
            IPropertyType() = default;

            /**
             * The destructor.
             */
            virtual ~IPropertyType() = default;

            /**
             * The copy/move constructors.
             */
            IPropertyType(const IPropertyType&) = delete;
            IPropertyType(IPropertyType&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IPropertyType& operator=(const IPropertyType&) = delete;
            IPropertyType& operator=(IPropertyType&&) = delete;

            /**
             * Gets a boolean property.
             */
            virtual bool getBooleanProperty() const = 0;

            /**
             * Gets a short property.
             */
            virtual short getShortProperty() const = 0;

            /**
             * Gets an integer property.
             */
            virtual int getIntegerProperty() const = 0;

            /**
             * Gets a long property.
             */
            virtual long getLongProperty() const = 0;

            /**
             * Gets a float value.
             */
            virtual float getFloatProperty() const = 0;

            /**
             * Gets a double property.
             */
            virtual double getDoubleProperty() const = 0;

            /**
             * Gets a string property.
             */
            virtual const std::string& getStringProperty() const = 0;

            /**
             * Gets a boolean array property.
             */
            virtual const std::vector<bool>& getBooleanArrayProperty() const = 0;

            /**
             * Gets a short array property.
             */
            virtual const std::vector<short>& getShortArrayProperty() const = 0;;

            /**
             * Gets an integer array property.
             */
            virtual const std::vector<int>& getIntegerArrayProperty() const = 0;

            /**
             * Gets a long array property.
             */
            virtual const std::vector<long>& getLongArrayProperty() const = 0

            /**
             * Gets a float array property.
             */
            virtual const std::vector<float>& getFloatArrayProperty() const = 0;

            /**
             * Gets a double array property.
             */
            virtual const std::vector<double>& getDoubleArrayProperty() const = 0;

            /**
             * Gets a string array property.
             */
            virtual const std::vector<std::string>& getStringArrayProperty() const = 0;

            /**
             * Gets a blob property.
             */
            virtual const std::vector<std::byte>& getBlobProperty() const = 0;
        };

        using IPropertyTypePtr = std::shared_ptr<IPropertyType>;
    }
}

#endif // I_PROPERTY_TYPE_H_920e0871_878b_4dd1_880e_66e9dbc6f107
