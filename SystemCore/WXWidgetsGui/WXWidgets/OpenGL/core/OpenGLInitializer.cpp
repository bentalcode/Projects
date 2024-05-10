#include "OpenGLInitializer.h"
#include "OpenGLApi.h"

using namespace wxwidgets;

/**
 * The OpenGLInitializer constructor.
 */
OpenGLInitializer::OpenGLInitializer() :
    m_openGLApi(OpenGLApi::GetInstance())
{
    m_openGLApi->Initialize();
}

/**
 * The OpenGLInitializer destructor.
 */
OpenGLInitializer::~OpenGLInitializer()
{
    m_openGLApi->Shutdown();
}
