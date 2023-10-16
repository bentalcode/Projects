package problems.core;

import base.core.Conditions;
import base.core.Pair;
import base.interfaces.IPair;
import java.util.Arrays;

/**
 * The ClosestBirthday class implements the closest birthday problem.
 */
public final class ClosestBirthday extends AbstractClosestBirthday {
    private final int year;

    /**
     * The ClosestBirthday constructor.
     */
    public ClosestBirthday(int year) {
        validateYear(year);

        this.year = year;
    }

    /**
     * Calculates the number of days between the closest birthdays.
     * The dates of the birthdays are given with an integer format: MMDD.
     */
    @Override
    public int closestBirthdaysInDays(int[] birthdays) {
        Conditions.validateNotNull(
            birthdays,
            "The birthdays array is not defined.");

        Conditions.validate(
            birthdays.length >= 2,
            "The birthdays array has to contain at least two dates.");

        int[] days = createSortedDays(this.year, birthdays);
        return this.closestDays(days);
    }

    /**
     * Creates a sorted days.
     */
    private static int[] createSortedDays(int year, int[] dates) {
        int length = dates.length;
        int[] days = new int[length];

        for (int index = 0; index < length; ++index) {
            int date = dates[index];
            days[index] = daysInDate(year, date);
        }

        Arrays.sort(days);

        return days;
    }

    /**
     * Gets the number of days in a date.
     */
    private static int daysInDate(int year, int date) {
        IPair<Integer, Integer> monthAndDay = parseDate(date);
        int currMonth = monthAndDay.first();
        int currDay = monthAndDay.second();

        int numberOfDays = 0;
        for (int month = 1; month < currMonth; ++month) {
            numberOfDays += getDaysInMonth(year, month);
        }

        numberOfDays += currDay;

        return numberOfDays;
    }

    /**
     * Parses the date.
     */
    private static IPair<Integer, Integer> parseDate(int date) {
        Conditions.validate(
            date >= 101 && date <= 1231,
            "The date: " + date + " + is out of range.");

        int month = 0;
        int day = 0;

        int currValue = date;

        int index = 0;
        while (currValue != 0 && index < 4) {
            int digit = currValue % 10;

            if (index == 0) {
                day += digit;
            }
            else if (index == 1) {
                day += 10 * digit;
            }
            else if (index == 2) {
                month += digit;
            }
            else if (index == 3) {
                month += 10 * digit;
            }

            currValue /= 10;
            ++index;
        }

        validateMonth(month);
        validateDay(day);

        return Pair.make(month, day);
    }
}
