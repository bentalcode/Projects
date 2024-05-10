#ifndef I_OPEN_GL_API_a3407b9e_87f1_4424_916e_3c3ec1486100
#define I_OPEN_GL_API_a3407b9e_87f1_4424_916e_3c3ec1486100

#include <memory>
#include <string>

namespace WXWidgets {

    /**
     * The IOpenGLApi interface defines an Open GL APIs.
     * OpenGL (Open Graphics Library[3]) is a cross-language, cross-platform application programming interface (API)
     * for rendering 2D and 3D vector graphics.
     * The API is typically used to interact with a graphics processing unit (GPU), to achieve hardware-accelerated rendering.
     */
    class IOpenGLApi {
    public:
        IOpenGLApi() = default;
        virtual ~IOpenGLApi() = default;

        /**
         * Initializes Open GL API.
         */
        virtual void Initialize() = 0;

        /**
         * Shutdowns Open GL API.
         */
        virtual void Shutdown() = 0;

        /**
         * Initializes GLEW.
         */
        virtual void InitializeGlew() = 0;

        /**
         * Get Graphic Information.
         */
        virtual std::wstring GetGraphicInformation() const = 0;

        /**
         * Enables debugging.
         */
        virtual void EnableDebugging() = 0;

        /**
         * Verifies that GL Api has succeeded with no error.
         */
        virtual void VerifySuccess() = 0;
    };

    /**
     * Defines the Shared Ptr of Open GL API.
     */
    using IOpenGLApiSharedPtr = std::shared_ptr<IOpenGLApi>;

} // namespace WXWidgets

#endif // I_OPEN_GL_API_a3407b9e_87f1_4424_916e_3c3ec1486100
