#include "ListView.h"

using namespace wxwidgets;

/**
 * Creates a list view.
 */
IListViewPtr ListView::Make(
    wxWindow& parent, 
    const wxString& name, 
    wxWindowID id,
    const wxPoint& position, 
    const wxSize& size,
    long style, 
    const wxValidator& validator)
{ 
    return IListViewPtr::Make(new ListView(
        parent, 
        name, 
        id, 
        position, 
        size, 
        style, 
        validator));
}

/**
 * The ListView constructor.
 */
ListView::ListView(
    wxWindow& parent, 
    const wxString& name, 
    wxWindowID id,
    const wxPoint& position,
    const wxSize& size,
    long style,
    const wxValidator& validator) :
        AbstractListView(
            parent,
            name, 
            id, 
            position,
            size,
            style,
            validator)
{
}

/**
 * The ListView destructor.
 */
ListView::~ListView() 
{
}

/**
 * Initializes a GUI component.
 */
void ListView::Initialize(
    const std::vector<std::wstring>& headers, 
    const std::vector<std::vector<std::wstring>>& values, 
    const wxListColumnFormat& headerFormat,
    size_t headerWidth,
    IGuiControllerSharedPtr guiController, 
    bool showMode)
{
    //
    // Initialize a list view...
    //
    AbstractListView::Initialize(
        headers, 
        values, 
        headerFormat, 
        headerWidth,
        guiController,
        showMode);
}
