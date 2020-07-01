package basicio.interfaces;

import java.util.List;

/**
 * The ILineUpdater interface defines a line updater.
 */
public interface ILineUpdater {
    /**
     * Updates a line.
     * Return true if the update succeeded.
     */
    boolean update(
        IUpdateRecord updateData,
        UpdatePolicyType policyType);

    /**
     * Updates lines.
     * Returns the number of updates.
     */
    int update(
        List<IUpdateRecord> updatesData,
        UpdatePolicyType policyType);
}
