#include "AbstractWindow.h"
#include "wx/window.h"
#include "WXDataItems.h"
#include "PreRefreshEventInternal.h"
#include "RefreshEventInternal.h"
#include "PostRefreshEventInternal.h"
#include "WindowUpdationEventInternal.h"
#include "WXProperty.h"
#include "WindowLogic.h"

using namespace wxwidgets;

/**
 * The AbstractWindow constructor.
 */
AbstractWindow::AbstractWindow() 
{
}

/**
 * The AbstractWindow destructor.
 */
AbstractWindow::~AbstractWindow() 
{
}

/**
 * Initializes a GUI component.
 */
void AbstractWindow::Initialize(
    const IOnPreRefreshFunctorSharedPtr onPreRefreshFunctor,
    const IOnRefreshFunctorSharedPtr onRefreshFunctor,
    const IOnPostRefreshFunctorSharedPtr onPostRefreshFunctor,
    const IOnUpdationFunctorSharedPtr onUpdationFunctor,
    wxWindow& window, 
    IGuiControllerSharedPtr guiController, 
    bool showMode)
{
    //
    // Initialize GUI component...
    //
    std::wstring name = window.GetName().ToStdWstring();
    
    GuiComponent::Initialize(
        name, 
        window,
        guiController);

    //
    // Initialize functors...
    //
    m_onPreRefreshFunctor = onPreRefreshFunctor;
    m_onRefreshFunctor = onRefreshFunctor;
    m_onPostRefreshFunctor = onPostRefreshFunctor;
    m_onUpdationFunctor = onUpdationFunctor;

    //
    // Initialize window...
    //
    m_window = &window;
    m_showMode = showMode;

    //
    // Reset component...
    //
    Reset();

    //
    // Bind callbacks...
    //
    m_window->Bind(PreRefreshEventInternal::TYPE, &AbstractWindow::InternalOnPreRefresh, this);
    m_window->Bind(RefreshEventInternal::TYPE, &AbstractWindow::InternalOnRefresh, this);
    m_window->Bind(PostRefreshEventInternal::TYPE, &AbstractWindow::InternalOnPostRefresh, this);
    m_window->Bind(WindowUpdationEventInternal::TYPE, &AbstractWindow::InternalOnUpdation, this);
}

/**
 * Sets size.
 */
void AbstractWindow::SetSize(const wxSize& size)
{
    m_window->SetSize(size);
}

/**
 * Maximizes window.
 */
void AbstractWindow::Maximize()
{
    wxWindow* parent = m_window->GetParent();
    wxSize parentSize = parent->DoGetVirtualSize();
    m_window->SetSize(parentSize);
}

/**
 * Centralizes window.
 */
void AbstractWindow::Centralize()
{
    m_window->Centre();
}

/**
 * Maximizes and centeralize window.
 */
void AbstractWindow::MaximizeAndCenteralize()
{
    Maximize();
    Centralize();
}

/**
 * Gets a window.
 */
wxWindow& AbstractWindow::AsWindow()
{
    return *m_window;
}

/**
 * Gets a GUI component.
 */
IGuiComponent& AbstractWindow::GetComponent()
{
    return *this;
}

/**
 * Shows or hides a window.
 */
void AbstractWindow::ShowOrHide(bool showMode)
{
    m_window->Show(showMode);
}

/**
 * Gets parent windows.
 */
void AbstractWindow::GetParentWindows(std::vector<wxWindow*>& windows)
{
    IWindowLogicSharedPtr windowLogic = WindowLogic::Make();
    windowLogic->GetParentWindows(*m_window, windows);
}

/**
 * Gets parent windows.
 */
void AbstractWindow::GetParentWindows(std::vector<const wxWindow*>& windows) const
{
    IWindowLogicSharedPtr windowLogic = WindowLogic::Make();
    windowLogic->GetParentWindows(*m_window, windows);
}

/**
 * Finds a common ancestor window.
 */
wxWindow* AbstractWindow::FindCommonAncestor(wxWindow& left, wxWindow& right)
{
    IWindowLogicSharedPtr windowLogic = WindowLogic::Make();
    return windowLogic->FindCommonAncestor(left, right);
}

/**
 * Finds a common ancestor window.
 */
const wxWindow* AbstractWindow::FindCommonAncestor(const wxWindow& left, const wxWindow& right) const
{
    IWindowLogicSharedPtr windowLogic = WindowLogic::Make();
    return windowLogic->FindCommonAncestor(left, right);
}

/**
 * Checks whether a window has a scrollbar.
 */
bool AbstractWindow::ScrollbarExists(Orient orient) const
{
    int orientValue = OrientValue(orient);
    return m_window->CanScroll(orientValue);
}

/**
 * Sets scrollbar of a window to min position.
 */
void AbstractWindow::SetScrollbarToMinPosition(Orient orient)
{
    int orientValue = OrientValue(orient);
    m_window->SetScrollPos(orientValue, 0, true);
}

/**
 * Sets scrollbar of a window to max position.
 */
void AbstractWindow::SetScrollbarToMaxPosition(Orient orient)
{
    int orientValue = OrientValue(orient);
    int range = m_window->GetScrollRange(orientValue);
    m_window->SetScrollPos(orientValue, range, true);
}

/**
 * The On Pre Refresh callback - Default Implementation.
 */
void AbstractWindow::OnPreRefresh(IGuiTransactionSharedPtr guiTransaction) 
{
}

/**
 * The On Refresh callback - Default Implementation.
 */
void AbstractWindow::OnRefresh(IGuiTransactionSharedPtr guiTransaction) 
{
    //
    // Update data from it's data container...
    //
    bool dataUpdated = UpdateFromDataContainer(GetData());

    //
    // Refresh component only in case data has been updated...
    //
    if (dataUpdated) {
        Update();

        m_window->Refresh();
    }
}

/**
 * The On Post Refresh callback - Default Implementation.
 */
void AbstractWindow::OnPostRefresh(IGuiTransactionSharedPtr guiTransaction)
{
    std::wstring name = GuiComponent::GetName();
    guiTransaction->SetComponentTransactionCompleted(name);
}

/**
 * The On Updation callback - Default Implementation.
 */
void AbstractWindow::OnUpdation() 
{
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool AbstractWindow::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = false;

    std::wstring dataItemName = WXDataItems::Read().GetComponentShowMode();

    if (dataContainer.HasDataItem(dataItemName)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemName);

        bool newShowMode = dataItem.GetValue()->GetBoolean();
        bool propertyUpdated = wxwidgets::WXProperty::UpdateValue(m_showMode, newShowMode);

        dataUpdated = propertyUpdated;
    }

    return dataUpdated;
}

/**
 * Updates component.
 */
void AbstractWindow::Update()
{
    //
    // Update component...
    //
    GuiComponent::Update();

    //
    // Reset component...
    //
    Reset();
}

/**
 * Resets component.
 */
void AbstractWindow::Reset() 
{
    //
    // Show or hide a component...
    //
    ShowOrHide(m_showMode);
}

/**
 * The internal On Pre Refresh callback.
 */
void AbstractWindow::InternalOnPreRefresh(PreRefreshEventInternal& event)
{
    //
    // Perform callback logic...
    //
    if (m_onPreRefreshFunctor) {
        m_onPreRefreshFunctor->operator()(event.GetGuiTransaction());
    }
}

/**
 * The internal On Refresh callback.
 */
void AbstractWindow::InternalOnRefresh(RefreshEventInternal& event)
{
    //
    // Perform callback logic...
    //
    if (m_onRefreshFunctor) {
        m_onRefreshFunctor->operator()(event.GetGuiTransaction());
    }
}

/**
 * The internal On Post Refresh callback.
 */
void AbstractWindow::InternalOnPostRefresh(PostRefreshEventInternal& event)
{
    //
    // Perform callback logic...
    //
    if (m_onPostRefreshFunctor) {
        m_onPostRefreshFunctor->operator()(event.GetGuiTransaction());
    }
}

/**
 * The internal On Updation callback.
 */
void AbstractWindow::InternalOnUpdation(const WindowUpdationEventInternal& event)
{
    //
    // Perform callback logic...
    //
    if (m_onUpdationFunctor) {
        m_onUpdationFunctor->operator()();
    }
}
