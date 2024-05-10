#pragma once

#include "error_code_exception.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The video_rendering_visualizer_exception class implements an exception in the Video Rendering Visualizer module.
 */
class video_rendering_visualizer_exception : public Utilities::error_code_exception {
public:
    /**
     * The video_rendering_visualizer_exception constructor.
     */
    explicit video_rendering_visualizer_exception(const std::wstring& errorMessage) : 
        Utilities::error_code_exception(errorMessage)
    {
    }

    /**
     * The video_rendering_visualizer_exception constructor.
     */
    video_rendering_visualizer_exception(unsigned long errorCode, const std::wstring& errorMessage) : 
        Utilities::error_code_exception(
            errorCode, 
            errorMessage)
    {
    }

    /**
     * The video_rendering_visualizer_exception destructor.
     */
    virtual ~video_rendering_visualizer_exception() = default;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
