#ifndef DATA_CONTAINER_EXCEPTION_H_7d5449df_28b1_42af_bc06_0b9a2852496f
#define DATA_CONTAINER_EXCEPTION_H_7d5449df_28b1_42af_bc06_0b9a2852496f

#include "BaseException.h"

namespace DataContainerManagement {

    /**
     * The data_container_exception class implements an exception in the Data Container module.
     */
    class data_container_exception final : public base::BaseException {
    public:
        /**
         * The data_container_exception constructor.
         */
        explicit data_container_exception(const std::wstring& errorMessage) :
            BaseException(errorMessage)
        {
        }

        /**
         * The data_container_exception constructor.
         */
        data_container_exception(
            unsigned long errorCode,
            const std::wstring& errorMessage) :
                BaseException(
                    errorCode,
                    errorMessage)
        {
        }

        /**
         * The data_container_exception destructor.
         */
        virtual ~data_container_exception() = default;
    };

}  // namespace DataContainerManagement

#endif // DATA_CONTAINER_EXCEPTION_H_7d5449df_28b1_42af_bc06_0b9a2852496f
