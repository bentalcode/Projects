#ifndef RANDOM_GENERATOR_UNIT_TEST_H_6ce11193_d3ab_4898_a4d9_6843c47a68ae
#define RANDOM_GENERATOR_UNIT_TEST_H_6ce11193_d3ab_4898_a4d9_6843c47a68ae

#include "PreCompiled.h"
#include "UnitTestBase.h"

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
        explicit RandomGeneratorUnitTest(const std::string& name);

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
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the logic of generating a random boolean.
         */
        void randomBooleanTest();

        /**
         * Tests the logic of generating a random integer.
         */
        void randomIntegerTest();

        /**
         * Tests the logic of generating a random size_t.
         */
        void randomSizeTTest();

        /**
         * Tests the logic of generating a random float.
         */
        void randomFloatTest();

    private:
        /**
         * Tests the logic of generating a random boolean.
         */
        void testRandomBoolean();

        /**
         * Tests the logic of generating a random integer.
         */
        void testRandomInteger(int from, int to);

        /**
         * Tests the logic of generating a random size_t.
         */
        void testRandomSizeT(size_t from, size_t to);

        /**
         * Tests the logic of generating a random float.
         */
        void testRandomFloat(float from, float to);
    };
}

#endif // RANDOM_GENERATOR_UNIT_TEST_H_6ce11193_d3ab_4898_a4d9_6843c47a68ae
