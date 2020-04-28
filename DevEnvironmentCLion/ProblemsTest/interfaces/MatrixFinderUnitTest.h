#ifndef MATRIX_FINDER_UNIT_TEST_H_5009ad59_237a_45b8_9d81_fcc9d84e6f5d
#define MATRIX_FINDER_UNIT_TEST_H_5009ad59_237a_45b8_9d81_fcc9d84e6f5d

#include "UnitTestBase.h"
#include "MatrixFinder.h"
#include "Matrix.h"
#include "Assertion.h"

namespace problems_test {

    /**
     * The MatrixFinderUnitTest class implements a unit test for a matrix finder problem.
     */
    class MatrixFinderUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The MatrixFinderUnitTest constructor.
         */
        explicit MatrixFinderUnitTest(const std::string& name);

        /**
         * The MatrixFinderUnitTest destructor.
         */
        virtual ~MatrixFinderUnitTest();

        /**
         * The copy/move constructors.
         */
        MatrixFinderUnitTest(const MatrixFinderUnitTest&) = delete;
        MatrixFinderUnitTest(MatrixFinderUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MatrixFinderUnitTest& operator=(const MatrixFinderUnitTest&) = delete;
        MatrixFinderUnitTest& operator=(MatrixFinderUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of a matrix finder.
         */
        void matrixFinderTest();

    private:
        /**
         * Tests the logic of a matrix finder.
         */
        template <typename T>
        void testMatrixFinder(
            const base::Matrix<T>& matrix,
            const T& item,
            bool expectedResult);
    };

    template <typename T>
    void MatrixFinderUnitTest::testMatrixFinder(
        const base::Matrix<T>& matrix,
        const T& item,
        bool expectedResult)
    {
        problems::MatrixFinder<T> matrixFinder;
        bool result = matrixFinder.hasItem(matrix.getData(), item);

        getAssertion().assertEquals(
           result,
           expectedResult,
           "Invalid logic of a matrix finder.");
    }
}

#endif /* MATRIX_FINDER_UNIT_TEST_H_5009ad59_237a_45b8_9d81_fcc9d84e6f5d */
