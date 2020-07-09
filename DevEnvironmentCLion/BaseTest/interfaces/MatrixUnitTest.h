#ifndef MATRIX_UNIT_TEST_H_186b27af_b022_46d8_b9fc_23d8b081f426
#define MATRIX_UNIT_TEST_H_186b27af_b022_46d8_b9fc_23d8b081f426

#include "UnitTestBase.h"
#include "Matrix.h"
#include "TestData.h"

namespace base_test {

    /**
     * The MatrixUnitTest class implements a unit test for a matrix.
     */
    class MatrixUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The constructor.
         */
        explicit MatrixUnitTest(const std::string& name);

        /**
         * The destructor.
         */
        virtual ~MatrixUnitTest();

        /**
         * The copy/move constructors.
         */
        MatrixUnitTest(const MatrixUnitTest&) = delete;
        MatrixUnitTest(MatrixUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MatrixUnitTest& operator=(const MatrixUnitTest&) = delete;
        MatrixUnitTest& operator=(MatrixUnitTest&&) = delete;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the creation logic of a matrix.
         */
        void matrixCreationTest();

        /**
         * Tests the iteration logic of a matrix.
         */
        void matrixIterationTest();

    private:
        /**
         * Tests the creation logic of a matrix.
         */
        void testMatrixCreation(const std::vector<std::vector<int>>& data);

        /**
         * Tests the iteration logic of a matrix.
         */
        void testMatrixIteration(const std::vector<std::vector<int>>& data);

        TestData m_testData;
    };
}

#endif // MATRIX_UNIT_TEST_H_186b27af_b022_46d8_b9fc_23d8b081f426
