#ifndef I_PARSER_H_9a3b0f34_296b_4f64_8a07_829eb1cda7e4
#define I_PARSER_H_9a3b0f34_296b_4f64_8a07_829eb1cda7e4

#include "IParsingResult.h"

namespace command
{
    /**
     * The IParser interface defines a generic parser.
     */
    template <typename T, typename TResult>
    class IParser
    {
    public:
        /**
         * The constructor.
         */
        IParser() = default;

        /**
         * The destructor.
         */
        virtual ~IParser() = default;

        /**
         * The copy/move constructors.
         */
        IParser(const IParser&) = delete;
        IParser(IParser&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IParser& operator=(const IParser&) = delete;
        IParser& operator=(IParser&&) = delete;

        /**
         * Parses an object.
         */
        virtual IParsingResultSharedPtr<TResult> Parse(const T& obj) = 0;
    };

    //
    // Defines the Shared Ptr of Parser...
    //
    template <typename T, typename TResult>
    using IParserSharedPtr = std::shared_ptr<IParser<T, TResult>>;

} // namespace command

#endif // I_PARSER_H_9a3b0f34_296b_4f64_8a07_829eb1cda7e4
