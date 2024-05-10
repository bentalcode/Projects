#include "AbstractGuiWindow.h"
#include "Loggers.h"
#include <sstream>

using namespace VideoRenderingVisualizer::Gui;

/**
 * The AbstractGuiWindow constructor.
 */
AbstractGuiWindow::AbstractGuiWindow(
    const std::wstring& name, 
    IGuiManager& guiManager) : 
    m_name(name), 
    m_guiManager(guiManager),
	m_loggers(logging::Loggers::Make(typeid(VideoRenderingVisualizer::Gui::AbstractGuiWindow)))
{
    std::wstringstream informationalStream;
    informationalStream << L"The GUI Window: " << m_name << L" has been created successfully.";
    std::wstring informationalMessage = informationalStream.str();

    LOG_INFO(m_loggers->GetLogger(), informationalMessage);
}

/**
 * The AbstractGuiWindow destructor.
 */
AbstractGuiWindow::~AbstractGuiWindow() 
{
    std::wstringstream informationalStream;
    informationalStream << L"The GUI Window: " << m_name << L" has been destroyed successfully.";
    std::wstring informationalMessage = informationalStream.str();

    LOG_INFO(m_loggers->GetLogger(), informationalMessage);
}

/**
 * Gets GUI manager.
 */
IGuiManager& AbstractGuiWindow::GetGuiManager() 
{
    return m_guiManager;
}

/**
 * Gets logger of GUI component.
 */
logging::ILoggerSharedPtr AbstractGuiWindow::GetLogger()
{
    return m_loggers->GetLogger();
}
