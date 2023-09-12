#ifndef I_PARSING_RESULT_H_263cddc4_2091_4baa_ba82_ec78fd33267f
#define I_PARSING_RESULT_H_263cddc4_2091_4baa_ba82_ec78fd33267f

namespace base
{
    /**
     * The IParsingResult interface defines a parsing result.
     */
    template <typename T>
    class IParsingResult
    {
    public:
        /**
         * The constructor.
         */
        IParsingResult() = default;

        /**
         * The destructor.
         */
        virtual ~IParsingResult() = default;

        /**
         * The copy/move constructors.
         */
        IParsingResult(const IParsingResult&) = delete;
        IParsingResult(IParsingResult&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IParsingResult& operator=(const IParsingResult&) = delete;
        IParsingResult& operator=(IParsingResult&&) = delete;

        /**
         * Returns if the parsing process succeeded.
         */
        virtual bool succeeded() const = 0;

        /**
         * Returns if the parsing process failed.
         */
        virtual bool failed() const = 0;

        /**
         * Gets a status of the parsing process.
         */
        virtual bool getStatus() const = 0;

        /**
         * Gets a result of the parsing process.
         */
        virtual T getResult() const = 0;

        /**
         * Gets an error message of the parsing process.
         */
        virtual const std::string& getErrorMessage() const = 0;
    };

    //
    // Defines the SharedPtr of Parsing Result...
    //
    template <typename T>
    using IParsingResultSharedPtr = std::shared_ptr<IParsingResult<T>>;
}

#endif // I_PARSING_RESULT_H_263cddc4_2091_4baa_ba82_ec78fd33267f
