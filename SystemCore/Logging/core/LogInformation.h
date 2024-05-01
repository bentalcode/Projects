#ifndef LOG_INFORMATION_H_575b823c_c351_404e_8fd1_856a5cd9c77c
#define LOG_INFORMATION_H_575b823c_c351_404e_8fd1_856a5cd9c77c

#include "ILogInformation.h"
#include "ITabularFileInformation.h"

namespace logging {

    /**
     * The LogInformation class implements information of a log.
     */
    class LogInformation final : public ILogInformation {
    public:
        /**
         * Creates Log Information.
         */
        static ILogInformationSharedPtr Make(const tabular_data::ITabularFileInformationSharedPtr tabularFileInformation);

        /**
         * The LogInformation constructor.
         */
        explicit LogInformation(const tabular_data::ITabularFileInformationSharedPtr tabularFileInformation);

        /**
         * The LogInformation destructor.
         */
        virtual ~LogInformation();

        /**
         * Gets information of a tabular file.
         */
        virtual const tabular_data::ITabularFileInformation& GetTabularFileInformation() const override;

    private:
        tabular_data::ITabularFileInformationSharedPtr m_tabularFileInformation;
    };

} // namespace logging

#endif // LOG_INFORMATION_H_575b823c_c351_404e_8fd1_856a5cd9c77c
