#ifndef I_CALL_INFORAMTION_COLLECTION_485e4629_f032_4b74_85ca_845b8494d9a1
#define I_CALL_INFORAMTION_COLLECTION_485e4629_f032_4b74_85ca_845b8494d9a1

#include "IModelCollection.h"
#include "ICallInformation.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The ICallInformationCollection interface defines a collection of calls information.
         */
        class ICallInformationCollection : public IModelCollection<std::wstring, ICallInformation> {
        public:
            ICallInformationCollection() = default;
            virtual ~ICallInformationCollection() = default;

            /**
             * Finds corresponding call by logging object.
             * Returns nullptr in case no corresponding call has not been found.
             */
            virtual ICallInformationSharedPtr FindCallByLoggingObject(const std::wstring& memoryAddress) = 0;

            /**
             * Finds corresponding call by logging object.
             * Returns nullptr in case no corresponding call has not been found.
             */
            virtual const ICallInformationSharedPtr FindCallByLoggingObject(const std::wstring& memoryAddress) const = 0;
        };

        /**
         * Defines the Shared Ptr of Call Information Collection.
         */
        using ICallInformationCollectionSharedPtr = std::shared_ptr<ICallInformationCollection>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_CALL_INFORAMTION_COLLECTION_485e4629_f032_4b74_85ca_845b8494d9a1
