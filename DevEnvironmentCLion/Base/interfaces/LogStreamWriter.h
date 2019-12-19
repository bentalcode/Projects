#ifndef LOG_STREAM_WRITER_H_9932cee8_215f_4c9b_ac33_7b4af1bbf238
#define LOG_STREAM_WRITER_H_9932cee8_215f_4c9b_ac33_7b4af1bbf238

namespace base
{
    class LogStreamWriter;
    using LogStreamWriterPtr = std::shared_ptr<LogStreamWriter>;

    /**
     * The LogStreamWriter class implements a writer to a log stream.
     */
    class LogStreamWriter final
    {
    public:
        /**
         * The LogStreamWriter default constructor.
         */
        LogStreamWriter();

        /**
         * The constructor.
         */
        LogStreamWriter(
            std::ostream& errorStream,
            std::ostream& warningStream,
            std::ostream& informationalStream,
            std::ostream& debugStream);

        /**
         * The destructor.
         */
        ~LogStreamWriter();

        /**
         * The copy/move constructors.
         */
        LogStreamWriter(const LogStreamWriter&) = delete;
        LogStreamWriter(LogStreamWriter&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        LogStreamWriter& operator=(const LogStreamWriter&) = delete;
        LogStreamWriter& operator=(LogStreamWriter&&) = delete;

        /**
         * Gets an error stream.
         */
        inline std::ostream& getErrorStream() const;

        /**
         * Gets a warning stream.
         */
        inline std::ostream& getWarningStream() const;

        /**
         * Gets an informational stream.
         */
        inline std::ostream& getInformationalStream() const;

        /**
         * Gets a debug stream.
         */
        inline std::ostream& getDebugStream() const;

    private:
        std::ostream& m_errorStream;
        std::ostream& m_warningStream;
        std::ostream& m_informationalStream;
        std::ostream& m_debugStream;
    };

    /**
     * Gets an error stream.
     */
    inline std::ostream& LogStreamWriter::getErrorStream() const
    {
        return m_errorStream;
    }

    /**
     * Gets a warning stream.
     */
    inline std::ostream& LogStreamWriter::getWarningStream() const
    {
        return m_warningStream;
    }

    /**
     * Gets an informational stream.
     */
    inline std::ostream& LogStreamWriter::getInformationalStream() const
    {
        return m_informationalStream;
    }

    /**
     * Gets a debug stream.
     */
    inline std::ostream& LogStreamWriter::getDebugStream() const
    {
        return m_debugStream;
    }
}

#endif // LOG_STREAM_WRITER_H_9932cee8_215f_4c9b_ac33_7b4af1bbf238
