#ifndef I_TLOG_RECORD_PARSER_H_f92a2d3d_fe20_4e24_85f7_ae5e58f43261
#define I_TLOG_RECORD_PARSER_H_f92a2d3d_fe20_4e24_85f7_ae5e58f43261

#include "ITLogRecord.h"

namespace tlogging {

    /**
     * The ITLogRecordParser interface defines a parser of Tlog record.
     */
    class ITLogRecordParser {
    public:
        ITLogRecordParser() = default;
        virtual ~ITLogRecordParser() = default;

        /**
         * Parses a TLog record.
         */
        virtual ITLogRecordSharedPtr Parse(const logging::ILogRecordSharedPtr record) const = 0;

        /**
         * Parses a Call Started record.
         */
        virtual ITLogRecordSharedPtr ParseCallStartedRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const = 0;

        /**
         * Parses a Call Ended record.
         */
        virtual ITLogRecordSharedPtr ParseCallEndedRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const = 0;

        /**
         * Parses a Compositor Created record.
         */
        virtual ITLogRecordSharedPtr ParseCompositorCreatedRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const = 0;

        /**
         * Parses a Compositor Destroyed record.
         */
        virtual ITLogRecordSharedPtr ParseCompositorDestroyedRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const = 0;

        /**
         * Parses an Add View record.
         */
        virtual ITLogRecordSharedPtr ParseAddViewRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const = 0;

        /**
         * Parses a Remove View record.
         */
        virtual ITLogRecordSharedPtr ParseRemoveViewRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const = 0;

        /**
         * Parses a Set Configutration record.
         */
        virtual ITLogRecordSharedPtr ParseSetConfigurationRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const = 0;

        /**
         * Parses a Set View Properties record.
         */
        virtual ITLogRecordSharedPtr ParseSetViewPropertiesRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const = 0;
    };

    /**
     * Defines the Shared Ptr of TLog Record Parser.
     */
    using ITLogRecordParserSharedPtr = std::shared_ptr<ITLogRecordParser>;

} // namespace tlogging

#endif // I_TLOG_RECORD_PARSER_H_f92a2d3d_fe20_4e24_85f7_ae5e58f43261
