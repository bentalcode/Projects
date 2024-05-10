#ifndef OPEN_GL_API_85f481f8_e58d_414f_808f_1f66a101b84f
#define OPEN_GL_API_85f481f8_e58d_414f_808f_1f66a101b84f

#include "IOpenGLApi.h"
#include "ILoggers.h"
#include <mutex>

namespace WXWidgets {

    /**
     * The OpenGLApi class implements an Open GL APIs.
     * OpenGL (Open Graphics Library[3]) is a cross-language, cross-platform application programming interface (API)
     * for rendering 2D and 3D vector graphics.
     * The API is typically used to interact with a graphics processing unit (GPU), to achieve hardware-accelerated rendering.
     */
    class OpenGLApi final : public IOpenGLApi {
    public:
        static const unsigned int MAJOR_VERSION;
        static const unsigned int MINOR_VERSION;

        /**
         * Gets an instance of a Open GL API.
         */
        static IOpenGLApiSharedPtr GetInstance();

        /**
         * The OpenGLApi constructor.
         */
        OpenGLApi();

        /**
         * The OpenGLApi destructor.
         */
        virtual ~OpenGLApi();

        /**
         * Initializes Open GL API.
         */
        virtual void Initialize() override;

        /**
         * Shutdowns Open GL API.
         */
        virtual void Shutdown() override;

        /**
         * Initializes GLEW.
         */
        virtual void InitializeGlew() override;

        /**
         * Get Graphic Information.
         */
        virtual std::wstring GetGraphicInformation() const override;

        /**
         * Enables debugging.
         */
        virtual void EnableDebugging() override;

        /**
         * Verifies that GL Api has succeeded with no error.
         */
        virtual void VerifySuccess() override;

        /**
         * Clears errors.
         */
        static void ClearErrors();

        /**
         * Verifies that the last call to GL API has succeeded with no error.
         */
        static void VerifyLastGLCall(
            const char* function,
            const char* file,
            int line);

        /**
         * Gets last GL API status.
         */
        static bool GetLastGLCallStatus(
            const char* function,
            const char* file,
            int line,
            std::wstring& errorMessage);

    private:
        //
        // The Singletone data...
        //
        static IOpenGLApiSharedPtr INSTANCE;
        static std::mutex MUTEX;

        /**
         * Logs GL call.
         */
        static void LogGLCall(const std::wstring& errorMessage);

        /**
         * Gets error message.
         */
        static std::wstring GetErrorMessage(
            int statusCode,
            const char* function,
            const char* file,
            int line);

        /**
         * The OnError Callback.
         */
        static void OnError(int error, const char* description);

        /**
         * The OnDebug Callback.
         */
        static void OnDebug(
            unsigned int source,
            unsigned int type,
            unsigned int id,
            unsigned int severity,
            int length,
            const char* message,
            const void* userParam);

        /**
         * Gets a static logger.
         */
        static logging::ILoggerSharedPtr GetSLogger();

        logging::ILoggersSharedPtr m_loggers;
    };

    #define GL_CALL(x)                       \
        WXWidgets::OpenGLApi::ClearErrors(); \
        x;                                   \
        WXWidgets::OpenGLApi::VerifyLastGLCall(#x, __FILE__, __LINE__);

} // namespace WXWidgets

#endif // OPEN_GL_API_85f481f8_e58d_414f_808f_1f66a101b84f
