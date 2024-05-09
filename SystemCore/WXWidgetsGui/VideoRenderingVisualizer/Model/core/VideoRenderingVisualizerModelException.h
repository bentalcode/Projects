#ifndef VIDEO_RENDERING_VISUALIZER_MODEL_EXCEPTION_801a8835_0c52_4501_901e_800082868b3b
#define VIDEO_RENDERING_VISUALIZER_MODEL_EXCEPTION_801a8835_0c52_4501_901e_800082868b3b

#include "BaseException.h"

namespace VideoRenderingVisualizer {

    namespace Model {

            /**
             * The VideoRenderingVisualizerModelException class implements an exception
             * in the Video Rendering Visualizer Model module.
             */
            class VideoRenderingVisualizerModelException : public base::BaseException {
            public:
                /**
                 * The VideoRenderingVisualizerModelException constructor.
                 */
                explicit VideoRenderingVisualizerModelException(const std::wstring& errorMessage) :
                    base::BaseException(errorMessage)
                {
                }

                /**
                 * The VideoRenderingVisualizerModelException constructor.
                 */
                VideoRenderingVisualizerModelException(
                    unsigned long errorCode,
                    const std::wstring& errorMessage) :
                        BaseException(
                            errorCode,
                            errorMessage)
                {
                }

                /**
                 * The VideoRenderingVisualizerModelException destructor.
                 */
                virtual ~VideoRenderingVisualizerModelException() = default;
            };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // VIDEO_RENDERING_VISUALIZER_MODEL_EXCEPTION_801a8835_0c52_4501_901e_800082868b3b
