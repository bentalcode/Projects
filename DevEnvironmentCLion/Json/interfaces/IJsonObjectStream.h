#ifndef I_JSON_OBJECT_STREAM_H_6006acf3_1433_4f31_b7d8_9450f7888851
#define I_JSON_OBJECT_STREAM_H_6006acf3_1433_4f31_b7d8_9450f7888851

namespace json
{
    /**
     * The IJsonObjectStream interface defines a json stream for an object.
     */
    class IJsonObjectStream
    {
    public:
        /**
         * The constructor.
         */
        IJsonObjectStream() = default;

        /**
         * The destructor.
         */
        virtual ~IJsonObjectStream() = default;

        /**
         * The copy/move constructors.
         */
        IJsonObjectStream(const IJsonObjectStream&) = delete;
        IJsonObjectStream(IJsonObjectStream&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IJsonObjectStream& operator=(const IJsonObjectStream&) = delete;
        IJsonObjectStream& operator=(IJsonObjectStream&&) = delete;

        /**
         * Serializes an object to a json string.
         */
        template <typename T>
        virtual std::string toJson(const T& obj) = 0;

        /**
         * De-Serializes an object from a json string.
         */
        template <typename T>
        virtual std::shared_ptr<T> fromJson(const std::string& json) = 0;
    };

    using IJsonObjectStreamPtr = std::shared_ptr<IJsonObjectStream>;
}

#endif // I_JSON_OBJECT_STREAM_H_6006acf3_1433_4f31_b7d8_9450f7888851
