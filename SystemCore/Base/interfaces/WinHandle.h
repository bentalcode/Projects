#ifndef WINDOWS_HANDLE_H_be4ac0b3_c800_4a0e_a434_1a8b3c366a72
#define WINDOWS_HANDLE_H_be4ac0b3_c800_4a0e_a434_1a8b3c366a72

#include "Handle.h"
#include <windows.h>

namespace base {

    namespace windows {

        /**
         * The Handle Releaser functor releases a windows handle.
         */
        class HandleReleaserFunctor final {
        public:
            /**
             * The functor logic.
             */
            void operator()(HANDLE value)
            {
                ::CloseHandle(value);
            }
        };

        /**
         * The WinHandle class implements an auto releaser for a HANDLE type.
         */
        class WinHandle : public Handle<HANDLE> {
        public:
            /**
             * The WinHandle constructor.
             */
            WinHandle(
                HANDLE handle,
                IReleaserFunctorSharedPtr releaser =
                    std::make_shared<Handle<HANDLE>::IReleaserFunctor>(HandleReleaserFunctor{}));

            /**
             * The WinHandle destructor.
             */
            virtual ~WinHandle();
        };

        /**
         * The WinHandle constructor.
         */
        WinHandle::WinHandle(
            HANDLE handle,
            IReleaserFunctorSharedPtr releaser) :
                Handle<HANDLE>(
                    handle,
                    releaser)
        {
        }

        /**
         * The WinHandle destructor.
         */
        WinHandle::~WinHandle()
        {
        }

    }  // namespace windows

}  // namespace base

#endif // WINDOWS_HANDLE_H_be4ac0b3_c800_4a0e_a434_1a8b3c366a72
