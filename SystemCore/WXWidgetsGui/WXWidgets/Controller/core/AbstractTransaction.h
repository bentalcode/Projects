#ifndef ABSTRACT_TRANSACTION_H_cc518753_789e_41b7_9bfd_7151015ef844
#define ABSTRACT_TRANSACTION_H_cc518753_789e_41b7_9bfd_7151015ef844

#include "ITransaction.h"

namespace WXWidgets {

    namespace Command {

        class IControllerManager;

        /**
         * The AbstractTransaction class implements an abstract transaction.
         */
        class AbstractTransaction : public ITransaction {
        public:
            /**
             * The AbstractTransaction constructor.
             */
            explicit AbstractTransaction(IControllerManager& controllerManager);

            /**
             * The AbstractTransaction destructor.
             */
            virtual ~AbstractTransaction();

            /**
             * Gets a controller manager.
             */
            IControllerManager& GetControllerManager();

        private:
            IControllerManager& m_controllerManager;
        };

    } // namespace Command

} // namespace WXWidgets

#endif // namespace ABSTRACT_TRANSACTION_H_cc518753_789e_41b7_9bfd_7151015ef844
