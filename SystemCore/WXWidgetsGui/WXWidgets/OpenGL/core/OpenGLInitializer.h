#ifndef OPEN_GL_INITIALIZER_f78ac1cc_2ed2_42c2_a820_45cd30fa5726
#define OPEN_GL_INITIALIZER_f78ac1cc_2ed2_42c2_a820_45cd30fa5726

#include "IOpenGLApi.h"

namespace WXWidgets {

    /**
     * The OpenGLInitializer class implements an initilaizer of Open GL APIs.
     * OpenGL (Open Graphics Library[3]) is a cross-language, cross-platform application programming interface (API)
     * for rendering 2D and 3D vector graphics.
     * The API is typically used to interact with a graphics processing unit (GPU), to achieve hardware-accelerated rendering.
     */
    class OpenGLInitializer final {
    public:
        /**
         * The OpenGLInitializer constructor.
         */
        OpenGLInitializer();

        /**
         * The OpenGLInitializer destructor.
         */
        virtual ~OpenGLInitializer();

    private:
        IOpenGLApiSharedPtr m_openGLApi;
    };

} // namespace WXWidgets

#endif // OPEN_GL_INITIALIZER_f78ac1cc_2ed2_42c2_a820_45cd30fa5726
