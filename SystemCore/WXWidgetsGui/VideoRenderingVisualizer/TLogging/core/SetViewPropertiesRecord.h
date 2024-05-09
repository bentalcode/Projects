#ifndef SET_VIEW_PROPERTIES_RECORD_H_f294f6d4_1635_47e9_b1bc_0439d0f91a6b
#define SET_VIEW_PROPERTIES_RECORD_H_f294f6d4_1635_47e9_b1bc_0439d0f91a6b

#include "ISetViewPropertiesRecord.h"
#include "ILogRecord.h"
#include "ILoggers.h"

namespace tlogging {

    class ITLogProcessor;

    /**
     * The SetViewPropertiesRecord class implements a Set View Properties Record.
     */
    class SetViewPropertiesRecord final : public ISetViewPropertiesRecord {
    public:
        /**
         * Creates a Set View Properties Record.
         */
        static ITLogRecordSharedPtr Make(
            const std::wstring& header,
            const PropertyMapSharedPtr properties,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The SetViewPropertiesRecord constructor.
         */
        SetViewPropertiesRecord(
            const std::wstring& header,
            const PropertyMapSharedPtr properties,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The SetViewPropertiesRecord destructor.
         */
        virtual ~SetViewPropertiesRecord();

        /**
         * Gets an optional header.
         */
        virtual const std::wstring& GetHeader() const override;

        /**
         * Checks whether a property exists.
         */
        virtual bool HasProperty(const std::wstring& name) const override;

        /**
         * Gets a value of a property.
         */
        virtual const std::wstring& GetPropertyValue(const std::wstring& name) const override;

        /**
         * Gets properties of configuration.
         */
        virtual const PropertyMap& GetProperties() const override;

        /**
         * Gets a log record.
         */
        virtual logging::ILogRecord& GetLogRecord() const override;

        /**
         * Processes a record.
         */
        virtual void Process(ITLogProcessor& processor) const override;

    private:
        /**
         * Finds a property by name.
         */
        const std::wstring* FindProperty(const std::wstring& name) const;

        std::wstring m_header;
        PropertyMapSharedPtr m_properties;
        logging::ILogRecordSharedPtr m_logRecord;
        logging::ILoggersSharedPtr m_loggers;
    };

} // namespace tlogging

#endif // SET_VIEW_PROPERTIES_RECORD_H_f294f6d4_1635_47e9_b1bc_0439d0f91a6b

