#ifndef I_COMMAND_MESSAGE_WRITER_H_c1629ca1_1995_4761_a17d_cfd8c4c2b4bd
#define I_COMMAND_MESSAGE_WRITER_H_c1629ca1_1995_4761_a17d_cfd8c4c2b4bd

#include "IMessageWriter.h"

namespace command {

    /**
     * The ICommandMessageWriter interface defines a writer of a command message.
     */
    class ICommandMessageWriter : public IMessageWriter
    {
    public:
        /**
         * The constructor.
         */
        ICommandMessageWriter() = default;

        /**
         * The destructor.
         */
        virtual ~ICommandMessageWriter() = default;

        /**
         * The copy/move constructors.
         */
        ICommandMessageWriter(const ICommandMessageWriter&) = delete;
        ICommandMessageWriter(ICommandMessageWriter&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ICommandMessageWriter& operator=(const ICommandMessageWriter&) = delete;
        ICommandMessageWriter& operator=(ICommandMessageWriter&&) = delete;

        /**
         * Writes a usage message.
         */
        virtual void writeUsageMessage() = 0;

        /**
         * Writes a usage message.
         */
        virtual void writeUsageMessage(bool status) = 0;
    };

    using ICommandMessageWriterPtr = std::shared_ptr<ICommandMessageWriter>;
}

#endif // I_COMMAND_MESSAGE_WRITER_H_c1629ca1_1995_4761_a17d_cfd8c4c2b4bd
