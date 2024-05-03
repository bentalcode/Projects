#include "SplitterWindow.h"

using namespace WXWidgets;

namespace SplitterWindowFunctors {

/**
 * The OnUpdationFunctor class implements an On Updation functor.
 */
class OnUpdationFunctor final {
public:
    /**
     * The functor constructor.
     */
    OnUpdationFunctor(SplitterWindow& splitterWindow) : 
        m_splitterWindow(splitterWindow)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const ISplitterWindowConfiguration& configuration)
    {
        m_splitterWindow.OnUpdation(configuration);
    }

private:
    SplitterWindow& m_splitterWindow;
};

}  // namespace SplitterWindowFunctors

/**
 * The SplitterWindow constructor.
 */
SplitterWindow::SplitterWindow(
    const wxString& name, 
    wxWindow& parent, 
    wxWindowID id,
    const wxPoint& position, 
    const wxSize& size, 
    long style) : 
        AbstractSplitterWindow(
            name, 
            parent, 
            id, 
            position,
            size, 
            style)
{
}

/**
 * The SplitterWindow destructor.
 */
SplitterWindow::~SplitterWindow() 
{
}

/**
 * Initializes a GUI component.
 */
void SplitterWindow::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize splitter window...
    //
    SplitterWindow::IOnUpdationFunctorSharedPtr onUpdationFunctor =
        std::make_shared<SplitterWindow::IOnUpdationFunctor>(SplitterWindowFunctors::OnUpdationFunctor{ *this });

    AbstractSplitterWindow::Initialize(
        onUpdationFunctor, 
        guiController);
}

/**
 * The on updation callback - Default Implementation.
 */
void SplitterWindow::OnUpdation(const ISplitterWindowConfiguration& configuration)
{
}
