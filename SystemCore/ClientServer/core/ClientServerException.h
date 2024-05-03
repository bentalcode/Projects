#ifndef CLIENT_SERVER_EXCEPTION_H_74038af5_78e2_47b4_af29_53b616f7926c
#define CLIENT_SERVER_EXCEPTION_H_74038af5_78e2_47b4_af29_53b616f7926c

#include "BaseException.h"

namespace client_server {

/**
 * The ClientServerException class implements an exception in the Client Server module.
 */
class ClientServerException : public base::BaseException {
public:
    /**
     * The ClientServerException constructor.
     */
    explicit ClientServerException(const std::wstring& errorMessage) :
        base::BaseException(errorMessage)
    {
    }

    /**
     * The ClientServerException constructor.
     */
    ClientServerException(
        long errorCode,
        const std::wstring& errorMessage) :
            base::BaseException(
                errorCode, 
                errorMessage)
    {
    }

    /**
     * The ClientServerException destructor.
     */
    virtual ~ClientServerException() = default;
};

}  // namespace client_server

#endif // CLIENT_SERVER_EXCEPTION_H_74038af5_78e2_47b4_af29_53b616f7926c
