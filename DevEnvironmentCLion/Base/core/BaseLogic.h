#ifndef BASE_LOGIC_H_88ccaf5d_7c42_4c54_be94_7fcea48749ef
#define BASE_LOGIC_H_88ccaf5d_7c42_4c54_be94_7fcea48749ef

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

#endif // BASE_LOGIC_H_88ccaf5d_7c42_4c54_be94_7fcea48749ef