package base.interfaces;

import java.util.Date;

/**
 * The IToDate interface defines a to date.
 */
public interface IToDate<T> {
    /**
     * Converts the object to a date.
     */
    Date toDate(T obj);
}
