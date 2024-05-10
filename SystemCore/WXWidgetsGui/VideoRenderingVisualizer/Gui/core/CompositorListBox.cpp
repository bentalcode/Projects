#include "CompositorListBox.h"
#include "IGuiManager.h"
#include "CompositorInformation.h"
#include "GuiPaths.h"
#include "GuiDataItems.h"
#include "RefreshingTransaction.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Rendering Pipelines List Box.
 */
wxwidgets::IListBoxPtr CompositorListBox::Make(
    wxWindow& parent, 
    const std::vector<std::wstring>& items,
    IGuiManager& guiManager)
{
    return wxwidgets::IListBoxPtr::Make(new CompositorListBox(
        parent, 
        items, 
        guiManager));
}

/**
 * The CompositorListBox constructor.
 */
CompositorListBox::CompositorListBox(
    wxWindow& parent, 
    const std::vector<std::wstring>& items, 
    IGuiManager& guiManager) : 
        ListBox(
            parent, 
            GuiPaths::Read().GetMainFrameMainLeftTopWindowLowerSubWindowListBox(), 
            wxLB_SINGLE | wxVSCROLL | wxHSCROLL), 
    m_guiManager(guiManager)
{
    //
    // Initialize a GUI component...
    //
    Initialize(items);
}

/**
 * The CompositorListBox destructor.
 */
CompositorListBox::~CompositorListBox() 
{
}

/**
 * Initializes a GUI component.
 */
void CompositorListBox::Initialize(const std::vector<std::wstring>& items)
{
    ListBox::Initialize(
        items, 
        m_guiManager.GetGuiController());
}

/**
 * The On Selected Item callback.
 */
void CompositorListBox::OnSelectedItem(const std::wstring& item)
{
    //
    // Parse compositor id...
    //
    std::wstring compositorId = Model::CompositorInformation::ParseIdFromShortDisplayString(item);

    //
    // Update data of a compositor text box...
    //
    wxwidgets::controller::IControllerManagerSharedPtr controllerManager = m_guiManager.GetControllerManager();
    wxwidgets::controller::IRefreshingTransactionSharedPtr transaction = wxwidgets::controller::RefreshingTransaction::Make(*controllerManager);

    std::wstring leftBottomWindowCompositorTextBox = GuiPaths::Read().GetMainFrameMainLeftBottomWindowStaticText();
    std::wstring dataItemCompositorId = GuiDataItems::Read().GetCompositorId();

    transaction->UpdateData(
        leftBottomWindowCompositorTextBox, 
        dataItemCompositorId, 
        compositorId);

    transaction->Commit();
}
