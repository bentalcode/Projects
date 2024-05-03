#ifndef GL_CANVAS_696779c3_5d9e_4dc4_a2d8_65bc93d3887f
#define GL_CANVAS_696779c3_5d9e_4dc4_a2d8_65bc93d3887f

#include "AbstractGLCanvas.h"
#include "WXObjectId.h"

namespace WXWidgets {

    /**
     * The GLCanvas class implements an abstract base class of a GL Canvas
     * for displaying OpenGL Graphics.
     */
    class GLCanvas : public AbstractGLCanvas {
    public:
        /**
         * The GLCanvas constructor.
         */
        GLCanvas(
            wxWindow& parent,
            const wxString& name,
            const wxGLAttributes& attributes = CreateDefaultAttributes(),
            long style = 0,
            wxWindowID id = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            const wxPalette& palette = wxNullPalette);

        /**
         * The GLCanvas destructor.
         */
        virtual ~GLCanvas();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;

        /**
         * Validates attributes.
         */
        static void ValidateAttributes(const wxGLAttributes& attributes);

        /**
         * Creates default attributes of canvas.
         */
        static const wxGLAttributes& CreateDefaultAttributes();

    private:
        /**
         * Initializes default attributes.
         */
        static void InitializeDefaultAttributes(wxGLAttributes& attributes);
    };

}  // namespace WXWidgets

#endif // GL_CANVAS_696779c3_5d9e_4dc4_a2d8_65bc93d3887f
