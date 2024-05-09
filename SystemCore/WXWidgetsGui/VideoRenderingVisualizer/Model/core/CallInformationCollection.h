#ifndef CALL_INFORMATION_COLLECTION_c7be2cdb_03e7_4fb9_8a98_ca6c279e845b
#define CALL_INFORMATION_COLLECTION_c7be2cdb_03e7_4fb9_8a98_ca6c279e845b

#include "ICallInformationCollection.h"
#include "IModelCollection.h"
#include <map>

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The CallInformationCollection class implements a collection of calls information.
         */
        class CallInformationCollection final : public ICallInformationCollection {
        public:
            /**
             * Creates a collection of call information.
             */
            static ICallInformationCollectionSharedPtr Make();

            /**
             * The CallInformationCollection constructor.
             */
            CallInformationCollection();

            /**
             * The CallInformationCollection destructor.
             */
            virtual ~CallInformationCollection();

            /**
             * Adds an item.
             */
            virtual void AddItem(const ICallInformationSharedPtr item) override;

            /**
             * Removes an item.
             * Returns true in case item has been removed, and false in case item has not been found.
             */
            virtual bool RemoveItem(const std::wstring& id) override;

            /**
             * Gets a specific item.
             */
            virtual const ICallInformationSharedPtr GetItem(const std::wstring& id) const override;

            /**
             * Checks whether a specific item exists.
             */
            virtual bool HasItem(const std::wstring& id) const override;

            /**
             * Gets size of a collection.
             */
            virtual size_t Size() const override;

            /**
             * Checks whether a collection is empty.
             */
            virtual bool Empty() const override;

            /**
             * Gets an iterator.
             */
            virtual base::IIteratorSharedPtr<ICallInformationSharedPtr> GetIterator() const override;

            /**
             * Finds corresponding call by logging object.
             * Returns nullptr in case no corresponding call has not been found.
             */
            virtual ICallInformationSharedPtr FindCallByLoggingObject(const std::wstring& memoryAddress) override;

            /**
             * Finds corresponding call by logging object.
             * Returns nullptr in case no corresponding call has not been found.
             */
            virtual const ICallInformationSharedPtr FindCallByLoggingObject(const std::wstring& memoryAddress) const override;

        private:
            //
            // The actual collection of calls...
            //
            IModelCollectionSharedPtr<std::wstring, ICallInformation> m_impl;

            //
            // Defines the mapping between a logging object memory address to a call...
            //
            using LoggingObjectAddressToCallMap = std::map<std::wstring, ICallInformationSharedPtr>;
            LoggingObjectAddressToCallMap m_loggingObjectAddressToCall;
        };

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // CALL_INFORMATION_COLLECTION_c7be2cdb_03e7_4fb9_8a98_ca6c279e845b
