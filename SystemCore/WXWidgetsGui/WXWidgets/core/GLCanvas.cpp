#include "GLCanvas.h"

using namespace WXWidgets;

/**
 * The GLCanvas constructor.
 */
GLCanvas::GLCanvas(
    wxWindow& parent, 
    const wxString& name, 
    const wxGLAttributes& attributes,
    long style, 
    wxWindowID id,
    const wxPoint& position, 
    const wxSize& size,
    const wxPalette& palette) : 
        AbstractGLCanvas(
            parent, 
            name, 
            attributes, 
            style, 
            id, 
            position, 
            size, 
            palette)
{
}

/**
 * The GLCanvas destructor.
 */
GLCanvas::~GLCanvas()
{
}

/**
 * Initializes a GUI component.
 */
void GLCanvas::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize GUI component...
    //
    AbstractGLCanvas::Initialize(guiController);
}

/**
 * Validates attributes.
 */
void GLCanvas::ValidateAttributes(const wxGLAttributes& attributes) 
{
    if (!wxGLCanvas::IsDisplaySupported(attributes))
    {
        assert(false);

        long errorCode = base::ErrorCodes::FAIL;
        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The GL Canvas does not support configured attributes"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }
}

/**
 * Gets default attributes of canvas.
 */
const wxGLAttributes& GLCanvas::CreateDefaultAttributes()
{
    static std::unique_ptr<wxGLAttributes> attributesPtr;

    if (!attributesPtr) {
        attributesPtr.reset(new wxGLAttributes);
        InitializeDefaultAttributes(*attributesPtr);
    }

    return *attributesPtr;
}

/**
 * Initializes default attributes.
 */
void GLCanvas::InitializeDefaultAttributes(wxGLAttributes& attributes)
{
    attributes.PlatformDefaults().Defaults().EndList();
    ValidateAttributes(attributes);
}
