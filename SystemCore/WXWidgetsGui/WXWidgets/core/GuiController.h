#ifndef GUI_CONTROLLER_c6741841_9823_42b7_b55c_2d010cf738b9
#define GUI_CONTROLLER_c6741841_9823_42b7_b55c_2d010cf738b9

#include "IGuiController.h"
#include <map>
#include <mutex>
#include "ILogger.h"

namespace WXWidgets {

    /**
     * The GuiController class implements a GUI controller for managing GUI components.
     */
    class GuiController final : public IGuiController {
    public:
        /**
         * Creates a GUI controller.
         */
        static IGuiControllerSharedPtr Create();

        /**
         * The GuiController constructor.
         */
        GuiController();

        /**
         * The GuiController destructor.
         */
        virtual ~GuiController();

        /**
         * Sets app component.
         */
        virtual void SetAppComponent(IGuiComponent* component) override;

        /**
         * Gets app component.
         */
        virtual IGuiComponent& GetAppComponent() override;

        /**
         * Adds a new component.
         */
        virtual void AddComponent(IGuiComponent& component) override;

        /**
         * Removes an existing component by name.
         */
        virtual void RemoveComponent(const std::wstring& name) override;

        /**
         * Sets a component by name.
         */
        virtual void SetComponent(IGuiComponent& component) override;

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

        /**
         * Gets a string of components list.
         */
        static std::wstring GetComponentListString(IGuiComponentList& components);

    private:
        /**
         * Finds a component by name.
         */
        IGuiComponent* FindComponent(const std::wstring& name);

        /**
         * Gets a static logger.
         */
        static logging::ILoggerSharedPtr GetSLogger();

        //
        // The mutex of this class...
        //
        mutable std::mutex m_mutex;

        //
        // The app component...
        //
        IGuiComponent* m_app;

        //
        // Defines a GUI Component Map...
        //
        using GuiComponentMap = std::map<std::wstring, IGuiComponent*>;
        GuiComponentMap m_componentMap;

        //
        // Defines a GUI Component List for initialization order...
        //
        IGuiComponentList m_componentList;
    };

} // namespace WXWidgets

#endif // GUI_CONTROLLER_c6741841_9823_42b7_b55c_2d010cf738b9
