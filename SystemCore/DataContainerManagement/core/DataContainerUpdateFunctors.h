#ifndef DATA_CONTAINER_UPDATE_FUNCTORS_H_fc67de40_f13d_403a_beb6_8f95ff2e063c
#define DATA_CONTAINER_UPDATE_FUNCTORS_H_fc67de40_f13d_403a_beb6_8f95ff2e063c

#include "IDataContainerUpdateFunctors.h"
#include <map>
#include <mutex>
#include "DataContainerException.h"
#include "ILogger.h"

namespace DataContainerManagement {

    /**
     * The DataContainerUpdateFunctors class implements update functors of data container.
     */
    class DataContainerUpdateFunctors final : public IDataContainerUpdateFunctors {
    public:
        /**
         * Creates a data container update functors.
         */
        static IDataContainerUpdateFunctorsSharedPtr Make();

        /**
         * The DataContainerUpdateFunctors constructor.
         */
        DataContainerUpdateFunctors();

        /**
         * The DataContainerUpdateFunctors destructor.
         */
        ~DataContainerUpdateFunctors();

        /**
         * Registers an update functor of type boolean.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr updateFunctor) override;

        /**
         * Registers an update functor of type integer.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr updateFunctor) override;

        /**
         * Registers an update functor of type long.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDataContainerUpdateFunctors::ILongFunctorSharedPtr updateFunctor) override;

        /**
         * Registers an update functor of type double.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDataContainerUpdateFunctors::IDoubleFunctorSharedPtr updateFunctor) override;

        /**
         * Registers an update functor of type string.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDataContainerUpdateFunctors::IStringFunctorSharedPtr updateFunctor) override;

        /**
         * Registers an update functor of type date-time.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr updateFunctor) override;

        /**
         * Registers an update functor of type duration.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDataContainerUpdateFunctors::IDurationFunctorSharedPtr updateFunctor) override;

        /**
         * Registers an update functor of type string array.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDataContainerUpdateFunctors::IStringArrayFunctorSharedPtr updateFunctor) override;

        /**
         * Registers an update functor of type array of string array.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IStringArrayArrayFunctorSharedPtr updateFunctor) override;

        /**
         * Gets an update functor of type boolean.
         */
        virtual IBooleanFunctorSharedPtr GetBooleanUpdateFunctor(const std::wstring& name) override;

        /**
         * Gets an update functor of type integer.
         */
        virtual IIntegerFunctorSharedPtr GetIntegerUpdateFunctor(const std::wstring& name) override;

        /**
         * Gets an update functor of type long.
         */
        virtual ILongFunctorSharedPtr GetLongUpdateFunctor(const std::wstring& name) override;

        /**
         * Gets an update functor of type double.
         */
        virtual IDoubleFunctorSharedPtr GetDoubleUpdateFunctor(const std::wstring& name) override;

        /**
         * Gets an update functor of type string.
         */
        virtual IStringFunctorSharedPtr GetStringUpdateFunctor(const std::wstring& name) override;

        /**
         * Gets an update functor of type date-time.
         */
        virtual IDateTimeFunctorSharedPtr GetDateTimeUpdateFunctor(const std::wstring& name) override;

        /**
         * Gets an update functor of type duration.
         */
        virtual IDurationFunctorSharedPtr GetDurationUpdateFunctor(const std::wstring& name) override;

        /**
         * Gets an update functor of type string array.
         */
        virtual IStringArrayFunctorSharedPtr GetStringArrayUpdateFunctor(const std::wstring& name) override;

        /**
         * Gets an update functor of type array of string array.
         */
        virtual IStringArrayArrayFunctorSharedPtr GetStringArrayArrayUpdateFunctor(const std::wstring& name) override;

    private:
        //
        // The mutex of this class...
        //
        mutable std::mutex m_mutex;

        /**
         * Registers an update functor of generic type.
         */
        template <typename FunctorType, typename ContainerType>
        static void RegisterUpdateFunctor(
            const std::wstring& name,
            FunctorType updateFunctor,
            ContainerType& container);

        /**
         * Gets an update functor of generic type.
         */
        template <typename FunctorType, typename ContainerType>
        static FunctorType& GetUpdateFunctor(
            const std::wstring& name,
            ContainerType& container);

        /**
         * Gets a static logger.
         */
        static logging::ILoggerSharedPtr GetSLogger();

        //
        // The map of update functors of type boolean....
        //
        using UpdateBooleanFunctorMap = std::map<std::wstring, IDataContainerUpdateFunctors::IBooleanFunctorSharedPtr>;
        UpdateBooleanFunctorMap m_updateBooleanFunctorMap;

        //
        // The map of update functors of type integer....
        //
        using UpdateIntegerFunctorMap = std::map<std::wstring, IDataContainerUpdateFunctors::IIntegerFunctorSharedPtr>;
        UpdateIntegerFunctorMap m_updateIntegerFunctorMap;

        //
        // The map of update functors of type long....
        //
        using UpdateLongFunctorMap = std::map<std::wstring, IDataContainerUpdateFunctors::ILongFunctorSharedPtr>;
        UpdateLongFunctorMap m_updateLongFunctorMap;

        //
        // The map of update functors of type double....
        //
        using UpdateDoubleFunctorMap = std::map<std::wstring, IDataContainerUpdateFunctors::IDoubleFunctorSharedPtr>;
        UpdateDoubleFunctorMap m_updateDoubleFunctorMap;

        //
        // The map of update functors of type string....
        //
        using UpdateStringFunctorMap = std::map<std::wstring, IDataContainerUpdateFunctors::IStringFunctorSharedPtr>;
        UpdateStringFunctorMap m_updateStringFunctorMap;

        //
        // The map of update functors of type date-time....
        //
        using UpdateDateTimeFunctorMap = std::map<std::wstring, IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr>;
        UpdateDateTimeFunctorMap m_updateDateTimeFunctorMap;

        //
        // The map of update functors of type duration....
        //
        using UpdateDurationFunctorMap = std::map<std::wstring, IDataContainerUpdateFunctors::IDurationFunctorSharedPtr>;
        UpdateDurationFunctorMap m_updateDurationFunctorMap;

        //
        // The map of update functors of type string array....
        //
        using UpdateStringArrayFunctorMap = std::map<std::wstring, IDataContainerUpdateFunctors::IStringArrayFunctorSharedPtr>;
        UpdateStringArrayFunctorMap m_updateStringArrayFunctorMap;

        //
        // The map of update functors of type array of string array....
        //
        using UpdateStringArrayArrayFunctorMap = std::map<std::wstring, IDataContainerUpdateFunctors::IStringArrayArrayFunctorSharedPtr>;
        UpdateStringArrayArrayFunctorMap m_updateStringArrayArrayFunctorMap;
    };

    /**
     * Registers an update functor of generic type.
     */
    template <typename FunctorType, typename ContainerType>
    void DataContainerUpdateFunctors::RegisterUpdateFunctor(
        const std::wstring& name,
        FunctorType updateFunctor,
        ContainerType& container)
    {
        auto functorIterator = container.find(name);

        if (functorIterator != container.end()) {
            long errorCode = base::ErrorCodes::RESOURCE_ALREADY_EXISTS;

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"Data Container Update Functors already contains a functor with name: " << name
                << base::ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();

            LOG_ERROR(GetSLogger(), errorMessage);
            throw data_container_exception(errorCode, errorMessage);
        }

        container.insert(std::make_pair(name, updateFunctor));
    }

    /**
     * Gets an update functor of generic type.
     */
    template <typename FunctorType, typename ContainerType>
    FunctorType& DataContainerUpdateFunctors::GetUpdateFunctor(
        const std::wstring& name,
        ContainerType& container)
    {
        auto functorIterator = container.find(name);

        if (functorIterator == container.end()) {
            long errorCode = base::ErrorCodes::RESOURCE_NOT_FOUND;

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"Data Container Update Functors does not contain a functor with name: " << name
                << base::ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();

            LOG_ERROR(GetSLogger(), errorMessage);
            throw data_container_exception(errorCode, errorMessage);
        }

        return functorIterator->second;
    }

} // namespace DataContainerManagement

#endif // DATA_CONTAINER_UPDATE_FUNCTORS_H_fc67de40_f13d_403a_beb6_8f95ff2e063c
