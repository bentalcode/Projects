#ifndef I_GUI_CONTROLLER_c613bfb1_b451_4e4b_b422_f232e5bcc499
#define I_GUI_CONTROLLER_c613bfb1_b451_4e4b_b422_f232e5bcc499

#include <string>
#include <list>
#include <memory>

namespace WXWidgets {

    class IGuiComponent;
    using IGuiComponentList = std::list<IGuiComponent*>;

    /**
     * The IGuiController interface defines a GUI Controller for managing GUI components.
     */
    class IGuiController {
    public:
        IGuiController() = default;
        virtual ~IGuiController() = default;

        /**
         * Sets app component.
         */
        virtual void SetAppComponent(IGuiComponent* component) = 0;

        /**
         * Gets app component.
         */
        virtual IGuiComponent& GetAppComponent() = 0;

        /**
         * Adds a new component.
         */
        virtual void AddComponent(IGuiComponent& component) = 0;

        /**
         * Removes an existing component by name.
         */
        virtual void RemoveComponent(const std::wstring& name) = 0;

        /**
         * Sets a component by name.
         */
        virtual void SetComponent(IGuiComponent& component) = 0;

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
     * Defines the Shared Ptr of GUI Controller.
     */
    using IGuiControllerSharedPtr = std::shared_ptr<IGuiController>;

} // namespace WXWidgets

#endif // I_GUI_CONTROLLER_c613bfb1_b451_4e4b_b422_f232e5bcc499
