package problems.interfaces;

/**
 * The IClosestBirthday interface defines the closest birthday problem.
 */
public interface IClosestBirthday {
    /**
     * Calculates the number of days between the closest birthdays.
     * The dates of the birthdays are given with an integer format: MMDD.
     */
    int closestBirthdaysInDays(int[] birthdays);
}
