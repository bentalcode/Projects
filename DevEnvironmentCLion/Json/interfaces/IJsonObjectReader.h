#ifndef I_JSON_OBJECT_READER_H_1ba919f5_ecab_4880_b939_7112695f92fe
#define I_JSON_OBJECT_READER_H_1ba919f5_ecab_4880_b939_7112695f92fe

#include "IFromString.h"
#include "DateTime.h"
#include "Duration.h"

namespace json
{
    /**
     * The IJsonObjectReader interface defines a reader of a json object.
     */
    class IJsonObjectReader
    {
    public:
        /**
         * The constructor.
         */
        IJsonObjectReader() = default;

        /**
         * The destructor.
         */
        virtual ~IJsonObjectReader() = default;

        /**
         * The copy/move constructors.
         */
        IJsonObjectReader(const IJsonObjectReader&) = delete;
        IJsonObjectReader(IJsonObjectReader&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IJsonObjectReader& operator=(const IJsonObjectReader&) = delete;
        IJsonObjectReader& operator=(IJsonObjectReader&&) = delete;

        /**
         * Determines whether the property exists.
         */
        virtual bool hasProperty(const std::string& name) const = 0;

        /**
         * Reads a boolean property.
         */
        virtual bool readBooleanProperty(const std::string& name) const = 0;

        /**
         * Reads a short property.
         */
        virtual short readShortProperty(const std::string& name) const = 0;

        /**
         * Reads an integer property.
         */
        virtual int readIntegerProperty(const std::string& name) const = 0;

        /**
         * Reads a long property.
         */
        virtual long readLongProperty(const std::string& name) const = 0;

        /**
         * Reads a float property.
         */
        virtual float readFloatProperty(const std::string& name) const = 0;

        /**
         * Reads a double property.
         */
        virtual double readDoubleProperty(const std::string& name) const = 0;

        /**
         * Reads a string property.
         */
        virtual std::string readStringProperty(const std::string& name) const = 0;

        /**
         * Reads a generic property with a transformer.
         */
        template <typename T>
        virtual T readProperty(
            const std::string& name,
            const base::IFromString<T>& transformer) const = 0;

        /**
         * Reads a boolean array property.
         */
        virtual void readBooleanArrayProperty(
            const std::string& name,
            std::vector<bool>& result) const = 0;

        /**
         * Reads a short array property.
         */
        virtual void readShortArrayProperty(
            const std::string& name,
            std::vector<short>& result) const = 0;

        /**
         * Reads an integer array property.
         */
        virtual void readIntegerArrayProperty(
            const std::string& name,
            std::vector<int>& result) const = 0;

        /**
         * Reads a long array property.
         */
        virtual void readLongArrayProperty(
            const std::string& name,
            std::vector<long>& result) const = 0;

        /**
         * Reads a float array property.
         */
        virtual void readFloatArrayProperty(
            const std::string& name,
            std::vector<float>& result) const = 0;

        /**
         * Reads a double array property.
         */
        virtual void readDoubleArrayProperty(
            const std::string& name,
            std::vector<double>& result) const = 0;

        /**
         * Reads a string array property.
         */
        virtual void readStringArrayProperty(
            const std::string& name,
            std::vector<std::string>& result) const = 0;

        /**
         * Reads a string list property.
         */
        virtual void readStringListProperty(
            const std::string& name,
            std::list<std::string>& result) const = 0;

        /**
         * Reads a string set property.
         */
        virtual void readStringSetProperty(
            const std::string& name,
            std::set<std::string>& result) const = 0;

        /**
         * Reads a string map property.
         */
        virtual void readStringMapProperty(
            const std::string& name,
            std::map<std::string, std::string>& result) const = 0;

        /**
         * Reads a blob property.
         */
        virtual void readBlobProperty(
            const std::string& name,
            std::vector<std::byte>& result) const = 0;

        /**
         * Reads a date property.
         */
        virtual base::DateTimePtr readDateProperty(const std::string& name) const = 0;

        /**
         * Reads a duration property.
         */
        virtual base::DurationPtr readDurationProperty(const std::string& name) const = 0;

        /**
         * Reads a generic object property.
         * T implements IJsonSerialization.
         */
        template <typename T>
        T readObjectProperty(const std::string& name);

        /**
         * Reads a generic vector property.
         * T implements IJsonSerialization.
         */
        template <typename T>
        void readVectorProperty(
            const std::string& name,
            std::vector<T>& result);

        /**
         * Reads a generic list property.
         * T implements IJsonSerialization.
         */
        template <typename T>
        void readListProperty(
            const std::string& name,
            std::list<T>& result);

        /**
         * Reads a generic set property.
         * T implements IJsonSerialization.
         */
        template <typename T>
        void readSetProperty(
            const std::string& name,
            std::set<T>& result);

        /**
         * Reads a generic vector property with a transformer.
         */
        template <typename T>
        void readVectorProperty(
            const std::string& name,
            const base::IFromString<T>& transformer,
            std::vector<T>& result);

        /**
         * Reads a generic list property with a transformer.
         */
        template <typename T>
        void readListProperty(
            const std::string& name,
            const base::IFromString<T>& transformer,
            std::list<T>& result);

        /**
         * Reads a generic set property with a transformer.
         */
        template <typename T>
        void readSetProperty(
            const std::string& name,
            const base::IFromString<T>& transformer,
            std::set<T>& result);

        /**
         * Reads a generic map property with key and value transformers.
         */
        template <typename TKey, typename TValue>
        void readMapProperty(
            const std::string& name,
            const base::IFromString<TKey>& keyTransformer,
            const base::IFromString<TValue>& valueTransformer,
            std::map<TKey, TValue>& result);
    };

    using IJsonObjectReaderPtr = std::shared_ptr<IJsonObjectReader>;
}

#endif // I_JSON_OBJECT_READER_H_1ba919f5_ecab_4880_b939_7112695f92fe
