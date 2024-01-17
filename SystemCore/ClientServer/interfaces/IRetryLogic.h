#ifndef I_RETRY_LOGIC_H_16a5ee7e_f49d_4e91_9e98_c35c88fc9014
#define I_RETRY_LOGIC_H_16a5ee7e_f49d_4e91_9e98_c35c88fc9014

#include "ILogic.h"
#include "ClassType.h"
#include <vector>
#include <sstream>

namespace client_server {

    /**
     * The IRetryLogic interface defines a generic retry logic.
     */
    class IRetryLogic : public ILogic {
    public:
        IRetryLogic() = default;
        virtual ~IRetryLogic() = default;

        /**
         * The copy/move constructors.
         */
        IRetryLogic(const IRetryLogic&) = delete;
        IRetryLogic(IRetryLogic&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IRetryLogic& operator=(const IRetryLogic&) = delete;
        IRetryLogic& operator=(IRetryLogic&&) = delete;

        /**
         * Gets the set of the absorbed exception types.
         */
        virtual const std::vector<base::IClassTypeSharedPtr>& GetAbsorbedExceptions() const = 0;
    };

    /**
     * Defines the Shared Ptr of Retry Logic.
     */
    using IRetryLogicSharedPtr = std::shared_ptr<IRetryLogic>;

    /**
     * Writes retry logic to an output stream.
     */
    inline std::wostream& operator<<(std::wostream& stream, const IRetryLogic& retryLogic)
    {
        stream << L"Retry Logic: " << retryLogic.GetName();
        return stream;
    }

} // namespace client_server

#endif // I_RETRY_LOGIC_H_16a5ee7e_f49d_4e91_9e98_c35c88fc9014
