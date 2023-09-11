#ifndef UNIT_TESTING_CONSTS_H_a689161d_e27b_4a4d_aa81_49166762c5ea
#define UNIT_TESTING_CONSTS_H_a689161d_e27b_4a4d_aa81_49166762c5ea

namespace unit_testing
{
    /**
     * The UnitTestingConsts static class defines constants for the unit testing module.
     */
    class UnitTestingConsts final
    {
    public:
        static const std::string testStart;
        static const std::string testEnd;
        static const std::string testResultsStart;
        static const std::string testResultsEnd;

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        UnitTestingConsts() = delete;
        ~UnitTestingConsts() = delete;
    };

}

#endif // UNIT_TESTING_CONSTS_H_a689161d_e27b_4a4d_aa81_49166762c5ea
