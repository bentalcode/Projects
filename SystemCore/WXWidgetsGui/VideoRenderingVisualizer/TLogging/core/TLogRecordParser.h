#ifndef TLOG_RECORD_PARSER_H_0e55be35_9913_4597_a493_a86352878e69
#define TLOG_RECORD_PARSER_H_0e55be35_9913_4597_a493_a86352878e69

#include "ITLogRecordParser.h"
#include "TLogRecordType.h"
#include "ILoggers.h"
#include "ISetConfigurationRecord.h"
#include <regex>

namespace tlogging {

    /**
     * The TLogRecordParser class implements a parser of a TLog record.
     */
    class TLogRecordParser final : public ITLogRecordParser {
    public:
        /**
         * Creates a TLog Parser.
         */
        static ITLogRecordParserSharedPtr Make();

        /**
         * The TLogRecordParser constructor.
         */
        TLogRecordParser();

        /**
         * The TLogRecordParser destructor.
         */
        virtual ~TLogRecordParser();

        /**
         * Parses a TLog record.
         */
        virtual tlogging::ITLogRecordSharedPtr Parse(const logging::ILogRecordSharedPtr record) const override;

        /**
         * Parses a Call Started record.
         */
        virtual tlogging::ITLogRecordSharedPtr ParseCallStartedRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const override;

        /**
         * Parses a Call Ended record.
         */
        virtual tlogging::ITLogRecordSharedPtr ParseCallEndedRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const override;

        /**
         * Parses a Compositor Created record.
         */
        virtual tlogging::ITLogRecordSharedPtr ParseCompositorCreatedRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const override;

        /**
         * Parses a Compositor Destroyed record.
         */
        virtual tlogging::ITLogRecordSharedPtr ParseCompositorDestroyedRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const override;

        /**
         * Parses an Add View record.
         */
        virtual tlogging::ITLogRecordSharedPtr ParseAddViewRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const override;

        /**
         * Parses a Remove View record.
         */
        virtual tlogging::ITLogRecordSharedPtr ParseRemoveViewRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const override;

        /**
         * Parses a Set Configutration record.
         */
        virtual tlogging::ITLogRecordSharedPtr ParseSetConfigurationRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const override;

        /**
         * Parses a Set View Properties record.
         */
        virtual tlogging::ITLogRecordSharedPtr ParseSetViewPropertiesRecord(
            const std::wstring& content,
            const std::wstring& regex,
            const logging::ILogRecordSharedPtr record) const override;

    private:
        //
        // The regexes TLog records...
        //
        static const std::wstring CALL_STARTED;
        static const std::wstring CALL_ENDED;
        static const std::wstring COMPOSITOR_CREATED;
        static const std::wstring COMPOSITOR_DESTROYED;
        static const std::wstring ADD_VIEW;
        static const std::wstring REMOVE_VIEW;
        static const std::wstring SET_CONFIGURATION;
        static const std::wstring SET_VIEW_PROPERTIES;
        static const std::wstring ECS_SETTINGS;
        static const std::wstring SET_DIMENSIONS;

        static const std::wstring CALL_STARTED_RECORD_REGEX;
        static const std::wstring CALL_ENDED_RECORD_REGEX;
        static const std::wstring COMPOSITOR_CREATED_RECORD_REGEX;
        static const std::wstring COMPOSITOR_DESTROYED_RECORD_REGEX;
        static const std::wstring ADD_VIEW_RECORD_REGEX;
        static const std::wstring REMOVE_VIEW_RECORD_REGEX;
        static const std::wstring SET_CONFIGURATION_RECORD_REGEX1A;
        static const std::wstring SET_CONFIGURATION_RECORD_REGEX1B;
        static const std::wstring SET_CONFIGURATION_RECORD_REGEX2A;
        static const std::wstring SET_CONFIGURATION_RECORD_REGEX2B;
        static const std::wstring SET_VIEW_PROPERTIES_RECORD_REGEX1A;
        static const std::wstring SET_VIEW_PROPERTIES_RECORD_REGEX1B;
        static const std::wstring SET_VIEW_PROPERTIES_RECORD_REGEX2A;
        static const std::wstring SET_VIEW_PROPERTIES_RECORD_REGEX2B;

        static const std::wstring::value_type KEY_VALUE_SEPARATOR;
        static const std::wstring::value_type TOKEN_SEPARATOR;

        /**
         * Parses a TLog record.
         */
        ITLogRecordSharedPtr Parse(
            const std::wstring& content,
            TLogRecordType recordType,
            const std::wstring& matchingRegex,
            const logging::ILogRecordSharedPtr record) const;

        /**
         * Parses a type of a TLog record.
         */
        bool ParseRecordType(
            const std::wstring& content,
            TLogRecordType& type,
            std::wstring& matchingRegex) const;

        /**
         * Parses tokens of a record.
         */
        void ParseRecordTokens(
            TLogRecordType recordType,
            const std::wstring& content,
            const std::wstring& regex,
            size_t numberOfTokensToParse,
            std::vector<std::wstring>& tokens) const;

        /**
         * Tries to parse tokens of a record.
         */
        bool TryParseRecordTokens(
            TLogRecordType recordType,
            const std::wstring& content,
            const std::wstring& regex,
            size_t numberOfTokensToParse,
            std::vector<std::wstring>& tokens) const;

        /**
         * Creates a Record Regex to Record Type mapping.
         */
        using RecordRegexToRecordTypeMap = std::map<std::wstring, TLogRecordType>;
        static void CreateRecordRegexToTypeMap(RecordRegexToRecordTypeMap& map);

        /**
         * Creates a Record Type to a Record Creator mapping.
         */
        using RecordTypeToRecordCreatorMap = std::map<TLogRecordType, ITLogRecord::ICreatorFunctorSharedPtr>;
        void CreateRecordTypeToCreatorMap(RecordTypeToRecordCreatorMap& map) const;

        /**
         * Parses key-values from the following string format: { key=value key=value key=value ... }
         */
        static void ParseKeyValues(
            const std::wstring& str,
            ISetConfigurationRecord::PropertyMap& properties,
            std::wstring::value_type keyValueSeparator = KEY_VALUE_SEPARATOR,
            std::wstring::value_type tokenSeparator = TOKEN_SEPARATOR);

        /**
         * Finds left token.
         */
        static std::wstring FindLeftToken(
            const std::wstring& str,
            size_t startIndex, size_t endIndex,
            std::wstring::value_type separator);

        /**
         * Finds right token.
         */
        static std::wstring FindRightToken(
            const std::wstring& str,
            size_t startIndex,
            size_t endIndex,
            std::wstring::value_type separator);

        /**
         * Tries to optimize content.
         */
        static bool TryOptimizeContent(
            const std::wstring& str,
            std::wstring& result);

        /**
         * Strips prefixes from content of record.
         * Returns false if no prefix is found.
         */
        static bool StripRecordPrefixes(
            const std::wstring& content,
            const std::wstring& header,
            std::wstring& result,
            const std::vector<std::wstring>& prefixes = { L":", L"-", L" -"} );

        RecordRegexToRecordTypeMap m_recordRegexToRecordTypeMap;
        RecordTypeToRecordCreatorMap m_recordTypeToRecordCreatorMap;

        logging::ILoggersSharedPtr m_loggers;
    };

    /**
     * Defines the Shared Ptr of TLog Record Parser.
     */
    using ITLogRecordParserSharedPtr = std::shared_ptr<ITLogRecordParser>;

} // namespace tlogging

#endif // TLOG_RECORD_PARSER_H_0e55be35_9913_4597_a493_a86352878e69
