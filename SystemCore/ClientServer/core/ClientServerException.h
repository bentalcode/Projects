#pragma once

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
        unsigned long errorCode, 
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
