#ifndef CALL_INFORMATION_45365f02_1fb3_4554_9b4f_5006ab8b3353
#define CALL_INFORMATION_45365f02_1fb3_4554_9b4f_5006ab8b3353

#include "ICallInformation.h"
#include <vector>
#include "ILogger.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The CallInformation class implements information of a specific call.
         */
        class CallInformation final : public ICallInformation {
        public:
            /**
             * Creates a call information.
             */
            static ICallInformationSharedPtr Make(
                const std::wstring& id,
                const base::DateTimeSharedPtr startTime,
                const base::DateTimeSharedPtr endTime,
                const std::wstring& loggingObjectMemoryAddess);

            /**
             * The CallInformation constructor.
             */
            CallInformation(
                const std::wstring& id,
                const base::DateTimeSharedPtr startTime,
                const base::DateTimeSharedPtr endTime,
                const std::wstring& loggingObjectMemoryAddess);

            /**
             * The CallInformation destructor.
             */
            virtual ~CallInformation();

            /**
             * Gets an id of a call.
             */
            virtual const std::wstring& GetId() const override;

            /**
             * Gets a start time of a call.
             */
            virtual const base::DateTimeSharedPtr GetStartTime() const override;

            /**
             * Gets an end time of a call.
             */
            virtual const base::DateTimeSharedPtr GetEndTime() const override;

            /**
             * Sets a start time of a call.
             */
            virtual void SetStartTime(base::DateTimeSharedPtr time) override;

            /**
             * Sets an end time of a call.
             */
            virtual void SetEndTime(base::DateTimeSharedPtr time) override;

            /**
             * Gets a duration of a call.
             */
            virtual const base::DurationSharedPtr GetDuration() const override;

            /**
             * Gets memory address of a logging object.
             */
            virtual const std::wstring& GetLoggingObjectMemoryAddress() const override;

            /**
             * Gets a list of compositors.
             */
            virtual ICompositorInformationCollectionSharedPtr GetCompoistors() override;

            /**
             * Gets a list of compositors.
             */
            virtual const ICompositorInformationCollectionSharedPtr GetCompoistors() const override;

            /**
             * Gets the display string.
             */
            virtual std::wstring ToDisplayString() const override;

            /**
             * Parses an id of a call from display string.
             */
            static std::wstring ParseIdFromDisplayString(const std::wstring& displayString);

        private:
            static const std::wstring DISPLAY_STRING_REGEX;

            /**
             * Validates a display string.
             */
            static void ValidateDisplayString(const std::wstring& str, std::vector<std::wstring>& subStrings);

            /**
             * Gets a static logger.
             */
            static logging::ILoggerSharedPtr GetSLogger();

            std::wstring m_id;
            base::DateTimeSharedPtr m_startTime;
            base::DateTimeSharedPtr m_endTime;
            std::wstring m_loggingObjectMemoryAddess;
            ICompositorInformationCollectionSharedPtr m_compositors;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // CALL_INFORMATION_45365f02_1fb3_4554_9b4f_5006ab8b3353
