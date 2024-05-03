#include "AbstractGLCanvas.h"
#include "wx/msw/setup.h"
#include "wx/dcclient.h"
#include "WXObjectPtr.h"
#include "OpenGLApi.h"
#include "wx/log.h"

using namespace WXWidgets;

/**
 * The AbstractGLCanvas constructor.
 */
AbstractGLCanvas::AbstractGLCanvas(
    wxWindow& parent, 
    const wxString& name, 
    const wxGLAttributes& attributes, 
    long style, 
    wxWindowID id, 
    const wxPoint& position,
    const wxSize& size, 
    const wxPalette& palette) : 
        wxGLCanvas(
            &parent, 
            attributes, 
            id, 
            position, 
            size, 
            style, 
            name, 
            palette), 
    m_wxLogger(IWXLogPtr::Make(new wxLogStderr, true))
{
    wxLog::SetActiveTarget(m_wxLogger.Get());
}

/**
 * The AbstractGLCanvas destructor.
 */
AbstractGLCanvas::~AbstractGLCanvas() 
{
    wxLog::SetActiveTarget(nullptr);
}

/**
 * Initializes a GUI component.
 */
void AbstractGLCanvas::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize component...
    //
    Window::Initialize(
        *this, 
        guiController);

    //
    // Bind callbacks...
    //
    Bind(wxEVT_PAINT, &AbstractGLCanvas::OnPaint, this);
    Bind(wxEVT_SIZE, &AbstractGLCanvas::OnSize, this);

    //
    // Create context...
    //
    m_context = CreateGLContext();

    //
    // Initialize rendering...
    // 
    InitializeRendering();
}

/**
 * Gets a window.
 */
IWindow& AbstractGLCanvas::GetWindow()
{
    return *this;
}

/**
 * The on paint callback.
 */
void AbstractGLCanvas::OnPaint(wxPaintEvent& event)
{
    if (!IsShown()) {
        return;
    }

    //
    // Set current context...
    //
    SetCurrentContext(*m_context);

    //
    // Enable debugging for open GL window...
    //
    OpenGLApi::GetInstance()->EnableDebugging();

    //
    // Log graphic information...
    //
    std::wstring graphicInformation = OpenGLApi::GetInstance()->GetGraphicInformation();
    LOG_INFO(GetLogger(), graphicInformation);

    //
    // Render painting...
    //
    RenderPainting();

    //
    // Swap buffers...
    //
    bool status = SwapBuffers();

    if (!status) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"The GL Canvas has failed swapping buffers" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

/**
 * The on size callback.
 */
void AbstractGLCanvas::OnSize(wxSizeEvent& event) 
{
}

/**
 * Creates a GL context.
 */
AbstractGLCanvas::IGLContextUniqueSharedPtr AbstractGLCanvas::CreateGLContext()
{
    //
    // Create context...
    //
    wxGLContextAttrs attributes;
    attributes.PlatformDefaults().CoreProfile().OGLVersion(
        OpenGLApi::MAJOR_VERSION, 
        OpenGLApi::MINOR_VERSION).EndList();

    IGLContextUniqueSharedPtr context = std::make_shared<wxGLContext>(
        this, 
        nullptr, 
        &attributes);

    //
    // Set current context...
    //
    SetCurrentContext(*context);

    //
    // Initialize GLEW...
    //
    OpenGLApi::GetInstance()->InitializeGlew();

    return context;
}

/**
 * Sets current context.
 */
void AbstractGLCanvas::SetCurrentContext(wxGLContext& context)
{
    bool status = SetCurrent(context);

    if (!status) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"The GL Canvas has failed setting current GL context" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }

    if (!context.IsOK()) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream messageStream;
        messageStream 
            << L"The GL Canvas has created an invalid GL context" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = messageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorMessage);
    }
}

