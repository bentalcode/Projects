#ifndef I_LOG_H_607081cb_2167_4438_97d5_2b07a634d861
#define I_LOG_H_607081cb_2167_4438_97d5_2b07a634d861

namespace base {

    /**
     * The ILog interface defines a log.
     */
    class ILog
    {
    public:
        /**
         * The constructor.
         */
        ILog() = default;

        /**
         * The destructor.
         */
        virtual ~ILog() = default;

        /**
         * The copy/move constructors.
         */
        ILog(const ILog&) = delete;
        ILog(ILog&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ILog& operator=(const ILog&) = delete;
        ILog& operator=(ILog&&) = delete;

        /**
         * Gets the name of the log.
         */
        virtual const std::string& getName() const = 0;

        /**
         * Writes an informational message.
         */
        virtual void writeInformationalMessage(const std::string& message) = 0;

        /**
         * Writes a warning message.
         */
        virtual void writeWarningMessage(const std::string& message) = 0;

        /**
         * Writes an error message.
         */
        virtual void writeErrorMessage(const std::string& message) = 0;

        /**
         * Writes a debug message.
         */
        virtual void writeDebugMessage(const std::string& message) = 0;
    };

    //
    // Defines the SharedPtr of Log...
    //
    using ILogSharedPtr = std::shared_ptr<ILog>;
}

#endif // I_LOG_H_607081cb_2167_4438_97d5_2b07a634d861
