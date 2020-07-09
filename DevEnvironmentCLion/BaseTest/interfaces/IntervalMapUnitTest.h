#ifndef INTERVAL_MAP_UNIT_TEST_H_1223ccf8_bd98_4701_b966_717d2fe5d89a
#define INTERVAL_MAP_UNIT_TEST_H_1223ccf8_bd98_4701_b966_717d2fe5d89a

#include "UnitTestBase.h"
#include "IntervalMap.h"
#include "Interval.h"

namespace base_test {

    /**
     * The IntervalMapUnitTest class implements a unit test for an interval map.
     */
    class IntervalMapUnitTest final : public unit_testing::UnitTestBase
    {
    public:
        /**
         * The constructor.
         */
        explicit IntervalMapUnitTest(const std::string& name);

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
        virtual void registerTests(unit_testing::ITestRegistration& registration);

        /**
         * Tests the creation of an interval map.
         */
        void intervalMapCreationTest();

        /**
         * Tests the iteration logic of an interval map.
         */
        void intervalMapIterationTest();

    private:
        /**
         * Tests the creation logic of an interval map.
         */
        template<typename Key, typename Value>
        void testIntervalMapCreation(
            const Value& initialValue,
            const std::vector<base::Pair<base::Interval<Key>, Value>>& data);

        /**
         * Tests the iteration logic of an interval map.
         */
        template<typename Key, typename Value>
        void testIntervalMapIteration(
            const Value& initialValue,
            const std::vector<base::Pair<base::Interval<Key>, Value>>& data);

        /**
         * Creates data of an interval map.
         */
        base::Pair<std::string, std::vector<base::Pair<base::Interval<int>, std::string>>> createIntervalMapData();
    };

    /**
     * Tests the creation logic of an interval map.
     */
    template<typename Key, typename Value>
    void IntervalMapUnitTest::testIntervalMapCreation(
        const Value& initialValue,
        const std::vector<base::Pair<base::Interval<Key>, Value>>& data) {

        base::IntervalMap<Key, Value> intervalMap(initialValue);

        for (base::Pair<base::Interval<Key>, Value> dataEntry : data) {
            base::Interval<Key> interval = dataEntry.getFirst();
            Value value = dataEntry.getSecond();

            intervalMap.assign(interval.getStart(), interval.getEnd(), value);
        }

        for (base::Pair<base::Interval<Key>, Value> dataEntry : data) {
            base::Interval<Key> interval = dataEntry.getFirst();
            Value expectedValue = dataEntry.getSecond();

            for (int i = interval.getStart(); i < interval.getEnd(); ++i) {
                Value value = intervalMap[i];

                this->getAssertion().assertEquals(
                    value,
                    expectedValue,
                    "Incorrect logic of creation an Interval Map.");
            }
        }
    }

    /**
     * Tests the iteration logic of an interval map.
     */
    template<typename Key, typename Value>
    void IntervalMapUnitTest::testIntervalMapIteration(
        const Value& initialValue,
        const std::vector<base::Pair<base::Interval<Key>, Value>>& data) {

        base::IntervalMap<Key, Value> intervalMap(initialValue);

        for (base::Pair<base::Interval<Key>, Value> dataEntry : data) {
            base::Interval<Key> interval = dataEntry.getFirst();
            Value value = dataEntry.getSecond();

            intervalMap.assign(interval.getStart(), interval.getEnd(), value);
        }

        base::IIteratorPtr<base::Pair<base::Interval<Key>, Value>> iterator = intervalMap.getIterator();

        size_t index = 0;
        while (iterator->hasNext()) {
            base::Pair<base::Interval<Key>, Value> expectedIntervalData = data[index];
            ++index;

            base::Pair<base::Interval<Key>, Value> currIntervalData = iterator->next();

            this->getAssertion().assertEquals(
                expectedIntervalData,
                currIntervalData,
                "Incorrect logic of iteration of an Interval Map.");
        }
    }
}

#endif // INTERVAL_MAP_UNIT_TEST_H_1223ccf8_bd98_4701_b966_717d2fe5d89a