#ifndef BASE_LOGIC_H_c4a868dc_da0b_4927_ab53_fc88886932f3
#define BASE_LOGIC_H_c4a868dc_da0b_4927_ab53_fc88886932f3

#include "BaseException.h"

namespace base {

    template <typename T>
    bool operator==(const T& left, const T& right)
    {
        return !(left < right) && !(right < left);
    }

    template <typename T>
    bool operator>(const T& left, const T& right)
    {
        return right < left;
    }

    template <typename T>
    bool operator<=(const T& left, const T& right)
    {
        return !(right < left);
    }

    template <typename T>
    bool operator>=(const T& left, const T& right)
    {
        return !(left < right);
    }

    /**
    * Defines the dereference less for pointers.
    */
    template<typename T>
    struct DereferenceLess final
    {
        bool operator()(T leftPtr, T rightPtr)
        const
        {
            return *leftPtr < *rightPtr;
        }
    };

}

#endif // BASE_LOGIC_H_c4a868dc_da0b_4927_ab53_fc88886932f3
