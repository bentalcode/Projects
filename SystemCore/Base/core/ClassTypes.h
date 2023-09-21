#ifndef CLASS_TYPES_H_885ae9ea_c65b_43fa_9273_7226f8d77a8b
#define CLASS_TYPES_H_885ae9ea_c65b_43fa_9273_7226f8d77a8b

namespace base
{
    /**
     * The ClassTypes class implements complementary APIs for class types.
     */
    class ClassTypes final
    {
    public:
        /**
         * Checks whether whether the object is an instance of the specified type (class or subclass or interface).
         */
        template <typename Base, typename T>
        static bool InstanceOf(const T*);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        ClassTypes() = delete;
        ~ClassTypes() = delete;
    };

    /**
     * Checks whether whether the object is an instance of the specified type (class or subclass or interface).
     */
    template <typename Base, typename T>
    bool ClassTypes::InstanceOf(const T*) {
        return std::is_base_of<Base, T>::value;
    }

} // namespace base

#endif // CLASS_TYPES_H_885ae9ea_c65b_43fa_9273_7226f8d77a8b
