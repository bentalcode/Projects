#ifndef LOG_H_96693a78_4046_49cb_b6dd_b50f9b3d5fa4
#define LOG_H_96693a78_4046_49cb_b6dd_b50f9b3d5fa4

#include "ILog.h"
#include "IMessageWriter.h"
#include "LogLevelType.h"

namespace base {

    /**
     * The Log class implements a log.
     */
    class Log final : public ILog
    {
    public:
        /**
         * Creates a new log.
         */
        static ILogPtr make(
            const std::string name,
            LogLevelType logLevelType = LogLevelType::Informational);

        /**
         * The Log Constructor.
         */
        Log(
            const std::string& name,
            LogLevelType logLevelType,
            base::IMessageWriterPtr messageWriter);

        /**
         * The Log Destructor.
         */
        virtual ~Log();

        /**
         * The copy/move constructors.
         */
        Log(const Log&) = delete;
        Log(Log&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        Log& operator=(const Log&) = delete;
        Log& operator=(Log&&) = delete;

        /**
         * Gets the name of the log.
         */
        virtual const std::string& getName() const override;

        /**
         * Writes an informational message.
         */
        virtual void writeInformationalMessage(const std::string& message) override;

        /**
         * Writes a warning message.
         */
        virtual void writeWarningMessage(const std::string& message) override;

        /**
         * Writes an error message.
         */
        virtual void writeErrorMessage(const std::string& message) override;

        /**
         * Writes a debug message.
         */
        virtual void writeDebugMessage(const std::string& message) override;

    private:
        /**
         * Checks if the current log is active at the specific level.
         */
        bool active(LogLevelType logLevelType) const;

        std::string m_name;
        LogLevelType m_logLevelType;
        base::IMessageWriterPtr m_messageWriter;
    };
}

#endif // LOG_H_96693a78_4046_49cb_b6dd_b50f9b3d5fa4
