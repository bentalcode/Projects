#ifndef I_DATA_CONTAINER_UPDATE_FUNCTORS_H_598c482d_abcc_4355_aad7_976814bcdc7a
#define I_DATA_CONTAINER_UPDATE_FUNCTORS_H_598c482d_abcc_4355_aad7_976814bcdc7a

#include <functional>
#include <vector>
#include <string>
#include <memory>
#include "DateTime.h"
#include "Duration.h"

namespace DataContainerManagement {

    /**
     * The IDataContainerUpdateFunctors interface defines functors of data container updation.
     */
    class IDataContainerUpdateFunctors {
    public:
        //
        // Defines the SharedPtr of Update Functor of type boolean...
        //
        using IBooleanFunctor = std::function<void(bool)>;
        using IBooleanFunctorSharedPtr = std::shared_ptr<IBooleanFunctor>;

        //
        // Defines the SharedPtr of Update Functor of type integer...
        //
        using IIntegerFunctor = std::function<void(int)>;
        using IIntegerFunctorSharedPtr = std::shared_ptr<IIntegerFunctor>;

        //
        // Defines the SharedPtr of Update Functor of type long...
        //
        using ILongFunctor = std::function<void(long)>;
        using ILongFunctorSharedPtr = std::shared_ptr<ILongFunctor>;

        //
        // Defines the SharedPtr of Update Functor of type double...
        //
        using IDoubleFunctor = std::function<void(double)>;
        using IDoubleFunctorSharedPtr = std::shared_ptr<IDoubleFunctor>;

        //
        // Defines the SharedPtr of Update Functor of type string...
        //
        using IStringFunctor = std::function<void(const std::wstring&)>;
        using IStringFunctorSharedPtr = std::shared_ptr<IStringFunctor>;

        //
        // Defines the SharedPtr of Update Functor of type date time...
        //
        using IDateTimeFunctor = std::function<void(const base::DateTime&)>;
        using IDateTimeFunctorSharedPtr = std::shared_ptr<IDateTimeFunctor>;

        //
        // Defines the SharedPtr of Update Functor of type duration...
        //
        using IDurationFunctor = std::function<void(const base::Duration&)>;
        using IDurationFunctorSharedPtr = std::shared_ptr<IDurationFunctor>;

        //
        // Defines the SharedPtr of Update Functor of type string array...
        //
        using IStringArrayFunctor = std::function<void(const std::vector<std::wstring>&)>;
        using IStringArrayFunctorSharedPtr = std::shared_ptr<IStringArrayFunctor>;

        //
        // Defines the SharedPtr of Update Functor of type string array array...
        //
        using IStringArrayArrayFunctor = std::function<void(const std::vector<std::vector<std::wstring>>&)>;
        using IStringArrayArrayFunctorSharedPtr = std::shared_ptr<IStringArrayArrayFunctor>;

        IDataContainerUpdateFunctors() = default;
        virtual ~IDataContainerUpdateFunctors() = default;

        /**
         * Registers an update functor of type boolean.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IBooleanFunctorSharedPtr updateFunctor) = 0;

        /**
         * Registers an update functor of type integer.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IIntegerFunctorSharedPtr updateFunctor) = 0;

        /**
         * Registers an update functor of type long.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            ILongFunctorSharedPtr updateFunctor) = 0;

        /**
         * Registers an update functor of type double.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDoubleFunctorSharedPtr updateFunctor) = 0;

        /**
         * Registers an update functor of type string.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IStringFunctorSharedPtr updateFunctor) = 0;

        /**
         * Registers an update functor of type date-time.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDateTimeFunctorSharedPtr updateFunctor) = 0;

        /**
         * Registers an update functor of type duration.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IDurationFunctorSharedPtr updateFunctor) = 0;

        /**
         * Registers an update functor of type string array.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IStringArrayFunctorSharedPtr updateFunctor) = 0;

        /**
         * Registers an update functor of type array of string array.
         */
        virtual void RegisterUpdateFunctor(
            const std::wstring& name,
            IStringArrayArrayFunctorSharedPtr updateFunctor) = 0;

        /**
         * Gets an update functor of type boolean.
         */
        virtual IBooleanFunctorSharedPtr GetBooleanUpdateFunctor(const std::wstring& name) = 0;

        /**
         * Gets an update functor of type integer.
         */
        virtual IIntegerFunctorSharedPtr GetIntegerUpdateFunctor(const std::wstring& name) = 0;

        /**
         * Gets an update functor of type long.
         */
        virtual ILongFunctorSharedPtr GetLongUpdateFunctor(const std::wstring& name) = 0;

        /**
         * Gets an update functor of type double.
         */
        virtual IDoubleFunctorSharedPtr GetDoubleUpdateFunctor(const std::wstring& name) = 0;

        /**
         * Gets an update functor of type string.
         */
        virtual IStringFunctorSharedPtr GetStringUpdateFunctor(const std::wstring& name) = 0;

        /**
         * Gets an update functor of type date-time.
         */
        virtual IDateTimeFunctorSharedPtr GetDateTimeUpdateFunctor(const std::wstring& name) = 0;

        /**
         * Gets an update functor of type duration.
         */
        virtual IDurationFunctorSharedPtr GetDurationUpdateFunctor(const std::wstring& name) = 0;

        /**
         * Gets an update functor of type string array.
         */
        virtual IStringArrayFunctorSharedPtr GetStringArrayUpdateFunctor(const std::wstring& name) = 0;

        /**
         * Gets an update functor of type array of string array.
         */
        virtual IStringArrayArrayFunctorSharedPtr GetStringArrayArrayUpdateFunctor(const std::wstring& name) = 0;
    };

    /**
     * Defines the Shared Ptr of Data Container Update.
     */
    using IDataContainerUpdateFunctorsSharedPtr = std::shared_ptr<IDataContainerUpdateFunctors>;

}  // namespace DataContainerManagement

#endif // I_DATA_CONTAINER_UPDATE_FUNCTORS_H_598c482d_abcc_4355_aad7_976814bcdc7a
