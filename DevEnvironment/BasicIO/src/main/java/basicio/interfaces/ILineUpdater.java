package basicio.interfaces;

import java.util.List;

/**
 * The ILineUpdater interface defines a line updater.
 */
public interface ILineUpdater {
    /**
     * Updates lines that matches an update record.
     * The search direction is from top to bottom.
     * Returns the number of lines which got updated.
     */
    int update(IUpdateRecord updateData);

    /**
     * Updates a line that matches an update record.
     * The search direction is from bottom to top.
     * Returns the number of lines which got updated.
     */
    int updateFromEnd(IUpdateRecord updateData);

    /**
     * Updates lines that matches update records.
     * The search direction is from top to bottom.
     * Returns the number of lines which got updated.
     */
    int update(List<IUpdateRecord> updatesData);

    /**
     * Updates lines that matches update records.
     * The search direction is from bottom to top.
     * Returns the number of lines which got updated.
     */
    int updateFromEnd(List<IUpdateRecord> updateRecords);
}
