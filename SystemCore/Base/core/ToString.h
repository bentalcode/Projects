#ifndef TO_STRING_H_205b3b36_02d1_4af9_a4ed_b49cc81b1582
#define TO_STRING_H_205b3b36_02d1_4af9_a4ed_b49cc81b1582

#include "IToString.h"
#include "StringUtils.h"

namespace base {

     /**
     * The DefaultToString class implements the default conversion logic for transforming an object to a string.
     */
    class DefaultToString final : public IToString<std::wstring> {
    public:
        /**
         * Creates an instance Of ToString.
         */
        static IToStringSharedPtr<std::wstring> Make();

        /**
         * The DefaultToString constructor.
         */
        DefaultToString();

        /**
         * The DefaultToString destructor.
         */
        virtual ~DefaultToString();

        /**
         * Gets a string translation of an object.
         */
        virtual std::wstring ToString(const std::wstring& hr) const override;
    };

    /**
     * The HResultToString class implements the conversion logic for transforming an HResult to a string.
     */
    class HResultToString final : public IToString<long> {
    public:
        /**
         * Creates an instance Of ToString.
         */
        static IToStringSharedPtr<long> Make();

        /**
         * The HResultToString constructor.
         */
        HResultToString();

        /**
         * The HResultToString destructor.
         */
        virtual ~HResultToString();

        /**
         * Gets a string translation of an object.
         */
        virtual std::wstring ToString(const long& hr) const override;
    };

    /**
     * The ClassTypeToString class implements the conversion logic for transforming a class type to a string.
     */
    template <typename T>
    class ClassTypeToString final : public IToString<T> {
    public:
        /**
         * Creates an instance of a ToString interface.
         */
        static IToStringSharedPtr<T> Make();

        /**
         * The ClassTypeToString constructor.
         */
        ClassTypeToString();

        /**
         * The ClassTypeToString destructor.
         */
        virtual ~ClassTypeToString();

        /**
         * Gets a string translation of an object.
         */
        virtual std::wstring ToString(const T&) const override;

    private:
        T& m_value;
    };

    /**
     * The StdToString class implements the conversion logic for transforming a std type to a string.
     */
    template <typename T>
    class StdToString final : public IToString<T> {
    public:
        /**
         * Creates an instance of a ToString interface.
         */
        static IToStringSharedPtr<T> Make();

        /**
         * The StdToString constructor.
         */
        StdToString();

        /**
         * The StdToString destructor.
         */
        virtual ~StdToString();

        /**
         * Gets a string translation of an object.
         */
        virtual std::wstring ToString(const T& obj) const override;

    private:
        T m_value;
    };

    /**
     * Creates an instance of a ToString interface.
     */
    template <typename T>
    IToStringSharedPtr<T> StdToString<T>::Make()
    {
        return std::make_shared<StdToString<T>>();
    }

    /**
     * The StdToString constructor.
     */
    template <typename T>
    StdToString<T>::StdToString()
    {
    }

    /**
     * The StdToString destructor.
     */
    template <typename T>
    StdToString<T>::~StdToString()
    {
    }

    /**
     * Gets a string translation of an object.
     */
    template <typename T>
    std::wstring StdToString<T>::ToString(const T& obj) const
    {
        return std::to_wstring(obj);
    }

    /**
     * Creates an instance of a ToString interface.
     */
    template <typename T>
    IToStringSharedPtr<T> ClassTypeToString<T>::Make()
    {
        return std::make_shared<ClassTypeToString<T>>();
    }

    /**
     * The ClassTypeToString constructor.
     */
    template <typename T>
    ClassTypeToString<T>::ClassTypeToString()
    {
    }

    /**
     * The ClassTypeToString destructor.
     */
    template <typename T>
    ClassTypeToString<T>::~ClassTypeToString()
    {
    }

    /**
     * Gets a string translation of an object.
     */
    template <typename T>
    std::wstring ClassTypeToString<T>::ToString(const T&) const
    {
        std::string className(typeid(T).name());
        return StringUtils::StringToWideString(className);
    }

} // namespace base

#endif // TO_STRING_H_205b3b36_02d1_4af9_a4ed_b49cc81b1582
