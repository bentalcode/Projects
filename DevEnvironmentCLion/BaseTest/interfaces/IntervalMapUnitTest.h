#ifndef INTERVAL_MAP_UNIT_TEST_H_639b3965_3158_47c6_af78_a44c920b0a76
#define INTERVAL_MAP_UNIT_TEST_H_639b3965_3158_47c6_af78_a44c920b0a76

#include "UnitTestBase.h"
#include "IntervalMap.h"
#include "Pair.h"

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
        template<typename K, typename V>
        void testIntervalMapCreation(
            const V& initialValue,
            const std::vector<base::Pair<base::Pair<K, K>, V>>& data);

        /**
         * Tests the iteration logic of an interval map.
         */
        template<typename K, typename V>
        void testIntervalMapIteration(const std::vector<base::Pair<K, V>>& data);
    };

    /**
     * Tests the creation logic of an interval map.
     */
    template<typename K, typename V>
    void IntervalMapUnitTest::testIntervalMapCreation(
        const V& initialValue,
        const std::vector<base::Pair<base::Pair<K, K>, V>>& data) {

        base::IntervalMap<K, V> intervalMap(initialValue);

        for (base::Pair<base::Pair<K, K>, V> dataEntry : data) {
            base::Pair<K, K> interval = dataEntry.getFirst();
            V value = dataEntry.getSecond();

            intervalMap.assign(interval.getFirst(), interval.getSecond(), value);
        }

        for (base::Pair<base::Pair<K, K>, V> dataEntry : data) {
            base::Pair<K, K> interval = dataEntry.getFirst();
            K start = interval.getFirst();
            K end = interval.getSecond();
            V expectedValue = dataEntry.getSecond();

            for (int i = start; i < end; ++i) {
                V value = intervalMap[i];

                this->getAssertion().assertEquals(
                    value,
                    expectedValue,
                    "Incorrect logic of the Interval Map.");
            }
        }
    }

    /**
     * Tests the iteration logic of an interval map.
     */
    template<typename K, typename V>
    void IntervalMapUnitTest::testIntervalMapIteration(const std::vector<base::Pair<K, V>>& data) {
    }
}

#endif /* INTERVAL_MAP_UNIT_TEST_H_639b3965_3158_47c6_af78_a44c920b0a76 */
