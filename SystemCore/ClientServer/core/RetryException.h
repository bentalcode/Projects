#pragma once

#include "ClientServerException.h"

namespace client_server {

/**
 * The RetryException class implements a retry exception in the Client Server module.
 */
class RetryException final : public ClientServerException {
public:
    /**
     * The RetryException constructor.
     */
    explicit RetryException(const std::wstring& errorMessage) :
        ClientServerException(errorMessage)
    {
    }

    /**
     * The RetryException constructor.
     */
    RetryException(
        unsigned long errorCode, 
        const std::wstring& errorMessage) :
            ClientServerException(
                errorCode, 
                errorMessage)
    {
    }

    /**
     * The RetryException destructor.
     */
    virtual ~RetryException() = default;
};

}  // namespace client_server
