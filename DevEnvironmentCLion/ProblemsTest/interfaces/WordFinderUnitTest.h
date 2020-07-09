#ifndef WORD_FINDER_UNIT_TEST_H_14a35f72_4e56_46b0_bed8_19e5df53e6d9
#define WORD_FINDER_UNIT_TEST_H_14a35f72_4e56_46b0_bed8_19e5df53e6d9

#include "UnitTestBase.h"
#include "Matrix.h"
#include "Position.h"

namespace problems_test {

    /**
     * The WordFinderUnitTest class implements a unit test for a word finder problem.
     */
    class WordFinderUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The WordFinderUnitTest constructor.
         */
        explicit WordFinderUnitTest(const std::string& name);

        /**
         * The WordFinderUnitTest destructor.
         */
        virtual ~WordFinderUnitTest();

        /**
         * The copy/move constructors.
         */
        WordFinderUnitTest(const WordFinderUnitTest&) = delete;
        WordFinderUnitTest(WordFinderUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        WordFinderUnitTest& operator=(const WordFinderUnitTest&) = delete;
        WordFinderUnitTest& operator=(WordFinderUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of a word finder.
         */
        void wordFinderTest();

    private:
        /**
         * Tests the logic of a word finder.
         */
        void testWordFinder(
            const base::Matrix<char>& matrix,
            const std::string& word,
            std::vector<std::vector<base::Position>> expectedPaths);
    };

}

#endif // WORD_FINDER_UNIT_TEST_H_14a35f72_4e56_46b0_bed8_19e5df53e6d9
