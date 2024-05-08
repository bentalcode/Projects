#ifndef CONTROLLER_MANAGER_H_fa6e7f58_3ed8_441d_8dbb_742ef21facc5
#define CONTROLLER_MANAGER_H_fa6e7f58_3ed8_441d_8dbb_742ef21facc5

#include "IControllerManager.h"
#include "IGuiController.h"

namespace WXWidgets {

    namespace Command {

        /**
         * The ControllerManager class implements a controller manager.
         */
        class ControllerManager final : public IControllerManager {
        public:
              /**
              * Creates a controller manager.
              */
              static IControllerManagerSharedPtr Make(IGuiControllerSharedPtr guiController);

              /**
              * The ControllerManager constructor.
              */
              explicit ControllerManager(IGuiControllerSharedPtr guiController);

              /**
              * The ControllerManager destructor.
              */
              virtual ~ControllerManager();

              /**
              * Gets app component.
              */
              virtual WXWidgets::IGuiComponent& GetAppComponent() override;

              /**
              * Gets a component by name.
              */
              virtual IGuiComponent& GetComponent(const std::wstring& name) override;

              /**
              * Checks whether a component exists.
              */
              virtual bool HasComponent(const std::wstring& name) const override;

              /**
              * Gets components.
              */
              virtual void GetComponents(IGuiComponentList& components) override;

        private:
            IGuiControllerSharedPtr m_guiController;
        };

    } // namespace Command

} // namespace WXWidgets

#endif // namespace CONTROLLER_MANAGER_H_fa6e7f58_3ed8_441d_8dbb_742ef21facc5
