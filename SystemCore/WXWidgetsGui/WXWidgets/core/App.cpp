#include "App.h"

using namespace wxwidgets;

/**
 * The App constructor.
 */
App::App() : 
    AbstractApp()
{
}

/**
 * The App destructor.
 */
App::~App() 
{
}

/**
 * Initializes a GUI component.
 */
void App::Initialize(
    const std::wstring& name, 
    IGuiControllerSharedPtr guiController)
{
    //
    // Initialize GUI component...
    //
    AbstractApp::Initialize(name, guiController);

    //
    // Set the app component in the GUI Controller...
    //
    guiController->SetAppComponent(this);
}
