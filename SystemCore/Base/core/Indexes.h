#ifndef INDEXES_H_3e52ab95_6bc4_4242_8937_122765bf07c7
#define INDEXES_H_3e52ab95_6bc4_4242_8937_122765bf07c7

#include "BaseException.h"

namespace base {

    /**
     * The Indexes class implements complementary APIs for indexes.
     */
    class Indexes final {
    public:
        Indexes() = delete;
        ~Indexes() = delete;

        /**
         * Validates an index.
         */
        template <typename T>
        static void ValidateIndex(T index, T startIndex, T endIndex);

        /**
         * Gets number ofindexes in a dimension.
         */
        template <typename T>
        static size_t Size(T startIndex, T endIndex);
    };

    /**
     * Validates an index.
     */
    template <typename T>
    void Indexes::ValidateIndex(T index, T startIndex, T endIndex)
    {
        if (index < startIndex || index > endIndex) {
            long errorCode = ErrorCodes::INVALID_ARG;

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"Index: " << std::to_wstring(index) << L" is out ofrange."
                << L" Specified range: [" << std::to_wstring(startIndex) << L"-" << std::to_wstring(endIndex) << L"]"
                << ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            throw BaseException(errorCode, errorMessage);
        }
    }

    /**
     * Gets number ofindexes in a dimension.
     */
    template <typename T>
    size_t Indexes::Size(T startIndex, T endIndex)
    {
        return startIndex <= endIndex ? endIndex - startIndex + 1 : 0;
    }

}  // namespace base

#endif // INDEXES_H_3e52ab95_6bc4_4242_8937_122765bf07c7
