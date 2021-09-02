package problems.core;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import problems.interfaces.IClosestBirthday;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The ClosestBirthdayTest class implements tests for the closest birthday problem.
 */
public final class ClosestBirthdayTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The ClosestBirthdayTest constructor.
     */
    public ClosestBirthdayTest() {
    }

    /**
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the logic of finding the closest birthdays.
     */
    @Test
    public void findClosestBirthdaysTest() {
        int year = 2021;

        int[] birthdays1 = {101, 201};
        int result1 = 31;

        int[] birthdays2 = {201, 301};
        int result2 = 28;

        int[] birthdays3 = {301, 401};
        int result3 = 31;

        int[] birthdays4 = {401, 501};
        int result4 = 30;

        int[] birthdays5 = {501, 601};
        int result5 = 31;

        int[] birthdays6 = {601, 701};
        int result6 = 30;

        int[] birthdays7 = {701, 801};
        int result7 = 31;

        int[] birthdays8 = {801, 901};
        int result8 = 31;

        int[] birthdays9 = {901, 1001};
        int result9 = 30;

        int[] birthdays10 = {1001, 1101};
        int result10 = 31;

        int[] birthdays11 = {1101, 1201};
        int result11 = 30;

        int[] birthdays12 = {101, 1201};
        int result12 = 334;

        int[] birthdays13 = {1201, 1231};
        int result13 = 30;

        int[] birthdays14 = {101, 101};
        int result14 = 0;

        int[] birthdays15 = {101, 131, 115, 110};
        int result15 = 5;

        this.testFindingClosestBirthdays(year, birthdays1, result1);
        this.testFindingClosestBirthdays(year, birthdays2, result2);
        this.testFindingClosestBirthdays(year, birthdays3, result3);
        this.testFindingClosestBirthdays(year, birthdays4, result4);
        this.testFindingClosestBirthdays(year, birthdays5, result5);
        this.testFindingClosestBirthdays(year, birthdays6, result6);
        this.testFindingClosestBirthdays(year, birthdays7, result7);
        this.testFindingClosestBirthdays(year, birthdays8, result8);
        this.testFindingClosestBirthdays(year, birthdays9, result9);
        this.testFindingClosestBirthdays(year, birthdays10, result10);
        this.testFindingClosestBirthdays(year, birthdays11, result11);
        this.testFindingClosestBirthdays(year, birthdays12, result12);
        this.testFindingClosestBirthdays(year, birthdays13, result13);
        this.testFindingClosestBirthdays(year, birthdays14, result14);
        this.testFindingClosestBirthdays(year, birthdays15, result15);
    }

    /**
     * Tests the logic of finding the closest birthdays II.
     */
    @Test
    public void findClosestBirthdaysTestII() {
        int year = 2021;
        this.testFindingClosestBirthdaysII(year);
    }

    /**
     * Tests the logic of finding the closest birthdays.
     */
    private void testFindingClosestBirthdays(
        int year,
        int[] birthdays,
        int expectedResult) {

        IClosestBirthday closestBirthday = new ClosestBirthday(year);
        int result = closestBirthday.closestBirthdaysInDays(birthdays);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for finding the closest birthday.");
    }

    /**
     * Tests the logic of finding the closest birthdays II.
     */
    private void testFindingClosestBirthdaysII(int year) {
        int[] dates = createDatesOfYear(year);

        for (int fromDateIndex = 0; fromDateIndex < dates.length - 1; ++fromDateIndex) {
            for (int toDateIndex = fromDateIndex + 1; toDateIndex < dates.length - 1; ++toDateIndex) {

                int fromDate = dates[fromDateIndex];
                int toDate = dates[toDateIndex];

                int[] birthdays = new int[2];
                birthdays[0] = fromDate;
                birthdays[1] = toDate;

                IClosestBirthday closestBirthday = new ClosestBirthdayII(year);
                int result = closestBirthday.closestBirthdaysInDays(birthdays);

                int expectedResult = toDateIndex - fromDateIndex;

                this.assertion.assertEquals(
                    result,
                    expectedResult,
                    "Incorrect logic for finding the closest birthday II.");
            }
        }
    }

    /**
     * Creates dates of the year.
     */
    private static int[] createDatesOfYear(int year) {
        int numberOfDays = 0;

        for (int month = 1; month <= 12; ++month) {
            numberOfDays += ClosestBirthday.getDaysInMonth(year, month);
        }

        int[] dates = new int[numberOfDays];
        int insertIndex = 0;

        for (int month = 1; month <= 12; ++month) {
            int numberOfDaysInMonth = ClosestBirthday.getDaysInMonth(year, month);

            for (int day = 1; day <= numberOfDaysInMonth; ++day) {
                int date = AbstractClosestBirthday.createDate(month, day);

                dates[insertIndex] = date;
                ++insertIndex;
            }
        }

        return dates;
    }
}
