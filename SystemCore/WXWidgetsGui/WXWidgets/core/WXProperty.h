#ifndef WX_PROPERTY_2d5c6b10_be8c_4ccb_9d53_9d8d34cb9296
#define WX_PROPERTY_2d5c6b10_be8c_4ccb_9d53_9d8d34cb9296

#include <vector>
#include <memory>

namespace wxwidgets {

    /**
     * The WXProperty class implements utilities for properties of WXWidgets.
     */
    class WXProperty final {
    public:
        WXProperty() = delete;
        ~WXProperty() = delete;

        /**
         * Updates value of a property.
         * Returns true in case value has been updated.
         */
        template <typename T>
        static bool UpdateValue(T& value, const T& newValue);

        /**
         * Updates shared ptr of a value of a property.
         * Returns true in case value has been updated.
         */
        template <typename T>
        static bool UpdateSharedValuePtr(std::shared_ptr<T>& value, const T& newValue);

        /**
         * Updates an array of values of a property.
         * Returns true in case value has been updated.
         */
        template <typename T>
        static bool UpdateArrayValue(std::vector<T>& value, const std::vector<T>& newValue);

        /**
         * Updates an array of array values of a property.
         * Returns true in case value has been updated.
         */
        template <typename T>
        static bool UpdateArrayArrayValue(std::vector<std::vector<T>>& value, const std::vector<std::vector<T>>& newValue);

    private:
        /**
         * Checks whether left and right values are equal.
         */
        template <typename T>
        static bool IsEqual(const std::vector<T>& lhs, const std::vector<T>& rhs);

        /**
         * Checks whether left and right values are equal.
         */
        template <typename T>
        static bool IsEqual(const std::vector<std::vector<T>>& lhs, const std::vector<std::vector<T>> & rhs);
    };

    /**
     * Updates value of a property.
     * Returns true in case a value has been updated.
     */
    template <typename T>
    bool WXProperty::UpdateValue(T& value, const T& newValue)
    {
        if (value == newValue) {
            return false;
        }

        value = newValue;

        return true;
    }

    /**
     * Updates shared ptr value of a property.
     * Returns true in case a value has been updated.
     */
    template <typename T>
    bool WXProperty::UpdateSharedValuePtr(std::shared_ptr<T>& value, const T& newValue)
    {
        if (value && *value == newValue) {
            return false;
        }

        value.reset(new T(newValue));

        return true;
    }

    /**
     * Updates an array of values of a property.
     * Returns true in case a value has been updated.
     */
    template <typename T>
    bool WXProperty::UpdateArrayValue(std::vector<T>& value, const std::vector<T>& newValue)
    {
        if (IsEqual(value, newValue)) {
            return false;
        }

        value.clear();
        value.insert(value.end(), newValue.begin(), newValue.end());

        return true;
    }

    /**
     * Updates an array of array of values of a property.
     * Returns true in case a value has been updated.
     */
    template <typename T>
    bool WXProperty::UpdateArrayArrayValue(std::vector<std::vector<T>>& value, const std::vector<std::vector<T>>& newValue)
    {
        if (IsEqual(value, newValue)) {
            return false;
        }

        value.clear();
        value.insert(value.end(), newValue.begin(), newValue.end());

        return true;
    }

    /**
     * Updates value of a property.
     * Returns true in case a value has been updated.
     */
    template <typename T>
    bool WXProperty::IsEqual(const std::vector<T>& lhs, const std::vector<T>& rhs)
    {
        if (lhs.size() != rhs.size()) {
            return false;
        }

        typename std::vector<T>::const_iterator lhsIterator = lhs.begin();
        typename std::vector<T>::const_iterator rhsIterator = rhs.begin();

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end()) {
            if (*lhsIterator  == *rhsIterator) {
                return false;
            }

            ++lhsIterator;
            ++rhsIterator;
        }

        return lhsIterator == lhs.end() && rhsIterator == rhs.end();
    }

    /**
     * Updates value of a property.
     * Returns true in case a value has been updated.
     */
    template <typename T>
    bool WXProperty::IsEqual(const std::vector<std::vector<T>>& lhs, const std::vector<std::vector<T>>& rhs)
    {
        if (lhs.size() != rhs.size()) {
            return false;
        }

        typename std::vector<std::vector<T>>::const_iterator lhsIterator = lhs.begin();
        typename std::vector<std::vector<T>>::const_iterator rhsIterator = rhs.begin();

        while (lhsIterator != lhs.end() && rhsIterator != rhs.end()) {
            if (!IsEqual(*lhsIterator, *rhsIterator)) {
                return false;
            }

            ++lhsIterator;
            ++rhsIterator;
        }

        return lhsIterator == lhs.end() && rhsIterator == rhs.end();
    }

} // namespace wxwidgets

#endif // WX_PROPERTY_2d5c6b10_be8c_4ccb_9d53_9d8d34cb9296
