package hashcodecommand.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import basicio.core.FileLineUpdater;
import basicio.core.UpdateRecordProvider;
import basicio.interfaces.IContentProvider;
import basicio.interfaces.IUpdateRecord;
import basicio.interfaces.MatchPolicyType;
import hashcodecommand.interfaces.IHashCodeFileUpdater;
import java.nio.file.Path;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The HashCodeFileUpdater class implements an updater of hash-codes in a file.
 */
public final class HashCodeFileUpdater implements IHashCodeFileUpdater {
    private static final String hashCodeRegex =
        "(.*)(return new HashCodeBuilder)(\\([0-9]*, [0-9]*\\))(.*)";

    private final Path path;
    private final IContentProvider hashCodeProvider;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The HashCodeFileUpdater constructor.
     */
    public HashCodeFileUpdater(
        Path path,
        IContentProvider hashCodeProvider) {

        Conditions.validateNotNull(
            path,
            "The path.");

        Conditions.validateNotNull(
            hashCodeProvider,
            "The hash code provider.");

        this.path = path;
        this.hashCodeProvider = hashCodeProvider;
    }

    /**
     * Updates the hash-codes.
     * Return -1 if the hash-codes can not get updated.
     */
    @Override
    public long update() {
        return this.updateHashCodes(this.path);
    }

    /**
     * Updates hash codes.
     */
    private long updateHashCodes(Path path) {
        long numberOfUpdates;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            FileLineUpdater lineUpdater = new FileLineUpdater(path);
            destructorHandler.register(lineUpdater);

            IUpdateRecord updateRecord = new UpdateRecordProvider(
                hashCodeRegex,
                this.hashCodeProvider,
                MatchPolicyType.AllMatches);

            numberOfUpdates = lineUpdater.update(updateRecord);
        }

        return numberOfUpdates;
    }
}
