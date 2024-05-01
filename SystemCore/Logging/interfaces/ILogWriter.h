#ifndef I_LOG_WRITER_H_3be2597e_7181_448d_9327_40bccf61f884
#define I_LOG_WRITER_H_3be2597e_7181_448d_9327_40bccf61f884

#include <memory>

namespace logging {

    class ILogHeader;
    class ILogRecord;

    /**
     * The ILogWriter interface defines a Log Writer.
     */
    class ILogWriter {
    public:
        ILogWriter() = default;
        virtual ~ILogWriter() = default;

        /**
         * Writes header.
         */
        virtual void WriteHeader(const ILogHeader& header) = 0;

        /**
         * Writes record.
         */
        virtual void WriteRecord(const ILogRecord& record) = 0;

        /**
         * Writes a new line.
         */
        virtual void NewLine() = 0;
    };

    /**
     * Defines the Shared Ptr of ILogWriter.
     */
    using ILogWriterSharedPtr = std::shared_ptr<ILogWriter>;

} // namespace logging

#endif // I_LOG_WRITER_H_3be2597e_7181_448d_9327_40bccf61f884
