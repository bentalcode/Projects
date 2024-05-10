#ifndef VIDEO_RENDERING_VISUALIZER_EXCEPTION_H_c24b61d1_2c51_4e3a_afab_248f7de6fbe2
#define VIDEO_RENDERING_VISUALIZER_EXCEPTION_H_c24b61d1_2c51_4e3a_afab_248f7de6fbe2

#include "BaseException.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The VideoRenderingVisualizerException class implements an exception
         * in the Video Rendering Visualizer module.
         */
        class VideoRenderingVisualizerException : public base::BaseException {
        public:
            /**
             * The VideoRenderingVisualizerException constructor.
             */
            explicit VideoRenderingVisualizerException(const std::wstring& errorMessage) :
                base::BaseException(errorMessage)
            {
            }

            /**
             * The VideoRenderingVisualizerException constructor.
             */
            VideoRenderingVisualizerException(
                long errorCode,
                const std::wstring& errorMessage) :
                    base::BaseException(
                        errorCode,
                        errorMessage)
            {
            }

            /**
             * The VideoRenderingVisualizerException destructor.
             */
            virtual ~VideoRenderingVisualizerException() = default;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // VIDEO_RENDERING_VISUALIZER_EXCEPTION_H_c24b61d1_2c51_4e3a_afab_248f7de6fbe2
