#ifndef GUI_TRANSACTION_7395be10_8196_4ba0_8613_5f7aa5d94934
#define GUI_TRANSACTION_7395be10_8196_4ba0_8613_5f7aa5d94934

#include "IGuiTransaction.h"
#include <map>
#include <mutex>
#include <condition_variable>
#include "ILoggers.h"

namespace WXWidgets {

    /**
     * The GuiTransaction class implements a GUI transaction.
     */
    class GuiTransaction final : public IGuiTransaction {
    public:
        /**
         * Creates a GUI Transaction.
         */
        static IGuiTransactionSharedPtr Make();

        /**
         * The GuiTransaction constructor.
         */
        GuiTransaction();

        /**
         * The GuiTransaction destructor.
         */
        virtual ~GuiTransaction();

        /**
         * Registers a component.
         */
        virtual void RegisterComponent(IGuiComponent& component) override;

        /**
         * Unregisters a component.
         */
        virtual void UnregisterComponent(const std::wstring& name) override;

        /**
         * Checks whether a component is registered.
         */
        virtual bool ComponentRegistered(const std::wstring& name) const override;

        /**
         * Sets a component transaction as completed.
         */
        virtual void SetComponentTransactionCompleted(const std::wstring& name) override;

        /**
         * Sets an on completion event.
         */
        virtual void SetOnCompletionEvent(
            IWXEventHandler& eventHandler,
            IWXEventSharedPtr event) override;

    private:
        /**
         * Checks whether a component exists.
         */
        bool HasComponent(const std::wstring& name) const;

        /**
         * Finds a component by name.
         */
        IGuiComponent* FindComponent(const std::wstring& name);

        /**
         * Checks whether a transaction is completed.
         */
        bool TransactionCompleted() const;

        //
        // Defines a GUI Component State...
        //
        using GuiComponentState = std::map<std::wstring, std::pair<IGuiComponent*, bool>>;
        GuiComponentState m_componentState;

        //
        // The counter of completed components...
        //
        size_t m_counter;

        //
        // The mutex of this class...
        //
        mutable std::recursive_mutex m_mutex;

        //
        // The on completion event data...
        //
        IWXEventHandler* m_onCompletionEventHandler;
        IWXEventSharedPtr m_onCompletionEvent;

        logging::ILoggersSharedPtr m_loggers;
    };

} // namespace WXWidgets

#endif // GUI_TRANSACTION_7395be10_8196_4ba0_8613_5f7aa5d94934
