package base.interfaces;

import java.util.Date;

/**
 * The IToDate interface defines date conversion.
 */
public interface IToDate<T> {
    /**
     * Converts the object to a date.
     */
    Date toDate(T obj);
}
