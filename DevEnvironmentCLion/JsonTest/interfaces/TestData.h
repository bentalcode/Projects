#ifndef TEST_DATA_H_85ac285c_8309_4730_922b_52c8f67d434f
#define TEST_DATA_H_85ac285c_8309_4730_922b_52c8f67d434f

#include "ClassType.h"

namespace test {
    namespace json {

        /**
         * The TestData class implements data of tests.
         */
        class TestData final
        {
        public:
            /**
             * The TestData constructor.
             */
            TestData();

            /**
             * The TestData destructor.
             */
            ~TestData();

            /**
             * Gets information of json resources.
             */
            void getJsonResourcesInformation(std::vector<std::pair<std::string, base::ClassType>>& result);

        private:
            static const std::string dataDirectoryName;
            static const std::string jsonDirectoryName;
            static std::vector<std::pair<std::string, base::ClassType>> jsonResourcesInformation;
        };

    }
}

#endif // TEST_DATA_H_85ac285c_8309_4730_922b_52c8f67d434f
