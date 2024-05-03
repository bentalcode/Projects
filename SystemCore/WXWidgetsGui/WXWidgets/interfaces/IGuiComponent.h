#ifndef I_GUI_COMPONENT_e5ae7611_62de_4b6f_be23_303f7f785a3c
#define I_GUI_COMPONENT_e5ae7611_62de_4b6f_be23_303f7f785a3c

#include "IGuiController.h"
#include <string>
#include <memory>

namespace DataContainerManagement {
    class IDataContainer;
    class IDataContainerUpdateFunctors;
}

namespace WXWidgets {

    class IWXEventHandler;

    /**
     * The IGuiComponent interface defines a gui component.
     */
    class IGuiComponent {
    public:
        IGuiComponent() = default;
        virtual ~IGuiComponent() = default;

        /**
         * Gets a name of a component.
         */
        virtual const std::wstring GetName() const = 0;

        /**
         * Gets an event handler.
         */
        virtual IWXEventHandler& GetEventHandler() = 0;

        /**
         * Gets a GUI controller.
         */
        virtual IGuiControllerSharedPtr GetGuiController() = 0;

        /**
         * Gets a data container.
         */
        virtual DataContainerManagement::IDataContainer& GetData() = 0;

        /**
         * Gets a data update functors.
         */
        virtual DataContainerManagement::IDataContainerUpdateFunctors& GetDataUpdateFunctors() = 0;
    };

    /**
     * Defines the Shared Ptr of GUI component.
     */
    using IGuiComponentSharedPtr = std::shared_ptr<IGuiComponent>;

}  // namespace WXWidgets

#endif // I_GUI_COMPONENT_e5ae7611_62de_4b6f_be23_303f7f785a3c
