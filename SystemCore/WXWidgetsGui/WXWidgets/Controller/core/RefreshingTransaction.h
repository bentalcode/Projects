#ifndef REFRESHING_TRANSACTION_H_f6543ddf_4d55_40d6_847d_42a765949391
#define REFRESHING_TRANSACTION_H_f6543ddf_4d55_40d6_847d_42a765949391

#include "IRefreshingTransaction.h"
#include "AbstractTransaction.h"
#include "IDataContainerUpdateFunctors.h"

namespace wxwidgets {

    namespace controller {

        /**
         * The RefreshingTransaction class implements a refreshing transaction.
         */
        class RefreshingTransaction final : public IRefreshingTransaction, public AbstractTransaction {
        public:
            /**
             * Creates a refreshing transaction.
             */
            static IRefreshingTransactionSharedPtr Make(IControllerManager& controllerManager);

            /**
             * The RefreshingTransaction constructor.
             */
            explicit RefreshingTransaction(IControllerManager& controllerManager);

            /**
             * The RefreshingTransaction destructor.
             */
            virtual ~RefreshingTransaction();

            /**
             * Commits a transaction.
             */
            virtual void Commit() override;

            /**
             * Updates data with a boolean.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                bool value) override;

            /**
             * Updates data with an integer.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                int value) override;

            /**
             * Updates data with a long.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                long value) override;

            /**
             * Updates data with a double.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                double value) override;

            /**
             * Updates data with a date-time.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                const base::DateTime& value) override;

            /**
             * Updates data with a duration.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                const base::Duration& value) override;

            /**
             * Updates data with a string.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                const std::wstring& value) override;

            /**
             * Updates data with a string array.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                const std::vector<std::wstring>& value) override;

        private:
            /**
             * Gets an update functors.
             */
            DataContainerManagement::IDataContainerUpdateFunctors& GetUpdateFunctors(const std::wstring& componentName);
        };

    } // namespace controller

} // namespace wxwidgets

#endif // REFRESHING_TRANSACTION_H_f6543ddf_4d55_40d6_847d_42a765949391
