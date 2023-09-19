#ifndef ERROR_MESSAGES_H_533c2dda_4a8e_4f06_a9fc_d8f531768307
#define ERROR_MESSAGES_H_533c2dda_4a8e_4f06_a9fc_d8f531768307

#include <string>

namespace base {

/**
 * The ErrorMessages class implements API for error messages.
 */
class ErrorMessages final {
public:
    ErrorMessages() = delete;
    ~ErrorMessages() = delete;

    /**
     * Gets error code message.
     */
    static const std::wstring GetErrorCodeMessage(long errorCode);
};

} // namespace base

#endif // ERROR_MESSAGES_H_533c2dda_4a8e_4f06_a9fc_d8f531768307
