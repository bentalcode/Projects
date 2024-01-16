#ifndef I_COMMAND_MESSAGE_WRITER_H_c1629ca1_1995_4761_a17d_cfd8c4c2b4bd
#define I_COMMAND_MESSAGE_WRITER_H_c1629ca1_1995_4761_a17d_cfd8c4c2b4bd

#include "IMessageWriter.h"

namespace command {

    /**
     * The ICommandMessageWriter interface defines a writer of a command messages.
     */
    class ICommandMessageWriter
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
        virtual void WriteUsageMessage() = 0;

        /**
         * Writes a usage message.
         */
        virtual void WriteUsageMessage(bool status) = 0;

        /**
         * Gets a message writer.
         */
        virtual base::IMessageWriterSharedPtr GetMessageWriter() = 0;
    };

    //
    // Define the Shared Ptr Command Message Writer...
    //
    using ICommandMessageWriterSharedPtr = std::shared_ptr<ICommandMessageWriter>;

} // namespace command

#endif // I_COMMAND_MESSAGE_WRITER_H_c1629ca1_1995_4761_a17d_cfd8c4c2b4bd
