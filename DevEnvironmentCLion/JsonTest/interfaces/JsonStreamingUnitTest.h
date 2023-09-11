#ifndef JSON_STREAMING_UNIT_TEST_H_68edef42_d46f_4099_8782_0ce562fd8f90
#define JSON_STREAMING_UNIT_TEST_H_68edef42_d46f_4099_8782_0ce562fd8f90

#include "PreCompiled.h"
#include "UnitTestBase.h"
#include "TestData.h"
#include "JsonException.h"

using namespace json;

namespace test {
    namespace json {

        /**
         * The JsonStreamingTest class implements tests for reading writing from/to json streams.
         */
        class JsonStreamingUnitTest final : public unit_testing::UnitTestBase
        {
        public:
            /**
             * The JsonStreamingUnitTest constructor.
             */
            explicit JsonStreamingUnitTest(const std::string& name);

            /**
             * The JsonStreamingUnitTest destructor.
             */
            virtual ~JsonStreamingUnitTest();

            /**
             * Registers tests of the unit test.
             */
            virtual void registerTests(unit_testing::ITestRegistration& registration);

            /**
             * Tests the logic of streaming json.
             */
            void jsonStreamingTest();

        private:
            TestData m_testData;
        };

    }
}

#endif // JSON_STREAMING_UNIT_TEST_H_68edef42_d46f_4099_8782_0ce562fd8f90
