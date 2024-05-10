#ifndef ABSTRACT_GL_CANVAS_88340919_7ae6_41f0_a14d_954948363c2e
#define ABSTRACT_GL_CANVAS_88340919_7ae6_41f0_a14d_954948363c2e

#include "ICanvas.h"
#include "Window.h"
#include "OpenGLHeaders.h"
#include "wx/glcanvas.h"

namespace WXWidgets {

    /**
     * The AbstractGLCanvas class implements an abstract base class of a GL Canvas
     * for displaying OpenGL Graphics.
     */
    class AbstractGLCanvas : public ICanvas, public Window, public wxGLCanvas {
    public:
        /**
         * The AbstractDialog constructor.
         */
        AbstractGLCanvas(
            wxWindow& parent,
            const wxString& name,
            const wxGLAttributes& attributes,
            long style,
            wxWindowID id,
            const wxPoint& position,
            const wxSize& size,
            const wxPalette& palette);

        /**
         * The AbstractGLCanvas destructor.
         */
        virtual ~AbstractGLCanvas();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() override;

    protected:
        /**
         * Initialize rendering.
         */
        virtual void InitializeRendering() = 0;

        /**
         * Renders painting.
         */
        virtual void RenderPainting() = 0;

    private:
        /**
         * The on paint callback.
         */
        virtual void OnPaint(wxPaintEvent& event);

        /**
         * The on size callback.
         */
        virtual void OnSize(wxSizeEvent& event);

        //
        // Creates GL Context...
        //
        using IGLContextUniqueSharedPtr = std::shared_ptr<wxGLContext>;
        IGLContextUniqueSharedPtr CreateGLContext();

        //
        // Sets current context...
        //
        void SetCurrentContext(wxGLContext& context);

        //
        // The current GL Context...
        //
        IGLContextUniqueSharedPtr m_context;

        //
        // The WX logger.
        //
        using IWXLogPtr = WXObjectPtr<wxLog>;
        IWXLogPtr m_wxLogger;
    };

} // namespace WXWidgets

#endif // ABSTRACT_GL_CANVAS_88340919_7ae6_41f0_a14d_954948363c2e
