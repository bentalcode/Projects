#ifndef SET_VIEW_PROPERTIES_H_d6f6a5c2_32e7_42cf_8c90_0e009d7101fd
#define SET_VIEW_PROPERTIES_H_d6f6a5c2_32e7_42cf_8c90_0e009d7101fd

#include "ISetViewProperties.h"
#include "ILogRecord.h"
#include "ILoggers.h"

namespace tlogging {

    class ITLogProcessor;

    /**
     * The SetConfigurationRecord class implements a Set Configuration Record.
     */
    class SetViewProperties final : public ISetViewProperties {
    public:
        /**
         * Creates a Compositor Created Record.
         */
        static ITLogRecordSharedPtr Make(
            const ISetConfigurationRecord::PropertyMapSharedPtr properties,
            const Logging::ILogRecordSharedPtr logRecord);

        /**
         * The SetConfigurationRecord constructor.
         */
        SetConfigurationRecord(
            const ISetConfigurationRecord::PropertyMapSharedPtr properties,
            const Logging::ILogRecordSharedPtr logRecord);

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
        virtual Logging::ILogRecord& GetLogRecord() const override;

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
        Logging::ILogRecordSharedPtr m_logRecord;
        Logging::ILoggersSharedPtr m_loggers;
    };

} // namespace tlogging

#endif // SET_VIEW_PROPERTIES_H_d6f6a5c2_32e7_42cf_8c90_0e009d7101fd

