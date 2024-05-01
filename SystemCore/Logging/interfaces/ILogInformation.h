#ifndef I_LOG_INFORMATION_H_7b88897b_d2f7_4a67_bf5e_4485875edc8a
#define I_LOG_INFORMATION_H_7b88897b_d2f7_4a67_bf5e_4485875edc8a

#include <memory>

namespace tabular_data {
   class ITabularFileInformation;
}

namespace logging {

    /**
     * The ILogInformation interface defines information of log.
     */
    class ILogInformation {
    public:
        ILogInformation() = default;
        virtual ~ILogInformation() = default;

        /**
         * Gets information of tabular file.
         */
        virtual const tabular_data::ITabularFileInformation& GetTabularFileInformation() const = 0;
    };

    /**
     * Defines the Shared Ptr of Log Information.
     */
    using ILogInformationSharedPtr = std::shared_ptr<ILogInformation>;

} // namespace logging

#endif // I_LOG_INFORMATION_H_7b88897b_d2f7_4a67_bf5e_4485875edc8a

