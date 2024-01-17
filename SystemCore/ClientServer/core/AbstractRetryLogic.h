#ifndef ABSTRACT_RETRY_LOGIC_H_827eeed2_dc3c_469e_b9d7_7129670dc89e
#define ABSTRACT_RETRY_LOGIC_H_827eeed2_dc3c_469e_b9d7_7129670dc89e

#include "IRetryLogic.h"

namespace client_server {

    /**
     * The AbstractRetryLogic base class implements an abstract retry logic.
     */
    class AbstractRetryLogic : public IRetryLogic
    {
    public:
        /**
         * The AbstractRetryLogic constructor.
         */
        explicit AbstractRetryLogic(const std::wstring& name);

        /**
         * The AbstractRetryLogic constructor.
         */
        AbstractRetryLogic(
            const std::wstring& name,
            const std::vector<base::IClassTypeSharedPtr>& absorbedException);

        /**
         * The destructor.
         */
        virtual ~AbstractRetryLogic();

        /**
         * Gets the name of the logic.
         */
        virtual const std::wstring& GetName() const override;

        /**
         * Gets the set of the absorbed exception types.
         */
        virtual const std::vector<base::IClassTypeSharedPtr>& GetAbsorbedExceptions() const override;

    private:
        std::wstring m_name;
        std::vector<base::IClassTypeSharedPtr> m_absorbedException;
    };

} // namespace client_server

#endif // ABSTRACT_RETRY_LOGIC_H_827eeed2_dc3c_469e_b9d7_7129670dc89e
