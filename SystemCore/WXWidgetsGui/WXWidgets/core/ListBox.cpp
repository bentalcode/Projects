#include "ListBox.h"

using namespace WXWidgets;

namespace ListBoxFunctors {

/**
 * The OnSelectedFunctor class implements an On Selected functor.
 */
class OnSelectedFunctor final {
public:
    /**
     * The functor constructor.
     */
    explicit OnSelectedFunctor(ListBox& listBox) : 
        m_listBox(listBox) 
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const std::wstring& item)
    { 
        m_listBox.OnSelectedItem(item); 
    }

private:
    ListBox& m_listBox;
};

}  // namespace ListBoxFunctors

/**
 * Creates a list box.
 */
IListBoxPtr ListBox::Make(
    wxWindow& parent, 
    const wxString& name, 
    long style,
    wxWindowID id, 
    const wxPoint& position,
    const wxSize& size, 
    int n, 
    const wxValidator& validator)
{ 
    return IListBoxPtr::Make(new ListBox(
        parent, 
        name, 
        style,
        id, 
        position, 
        size, 
        n, 
        validator));
}

/**
 * The ListBox constructor.
 */
ListBox::ListBox(
    wxWindow& parent, 
    const wxString& name, 
    long style,
    wxWindowID id,
    const wxPoint& position,
    const wxSize& size,
    int n,
    const wxValidator& validator) :
        AbstractListBox(
            parent,
            name,
            id, 
            position,
            size,
            n, 
            style,
            validator)
{
}

/**
 * The ListBox destructor.
 */
ListBox::~ListBox() 
{
}

/**
 * Initializes a GUI component.
 */
void ListBox::Initialize(
    const std::vector<std::wstring>& items, 
    IGuiControllerSharedPtr guiController, 
    bool showMode)
{
    //
    // Initialize a list box...
    //
    ListBox::IOnSelectedItemFunctorSharedPtr onSelectedFunctor = 
        std::make_shared<ListBox::IOnSelectedItemFunctor>(ListBoxFunctors::OnSelectedFunctor{ *this });
    
    AbstractListBox::Initialize(
        onSelectedFunctor, 
        items, 
        guiController, 
        showMode);
}
