#include "RenderingPipelineInformation.h"
#include "Loggers.h"
#include "VideoRenderingVisualizerModelException.h"
#include <assert.h>

using namespace VideoRenderingVisualizer::Model;

const std::wstring RenderingPipelineInformation::ID_PROPERTY = L"ID";
const std::wstring RenderingPipelineInformation::MSI_PROPERTY = L"MSI";
const std::wstring RenderingPipelineInformation::FPS_PROPERTY = L"FPS";
const std::wstring RenderingPipelineInformation::RENDERING_STATUS_PROPERTY = L"STATUS";

/**
 * Creates a rendering pipeline information.
 */
IRenderingPipelineInformationSharedPtr RenderingPipelineInformation::Make(
    const std::wstring& id, 
    unsigned int msi,
    double fps, 
    RenderingStatus renderingStatus)
{
    return std::make_shared<RenderingPipelineInformation>(
        id, 
        msi, 
        fps, 
        renderingStatus);
}

/**
 * The RenderingPipelineInformation constructor.
 */
RenderingPipelineInformation::RenderingPipelineInformation(
    const std::wstring& id, 
    unsigned int msi, 
    double fps,
    RenderingStatus renderingStatus) : 
    m_id(id), 
    m_msi(msi), 
    m_fps(fps), 
    m_renderingStatus(renderingStatus)
{
}

/**
 * The RenderingPipelineInformation destructor.
 */
RenderingPipelineInformation::~RenderingPipelineInformation() 
{
}

/**
 * Gets an id of a rendering pipeline.
 */
const std::wstring& RenderingPipelineInformation::GetId() const
{
    return m_id;
}

/**
 * Gets a media stream identifier (MSI) of a rendering pipeline.
 */
unsigned int RenderingPipelineInformation::GetMsi() const
{
    return m_msi;
}

/**
 * Gets a frames per second (FPS) of a rendering pipeline.
 */
double RenderingPipelineInformation::GetFps() const
{
    return m_fps;
}

/**
 * Gets a rendering status of a rendering pipeline.
 */
RenderingStatus RenderingPipelineInformation::GetRenderingStatus() const
{
    return m_renderingStatus;
}

/**
 * Gets names of properties.
 */
void RenderingPipelineInformation::GetPropertiesNames(std::vector<std::wstring>& names)
{
    assert(names.empty());
    
    names.push_back(ID_PROPERTY);
    names.push_back(MSI_PROPERTY);
    names.push_back(FPS_PROPERTY);
    names.push_back(RENDERING_STATUS_PROPERTY);
}

/**
 * Gets rendering status as a string.
 */
std::wstring RenderingPipelineInformation::GetRenderingStatusString(RenderingStatus renderingStatus) 
{
    static RenderingStatusMapUniquePtr renderingStatusMap(CreateRenderingStatusMap());
    
    RenderingStatusMap::const_iterator renderingStatusIterator = renderingStatusMap->find(renderingStatus);

    if (renderingStatusIterator == renderingStatusMap->end()) {
        long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

        std::wstringstream errorMessageStream;
        errorMessageStream 
            << L"The Rendering Pipeline Information has failed translating a status to a string"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        LOG_ERROR(GetSLogger(), errorMessage);
        throw VideoRenderingVisualizerModelException(errorCode, errorMessage);
    } 

    return renderingStatusIterator->second;
}

/**
 * Creates a rendering status map.
 */
RenderingPipelineInformation::RenderingStatusMap* RenderingPipelineInformation::CreateRenderingStatusMap()
{
    RenderingStatusMapUniquePtr renderingStatusMap = std::make_unique<RenderingStatusMap>();

    renderingStatusMap->insert(std::make_pair(RenderingStatus::CREATED, L"Created"));
    renderingStatusMap->insert(std::make_pair(RenderingStatus::FROZEN, L"Frozen"));
    renderingStatusMap->insert(std::make_pair(RenderingStatus::RENDERING, L"Rendering"));

    return renderingStatusMap.release();
}

/**
 * Gets a static logger.
 */
logging::ILoggerSharedPtr RenderingPipelineInformation::GetSLogger()
{
    static logging::ILoggersSharedPtr loggers = logging::Loggers::Make(typeid(RenderingPipelineInformation));
    return loggers->GetLogger();
}