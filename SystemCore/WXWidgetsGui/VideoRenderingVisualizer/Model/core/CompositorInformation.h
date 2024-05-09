#ifndef COMPOSITOR_INFORMATION_3058e306_ca99_4c1a_9968_94a8d4e62f38
#define COMPOSITOR_INFORMATION_3058e306_ca99_4c1a_9968_94a8d4e62f38

#include "ICompositorInformation.h"
#include "ILoggers.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The CompositorInformation class implements information of a compositor.
         */
        class CompositorInformation final : public ICompositorInformation {
        public:
            /**
             * Creates a compositor information.
             */
            static ICompositorInformationSharedPtr Make(
                const std::wstring& id,
                const std::wstring& type,
                const std::wstring& compositionType,
                const std::wstring& renderer,
                const std::wstring& compositorState,
                unsigned long compositorFps,
                bool hasFallback,
                base::DateTimeSharedPtr startTime,
                base::DateTimeSharedPtr endTime = nullptr);

            /**
             * The CompositorInformation constructor.
             */
            CompositorInformation(
                const std::wstring& id,
                const std::wstring& type,
                const std::wstring& compositionType,
                const std::wstring& renderer,
                const std::wstring& compositorState,
                unsigned long compositorFps,
                bool hasFallback,
                base::DateTimeSharedPtr startTime,
                base::DateTimeSharedPtr endTime);

            /**
             * The CompositorInformation destructor.
             */
            virtual ~CompositorInformation();

            /**
             * Gets an id of a compositor.
             */
            virtual const std::wstring& GetId() const override;

            /**
             * Gets a type of a compositor.
             */
            virtual const std::wstring& GetType() const override;

            /**
             * Gets a composition type of a compositor.
             */
            virtual const std::wstring& GetCompositionType() const override;

            /**
             * Gets a renderer of a compositor.
             */
            virtual const std::wstring& GetRenderer() const override;

            /**
             * Gets a state of a compositor.
             */
            virtual const std::wstring& GetCompositorState() const override;

            /**
             * Gets frames per second (FPS) of a compostor.
             */
            virtual unsigned long GetCompositorFps() const override;

            /**
             * returns whether a compositor has a fallback.
             */
            virtual bool HasFallback() const override;

            /**
             * Gets a start time of a compositor.
             */
            virtual const base::DateTimeSharedPtr GetStartTime() const override;

            /**
             * Gets an end time of a compositor.
             */
            virtual const base::DateTimeSharedPtr GetEndTime() const override;

            /**
             * Gets a duration of a compositor.
             */
            virtual const base::DurationSharedPtr GetDuration() const override;

            /**
             * Sets a start time of a call.
             */
            virtual void SetStartTime(base::DateTimeSharedPtr time) override;

            /**
             * Sets an end time of a call.
             */
            virtual void SetEndTime(base::DateTimeSharedPtr time) override;

            /**
             * Gets a display string.
             */
            virtual std::wstring ToDisplayString() const override;

            /**
             * Gets a short display string.
             */
            virtual std::wstring ToShortDisplayString() const override;

            /**
             * Parses a compositor id from short display string.
             */
            static std::wstring ParseIdFromShortDisplayString(const std::wstring& str);

        private:
            /**
             * Tries to parse a compositor id from short display string.
             */
            static bool TryParseIdFromShortDisplayString(
                const std::wstring& str,
                std::wstring& id);

            /**
             * Gets a static logger.
             */
            static logging::ILoggerSharedPtr GetSLogger();

            std::wstring m_id;
            std::wstring m_type;
            std::wstring m_compositionType;
            std::wstring m_renderer;
            std::wstring m_compositorState;
            unsigned long m_compositorFps;
            bool m_hasFallback;
            base::DateTimeSharedPtr m_startTime;
            base::DateTimeSharedPtr m_endTime;
            logging::ILoggersSharedPtr m_loggers;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // COMPOSITOR_INFORMATION_3058e306_ca99_4c1a_9968_94a8d4e62f38
