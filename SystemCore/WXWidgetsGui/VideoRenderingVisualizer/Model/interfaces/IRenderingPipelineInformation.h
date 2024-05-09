#ifndef I_RENDERING_PIPELINE_INFORMATION_c5c1213e_6622_4d2c_9f1c_b95bd49227d4
#define I_RENDERING_PIPELINE_INFORMATION_c5c1213e_6622_4d2c_9f1c_b95bd49227d4

#include "RenderingStatus.h"
#include <string>
#include <memory>

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The IRenderingPipelineInformation interface defines an information of a specific rendering pipeline.
         */
        class IRenderingPipelineInformation {
        public:
            IRenderingPipelineInformation() = default;
            virtual ~IRenderingPipelineInformation() = default;

            /**
             * Gets an id of a rendering pipeline.
             */
            virtual const std::wstring& GetId() const = 0;

            /**
             * Gets a media stream identifier (MSI) of a rendering pipeline.
             */
            virtual unsigned int GetMsi() const = 0;

            /**
             * Gets a frames per second (FPS) of a rendering pipeline.
             */
            virtual double GetFps() const = 0;

            /**
             * Gets a rendering status of a rendering pipeline.
             */
            virtual RenderingStatus GetRenderingStatus() const = 0;
        };

        /**
         * Defines the Shared Ptr of Rendering Pipeline Information.
         */
        using IRenderingPipelineInformationSharedPtr = std::shared_ptr<IRenderingPipelineInformation>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_RENDERING_PIPELINE_INFORMATION_c5c1213e_6622_4d2c_9f1c_b95bd49227d4
