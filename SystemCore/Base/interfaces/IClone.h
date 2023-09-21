#ifndef I_CLONE_H_c0180a9c_57cf_11ee_8c99_0242ac120002
#define I_CLONE_H_c0180a9c_57cf_11ee_8c99_0242ac120002

#include <memory>

namespace base {

    /**
     * The IClone interface clones an object.
     */
    template <typename T, typename ResultT = T>
    class IClone {
    public:
        /**
         * The List constructor.
         */
        IClone() = default;

        /**
         * The List destructor.
         */
        virtual ~IClone() = default;

        /**
         * Clones an object.
         */
        virtual ResultT Clone(const T& obj);
    };

    /**
     * Defines the Shared Ptr of Clone.
     */
    template<typename T, typename ResultT = T>
    using ICloneSharedPtr = std::shared_ptr<IClone<T, ResultT>>;

} // namespace base

#endif // I_CLONE_H_c0180a9c_57cf_11ee_8c99_0242ac120002
