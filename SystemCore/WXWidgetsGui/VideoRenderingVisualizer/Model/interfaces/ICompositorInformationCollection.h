#ifndef I_COMPOSITOR_INFORMATION_COLLECTION_96b1ce9d_e8a8_4917_94a0_7b78fb516aae
#define I_COMPOSITOR_INFORMATION_COLLECTION_96b1ce9d_e8a8_4917_94a0_7b78fb516aae

#include "IModelCollection.h"
#include "ICompositorInformation.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The ICompositorInformationCollection interface defines a collection of compositor infomation.
         */
        class ICompositorInformationCollection : public IModelCollection<std::wstring, ICompositorInformation> {
        public:
            ICompositorInformationCollection() = default;
            virtual ~ICompositorInformationCollection() = default;
        };

        /**
         * Defines the Shared Ptr of Compositor Information Collection.
         */
        using ICompositorInformationCollectionSharedPtr = std::shared_ptr<ICompositorInformationCollection>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_COMPOSITOR_INFORMATION_COLLECTION_96b1ce9d_e8a8_4917_94a0_7b78fb516aae
