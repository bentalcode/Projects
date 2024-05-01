#ifndef LOGGERS_H_6b1e86a1_5fba_4dc8_adfc_38cef0f32a14
#define LOGGERS_H_6b1e86a1_5fba_4dc8_adfc_38cef0f32a14

#include "ILoggers.h"
#include <typeinfo>

namespace logging {

    /**
     * The Loggers class implements loggers of specific class.
     */
    class Loggers final : public ILoggers {
    public:
        /**
         * Creates a Loggers.
         */
        static ILoggersSharedPtr Make(const std::wstring& name);
        static ILoggersSharedPtr Make(const std::type_info& typeInfo);

        /**
         * The Loggers constructor.
         */
        explicit Loggers(const std::wstring& name);

        /**
         * The Loggers destructor.
         */
        virtual ~Loggers();

        /**
         * Gets a logger.
         */
        virtual ILoggerSharedPtr GetLogger() override;

    private:
        std::wstring m_name;
        ILoggerSharedPtr m_logger;
    };

} // namespace logging

#endif // LOGGERS_H_6b1e86a1_5fba_4dc8_adfc_38cef0f32a14
