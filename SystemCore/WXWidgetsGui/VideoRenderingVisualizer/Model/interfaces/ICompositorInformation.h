#ifndef I_COMPOSITOR_INFORMATION_b25fee4d_09d7_4287_aac1_ca1f0caf2afe
#define I_COMPOSITOR_INFORMATION_b25fee4d_09d7_4287_aac1_ca1f0caf2afe

#include <string>
#include "DateTime.h"
#include <memory>

namespace VideoRenderingVisualizer {

namespace Model {

        /**
         * The ICompositorInformation interface defines an information of a compositor.
         */
        class ICompositorInformation {
        public:
            ICompositorInformation() = default;
            virtual ~ICompositorInformation() = default;

            /**
             * Gets an id of a compositor.
             */
            virtual const std::wstring& GetId() const = 0;

            /**
             * Gets a type of a compositor.
             */
            virtual const std::wstring& GetType() const = 0;

            /**
             * Gets a composition type of a compositor.
             */
            virtual const std::wstring& GetCompositionType() const = 0;

            /**
             * Gets a renderer of a compositor.
             */
            virtual const std::wstring& GetRenderer() const = 0;

            /**
             * Gets a state of a compositor.
             */
            virtual const std::wstring& GetCompositorState() const = 0;

            /**
             * Gets frames per second (FPS) of a compostor.
             */
            virtual unsigned long GetCompositorFps() const = 0;

            /**
             * returns whether a compositor has a fallback.
             */
            virtual bool HasFallback() const = 0;

            /**
             * Gets a start time of a compositor.
             */
            virtual const base::DateTimeSharedPtr GetStartTime() const = 0;

            /**
             * Gets an end time of a compositor.
             */
            virtual const base::DateTimeSharedPtr GetEndTime() const = 0;

            /**
             * Gets a duration of a compositor.
             */
            virtual const base::DurationSharedPtr GetDuration() const = 0;

            /**
             * Sets a start time of a compositor.
             */
            virtual void SetStartTime(base::DateTimeSharedPtr time) = 0;

            /**
             * Sets an end time of a compositor.
             */
            virtual void SetEndTime(base::DateTimeSharedPtr time) = 0;

            /**
             * Gets a display string.
             */
            virtual std::wstring ToDisplayString() const = 0;

            /**
             * Gets a short display string.
             */
            virtual std::wstring ToShortDisplayString() const = 0;
        };

        /**
         * Defines the Shared Ptr of Compositor Information.
         */
        using ICompositorInformationSharedPtr = std::shared_ptr<ICompositorInformation>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_COMPOSITOR_INFORMATION_b25fee4d_09d7_4287_aac1_ca1f0caf2afe
