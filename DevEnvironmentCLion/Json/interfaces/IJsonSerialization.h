#ifndef I_JSON_SERIALIZATION_H_5095abab_87b5_42fe_9bb9_d09925af3352
#define I_JSON_SERIALIZATION_H_5095abab_87b5_42fe_9bb9_d09925af3352

#include "IJsonObjectWriter.h"

namespace json
{
    /**
     * The IJsonSerialization interface defines a json serialization object.
     */
    class IJsonSerialization
    {
    public:
        /**
         * The constructor.
         */
        IJsonSerialization() = default;

        /**
         * The destructor.
         */
        virtual ~IJsonSerialization() = default;

        /**
         * The copy/move constructors.
         */
        IJsonSerialization(const IJsonSerialization&) = delete;
        IJsonSerialization(IJsonSerialization&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IJsonSerialization& operator=(const IJsonSerialization&) = delete;
        IJsonSerialization& operator=(IJsonSerialization&&) = delete;

        /**
         * Writes an object to a json writer.
         */
        virtual void writeJson(IJsonObjectWriter& writer) = 0;
    };

    //
    // Defines the SharedPtr of Json Serialization...
    //
    using IJsonSerializationSharedPtr = std::shared_ptr<IJsonSerialization>;
}

#endif // I_JSON_SERIALIZATION_H_5095abab_87b5_42fe_9bb9_d09925af3352
