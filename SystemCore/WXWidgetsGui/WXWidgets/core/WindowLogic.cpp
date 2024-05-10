#include "WindowLogic.h"
#include "Loggers.h"
#include "wx/window.h"
#include "WXWidgetsException.h"

using namespace wxwidgets;

/**
 * Creates a window logic.
 */
IWindowLogicSharedPtr WindowLogic::Make()
{
    return std::make_shared<WindowLogic>();
}

/**
 * The WindowLogic constructor.
 */
WindowLogic::WindowLogic() : 
    m_loggers(logging::Loggers::Make(typeid(wxwidgets::WindowLogic)))
{
}

/**
 * The WindowLogic destructor.
 */
WindowLogic::~WindowLogic() 
{
}

/**
 * Gets root window.
 */
wxWindow& WindowLogic::GetRootWindow(wxWindow& window) const
{
    wxWindow* currWindow = &window;

    while (true) {
        wxWindow* parentWindow = currWindow->GetParent();

        if (parentWindow == nullptr) {
            return *currWindow;
        }

        currWindow = parentWindow;
    }

    assert(false);
    long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;
    
    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"The root window has not been found" 
        << base::ErrorMessages::GetErrorCodeMessage(errorCode);
    
    std::wstring errorMessase = errorMessageStream.str();

    LOG_ERROR(m_loggers->GetLogger(), errorMessase);
    throw WXWidgetsException(errorCode, errorMessase);
}

/**
 * Gets root window.
 */
const wxWindow& WindowLogic::GetRootWindow(const wxWindow& window) const
{
    return GetRootWindow(const_cast<wxWindow&>(window));
}

/**
 * Gets parent windows.
 */
void WindowLogic::GetParentWindows(
    wxWindow& window, 
    std::vector<wxWindow*>& windows) const
{
    assert(windows.empty());

    wxWindow* currWindow = window.GetParent();

    while (currWindow != nullptr) {
        windows.push_back(currWindow);
        currWindow = currWindow->GetParent();
    }
}

/**
 * Gets parent windows.
 */
void WindowLogic::GetParentWindows(
    const wxWindow& window, 
    std::vector<const wxWindow*>& windows) const
{ 
    assert(windows.empty());

    std::vector<wxWindow*> result;
    GetParentWindows(const_cast<wxWindow&>(window), result);

    windows.insert(windows.end(), result.begin(), result.end());
}

 /**
 * Finds a common ancestor window.
 * Returns nullptr if no common ancestor has been found.
 */
wxWindow* WindowLogic::FindCommonAncestor(
    wxWindow& first, 
    wxWindow& second) const
{
    if (&first == &second) {
        return &first;
    }

    std::vector<wxWindow*> firstAncestors;
    GetParentWindows(first, firstAncestors);

    std::vector<wxWindow*> secondAncestors;
    GetParentWindows(second, secondAncestors);

    for (wxWindow* firstAncestor : firstAncestors) {
        for (wxWindow* secondAncestor : secondAncestors) {
            if (firstAncestor == secondAncestor) {
                return firstAncestor;
            }
        }
    }

    return nullptr;
}

/**
 * Finds a common ancestor window.
 * Returns nullptr if no common ancestor has been found.
 */
const wxWindow* WindowLogic::FindCommonAncestor(
    const wxWindow& first, 
    const wxWindow& second) const
{
    return FindCommonAncestor(
        const_cast<wxWindow&>(first), 
        const_cast<wxWindow&>(second));
}
