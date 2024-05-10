#ifndef WX_WIDGETS_CONTROLLER_EXCEPTION_H_f5bf3957_8ffd_44dc_a6f9_29a458da9f73
#define WX_WIDGETS_CONTROLLER_EXCEPTION_H_f5bf3957_8ffd_44dc_a6f9_29a458da9f73

#include "WXWidgetsException.h"

namespace wxwidgets {

    namespace controller {

        /**
         * The WXWidgetsControllerException class implements an exception in the WXWidgets Controller module.
         */
        class WXWidgetsControllerException : public WXWidgetsException {
        public:
            /**
             * The WXWidgetsControllerException constructor.
             */
            explicit WXWidgetsControllerException(const std::wstring& errorMessage) :
                WXWidgetsException(errorMessage)
            {
            }

            /**
             * The WXWidgetsControllerException constructor.
             */
            WXWidgetsControllerException(
                unsigned long errorCode,
                const std::wstring& errorMessage) :
                    WXWidgetsException(
                        errorCode,
                        errorMessage)
            {
            }

            /**
             * The WXWidgetsControllerException destructor.
             */
            virtual ~WXWidgetsControllerException() = default;
        };

    } // namespace controller

} // namespace wxwidgets

#endif // WX_WIDGETS_CONTROLLER_EXCEPTION_H_f5bf3957_8ffd_44dc_a6f9_29a458da9f73
