#include "OpenGLInitializer.h"
#include "OpenGLApi.h"

using namespace WXWidgets;

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
