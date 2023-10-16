#ifndef RANDOM_GENERATOR_UNIT_TEST_H_6ce11193_d3ab_4898_a4d9_6843c47a68ae
#define RANDOM_GENERATOR_UNIT_TEST_H_6ce11193_d3ab_4898_a4d9_6843c47a68ae

#include "UnitTestBase.h"

namespace test {
    namespace base {

        /**
         * The RandomGeneratorUnitTest class implements a unit test for a random generator.
         */
        class RandomGeneratorUnitTest final : public unit_testing::UnitTestBase
        {
        public:
            /**
             * The constructor.
             */
            explicit RandomGeneratorUnitTest(const std::wstring& name);

            /**
             * The destructor.
             */
            virtual ~RandomGeneratorUnitTest();

            /**
             * The copy/move constructors.
             */
            RandomGeneratorUnitTest(const RandomGeneratorUnitTest&) = delete;
            RandomGeneratorUnitTest(RandomGeneratorUnitTest&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            RandomGeneratorUnitTest& operator=(const RandomGeneratorUnitTest&) = delete;
            RandomGeneratorUnitTest& operator=(RandomGeneratorUnitTest&&) = delete;

            /**
             * Registers tests of the unit test.
             */
            virtual void RegisterTests(unit_testing::ITestRegistration& registration);

            /**
             * Tests the logic of generating a random boolean.
             */
            void RandomBooleanTest();

            /**
             * Tests the logic of generating a random integer.
             */
            void RandomIntegerTest();

            /**
             * Tests the logic of generating a random size_t.
             */
            void RandomSizeTTest();

            /**
             * Tests the logic of generating a random float.
             */
            void RandomFloatTest();

            /**
             * Tests the logic of generating a random double.
             */
            void RandomDoubleTest();

        private:
            /**
             * Tests the logic of generating a random boolean.
             */
            void TestRandomBoolean();

            /**
             * Tests the logic of generating a random integer.
             */
            void TestRandomInteger(int from, int to);

            /**
             * Tests the logic of generating a random size_t.
             */
            void TestRandomSizeT(size_t from, size_t to);

            /**
             * Tests the logic of generating a random float.
             */
            void TestRandomFloat(float from, float to);

            /**
             * Tests the logic of generating a random double.
             */
            void TestRandomDouble(double from, double to);
        };
    }
}

#endif // RANDOM_GENERATOR_UNIT_TEST_H_6ce11193_d3ab_4898_a4d9_6843c47a68ae
