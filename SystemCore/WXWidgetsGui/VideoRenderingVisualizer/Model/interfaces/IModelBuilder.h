#ifndef I_MODEL_BUILDER_0938bee0_73e8_4e52_979b_7274ea453f46
#define I_MODEL_BUILDER_0938bee0_73e8_4e52_979b_7274ea453f46

#include "ITLogStatistics.h"

namespace VideoRenderingVisualizer {

    namespace Model {

        /**
         * The IModelBuilder interface defines a Model Builder.
         */
        class IModelBuilder {
        public:
            IModelBuilder() = default;
            virtual ~IModelBuilder() = default;

            /**
             * Builds a model.
             */
            virtual void Build() = 0;

            /**
             * Gets statistics.
             */
            virtual const tlogging::ITLogStatisticsSharedPtr GetStatistics() const = 0;
        };

        /**
         * Defines the Shared Ptr of Model Builder.
         */
        using IModelBuilderSharedPtr = std::shared_ptr<IModelBuilder>;

    } // namespace Model

} // namespace VideoRenderingVisualizer

#endif // I_MODEL_BUILDER_0938bee0_73e8_4e52_979b_7274ea453f46
