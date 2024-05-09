#ifndef I_CALL_INFORAMTION_34f03a87_4430_44ba_9cc1_dcc649903fab
#define I_CALL_INFORAMTION_34f03a87_4430_44ba_9cc1_dcc649903fab

#include "DateTime.h"
#include "Duration.h"
#include "ICompositorInformationCollection.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The ICallInformation interface defines an information of a specific call.
         */
        class ICallInformation {
        public:
            ICallInformation() = default;
            virtual ~ICallInformation() = default;

            /**
             * Gets an id of a call.
             */
            virtual const std::wstring& GetId() const = 0;

            /**
             * Gets a start time of a call.
             */
            virtual const base::DateTimeSharedPtr GetStartTime() const = 0;

            /**
             * Gets an end time of a call.
             */
            virtual const base::DateTimeSharedPtr GetEndTime() const = 0;

            /**
             * Sets a start time of a call.
             */
            virtual void SetStartTime(base::DateTimeSharedPtr time) = 0;

            /**
             * Sets an end time of a call.
             */
            virtual void SetEndTime(base::DateTimeSharedPtr time) = 0;

            /**
             * Gets a duration of a call.
             */
            virtual const base::DurationSharedPtr GetDuration() const = 0;

            /**
             * Gets memory address of a logging object.
             */
            virtual const std::wstring& GetLoggingObjectMemoryAddress() const = 0;

            /**
             * Gets compositors collection.
             */
            virtual ICompositorInformationCollectionSharedPtr GetCompoistors() = 0;

            /**
             * Gets compositors collection.
             */
            virtual const ICompositorInformationCollectionSharedPtr GetCompoistors() const = 0;

            /**
             * Gets the display string.
             */
            virtual std::wstring ToDisplayString() const = 0;
        };

        /**
         * Defines the Shared Ptr of Call Information.
         */
        using ICallInformationSharedPtr = std::shared_ptr<ICallInformation>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_CALL_INFORAMTION_34f03a87_4430_44ba_9cc1_dcc649903fab
