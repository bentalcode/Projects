#ifndef I_MESSAGE_WRITER_H_01c54c66_a0c8_4a91_b03f_99f0876f5e18
#define I_MESSAGE_WRITER_H_01c54c66_a0c8_4a91_b03f_99f0876f5e18

namespace command {

    /**
     * The IMessageWriter interface defines a writer of messages.
     */
    class IMessageWriter
    {
    public:
        /**
         * The constructor.
         */
        IMessageWriter() = default;

        /**
         * The destructor.
         */
        virtual ~IMessageWriter() = default;

        /**
         * The copy/move constructors.
         */
        IMessageWriter(const IMessageWriter&) = delete;
        IMessageWriter(IMessageWriter&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMessageWriter& operator=(const IMessageWriter&) = delete;
        IMessageWriter& operator=(IMessageWriter&&) = delete;

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
         * Gets an error stream.
         */
        virtual std::ostream& getErrorStream() = 0;

        /**
         * Gets a warning stream.
         */
        virtual std::ostream& getWarningStream() = 0;

        /**
         * Gets an informational stream.
         */
        virtual std::ostream& getInformationalStream() = 0;
    };

    using IMessageWriterPtr = std::shared_ptr<IMessageWriter>;
}

#endif // I_MESSAGE_WRITER_H_01c54c66_a0c8_4a91_b03f_99f0876f5e18