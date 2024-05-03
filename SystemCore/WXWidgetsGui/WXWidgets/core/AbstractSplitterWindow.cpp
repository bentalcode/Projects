#include "AbstractSplitterWindow.h"
#include "SplitterWindowConfiguration.h"
#include "SmartPointers.h"
#include "WXDataItems.h"
#include "DataItem.h"
#include "IDataCatalog.h"
#include "WXProperty.h"
#include "WXObjectId.h"
#include "wx/panel.h"
#include "wx/sizer.h"
#include "assert.h"

using namespace WXWidgets;

namespace AbstractSplitterWindowFunctors {

/**
 * The UpdateDataContainerFirstWindowShowModeFunctor class implements an update functor of first window show mode.
 */
class UpdateDataContainerFirstWindowShowModeFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerFirstWindowShowModeFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(bool showMode)
    {
        AbstractSplitterWindow::UpdateDataContainerFirstWindowShowMode(m_dataContainer, showMode);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

/**
 * The UpdateDataContainerSecondWindowShowModeFunctor class implements an update functor of second window show mode.
 */
class UpdateDataContainerSecondWindowShowModeFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerSecondWindowShowModeFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(bool showMode)
    {
        AbstractSplitterWindow::UpdateDataContainerSecondWindowShowMode(m_dataContainer, showMode);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

}  // namespace AbstractSplitterWindowFunctors

/**
 * The AbstractSplitterWindow constructor.
 */
AbstractSplitterWindow::AbstractSplitterWindow(
    const wxString& name,
    wxWindow& parent, 
    wxWindowID id, 
    const wxPoint& position, 
    const wxSize& size, 
    long style) : 
        wxSplitterWindow(
            &parent, 
            id, 
            position, 
            size, 
            style, 
            name), 
        m_firstPanel(nullptr), 
        m_firstBoxSizer(nullptr), 
        m_secondPanel(nullptr), 
        m_secondBoxSizer(nullptr)
{
}

/**
 * The AbstractSplitterWindow destructor.
 */
AbstractSplitterWindow::~AbstractSplitterWindow() 
{
}

/**
 * Initializes a GUI component.
 */
void AbstractSplitterWindow::Initialize(
    const IOnUpdationFunctorSharedPtr onUpdationFunctor, 
    IGuiControllerSharedPtr guiController)
{
    //
    // Initialize window...
    //
    Window::Initialize(
        *this, 
        guiController);

    //
    // Initialize functors...
    //
    m_onUpdationFunctor = onUpdationFunctor;

    //
    // Register data items...
    //
    std::wstring dataItemFirstWindowShowMode = WXDataItems::Read().GetSplitterWindowFirstSubWindowShowMode();
    std::wstring dataItemSecondWindowShowMode = WXDataItems::Read().GetSplitterWindowSecondSubWindowShowMode();

    DataContainerManagement::IDataContainer& dataContainer = GetData();
    dataContainer.GetCatalog().RegisterDataItem(dataItemFirstWindowShowMode);
    dataContainer.GetCatalog().RegisterDataItem(dataItemSecondWindowShowMode);

    //
    // Register data update functors...
    //
    DataContainerManagement::IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr firstWindowUpdateFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IBooleanFunctor>(
            AbstractSplitterWindowFunctors::UpdateDataContainerFirstWindowShowModeFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemFirstWindowShowMode, 
        firstWindowUpdateFunctor);

    DataContainerManagement::IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr secondWindowUpdateFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IBooleanFunctor>(
            AbstractSplitterWindowFunctors::UpdateDataContainerSecondWindowShowModeFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemSecondWindowShowMode,
        secondWindowUpdateFunctor);
}

/**
 * Gets a window.
 */
IWindow& AbstractSplitterWindow::GetWindow()
{
    return *this;
}

/**
 * Splits a window vertically.
 */
std::pair<wxWindow*, wxWindow*> AbstractSplitterWindow::SplitVertically(const ISplitterWindowConfigurationSharedPtr configuration)
{
    return Split(configuration, Orient::VERTICAL);
}

/**
 * Splits a window horizontally.
 */
std::pair<wxWindow*, wxWindow*> AbstractSplitterWindow::SplitHorizontally(const ISplitterWindowConfigurationSharedPtr configuration)
{
    return Split(configuration, Orient::HORIZONTAL);
}

/**
 * Connects windows.
 */
void AbstractSplitterWindow::ConnectWindows(
    wxWindow& firstWindow, 
    wxWindow& secondWindow)
{
    //
    // Initialize windows...
    //
    m_firstWindow = &firstWindow;
    m_secondWindow = &secondWindow;

    //
    // Connect a first window...
    //
    ISplitterSubWindowConfigurationSharedPtr firstWindowConfiguration = m_configuration->GetFirstWindowConfiguration();

    m_firstBoxSizer->Add(
        &firstWindow, 
        firstWindowConfiguration->GetProportion(), 
        firstWindowConfiguration->GetFlag());

    //
    // Connect a second window...
    //
    ISplitterSubWindowConfigurationSharedPtr secondWindowConfiguration = m_configuration->GetSecondWindowConfiguration();

    m_secondBoxSizer->Add(
        &secondWindow, 
        secondWindowConfiguration->GetProportion(), 
        secondWindowConfiguration->GetFlag());

    //
    // Show a windows accordingly...
    //
    firstWindow.Show(firstWindowConfiguration->GetShowMode());
    secondWindow.Show(secondWindowConfiguration->GetShowMode());

    //
    // Assert that the common ancestor window of connected windows is the splitter window...
    //
    assert(GetWindow().FindCommonAncestor(firstWindow, secondWindow) == &GetWindow().AsWindow());

    //
    // Fit components of splitter window...
    //
    FitComponents();
}

/**
 * Updates data container (first window show mode).
 */
void AbstractSplitterWindow::UpdateDataContainerFirstWindowShowMode(
    DataContainerManagement::IDataContainer& data,
    bool showMode)
{
    std::wstring dataItemName = WXDataItems::Read().GetSplitterWindowFirstSubWindowShowMode();

    DataContainerManagement::IDataItemSharedPtr dataItem = DataContainerManagement::DataItem::Create(
        dataItemName, 
        showMode);

    data.SetDataItem(dataItem);
}

/**
 * Updates data container (second window show mode).
 */
void AbstractSplitterWindow::UpdateDataContainerSecondWindowShowMode(
    DataContainerManagement::IDataContainer& data,
    bool showMode)
{
    std::wstring dataItemName = WXDataItems::Read().GetSplitterWindowSecondSubWindowShowMode();

    DataContainerManagement::IDataItemSharedPtr dataItem = DataContainerManagement::DataItem::Create(
        dataItemName, 
        showMode);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool AbstractSplitterWindow::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer) 
{
    bool configurationUpdated = false;

    bool firstWindowShowMode = m_configuration->GetFirstWindowConfiguration()->GetShowMode();

    std::wstring dataItemFirstWindowShowMode = WXDataItems::Read().GetSplitterWindowFirstSubWindowShowMode();

    if (dataContainer.HasDataItem(dataItemFirstWindowShowMode)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemFirstWindowShowMode);

        configurationUpdated = WXWidgets::WXProperty::UpdateValue(
            firstWindowShowMode, 
            dataItem.GetValue()->GetBoolean());
    }

    bool secondWindowShowMode = m_configuration->GetSecondWindowConfiguration()->GetShowMode();

    std::wstring dataItemSecondWindowShowMode = WXDataItems::Read().GetSplitterWindowSecondSubWindowShowMode();

    if (dataContainer.HasDataItem(dataItemSecondWindowShowMode)) {
        const DataContainerManagement::IDataItem& dataItem = dataContainer.GetDataItem(dataItemSecondWindowShowMode);

        bool propertyUpdated = WXWidgets::WXProperty::UpdateValue(
            secondWindowShowMode, 
            dataItem.GetValue()->GetBoolean());

        configurationUpdated |= propertyUpdated;
    }

    if (configurationUpdated) {
        ISplitterWindowConfigurationSharedPtr configuration = SplitterWindowConfiguration::Copy(*m_configuration);

        configuration->GetFirstWindowConfiguration()->SetShowMode(firstWindowShowMode);
        configuration->GetSecondWindowConfiguration()->SetShowMode(secondWindowShowMode);

        m_configuration = configuration;
    }

    return configurationUpdated;
}

/**
 * Updates component.
 */
void AbstractSplitterWindow::Update()
{
    bool firstWindowShowMode = m_configuration->GetFirstWindowConfiguration()->GetShowMode();
    bool secondWindowShowMode = m_configuration->GetSecondWindowConfiguration()->GetShowMode();

    m_firstTopBoxSizer->Show(firstWindowShowMode);
    m_secondTopBoxSizer->Show(secondWindowShowMode);

    FitComponents();
}

/**
 * Splits a window vertically or horizontally.
 */
std::pair<wxWindow*, wxWindow*> AbstractSplitterWindow::Split(
    const ISplitterWindowConfigurationSharedPtr configuration,
    Orient orient)
{
    //
    // Initialize a configuration...
    //
    base::SmartPointers::Validate(configuration);
    m_configuration = configuration;

    //
    // Initialize in a box sizer.
    //
    if (m_configuration->InitializeInBoxSizer()) {
        InitializeInBoxSizer(orient);
    }

    //
    // Create a first panel of a splitter window...
    //
    ISplitterSubWindowConfigurationSharedPtr firstWindowConfiguration = m_configuration->GetFirstWindowConfiguration();
    std::tuple<WXPanelPtr, WXBoxSizerPtr, wxBoxSizer*> firstInformation = CreatePanel(
        orient, 
        firstWindowConfiguration->GetBorderWindowConfiguration(), 
        firstWindowConfiguration->GetShowMode());

    //
    // Create a second panel of a splitter window...
    //
    ISplitterSubWindowConfigurationSharedPtr secondWindowConfiguration = m_configuration->GetSecondWindowConfiguration();
    std::tuple<WXPanelPtr, WXBoxSizerPtr, wxBoxSizer*> secondInformation = CreatePanel(
        orient, 
        secondWindowConfiguration->GetBorderWindowConfiguration(), 
        secondWindowConfiguration->GetShowMode());

    //
    // Initialize the panel information...
    //
    m_firstPanel = std::get<0>(firstInformation);
    m_firstBoxSizer = std::get<1>(firstInformation);
    m_firstTopBoxSizer = std::get<2>(firstInformation);

    m_secondPanel = std::get<0>(secondInformation);
    m_secondBoxSizer = std::get<1>(secondInformation);
    m_secondTopBoxSizer = std::get<2>(secondInformation);

    //
    // Set the first and second panels of splitter window...
    //
    if (orient == Orient::VERTICAL) {
        wxSplitterWindow::SplitVertically(&m_firstPanel, &m_secondPanel);
    }
    else {
        wxSplitterWindow::SplitHorizontally(&m_firstPanel, &m_secondPanel);
    }

    //
    // Set the sash gravity...
    // Gravity is real factor which controls position of sash while resizing wxSplitterWindow.
    // Gravity tells wxSplitterWindow how much will left/top window grow while resizing...
    //
    SetSashGravity(m_configuration->GetGravity());

    //
    // Return the first and second panels...
    //
    return std::make_pair<>(&m_firstPanel, &m_secondPanel);
}

/**
 * Creates a panel of splitter Window.
 */
std::tuple<WXPanelPtr, WXBoxSizerPtr, wxBoxSizer*> AbstractSplitterWindow::CreatePanel(
    Orient orient, 
    const IBorderWindowConfigurationSharedPtr borderWindowConfiguration,
    bool show)
{
    //
    // Create a panel...
    //
    WXPanelPtr panel = WXPanelPtr::Make(new wxPanel(this, WXObjectId::NextId()));
    
    wxBoxSizer* topBoxSizer = nullptr;

    //
    // Create a box sizer...
    //
    WXBoxSizerPtr boxSizer = WXBoxSizerPtr::Make(new wxBoxSizer(OrientValue(orient)));

    //
    // Incase a border is required, include first a static box sizer for defining a border...
    //
    if (borderWindowConfiguration) {
        WXStaticBoxSizerPtr staticBoxSizer =
            WXStaticBoxSizerPtr::Make(new wxStaticBoxSizer(
                OrientValue(orient), 
                &panel, 
                wxString(borderWindowConfiguration->GetLabel())));
        
        staticBoxSizer->Add(
            &boxSizer, 
            borderWindowConfiguration->GetProportion(), 
            borderWindowConfiguration->GetFlag());
        
        topBoxSizer = &staticBoxSizer;
    } 
    else {
        topBoxSizer = &boxSizer;
    }

    //
    // Show a box sizer accordingly...
    //
    topBoxSizer->Show(show);
    
    //
    // Connect a box sizer to the panel...
    //
    panel->SetSizer(topBoxSizer);
    
    return std::make_tuple<>(panel, boxSizer, topBoxSizer);
}

/**
 * Initializes a splitter window in a box sizer.
 */
void AbstractSplitterWindow::InitializeInBoxSizer(Orient orient)
{
    WXBoxSizerPtr mainBoxSizer = WXBoxSizerPtr::Make(new wxBoxSizer(OrientValue(orient)));
    mainBoxSizer->Add(this, 1, wxEXPAND);

    wxWindow* parent = GetParent();

    parent->SetSizer(&mainBoxSizer);
    mainBoxSizer->SetSizeHints(parent);
}

 /**
 * Fits components of splitter window.
 */
void AbstractSplitterWindow::FitComponents() 
{
    //
    // Fit components in splitter window layout...
    //
    std::vector<wxPanel*> panels = { m_firstPanel.Get(), m_secondPanel.Get() };
    std::vector<wxBoxSizer*> topBoxSizers = { m_firstBoxSizer.Get(), m_secondBoxSizer.Get() };
    std::vector<wxWindow*> windows = { m_firstWindow, m_secondWindow };

    for (size_t index = 0; index < 2; ++index) {
        wxPanel* panel = panels[index];
        wxBoxSizer* topBoxSizer = topBoxSizers[index];
        wxWindow* window = windows[index];

        panel->FitInside();
        topBoxSizer->FitInside(panel);
        window->FitInside();
    }
}
