#include "HtmlWindow.h"
#include "WXDataItems.h"
#include "DataItem.h"
#include "IDataCatalog.h"
#include "WXProperty.h"
#include "WXWidgetsException.h"

using namespace WXWidgets;

namespace HtmlWindowFunctors {

/**
 * The UpdateDataContainerContentFunctor class implements an update functor of content.
 */
class UpdateDataContainerContentFunctor final {
public:

    /**
     * The functor constructor.
     */
    UpdateDataContainerContentFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const std::wstring& content)
    { 
        HtmlWindow::UpdateDataContainerContent(m_dataContainer, content); 
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

}  // namespace HtmlWindowFunctors

/**
 * Creates a HTML window.
 */
IHtmlWindowPtr HtmlWindow::Make(
    wxWindow& parent, 
    const wxString& name, 
    wxWindowID id, 
    const wxPoint& position,
    const wxSize& size, 
    long style)
{
    return IHtmlWindowPtr::Make(
        new HtmlWindow(
            parent, 
            name, 
            id, 
            position,
            size,
            style));
}

/**
 * The HtmlWindow constructor.
 */
HtmlWindow::HtmlWindow(
    wxWindow& parent, 
    const wxString& name, 
    wxWindowID id,
    const wxPoint& position,
    const wxSize& size, 
    long style) : 
        wxHtmlWindow(
            &parent, 
            id,
            position,
            size,
            style, 
            name)
{
}

/**
 * The HtmlWindow destructor.
 */
HtmlWindow::~HtmlWindow() 
{
}

/**
 * Initializes a GUI component.
 */
void HtmlWindow::Initialize(IGuiControllerSharedPtr guiController)
{
    /**
     * Initializes window...
     */
    Window::Initialize(
        *this, 
        guiController);

    //
    // Register data items...
    //
    std::wstring dataItemHtmlWindowContent = WXDataItems::Read().GetHtmlWindowContent();

    DataContainerManagement::IDataContainer& dataContainer = GetData();
    dataContainer.GetCatalog().RegisterDataItem(dataItemHtmlWindowContent);

    //
    // Register data update functors...
    //
    DataContainerManagement::IDataContainerUpdateFunctors::IStringFunctorSharedPtr updateFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IStringFunctor>(
            HtmlWindowFunctors::UpdateDataContainerContentFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemHtmlWindowContent, 
        updateFunctor);
}

/**
 * Gets a window.
 */
IWindow& HtmlWindow::GetWindow()
{
    return *this;
}

/**
 * Loads file.
 */
void HtmlWindow::LoadFile(const std::wstring& path)
{
    wxFileName file(path);
    bool status = wxHtmlWindow::LoadFile(file);

    if (!status) {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"Html Window has failed loading file from: " << path
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetLogger(), errorMessage);
        throw WXWidgetsException(errorCode, errorMessage);
    }
}

/**
 * Updates data container (content).
 */
void HtmlWindow::UpdateDataContainerContent(
    DataContainerManagement::IDataContainer& data, 
    const std::wstring& content)
{
    std::wstring dataItemHtmlWindowContent = WXDataItems::Read().GetHtmlWindowContent();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemHtmlWindowContent, 
            content);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool HtmlWindow::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = Window::UpdateFromDataContainer(dataContainer);

    std::wstring dataItemHtmlWindowContent = WXDataItems::Read().GetHtmlWindowContent();

    if (dataContainer.HasDataItem(dataItemHtmlWindowContent)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemHtmlWindowContent);

        std::wstring content = dataItem.GetValue()->GetString();
        bool propertyUpdated = WXWidgets::WXProperty::UpdateValue(m_content, content);

        dataUpdated |= propertyUpdated;
    }

    return dataUpdated;
}

/**
 * Updates component.
 */
void HtmlWindow::Update()
{
    Window::Update();
}
