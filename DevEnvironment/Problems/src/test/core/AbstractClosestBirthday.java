package problems.core;

import base.core.Conditions;
import problems.interfaces.IClosestBirthday;

/**
 * The AbstractClosestBirthday class implements an abstract base class
 * of the closest birthday problem.
 */
public abstract class AbstractClosestBirthday implements IClosestBirthday {
    /**
     * The AbstractClosestBirthday constructor.
     */
    protected AbstractClosestBirthday() {
    }

    /**
     * Calculates the closest number of days.
     * The input days array is sorted.
     */
    protected int closestDays(int[] days) {
        int minDiff = Integer.MAX_VALUE;

        if (days.length == 0) {
            return minDiff;
        }

        int prevDays = days[0];

        for (int index = 1; index < days.length; ++index) {
            int currDays = days[index];
            int currDiff = currDays - prevDays;

            if (currDiff == 0) {
                return 0;
            }

            if (currDiff < minDiff) {
                minDiff = currDiff;
            }

            prevDays = currDays;
        }

        return minDiff;
    }

    /**
     * Creates a date.
     */
    public static int createDate(int month, int day) {
        assert(month >= 1 && month <= 12);
        assert(day >= 1 && day <= 31);

        int date = day;
        date += month * 100;
        return date;
    }

    /**
     * Gets the number of days in a month.
     */
    protected static int getDaysInMonth(int year, int month) {
        assert(year >= 0);
        assert(month >= 1 && month <= 12);

        if (month == 1 ||
            month == 3 ||
            month == 5 ||
            month == 7 ||
            month == 8 ||
            month == 10 ||
            month == 12) {

            return 31;
        }
        else if (
            month == 4 ||
            month == 6 ||
            month == 9 ||
            month == 11) {

            return 30;
        }
        else {
            return isLeapYear(year) ? 29 : 28;
        }
    }

    /**
     * Returns if the year is a leap year.
     */
    protected static boolean isLeapYear(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    /**
     * Validates a year.
     */
    protected static void validateYear(int year) {
        Conditions.validate(
            year >= 0,
            "The year range is: [0-]");
    }

    /**
     * Validates a month.
     */
    protected static void validateMonth(int month) {
        Conditions.validate(
            month >= 1 && month <= 12,
            "The month range is: [1-12]");
    }

    /**
     * Validates a day.
     */
    protected static void validateDay(int date) {
        Conditions.validate(
            date >= 1 && date <= 31,
            "The date range is: [1-31]");
    }
}
