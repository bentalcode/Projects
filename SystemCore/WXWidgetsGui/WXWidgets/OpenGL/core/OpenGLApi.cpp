#include "OpenGLApi.h"
#include "OpenGLHeaders.h"
#include "GLErrorCodes.h"
#include "StringUtils.h"
#include "Loggers.h"
#include "WXWidgetsException.h"
#include "wx/msgdlg.h"
#include <iostream>
#include <assert.h>

using namespace WXWidgets;

const unsigned int OpenGLApi::MAJOR_VERSION = 3;
const unsigned int OpenGLApi::MINOR_VERSION = 3;

IOpenGLApiSharedPtr OpenGLApi::INSTANCE;
std::mutex OpenGLApi::MUTEX;

/**
 * Gets an instance of a Open GL API.
 */
IOpenGLApiSharedPtr OpenGLApi::GetInstance() 
{
    if (!INSTANCE) {
        std::lock_guard<std::mutex> lock(MUTEX);

        if (!INSTANCE) {
            INSTANCE = std::make_shared<OpenGLApi>();
        }
    }

    return INSTANCE;
}

/**
 * The OpenGLApi constructor.
 */
OpenGLApi::OpenGLApi() :
    m_loggers(logging::Loggers::Make(typeid(WXWidgets::OpenGLApi)))
{
}

/**
 * The OpenGLApi destructor.
 */
OpenGLApi::~OpenGLApi() 
{
}

/**
 * Initializes Open GL API.
 */
void OpenGLApi::Initialize()
{
    //
    // Initializes the GLFW library...
    //
    int status = glfwInit();

    if (status != GLFW_TRUE) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Open GL API has failed initializing GLFW library" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    //
    // Setting callback. 
    // Calling twice for verifying that the callback has really been set.
    // The glfwSetErrorCallback API returns previously set callback or nullptr if no callback has been set or an error occurred.
    // Therefore, there is no way to determine on startup where no previous callback is set, 
    // that the API has really succeeded on the first attempt.
    //
    GLFWerrorfun glfwStatus = glfwSetErrorCallback(&OpenGLApi::OnError);
    glfwStatus = glfwSetErrorCallback(&OpenGLApi::OnError);

    if (glfwStatus == nullptr) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Open GL API has failed setting an error callback with GLFW library"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MINOR_VERSION);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    std::wstringstream informationalStream;
    informationalStream 
        << L"The Open GL API of GLFW library has been initialized successfully.";

    std::wstring informationalMessage = informationalStream.str();
    LOG_INFO(m_loggers->GetLogger(), informationalMessage);

    std::wstringstream informationalSettingsStream;
    informationalSettingsStream
        << L" GLFW_CONTEXT_VERSION_MAJOR: " << MAJOR_VERSION 
        << L" GLFW_CONTEXT_VERSION_MINOR: " << MINOR_VERSION
        << L" GLFW_OPENGL_PROFILE: GLFW_OPENGL_CORE_PROFILE";

    std::wstring informationalSettings = informationalSettingsStream.str();
    LOG_INFO(m_loggers->GetLogger(), informationalSettings);
}

/**
 * Shutdowns Open GL API.
 */
void OpenGLApi::Shutdown()
{
    //
    // Uninitializes the GLFW library...
    //
    glfwTerminate();

    std::wstringstream informationalStream;
    informationalStream << L"The Open GL API of GLFW library has been shutdown successfully.";

    std::wstring informationalMessage = informationalStream.str();
    LOG_INFO(m_loggers->GetLogger(), informationalMessage);
}

/**
 * Initializes GLEW.
 */
void OpenGLApi::InitializeGlew() 
{
    //
    // Initialize GLEW library...
    //
    GLenum status = glewInit();

    if (status != GLEW_OK) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The Open GL API has failed initializing GLEW library" 
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }

    std::wstringstream informationalStream;
    informationalStream << L"The Open GL API has initialized GLEW library successfully.";

    std::wstring informationalMessage = informationalStream.str();
    LOG_INFO(m_loggers->GetLogger(), informationalMessage);
}

/**
 * Gets Graphic Information.
 */
std::wstring OpenGLApi::GetGraphicInformation() const 
{
    std::wstring version = base::StringUtils::StringToWideString(reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    std::wstring vendor = base::StringUtils::StringToWideString(reinterpret_cast<const char*>(glGetString(GL_VENDOR)));

    std::wstringstream informationStream;
    informationStream 
        << L"Graphic Information:" 
        << L" [Version: " << version << L"]" 
        << L" [Vendor: " << vendor << L"]";

    return informationStream.str();
}

/**
 * Enables debugging.
 */
void OpenGLApi::EnableDebugging() 
{ 
    int contextFlags = 0; 
    glGetIntegerv(GL_CONTEXT_FLAGS, &contextFlags);
    
    if (contextFlags && GL_CONTEXT_FLAG_DEBUG_BIT) {
    
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(OpenGLApi::OnDebug, nullptr);
        
        GLenum source = GL_DONT_CARE;
        GLenum type = GL_DONT_CARE;
        GLenum severity = GL_DONT_CARE;
        GLsizei count = 0;
        const GLuint* ids = nullptr; 
        GLboolean enabled = GL_TRUE;

        glDebugMessageControl(
            source, 
            type, 
            severity, 
            count, 
            ids, 
            enabled);
    }
}

/**
 * Verifies that GL Api has succeeded with no error.
 */
void OpenGLApi::VerifySuccess() 
{
    while (true) {
        GLenum glStatusCode = glGetError();

        if (glStatusCode == GL_NO_ERROR) {
            break;
        }

        long errorCode = base::ErrorCodes::FAIL;
        std::wstring errorMessage = GetErrorMessage(
            glStatusCode,
            "OpenGLApi::VerifySuccess", 
            __FILE__, 
            __LINE__);

        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }
}

/**
 * Clears errors.
 */
void OpenGLApi::ClearErrors()
{ 
    std::vector<std::wstring> previousErrors;

    while (true) {
        GLenum statusCode = glGetError();
        
        if (statusCode == GL_NO_ERROR) {
            break;
        }

        std::wstring errorMessage = GLErrorCodes::GetErrorMessage(statusCode);
        previousErrors.push_back(errorMessage);
    }

    if (!previousErrors.empty()) {
        std::wstringstream messageStream;
        messageStream 
            << L"Open GL API has found previous errors while cleaning error buffer" 
            << L"; Warnings: " << base::StringUtils::ToString(previousErrors, L", ");

        std::wstring warningMessage = messageStream.str();
        LOG_WARNING(GetSLogger(), warningMessage);
    }
}

/**
 * Verifies that the last call to GL API has succeeded with no error.
 */
void OpenGLApi::VerifyLastGLCall(
    const char* function, 
    const char* file, 
    int line)
{
    std::wstring errorMessage;
    bool status = GetLastGLCallStatus(
        function, 
        file, 
        line, 
        errorMessage);

    if (!status) {
        __debugbreak();

        throw WXWidgetsException(
            base::ErrorCodes::FAIL,
            errorMessage);
    }
}

/**
 * Gets last GL API status.
 */
bool OpenGLApi::GetLastGLCallStatus(
    const char* function, 
    const char* file, 
    int line, 
    std::wstring& errorMessage)
{
    assert(errorMessage.empty());

    bool status = true;
    GLenum glStatusCode = GL_NO_ERROR;

    while ((glStatusCode = glGetError()) != GL_NO_ERROR) {
        std::wstring currErrorMessage = GetErrorMessage(glStatusCode, function, file, line);

        LogGLCall(currErrorMessage);

        if (errorMessage.empty()) {
            errorMessage = currErrorMessage;
        }
    }

    return status;
}

/**
 * Logs GL call.
 */
void OpenGLApi::LogGLCall(const std::wstring& errorMessage)
{
    LOG_ERROR(GetSLogger(), errorMessage);
    wxMessageBox(errorMessage);
}

/**
 * Gets error message.
 */
std::wstring OpenGLApi::GetErrorMessage(
    int statusCode, 
    const char* function, 
    const char* file, 
    int line)
{
    assert(statusCode != GL_NO_ERROR);

    long errorCode = base::ErrorCodes::FAIL;
    std::wstring glErrorCode = base::ErrorCodes::GetErrorCodeString(statusCode);
    std::wstring glErrorMessage = GLErrorCodes::GetErrorMessage(statusCode);

    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"Open GL API has failed" << L", GL Error Code: " << glErrorCode 
        << L", GL Error Message: " << glErrorMessage 
        << L", Function: " << function << L" -> ["
        << base::StringUtils::StringToWideString(file) << L", " << line << "]" << L"; ErrorCode: "
        << L"" << std::hex << errorCode << std::endl;

    return errorMessageStream.str();
}

/**
 * The OnError Callback.
 */
void OpenGLApi::OnError(int error, const char* description)
{
    std::wstring message = base::StringUtils::StringToWideString(description);
    long errorCode = base::ErrorCodes::FAIL;

    std::wstring glErrorCode = base::ErrorCodes::GetErrorCodeString(error);
    std::wstring glErrorMessage = GLErrorCodes::GetErrorMessage(error);

    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"Open GL API has failed with the following "
        << L" Description: " << base::StringUtils::StringToWideString(description)
        << L", GL Error Code: " << glErrorCode
        << L", GL Error Message: " << glErrorMessage 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();
    throw WXWidgetsException(errorCode, errorMessage);
}

/**
 * The On Debug Callback.
 */
void OpenGLApi::OnDebug(
    unsigned int source,
    unsigned int type,
    unsigned int id,
    unsigned int severity,
    int length,
    const char* message,
    const void* userParam)
{
    std::wstringstream informationStream;
    informationStream 
        << L"OpenGLApi::OnDebug " 
        << L" Source: " << source 
        << L" Type: " << type 
        << L" Id: " << id 
        << L" Severity: " << severity 
        << L" Length: " << length;

    LOG_INFO(GetSLogger(), informationStream.str());
}

/**
 * Gets a static logger.
 */
logging::ILoggerSharedPtr OpenGLApi::GetSLogger()
{
    static logging::ILoggersSharedPtr loggers = logging::Loggers::Make(typeid(WXWidgets::OpenGLApi));
    return loggers->GetLogger();
}
