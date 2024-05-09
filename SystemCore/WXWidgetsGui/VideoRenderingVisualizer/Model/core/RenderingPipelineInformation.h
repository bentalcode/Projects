#ifndef RENDERING_PIPELINE_INFORMATION_66d167ba_c8a6_42fc_9652_76ce016bed5d
#define RENDERING_PIPELINE_INFORMATION_66d167ba_c8a6_42fc_9652_76ce016bed5d

#include "IRenderingPipelineInformation.h"
#include <vector>
#include <map>
#include "ILogger.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The RenderingPipelineInformation class implements information of specific call.
         */
        class RenderingPipelineInformation final : public IRenderingPipelineInformation {
        public:
            /**
             * Creates a rendering pipeline information.
             */
            static IRenderingPipelineInformationSharedPtr Make(
                const std::wstring& id,
                unsigned int msi,
                double fps,
                RenderingStatus renderingStatus);

            /**
             * The RenderingPipelineInformation constructor.
             */
            RenderingPipelineInformation(
                const std::wstring& id,
                unsigned int msi,
                double fps, RenderingStatus renderingStatus);

            /**
             * The RenderingPipelineInformation destructor.
             */
            virtual ~RenderingPipelineInformation();

            /**
             * Gets an id of a rendering pipeline.
             */
            virtual const std::wstring& GetId() const override;

            /**
             * Gets a media stream identifier (MSI) of a rendering pipeline.
             */
            virtual unsigned int GetMsi() const override;

            /**
             * Gets a frames per second (FPS) of a rendering pipeline.
             */
            virtual double GetFps() const override;

            /**
             * Gets a rendering status of a rendering pipeline.
             */
            virtual RenderingStatus GetRenderingStatus() const override;

            /**
             * Gets names of properties.
             */
            static void GetPropertiesNames(std::vector<std::wstring>& names);

            /**
             * Gets rendering status as a string.
             */
            static std::wstring GetRenderingStatusString(RenderingStatus renderingStatus);

        private:
            //
            // Defines a rendering status map...
            //
            using RenderingStatusMap = std::map<RenderingStatus, std::wstring>;
            using RenderingStatusMapUniquePtr = std::unique_ptr<RenderingStatusMap>;

            /**
             * Creates a rendering status map.
             */
            static RenderingStatusMap* CreateRenderingStatusMap();

            /**
             * Gets a static logger.
             */
            static logging::ILoggerSharedPtr GetSLogger();

            static const std::wstring ID_PROPERTY;
            static const std::wstring MSI_PROPERTY;
            static const std::wstring FPS_PROPERTY;
            static const std::wstring RENDERING_STATUS_PROPERTY;

            std::wstring m_id;
            unsigned int m_msi;
            double m_fps;
            RenderingStatus m_renderingStatus;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // RENDERING_PIPELINE_INFORMATION_66d167ba_c8a6_42fc_9652_76ce016bed5d
