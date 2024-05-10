#ifndef I_CONTROLLER_MANAGER_H_952a95aa_9028_4638_941d_65bbd19022d1
#define I_CONTROLLER_MANAGER_H_952a95aa_9028_4638_941d_65bbd19022d1

#include "IGuiComponent.h"

namespace wxwidgets {

    namespace controller {

        /**
         * The IControllerManager interface defines a controller manager.
         */
        class IControllerManager {
        public:
            IControllerManager() = default;
            virtual ~IControllerManager() = default;

            /**
             * Gets an app component.
             */
            virtual IGuiComponent& GetAppComponent() = 0;

            /**
             * Gets a component by name.
             */
            virtual IGuiComponent& GetComponent(const std::wstring& name) = 0;

            /**
             * Checks whether a component exists.
             */
            virtual bool HasComponent(const std::wstring& name) const = 0;

            /**
             * Gets components.
             */
            virtual void GetComponents(IGuiComponentList& components) = 0;
        };

        /**
         * Defines the Shared Ptr of Controller Manager.
         */
        using IControllerManagerSharedPtr = std::shared_ptr<IControllerManager>;

    } // namespace controller

} // namespace wxwidgets

#endif // I_CONTROLLER_MANAGER_H_952a95aa_9028_4638_941d_65bbd19022d1
