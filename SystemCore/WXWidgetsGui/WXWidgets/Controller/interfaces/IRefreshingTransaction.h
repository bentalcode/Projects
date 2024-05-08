#ifndef I_REFRESHING_TRANSACTION_H_b6161727_3661_4a01_a51a_4b2334c783e6
#define I_REFRESHING_TRANSACTION_H_b6161727_3661_4a01_a51a_4b2334c783e6

#include "ITransaction.h"
#include "Duration.h"
#include <string>
#include <vector>

namespace WXWidgets {

    namespace Command {

        /**
         * The IRefreshingTransaction interface defines a refreshing transaction in controller.
         */
        class IRefreshingTransaction : public ITransaction {
        public:
            IRefreshingTransaction() = default;
            virtual ~IRefreshingTransaction() = default;

            /**
             * Updates data with a boolean.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                bool value) = 0;

            /**
             * Updates data with an integer.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                int value) = 0;

            /**
             * Updates data with a long.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                long value) = 0;

            /**
             * Updates data with a double.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                double value) = 0;

            /**
             * Updates data with a string.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                const std::wstring& value) = 0;

            /**
             * Updates data with a date-time.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                const base::DateTime& value) = 0;

            /**
             * Updates data with a duration.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                const base::Duration& value) = 0;

            /**
             * Updates data with a string array data.
             */
            virtual void UpdateData(
                const std::wstring& componentName,
                const std::wstring& functorName,
                const std::vector<std::wstring>& value) = 0;
        };

        /**
         * Defines the Shared Ptr of Refreshing Refreshing Transaction.
         */
        using IRefreshingTransactionSharedPtr = std::shared_ptr<IRefreshingTransaction>;

    } // namespace Command

} // namespace WXWidgets

#endif // I_REFRESHING_TRANSACTION_H_b6161727_3661_4a01_a51a_4b2334c783e6
