#ifndef SET_CONFIGURATION_RECORD_H_d6f6a5c2_32e7_42cf_8c90_0e009d7101fd
#define SET_CONFIGURATION_RECORD_H_d6f6a5c2_32e7_42cf_8c90_0e009d7101fd

#include "ISetConfigurationRecord.h"
#include "ILogRecord.h"
#include "ILoggers.h"

namespace tlogging {

    class ITLogProcessor;

    /**
     * The SetConfigurationRecord class implements a Set Configuration Record.
     */
    class SetConfigurationRecord final : public ISetConfigurationRecord {
    public:
        /**
         * Creates a Compositor Created Record.
         */
        static ITLogRecordSharedPtr Make(
            const PropertyMapSharedPtr properties,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The SetConfigurationRecord constructor.
         */
        SetConfigurationRecord(
            const PropertyMapSharedPtr properties,
            const logging::ILogRecordSharedPtr logRecord);

        /**
         * The SetConfigurationRecord destructor.
         */
        virtual ~SetConfigurationRecord();

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

        ISetConfigurationRecord::PropertyMapSharedPtr m_properties;
        logging::ILogRecordSharedPtr m_logRecord;
        logging::ILoggersSharedPtr m_loggers;
    };

} // namespace tlogging

#endif // SET_CONFIGURATION_RECORD_H_d6f6a5c2_32e7_42cf_8c90_0e009d7101fd
