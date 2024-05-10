#ifndef ABSTRACT_LIST_BOX_5f7b3113_4ce4_4326_9cd5_987641b1e8cf
#define ABSTRACT_LIST_BOX_5f7b3113_4ce4_4326_9cd5_987641b1e8cf

#include "IListBox.h"
#include "Window.h"
#include "wx/listbox.h"
#include <string>
#include <vector>

namespace wxwidgets {

    /**
     * The AbstractListBox class implements an abstract base class of a list box.
     */
    class AbstractListBox : public IListBox, public Window, public wxListBox {
    public:
        //
        // Defines a SharedPtr of On Selected Functor...
        //
        using IOnSelectedItemFunctor = std::function<void(const std::wstring&)>;
        using IOnSelectedItemFunctorSharedPtr = std::shared_ptr<IOnSelectedItemFunctor>;

        /**
         * The AbstractListBox constructor.
         */
        AbstractListBox(
            wxWindow& parent,
            const wxString& name,
            wxWindowID id,
            const wxPoint& position,
            const wxSize& size,
            int n,
            long style,
            const wxValidator& validator,
            size_t minItemSize = MIN_ITEM_SIZE,
            size_t minNumberOfItems = MIN_NUMBER_OF_PADS_ITEMS);

        /**
         * The AbstractListBox destructor.
         */
        virtual ~AbstractListBox();

        /**
         * Initializes a GUI component.
         */
        void Initialize(
            const IOnSelectedItemFunctorSharedPtr onSelectedItemFunctor,
            const std::vector<std::wstring>& items,
            IGuiControllerSharedPtr guiController,
            bool showMode = true);

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() override;

        /**
         * Set a selected item.
         */
        virtual bool SetSelectedItem(int index) override;

        /**
         * The On Selected Item callback - Default Implementation.
         */
        virtual void OnSelectedItem(const std::wstring& item) override;

        /**
         * Updates data container (items).
         */
        static void UpdateDataContainerItems(
            DataContainerManagement::IDataContainer& data,
            const std::vector<std::wstring>& items);

    protected:
        /**
         * Updates data from data container.
         * Returns true in case data has been updated.
         */
        virtual bool UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer) override;

        /**
         * Updates component.
         */
        virtual void Update() override;

    private:
        static const size_t MIN_ITEM_SIZE;
        static const size_t MIN_NUMBER_OF_PADS_ITEMS;

        /**
         * Resets component.
         */
        void Reset();

        /**
         * The internal On Selected Item callback.
         */
        void InternalOnSelectedItem(wxCommandEvent& event);

        /**
         * Sets items.
         */
        void SetItems(const std::vector<std::wstring>& items);

        /**
         * Pads an item.
         * Returns true if an item has been pad.
         */
        static bool PadItem(const std::wstring& item, std::wstring& result);

        /**
         * Creates a pad item with a specified size.
         */
        static std::wstring CreatePadItem(size_t size);

        //
        // The configured functors...
        //
        IOnSelectedItemFunctorSharedPtr m_onSelectedItemFunctor;

        //
        // The items of the list box...
        //
        std::vector<std::wstring> m_items;
        std::wstring m_padItem;

        //
        // The minimum item size...
        //
        size_t m_minItemSize;

        //
        // The minimum number of items...
        //
        size_t m_minNumberOfItems;
    };

} // namespace wxwidgets

#endif // ABSTRACT_LIST_BOX_5f7b3113_4ce4_4326_9cd5_987641b1e8cf
