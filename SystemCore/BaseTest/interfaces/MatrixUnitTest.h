#ifndef MATRIX_UNIT_TEST_H_64584a48_a421_4b30_b402_9086a6190fd1
#define MATRIX_UNIT_TEST_H_64584a48_a421_4b30_b402_9086a6190fd1

#include "UnitTestBase.h"
#include "Matrix.h"
#include "TestData.h"

namespace test {
    namespace base {

        /**
         * The MatrixUnitTest class implements a unit test for a matrix.
         */
        class MatrixUnitTest final : public unit_testing::UnitTestBase
        {
        public:
            /**
             * The constructor.
             */
            explicit MatrixUnitTest(const std::wstring& name);

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
            virtual void RegisterTests(unit_testing::ITestRegistration& registration);

            /**
             * Tests the creation logic of a matrix.
             */
            void MatrixCreationTest();

            /**
             * Tests the iteration logic of a matrix.
             */
            void MatrixIterationTest();

        private:
            /**
             * Tests the creation logic of a matrix.
             */
            void TestMatrixCreation(const std::vector<std::vector<int>>& data);

            /**
             * Tests the iteration logic of a matrix.
             */
            void TestMatrixIteration(const std::vector<std::vector<int>>& data);

            TestData m_testData;
        };
    }
}

#endif // MATRIX_UNIT_TEST_H_64584a48_a421_4b30_b402_9086a6190fd1
