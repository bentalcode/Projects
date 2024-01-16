#ifndef PARSING_RESULT_H_8b2afa42_8a63_4247_9b75_90c2a16adb27
#define PARSING_RESULT_H_8b2afa42_8a63_4247_9b75_90c2a16adb27

#include "IParsingResult.h"

namespace Command
{
    /**
     * The ParsingResult class implements a parsing result.
     */
    template <typename T>
    class ParsingResult final : public IParsingResult<T>
    {
    public:
        /**
         * Creates a new successful result.
         */
        static IParsingResultSharedPtr<T> SuccessfulResult(T result);

        /**
         * Creates a new failure result.
         */
        static IParsingResultSharedPtr<T> FailureResult(const std::wstring& errorMessage);

        /**
         * Creates a new failure result from a previous one.
         */
        template <typename T1>
        static IParsingResultSharedPtr<T> FailureResult(IParsingResultSharedPtr<T1> result)
        {
            return std::make_shared<ParsingResult>(false, nullptr, result->GetErrorMessage());
        }

        /**
         * The ParsingResult constructor.
         */
        ParsingResult(
            bool status,
            T result,
            const std::wstring& errorMessage);

        /**
         * The destructor.
         */
        virtual ~ParsingResult();

        /**
         * The copy/move constructors.
         */
        ParsingResult(const ParsingResult&) = delete;
        ParsingResult(ParsingResult&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ParsingResult& operator=(const ParsingResult&) = delete;
        ParsingResult& operator=(ParsingResult&&) = delete;

        /**
         * Returns if the parsing process succeeded.
         */
        virtual bool Succeeded() const override;

        /**
         * Returns if the parsing process failed.
         */
        virtual bool Failed() const override;

        /**
         * Gets a status of the parsing process.
         */
        virtual bool GetStatus() const override;

        /**
         * Gets a result of the parsing process.
         */
        virtual T GetResult() const override;

        /**
         * Gets an error message of the parsing process.
         */
        virtual const std::wstring& GetErrorMessage() const override;

    private:
        bool m_status;
        T m_result;
        std::wstring m_errorMessage;
    };

    /**
     * Creates a new successful result.
     */
    template <typename T>
    IParsingResultSharedPtr<T> ParsingResult<T>::SuccessfulResult(T result)
    {
        return std::make_shared<ParsingResult>(true, result, L"");
    }

    /**
     * Creates a new failure result.
     */
    template <typename T>
    IParsingResultSharedPtr<T> ParsingResult<T>::FailureResult(const std::wstring& errorMessage)
    {
        return std::make_shared<ParsingResult>(false, nullptr, errorMessage);
    }

    /**
     * The ParsingResult constructor.
     */
    template <typename T>
    ParsingResult<T>::ParsingResult(
        bool status,
        T result,
        const std::wstring& errorMessage) :
        m_status(status),
        m_result(result),
        m_errorMessage(errorMessage)
    {
    }

    /**
     * The destructor.
     */
    template <typename T>
    ParsingResult<T>::~ParsingResult()
    {
    }

    /**
     * Returns if the parsing process succeeded.
     */
    template <typename T>
    bool ParsingResult<T>::Succeeded() const
    {
        return m_status;
    }

    /**
     * Returns if the parsing process failed.
     */
    template <typename T>
    bool ParsingResult<T>::Failed() const
    {
        return !m_status;
    }

    /**
     * Gets a status of the parsing process.
     */
    template <typename T>
    bool ParsingResult<T>::GetStatus() const
    {
        return m_status;
    }

    /**
     * Gets a result of the parsing process.
     */
    template <typename T>
    T ParsingResult<T>::GetResult() const
    {
        return m_result;
    }

    /**
     * Gets an error message of the parsing process.
     */
    template <typename T>
    const std::wstring& ParsingResult<T>::GetErrorMessage() const
    {
        return m_errorMessage;
    }

} // namespace Command

#endif // PARSING_RESULT_H_8b2afa42_8a63_4247_9b75_90c2a16adb27
