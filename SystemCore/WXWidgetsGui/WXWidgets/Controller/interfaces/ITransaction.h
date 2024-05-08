#ifndef I_TRANSACTION_H_654f5588_a698_4e22_81a2_fafd82caf8ce
#define I_TRANSACTION_H_654f5588_a698_4e22_81a2_fafd82caf8ce

#include <memory>

namespace WXWidgets {

    namespace Command {

        /**
         * The ITransaction interface defines a generic type of a transaction in controller.
         */
        class ITransaction {
        public:
            ITransaction() = default;
            virtual ~ITransaction() = default;

            /**
             * Commits a transaction.
             */
            virtual void Commit() = 0;
        };

        /**
         * Defines the Shared Ptr of Transaction.
         */
        using ITransactionSharedPtr = std::shared_ptr<ITransaction>;

    } // namespace Command

} // namespace WXWidgets

#endif // I_TRANSACTION_H_654f5588_a698_4e22_81a2_fafd82caf8ce
