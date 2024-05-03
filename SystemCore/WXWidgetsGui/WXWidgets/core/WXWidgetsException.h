#ifndef WX_WIDGETS_EXCEPTION_092e3f88_729d_4ff7_9891_ed38b7491fbc
#define WX_WIDGETS_EXCEPTION_092e3f88_729d_4ff7_9891_ed38b7491fbc

#include "BaseException.h"

namespace WXWidgets {

    /**
     * The WXWidgetsException class implements an exception in the WX Widgets module.
     */
    class WXWidgetsException : public base::BaseException {
    public:
        /**
         * The WXWidgetsException constructor.
         */
        explicit WXWidgetsException(const std::wstring& errorMessage) :
            BaseException(errorMessage)
        {
        }

        /**
         * The WXWidgetsException constructor.
         */
        WXWidgetsException(
            long errorCode,
            const std::wstring& errorMessage) :
            BaseException(errorCode, errorMessage)
        {
        }

        /**
         * The WXWidgetsException destructor.
         */
        virtual ~WXWidgetsException() = default;
    };

}  // namespace WXWidgets

#endif // WX_WIDGETS_EXCEPTION_092e3f88_729d_4ff7_9891_ed38b7491fbc
