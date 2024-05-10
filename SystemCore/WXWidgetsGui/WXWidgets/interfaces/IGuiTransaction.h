#ifndef I_GUI_TRANSACTION_cff34f94_f929_4401_bcd9_29d2319101f1
#define I_GUI_TRANSACTION_cff34f94_f929_4401_bcd9_29d2319101f1

#include "IWXEventHandler.h"
#include <string>
#include <memory>

namespace WXWidgets {

    class IGuiComponent;

    /**
     * The IGuiTransaction interface defines a transaction in GUI.
     */
    class IGuiTransaction {
    public:
        IGuiTransaction() = default;
        virtual ~IGuiTransaction() = default;

        /**
         * Registers a component.
         */
        virtual void RegisterComponent(IGuiComponent& component) = 0;

        /**
         * Unregisters a component.
         */
        virtual void UnregisterComponent(const std::wstring& name) = 0;

        /**
         * Checks whether a component is registered.
         */
        virtual bool ComponentRegistered(const std::wstring& name) const = 0;

        /**
         * Sets a component transaction as completed.
         */
        virtual void SetComponentTransactionCompleted(const std::wstring& name) = 0;

        /**
         * Sets an on completion event.
         */
        virtual void SetOnCompletionEvent(
            IWXEventHandler& eventHandler,
            IWXEventSharedPtr event) = 0;
    };

    /**
     * Defines the Shared Ptr of GUI Transaction.
     */
    using IGuiTransactionSharedPtr = std::shared_ptr<IGuiTransaction>;

} // namespace WXWidgets

#endif // I_GUI_TRANSACTION_cff34f94_f929_4401_bcd9_29d2319101f1
