#ifndef I_JSON_OBJECT_WRITER_H_aaada994_33b0_4597_aa9c_d21d00f1d471
#define I_JSON_OBJECT_WRITER_H_aaada994_33b0_4597_aa9c_d21d00f1d471

#include "DateTime.h"
#include "Duration.h"
#include "IJsonSerialization.h"

namespace json
{
    /**
     * The IJsonObjectWriter interface defines a writer of a json object.
     */
    class IJsonObjectWriter
    {
    public:
        /**
         * The constructor.
         */
        IJsonObjectWriter() = default;

        /**
         * The destructor.
         */
        virtual ~IJsonObjectWriter() = default;

        /**
         * The copy/move constructors.
         */
        IJsonObjectWriter(const IJsonObjectWriter&) = delete;
        IJsonObjectWriter(IJsonObjectWriter&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IJsonObjectWriter& operator=(const IJsonObjectWriter&) = delete;
        IJsonObjectWriter& operator=(IJsonObjectWriter&&) = delete;

        /**
         * Writes a boolean property.
         */
        virtual void writeBooleanProperty(
            const std::string& name,
            bool value) = 0;

        /**
         * Writes a byte property.
         */
        virtual void writeByteProperty(
            const std::string& name,
            std::byte value) = 0;

        /**
         * Writes a short property.
         */
        virtual void writeShortProperty(
            const std::string& name,
            short value) = 0;

        /**
         * Writes an integer property.
         */
        virtual void writeIntegerProperty(
            const std::string& name,
            int value) = 0;

        /**
         * Writes a long property.
         */
        virtual void writeLongProperty(
            const std::string& name,
            long value) = 0;

        /**
         * Writes a float property.
         */
        virtual void writeFloatProperty(
            const std::string& name,
            float value) = 0;

        /**
         * Writes a double property.
         */
        virtual void writeDoubleProperty(
            const std::string& name,
            double value) = 0;

        /**
         * Writes a string property.
         */
        virtual void writeStringProperty(
            const std::string& name,
            const std::string& value) = 0;

        /**
         * Writes a boolean vector property.
         */
        virtual void writeVectorProperty(
            const std::string& name,
            const std::vector<bool>& vector) = 0;

        /**
         * Writes a byte vector property.
         */
        virtual void writeVectorProperty(
            const std::string& name,
            const std::vector<std::byte>& vector) = 0;

        /**
         * Writes a short vector property.
         */
        virtual void writeVectorProperty(
            const std::string& name,
            const std::vector<short>& vector) = 0;

        /**
         * Writes an integer array property.
         */
        virtual void writeVectorProperty(
            const std::string& name,
            const std::vector<int>& vector) = 0;

        /**
         * Writes a long array property.
         */
        virtual void writeVectorProperty(
            const std::string& name,
            const std::vector<long>& vector) = 0;

        /**
         * Writes a float vector property.
         */
        virtual void writeVectorProperty(
            const std::string& name,
            const std::vector<float>& vector) = 0;

        /**
         * Writes a double vector property.
         */
        virtual void writeVectorProperty(
            const std::string& name,
            const std::vector<double>& vector) = 0;

        /**
         * Writes a string vector property.
         */
        virtual void writeVectorProperty(
            const std::string& name,
            const std::vector<std::string>& vector) = 0;

        /**
         * Writes a date property.
         */
        virtual void writeDateProperty(
            const std::string& name,
            const base::DateTime& dateTime) = 0;

        /**
         * Writes a duration property.
         */
        virtual void writeDurationProperty(
            const std::string& name,
            const base::Duration& duration) = 0;

        /**
         * Writes a generic object property.
         */
        virtual void writeObjectProperty(
            const std::string& name,
            const IJsonSerialization& object) = 0;

        /**
         * Writes a generic vector property.
         * T implements IJsonSerialization.
         */
        template <typename T>
        virtual void writeVectorProperty(
            const std::string& name,
            const std::vector<T>& vector) = 0;

        /**
         * Writes a generic list property.
         * T implements IJsonSerialization.
         */
        template <typename T>
        virtual void writeListProperty(
            const std::string& name,
            const std::list<T>& list) = 0;

        /**
         * Writes a generic set property.
         * T implements IJsonSerialization.
         */
        template <typename T>
        virtual void writeSetProperty(
            const std::string& name,
            const std::set<T>& set) = 0;

        /**
         * Writes a generic vector property with a transformer.
         */
        template <typename T>
        virtual void writeVectorProperty(
            const std::string& name,
            const std::vector<T>& vector,
            const base::IToString<T>& transformer) = 0;

        /**
         * Writes a generic list property with a transformer.
         */
        template <typename T>
        virtual void writeVectorProperty(
            const std::string& name,
            const std::list<T>& vector,
            const base::IToString<T>& transformer) = 0;

        /**
         * Writes a generic set property with a transformer.
         */
        template <typename T>
        virtual void writeVectorProperty(
            const std::string& name,
            const std::set<T>& vector,
            const base::IToString<T>& transformer) = 0;

        /**
         * Writes a string map property.
         */
        virtual void writeMapProperty(
            const std::string& name,
            const std::map<std::string, std::string>& map) = 0;

        /**
         * Writes a map property with key and value transformers.
         */
        template <typename TKey, typename TValue>
        virtual void writeMapProperty(
            const std::string& name,
            const std::map<TKey, TValue>& map,
            const IToString<TKey>& keyTransformer,
            const IToString<TValue>& valueTransformer) = 0;
    };

    using IJsonObjectWriterPtr = std::shared_ptr<IJsonObjectWriter>;
}

#endif // I_JSON_OBJECT_WRITER_H_aaada994_33b0_4597_aa9c_d21d00f1d471
