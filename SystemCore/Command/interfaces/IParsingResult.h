#ifndef I_PARSING_RESULT_H_263cddc4_2091_4baa_ba82_ec78fd33267f
#define I_PARSING_RESULT_H_263cddc4_2091_4baa_ba82_ec78fd33267f

#include <string>
#include <memory>

namespace Command
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
        virtual bool Succeeded() const = 0;

        /**
         * Returns if the parsing process failed.
         */
        virtual bool Failed() const = 0;

        /**
         * Gets a status of the parsing process.
         */
        virtual bool GetStatus() const = 0;

        /**
         * Gets a result of the parsing process.
         */
        virtual T GetResult() const = 0;

        /**
         * Gets an error message of the parsing process.
         */
        virtual const std::wstring& GetErrorMessage() const = 0;
    };

    //
    // Defines the SharedPtr of Parsing Result...
    //
    template <typename T>
    using IParsingResultSharedPtr = std::shared_ptr<IParsingResult<T>>;

} // namespace Command

#endif // I_PARSING_RESULT_H_263cddc4_2091_4baa_ba82_ec78fd33267f
