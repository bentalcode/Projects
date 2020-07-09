#ifndef BASE_LOGIC_H_07043b6f_700b_48ad_b437_66214b8fe97f
#define BASE_LOGIC_H_07043b6f_700b_48ad_b437_66214b8fe97f

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
        return !(left < right || left == right);
    }

    template <typename T>
    bool operator<=(const T& left, const T& right)
    {
        return left < right || left == right;
    }

    template <typename T>
    bool operator>=(const T& left, const T& right)
    {
        return left > right || left == right;
    }

    /**
     * Defines the dereference less for pointers.
     */
    class DereferenceLess
    {
        template <typename T>
        bool operator() (T left, T right)
        {
            return *left < *right;
        }
    };
}

#endif // BASE_LOGIC_H_07043b6f_700b_48ad_b437_66214b8fe97f
