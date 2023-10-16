#ifndef INTERVAL_MAP_UNIT_TEST_H_f6d191f5_60be_4e5e_841f_867f77c76cc4
#define INTERVAL_MAP_UNIT_TEST_H_f6d191f5_60be_4e5e_841f_867f77c76cc4

#include "UnitTestBase.h"
#include "IntervalMap.h"
#include "Interval.h"
#include <vector>

using namespace base;

namespace test {
    namespace base {

        /**
         * The IntervalMapUnitTest class implements a unit test for an interval map.
         */
        class IntervalMapUnitTest final : public unit_testing::UnitTestBase
        {
        public:
            /**
             * The constructor.
             */
            explicit IntervalMapUnitTest(const std::wstring& name);

            /**
             * The destructor.
             */
            virtual ~IntervalMapUnitTest();

            /**
             * The copy/move constructors.
             */
            IntervalMapUnitTest(const IntervalMapUnitTest&) = delete;
            IntervalMapUnitTest(IntervalMapUnitTest&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IntervalMapUnitTest& operator=(const IntervalMapUnitTest&) = delete;
            IntervalMapUnitTest& operator=(IntervalMapUnitTest&&) = delete;

            /**
             * Registers tests of the unit test.
             */
            virtual void RegisterTests(unit_testing::ITestRegistration& registration);

            /**
             * Tests the creation of an interval map.
             */
            void IntervalMapCreationTest();

            /**
             * Tests the iteration logic of an interval map.
             */
            void IntervalMapIterationTest();

        private:
            /**
             * Tests the creation logic of an interval map.
             */
            template <typename Key, typename Value>
            void TestIntervalMapCreation(
                const Value& initialValue,
                const std::vector<Pair<Interval<Key>, Value>>& data);

            /**
             * Tests the iteration logic of an interval map.
             */
            template <typename Key, typename Value>
            void TestIntervalMapIteration(
                const Value& initialValue,
                const std::vector<Pair<Interval<Key>, Value>>& data);

            /**
             * Creates data of an interval map.
             */
            Pair<std::wstring, std::vector<Pair<Interval<int>, std::wstring>>> CreateIntervalMapData();
        };

        /**
         * Tests the creation logic of an interval map.
         */
        template <typename Key, typename Value>
        void IntervalMapUnitTest::TestIntervalMapCreation(
            const Value& initialValue,
            const std::vector<Pair<Interval<Key>, Value>>& data) {

            IntervalMap<Key, Value> intervalMap(initialValue);

            for (Pair<Interval<Key>, Value> dataEntry : data) {
                Interval<Key> interval = dataEntry.GetFirst();
                Value value = dataEntry.GetSecond();

                intervalMap.Assign(interval.GetStart(), interval.GetEnd(), value);
            }

            for (Pair<Interval<Key>, Value> dataEntry : data) {
                Interval<Key> interval = dataEntry.GetFirst();
                Value expectedValue = dataEntry.GetSecond();

                for (int i = interval.GetStart(); i < interval.GetEnd(); ++i) {
                    Value value = intervalMap[i];

                    GetAssertion().AssertEquals(
                        value,
                        expectedValue,
                        L"Incorrect logic of creation an Interval Map.");
                }
            }
        }

        /**
         * Tests the iteration logic of an interval map.
         */
        template <typename Key, typename Value>
        void IntervalMapUnitTest::TestIntervalMapIteration(
            const Value& initialValue,
            const std::vector<Pair<Interval<Key>, Value>>& data) {

            IntervalMap<Key, Value> intervalMap(initialValue);

            for (Pair<Interval<Key>, Value> dataEntry : data) {
                Interval<Key> interval = dataEntry.GetFirst();
                Value value = dataEntry.GetSecond();

                intervalMap.Assign(interval.GetStart(), interval.GetEnd(), value);
            }

            IIteratorSharedPtr<Pair<Interval<Key>, Value>> iterator = intervalMap.GetIterator();

            size_t index = 0;
            while (iterator->HasNext()) {
                Pair<Interval<Key>, Value> expectedIntervalData = data[index];
                ++index;

                Pair<Interval<Key>, Value> currIntervalData = iterator->Next();

                GetAssertion().AssertEquals(
                    expectedIntervalData,
                    currIntervalData,
                    L"Incorrect logic of iteration of an Interval Map.");
            }
        }
    }
}

#endif // INTERVAL_MAP_UNIT_TEST_H_f6d191f5_60be_4e5e_841f_867f77c76cc4
