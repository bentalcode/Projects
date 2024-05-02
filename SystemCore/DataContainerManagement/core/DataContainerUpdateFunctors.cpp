#include "DataContainerUpdateFunctors.h"
#include "Loggers.h"

using namespace DataContainerManagement;

/**
 * Creates a data container update functors.
 */
IDataContainerUpdateFunctorsSharedPtr DataContainerUpdateFunctors::Make()
{ 
    return std::make_shared<DataContainerUpdateFunctors>();
}

/**
 * The DataContainerUpdateFunctors constructor.
 */
DataContainerUpdateFunctors::DataContainerUpdateFunctors()
{
}

/**
 * The DataContainerUpdateFunctors destructor.
 */
DataContainerUpdateFunctors::~DataContainerUpdateFunctors()
{
}

/**
 * Registers an update functor of type boolean.
 */
void DataContainerUpdateFunctors::RegisterUpdateFunctor(
    const std::wstring& name,
    IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr updateFunctor)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    DataContainerUpdateFunctors::RegisterUpdateFunctor<
        IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr, 
        UpdateBooleanFunctorMap>(
            name, 
            updateFunctor, 
            m_updateBooleanFunctorMap);
}

/**
 * Registers an update functor of type integer.
 */
void DataContainerUpdateFunctors::RegisterUpdateFunctor(
    const std::wstring& name,
    IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr updateFunctor)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    DataContainerUpdateFunctors::RegisterUpdateFunctor
        <IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr, UpdateIntegerFunctorMap>(
            name, 
            updateFunctor, 
            m_updateIntegerFunctorMap);
}

/**
 * Registers an update functor of type long.
 */
void DataContainerUpdateFunctors::RegisterUpdateFunctor(
    const std::wstring& name,
    IDataContainerUpdateFunctors::ILongFunctorSharedPtr updateFunctor)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    DataContainerUpdateFunctors::RegisterUpdateFunctor
        <IDataContainerUpdateFunctors::ILongFunctorSharedPtr, UpdateLongFunctorMap>(
            name, 
            updateFunctor, 
            m_updateLongFunctorMap);
}

/**
 * Registers an update functor of type double.
 */
void DataContainerUpdateFunctors::RegisterUpdateFunctor(
    const std::wstring& name,
    IDataContainerUpdateFunctors::IDoubleFunctorSharedPtr updateFunctor)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    DataContainerUpdateFunctors::RegisterUpdateFunctor
        <IDataContainerUpdateFunctors::IDoubleFunctorSharedPtr, UpdateDoubleFunctorMap>(
            name, 
            updateFunctor,
            m_updateDoubleFunctorMap);
}

/**
 * Registers an update functor of type string.
 */
void DataContainerUpdateFunctors::RegisterUpdateFunctor(
    const std::wstring& name,
    IDataContainerUpdateFunctors::IStringFunctorSharedPtr updateFunctor)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    DataContainerUpdateFunctors::RegisterUpdateFunctor
        <IDataContainerUpdateFunctors::IStringFunctorSharedPtr, UpdateStringFunctorMap>(
            name, 
            updateFunctor, 
            m_updateStringFunctorMap);
}

/**
 * Registers an update functor of type date-time.
 */
void DataContainerUpdateFunctors::RegisterUpdateFunctor(
    const std::wstring& name,
    IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr updateFunctor)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    DataContainerUpdateFunctors::RegisterUpdateFunctor<IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr, UpdateDateTimeFunctorMap>(
        name, 
        updateFunctor, 
        m_updateDateTimeFunctorMap);
}

/**
 * Registers an update functor of type duration.
 */
void DataContainerUpdateFunctors::RegisterUpdateFunctor(
    const std::wstring& name,
    IDataContainerUpdateFunctors::IDurationFunctorSharedPtr updateFunctor)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    DataContainerUpdateFunctors::RegisterUpdateFunctor<IDataContainerUpdateFunctors::IDurationFunctorSharedPtr, UpdateDurationFunctorMap>(
        name, 
        updateFunctor, 
        m_updateDurationFunctorMap);
}

/**
 * Registers an update functor of type string array.
 */
void DataContainerUpdateFunctors::RegisterUpdateFunctor(
    const std::wstring& name,
    IDataContainerUpdateFunctors::IStringArrayFunctorSharedPtr updateFunctor)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    DataContainerUpdateFunctors::RegisterUpdateFunctor
        <IDataContainerUpdateFunctors::IStringArrayFunctorSharedPtr, UpdateStringArrayFunctorMap>(
            name, 
            updateFunctor,
            m_updateStringArrayFunctorMap);
}

/**
 * Registers an update functor of type array of string array.
 */
void DataContainerUpdateFunctors::RegisterUpdateFunctor(
    const std::wstring& name,
    IDataContainerUpdateFunctors::IStringArrayArrayFunctorSharedPtr updateFunctor)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    DataContainerUpdateFunctors::RegisterUpdateFunctor
        <IDataContainerUpdateFunctors::IStringArrayArrayFunctorSharedPtr, UpdateStringArrayArrayFunctorMap>(
            name, 
            updateFunctor,
            m_updateStringArrayArrayFunctorMap);
}

/**
 * Gets an update functor of type boolean.
 */
IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr 
DataContainerUpdateFunctors::GetBooleanUpdateFunctor(const std::wstring& name) 
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr functor = DataContainerUpdateFunctors::GetUpdateFunctor
        <IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr, UpdateBooleanFunctorMap>(
            name,
            m_updateBooleanFunctorMap);

    return functor;
}

/**
 * Gets an update functor of type integer.
 */
IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr
DataContainerUpdateFunctors::GetIntegerUpdateFunctor(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr functor =
        DataContainerUpdateFunctors::GetUpdateFunctor<IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr, UpdateIntegerFunctorMap>(
            name, 
            m_updateIntegerFunctorMap);

    return functor;
}

/**
 * Gets an update functor of type long.
 */
IDataContainerUpdateFunctors::ILongFunctorSharedPtr 
DataContainerUpdateFunctors::GetLongUpdateFunctor(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IDataContainerUpdateFunctors::ILongFunctorSharedPtr functor =
        DataContainerUpdateFunctors::GetUpdateFunctor<IDataContainerUpdateFunctors::ILongFunctorSharedPtr, UpdateLongFunctorMap>(
            name, 
            m_updateLongFunctorMap);

    return functor;
}

/**
 * Gets an update functor of type double.
 */
IDataContainerUpdateFunctors::IDoubleFunctorSharedPtr
DataContainerUpdateFunctors::GetDoubleUpdateFunctor(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IDataContainerUpdateFunctors::IDoubleFunctorSharedPtr functor =
        DataContainerUpdateFunctors::GetUpdateFunctor<IDataContainerUpdateFunctors::IDoubleFunctorSharedPtr, UpdateDoubleFunctorMap>(
            name, 
            m_updateDoubleFunctorMap);

    return functor;
}

/**
 * Gets an update functor of type string.
 */
IDataContainerUpdateFunctors::IStringFunctorSharedPtr
DataContainerUpdateFunctors::GetStringUpdateFunctor(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IDataContainerUpdateFunctors::IStringFunctorSharedPtr functor =
        DataContainerUpdateFunctors::GetUpdateFunctor<IDataContainerUpdateFunctors::IStringFunctorSharedPtr, UpdateStringFunctorMap>(
            name, 
            m_updateStringFunctorMap);

    return functor;
}

/**
 * Gets an update functor of type date-time.
 */
IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr
DataContainerUpdateFunctors::GetDateTimeUpdateFunctor(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr functor =
        DataContainerUpdateFunctors::GetUpdateFunctor<IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr, UpdateDateTimeFunctorMap>(
            name, m_updateDateTimeFunctorMap);

    return functor;
}

/**
 * Gets an update functor of type duration.
 */
IDataContainerUpdateFunctors::IDurationFunctorSharedPtr
DataContainerUpdateFunctors::GetDurationUpdateFunctor(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IDataContainerUpdateFunctors::IDurationFunctorSharedPtr functor =
        DataContainerUpdateFunctors::GetUpdateFunctor<IDataContainerUpdateFunctors::IDurationFunctorSharedPtr, UpdateDurationFunctorMap>(
            name, 
            m_updateDurationFunctorMap);

    return functor;
}

/**
 * Gets an update functor of type string array.
 */
IDataContainerUpdateFunctors::IStringArrayFunctorSharedPtr
DataContainerUpdateFunctors::GetStringArrayUpdateFunctor(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IDataContainerUpdateFunctors::IStringArrayFunctorSharedPtr functor =
        DataContainerUpdateFunctors::GetUpdateFunctor<IDataContainerUpdateFunctors::IStringArrayFunctorSharedPtr, UpdateStringArrayFunctorMap>(
            name, 
            m_updateStringArrayFunctorMap);

    return functor;
}

/**
 * Gets an update functor of type array of string array.
 */
IDataContainerUpdateFunctors::IStringArrayArrayFunctorSharedPtr
DataContainerUpdateFunctors::GetStringArrayArrayUpdateFunctor(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    IDataContainerUpdateFunctors::IStringArrayArrayFunctorSharedPtr functor =
        DataContainerUpdateFunctors::GetUpdateFunctor<IDataContainerUpdateFunctors::IStringArrayArrayFunctorSharedPtr, UpdateStringArrayArrayFunctorMap>(
            name, 
            m_updateStringArrayArrayFunctorMap);

    return functor;
}

/**
 * Gets a static logger.
 */
logging::ILoggerSharedPtr DataContainerUpdateFunctors::GetSLogger()
{
    static logging::ILoggersSharedPtr loggers = logging::Loggers::Make(typeid(DataContainerManagement::DataContainerUpdateFunctors));
    return loggers->GetLogger();
}
