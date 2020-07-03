package basicio.interfaces;

import java.util.List;

/**
 * The ILineUpdater interface defines a line updater.
 */
public interface ILineUpdater {
    /**
     * Updates a line that matches an update record.
     * The search direction is from top to bottom.
     */
    boolean update(IUpdateRecord updateData);

    /**
     * Updates a line that matches an update record.
     * The search direction is from bottom to top.
     */
    boolean updateFromEnd(IUpdateRecord updateData);

    /**
     * Updates lines that matches update records.
     * The search direction is from top to bottom.
     */
    int update(
        List<IUpdateRecord> updatesData,
        UpdatePolicyType policyType);

    /**
     * Updates lines that matches update records.
     * The search direction is from bottom to top.
     */
    int updateFromEnd(
        List<IUpdateRecord> updateRecords,
        UpdatePolicyType policyType);
}
