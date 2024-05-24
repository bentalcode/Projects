#ifndef THREAD_ID_TRANSFORMER_H_d7d2c6f1_c397_46e9_8420_d920b8542e2b
#define THREAD_ID_TRANSFORMER_H_d7d2c6f1_c397_46e9_8420_d920b8542e2b

#include "ILogInformation.h"
#include "IValueTransformer.h"
#include <thread>

namespace logging {

    /**
     * The ThreadIdTransformer class implements a transformer to a thread id.
     */
    class ThreadIdTransformer final : public tabular_data::IValueTransformer<std::thread::id> {
    public:
        /**
         * Creates a Thread Id Transformer.
         */
        static tabular_data::IValueTransformerSharedPtr<std::thread::id> Make();

        /**
         * The ThreadIdTransformer constructor.
         */
        ThreadIdTransformer();

        /**
         * The ThreadIdTransformer destructor.
         */
        virtual ~ThreadIdTransformer();

        /**
         * Transforms a value to a thread id.
         */
        virtual std::thread::id Transform(const std::wstring& value) const override;
    };

} // namespace logging

#endif // THREAD_ID_TRANSFORMER_H_d7d2c6f1_c397_46e9_8420_d920b8542e2b

