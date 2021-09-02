package problems.core;

import base.core.Conditions;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * The ClosestBirthdayII class implements a closest birthday problem.
 */
public final class ClosestBirthdayII extends AbstractClosestBirthday {
    private final Map<Integer, Integer> dateToDaysMap;

    /**
     * The ClosestBirthdayII constructor.
     */
    public ClosestBirthdayII(int year) {
        validateYear(year);
        this.dateToDaysMap = createDateToDaysMapForYear(year);
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

        int[] days = this.createSortedDays(birthdays);
        return this.closestDays(days);
    }

    /**
     * Creates a sorted days array.
     */
    private int[] createSortedDays(int[] dates) {
        int length = dates.length;
        int[] days = new int[length];

        for (int index = 0; index < length; ++index) {
            int date = dates[index];

            if (!this.dateToDaysMap.containsKey(date)) {
                throw new IllegalArgumentException(
                    "The input date: " + date + " is not cached.");
            }

            days[index] = this.dateToDaysMap.get(date);
        }

        Arrays.sort(days);

        return days;
    }

    /**
     * Creates a mapping of of days to dates for a year.
     */
    private static Map<Integer, Integer> createDateToDaysMapForYear(int year) {
        Map<Integer, Integer> dateToDaysMap = new HashMap<>();

        int counter = 0;

        for (int month = 1; month <= 12; ++month) {
            int numberOfDaysInMonth = getDaysInMonth(year, month);

            for (int day = 1; day <= numberOfDaysInMonth; ++day) {
                ++counter;

                int date = createDate(month, day);
                dateToDaysMap.put(date, counter);
            }
        }

        return dateToDaysMap;
    }
}
