#include "Window.h"
#include "WindowUpdationEventInternal.h"

using namespace wxwidgets;

namespace WindowFunctors {

/**
 * The OnPreRefreshFunctor class implements an On Pre Refresh functor.
 */
class OnPreRefreshFunctor final {
public:
    /**
     * The functor constructor.
     */
    explicit OnPreRefreshFunctor(Window& component) :
        m_component(component)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(IGuiTransactionSharedPtr guiTransaction)
    {
        m_component.OnPreRefresh(guiTransaction);
    }

private:
    Window& m_component;
};

/**
 * The OnRefreshFunctor class implements an On Refresh functor.
 */
class OnRefreshFunctor final {
public:
    /**
     * The functor constructor.
     */
    explicit OnRefreshFunctor(Window& component) :
        m_component(component)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(IGuiTransactionSharedPtr guiTransaction)
    {
        m_component.OnRefresh(guiTransaction);
    }

private:
    Window& m_component;
};

/**
 * The OnPostRefreshFunctor class implements an On Post Refresh functor.
 */
class OnPostRefreshFunctor final {
public:
    /**
     * The functor constructor.
     */
    explicit OnPostRefreshFunctor(Window& component) :
        m_component(component)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(IGuiTransactionSharedPtr guiTransaction)
    {
        m_component.OnPostRefresh(guiTransaction);
    }

private:
    Window& m_component;
};

/**
 * The OnUpdationFunctor class implements an On Updation functor.
 */
class OnUpdationFunctor final {
public:
    /**
     * The functor constructor.
     */
    explicit OnUpdationFunctor(Window& window) :
        m_window(window)
    {
    }

    /**
     * The functor logic.
     */
    void operator()()
    {
        m_window.OnUpdation();
    }

private:
    Window& m_window;
};

} // namespace WindowFunctors

/**
 * The Window constructor.
 */
Window::Window() :
    AbstractWindow()
{
}

/**
 * The Window destructor.
 */
Window::~Window() 
{
}

/**
 * Window a GUI component.
 */
void Window::Initialize(
    wxWindow& window, 
    IGuiControllerSharedPtr guiController, 
    bool showMode)
{
    //
    // Initialize window...
    //
    Window::IOnPreRefreshFunctorSharedPtr onPreRefreshFunctor =
        std::make_shared<Window::IOnPreRefreshFunctor>(WindowFunctors::OnPreRefreshFunctor{ *this });

    Window::IOnRefreshFunctorSharedPtr onRefreshFunctor =
        std::make_shared<Window::IOnRefreshFunctor>(WindowFunctors::OnRefreshFunctor{ *this });

    Window::IOnPostRefreshFunctorSharedPtr onPostRefreshFunctor =
        std::make_shared<Window::IOnPostRefreshFunctor>(WindowFunctors::OnPostRefreshFunctor{ *this });

    Window::IOnUpdationFunctorSharedPtr onUpdationFunctor = 
        std::make_shared<Window::IOnUpdationFunctor>(WindowFunctors::OnUpdationFunctor{ *this });

    AbstractWindow::Initialize(
        onPreRefreshFunctor, 
        onRefreshFunctor, 
        onPostRefreshFunctor, 
        onUpdationFunctor,
        window, 
        guiController, 
        showMode);
}
