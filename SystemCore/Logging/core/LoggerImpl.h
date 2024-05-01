#ifndef LOGGER_IMPL_H_6c9f4f17_af7f_46a2_9072_1a17584d174c
#define LOGGER_IMPL_H_6c9f4f17_af7f_46a2_9072_1a17584d174c

#include "ILoggerImpl.h"
#include "ILogWriter.h"
#include <mutex>
#include <atomic>

namespace logging {

    /**
     * The LoggerImpl class implements a logger implementation for the used loggers.
     */
    class LoggerImpl final : public ILoggerImpl {
    public:
        /**
         * Creates a LoggerImpl.
         */
        static ILoggerImplSharedPtr Make(ILogWriterSharedPtr logWriter);

        /**
         * The LoggerImpl constructor.
         */
        explicit LoggerImpl(ILogWriterSharedPtr logWriter);

        /**
         * The Logger destructor.
         */
        virtual ~LoggerImpl();

        /**
         * Logs a message.
         */
        virtual void Log(
            const std::wstring& loggerName,
            LogLevel logLevel,
            const std::wstring& message,
            const std::string& file,
            size_t line) override;

    private:
        /**
         * Get the next record index.
         */
        size_t NextRecordIndex();

        /**
         * Gets thread id.
         */
        static unsigned long GetThreadId();

        /**
         * Gets logging component.
         */
        static std::wstring GetLoggingComponent(const std::wstring& loggerName);

        //
        // The shared mutex for guarding the log...
        //
        std::mutex m_mutex;

        //
        // The current record index...
        //
        std::atomic<size_t> m_currRecordIndex;

        //
        // The log writer...
        //
        ILogWriterSharedPtr m_logWriter;
    };

} // namespace logging

#endif // LOGGER_IMPL_H_6c9f4f17_af7f_46a2_9072_1a17584d174c
