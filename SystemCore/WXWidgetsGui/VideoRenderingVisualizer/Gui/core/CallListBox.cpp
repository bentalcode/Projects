#include "CallListBox.h"
#include "IGuiManager.h"
#include "CallInformation.h"
#include "WXDataItems.h"
#include "GuiPaths.h"
#include "GuiDataItems.h"
#include "RefreshingTransaction.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a call list box.
 */
wxwidgets::IListBoxPtr CallListBox::Make(
    wxWindow& parent, 
    const std::vector<std::wstring>& items,
    IGuiManager& guiManager)
{
    return wxwidgets::IListBoxPtr::Make(
        new CallListBox(
            parent, 
            items, 
            guiManager));
}

/**
 * The CallListBox constructor.
 */
CallListBox::CallListBox(
    wxWindow& parent, 
    const std::vector<std::wstring>& items, 
    IGuiManager& guiManager) : 
        ListBox(
            parent, 
            GuiPaths::Read().GetMainFrameMainLeftTopWindowUpperSubWindowListBox(), 
            wxLB_SINGLE | wxVSCROLL | wxHSCROLL),
        m_guiManager(guiManager)
{
    //
    // Initialize a GUI component...
    //
    Initialize(
        items, 
        guiManager);
}

/**
 * The CallListBox destructor.
 */
CallListBox::~CallListBox() 
{
}

/**
 * Initializes a GUI component.
 */
void CallListBox::Initialize(
    const std::vector<std::wstring>& items, 
    IGuiManager& guiManager)
{
    //
    // Initialize a list box...
    //
    ListBox::Initialize(
        items, 
        guiManager.GetGuiController());
}

/**
 * The On Selected Item callback.
 */
void CallListBox::OnSelectedItem(const std::wstring& item)
{
    //
    // Parse call id from display information...
    //
    std::wstring callId = Model::CallInformation::ParseIdFromDisplayString(item);

    //
    // Query items of a compositor list box...
    //
    std::vector<std::wstring> items;
    QueryCompositorListBoxItems(callId, items);

    //
    // Query rendering pipelines time interval....
    //
    base::DateTimeIntervalSharedPtr renderingPipelinesTimeInterval = QueryRenderingPipelinesTimeInterval(callId);

    //
    // Update items of a compositor list box...
    //
    wxwidgets::controller::IControllerManagerSharedPtr controllerManager = m_guiManager.GetControllerManager();
    wxwidgets::controller::IRefreshingTransactionSharedPtr transaction = wxwidgets::controller::RefreshingTransaction::Make(*controllerManager);
    
    std::wstring compositorListBoxComponent = GuiPaths::Read().GetMainFrameMainLeftTopWindowLowerSubWindowListBox();
    
    std::wstring dataItemListBoxItems = wxwidgets::WXDataItems::Read().GetListBoxItems();
    std::wstring dataItemComponentShowMode = wxwidgets::WXDataItems::Read().GetComponentShowMode();

    transaction->UpdateData(
        compositorListBoxComponent, 
        dataItemListBoxItems,
        items);

    transaction->UpdateData(
        compositorListBoxComponent, 
        dataItemComponentShowMode,
        true);

    //
    // Update show mode of left window splitter window...
    //
    std::wstring leftWindowSplitterWindow = GuiPaths::Read().GetMainFrameMainLeftWindowSplitterWindow();
    std::wstring dataItemSplitterWindowSecondSubWindowShowMode =
        wxwidgets::WXDataItems::Read().GetSplitterWindowSecondSubWindowShowMode();

    transaction->UpdateData(
        leftWindowSplitterWindow, 
        dataItemSplitterWindowSecondSubWindowShowMode,
        true);

    //
    // Update rendering pipelines interval time of right bottom window/right top lower sub windows... 
    //
    std::vector<std::wstring> componentsToUpdate = { 
        GuiPaths::Read().GetMainFrameMainRightBottomWindowListView(),
        GuiPaths::Read().GetMainFrameMainRightTopWindowLowerSubWindowSlider() 
    };

    std::wstring dataItemRenderingPipelinesStartIntervalTime =
        GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();
    
    std::wstring dataItemRenderingPipelinesEndIntervalTime = 
        GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    for (const std::wstring& componentToUpdate : componentsToUpdate) {
        transaction->UpdateData(
            componentToUpdate, 
            dataItemRenderingPipelinesStartIntervalTime,
            *renderingPipelinesTimeInterval->GetStartTime());

        transaction->UpdateData(
            componentToUpdate, 
            dataItemRenderingPipelinesEndIntervalTime,
            *renderingPipelinesTimeInterval->GetEndTime());
    }

    //
    // Commit a refreshing transaction...
    //
    transaction->Commit();
}

/**
 * Queries items of a compositor list box.
 */
void CallListBox::QueryCompositorListBoxItems(
    const std::wstring& callId, 
    std::vector<std::wstring>& items) const
{
    //
    // Calculate corresponding compositors...
    //
    const Model::IDataRepositorySharedPtr dataRepository = m_guiManager.GetDataRepository();
    const Model::IDataQuerySharedPtr dataQuery = dataRepository->GetDataQuery();

    Model::ICompositorInformationCollectionSharedPtr compositors = dataQuery->QueryCompositors(callId);
    
    base::IIteratorSharedPtr<Model::ICompositorInformationSharedPtr> compositorInformationIterator = compositors->GetIterator();

    //
    // Create corresponding compositors items...
    //
    while (compositorInformationIterator->HasNext()) {
        Model::ICompositorInformationSharedPtr compositorInformation = compositorInformationIterator->Next();

        std::wstring item = compositorInformation->ToShortDisplayString();
        items.push_back(item);
    }
}

/**
 * Queries rendering pipelines time interval.
 */
base::DateTimeIntervalSharedPtr CallListBox::QueryRenderingPipelinesTimeInterval(const std::wstring& callId) const
{
    const Model::IDataRepositorySharedPtr dataRepository = m_guiManager.GetDataRepository();
    const Model::IDataQuerySharedPtr dataQuery = dataRepository->GetDataQuery();

    return dataQuery->QueryRenderingPipelinesTimeInterval(callId);
}
