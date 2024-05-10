#include "CompositorTextBox.h"
#include "CompositorInformation.h"
#include "GuiPaths.h"
#include "GuiDataItems.h"
#include "DataItem.h"
#include "IDataCatalog.h"
#include "WXProperty.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

namespace CompositorTextBoxFunctors {

/**
 * The UpdateDataContainerCompositorIdFunctor class implements an update functor of compositor id.
 */
class UpdateDataContainerCompositorIdFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerCompositorIdFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const std::wstring& compositorId)
    {
        CompositorTextBox::UpdateDataContainerCompositorId(m_dataContainer, compositorId);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

}  // namespace CompositorTextBoxFunctors

/**
 * Creates a compositor static text box.
 */
WXWidgets::IStaticTextPtr CompositorTextBox::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return WXWidgets::IStaticTextPtr::Make(
        new CompositorTextBox(
            parent, 
            guiManager));
}

/**
 * The CompositorTextBox constructor.
 */
CompositorTextBox::CompositorTextBox(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
        WXWidgets::StaticText(
            parent, 
            GuiPaths::Read().GetMainFrameMainLeftBottomWindowStaticText()), 
            m_guiManager(guiManager)
{
    //
    // Initialize a GUI component...
    //
    Initialize(guiManager);
}

/**
 * The CompositorTextBox destructor.
 */
CompositorTextBox::~CompositorTextBox() 
{
}

/**
 * Initializes a GUI component.
 */
void CompositorTextBox::Initialize(IGuiManager& guiManager)
{
    //
    // Initialize static text...
    //
    WXWidgets::StaticText::Initialize(guiManager.GetGuiController());

    //
    // Register data items...
    //
    std::wstring dataItemCompositorId = GuiDataItems::Read().GetCompositorId();

    DataContainerManagement::IDataContainer& dataContainer = GetData();
    dataContainer.GetCatalog().RegisterDataItem(dataItemCompositorId);

    //
    // Register data update functors...
    //
    DataContainerManagement::IDataContainerUpdateFunctors::IStringFunctorSharedPtr updateFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IStringFunctor>(
            CompositorTextBoxFunctors::UpdateDataContainerCompositorIdFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemCompositorId, 
        updateFunctor);
}

/**
 * Updates data container (compositor id).
 */
void CompositorTextBox::UpdateDataContainerCompositorId(
    DataContainerManagement::IDataContainer& data, 
    const std::wstring& compositorId)
{
    std::wstring dataItemName = GuiDataItems::Read().GetCompositorId();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            compositorId);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool CompositorTextBox::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = false;

    std::wstring compositorInformation;

    std::wstring dataItemCompositorId = GuiDataItems::Read().GetCompositorId();

    if (dataContainer.HasDataItem(dataItemCompositorId)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemCompositorId);

        std::wstring compositorId = dataItem.GetValue()->GetString();
        compositorInformation = QueryCompositorDisplayInformation(compositorId);

        bool propertyUpdated = WXWidgets::WXProperty::UpdateValue(m_compositorId, compositorId);

        dataUpdated |= propertyUpdated;

        if (propertyUpdated) {
            StaticText::UpdateDataContainerText(dataContainer, compositorInformation);
            bool propertyUpdated = StaticText::UpdateFromDataContainer(dataContainer);

            dataUpdated |= propertyUpdated;
        }
    }

    return dataUpdated;
}

/**
 * Queries display information of a compositor.
 */
std::wstring CompositorTextBox::QueryCompositorDisplayInformation(const std::wstring& compositorId) 
{
    const Model::IDataRepositorySharedPtr dataRepository = m_guiManager.GetDataRepository();
    const Model::IDataModelSharedPtr dataModel = dataRepository->GetDataModel();

    const Model::ICompositorInformationCollectionSharedPtr compositorsInformationCollection = dataModel->GetCompositors();
    Model::ICompositorInformationSharedPtr compositorInformation = compositorsInformationCollection->GetItem(compositorId);

    return compositorInformation->ToDisplayString();
}
