#ifndef UNIT_TESTING_CONSTS_H_a689161d_e27b_4a4d_aa81_49166762c5ea
#define UNIT_TESTING_CONSTS_H_a689161d_e27b_4a4d_aa81_49166762c5ea

#include <string>

namespace unit_testing
{
    /**
     * The UnitTestingConsts static class defines constants for the unit testing module.
     */
    class UnitTestingConsts final
    {
    public:
        static const std::wstring TEST_START;
        static const std::wstring TEST_END;
        static const std::wstring TEST_RESULTS_START;
        static const std::wstring TEST_RESULTS_END;

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        UnitTestingConsts() = delete;
        ~UnitTestingConsts() = delete;
    };

}

#endif // UNIT_TESTING_CONSTS_H_a689161d_e27b_4a4d_aa81_49166762c5ea
