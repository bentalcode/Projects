package basicio.core;

import base.core.Conditions;
import basicio.interfaces.IContentProvider;
import basicio.interfaces.IUpdateRecord;
import basicio.interfaces.MatchPolicyType;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * The UpdateRecordProvider class implements an update record with a provider.
 */
public final class UpdateRecordProvider implements IUpdateRecord {
    private final Pattern matchingRegex;
    private final IContentProvider newContentProvider;
    private final MatchPolicyType policyType;

    /**
     * The UpdateRecordProvider constructor.
     */
    public UpdateRecordProvider(
        String matchingRegex,
        IContentProvider newContentProvider,
        MatchPolicyType policyType) {

        Conditions.validateNotNull(
            matchingRegex,
            "The matching regex.");

        Conditions.validateNotNull(
            newContentProvider,
            "The new content provider.");

        this.matchingRegex = Pattern.compile(matchingRegex);
        this.newContentProvider = newContentProvider;
        this.policyType = policyType;
    }

    /**
     * Gets the matching regex.
     */
    @Override
    public Pattern getMatchingRegex() {
        return this.matchingRegex;
    }

    /**
     * Gets the new content.
     */
    @Override
    public String getNewContent(String currContent, Matcher matcher) {
        return this.newContentProvider.get(currContent, matcher);
    }

    /**
     * Gets the policy type.
     */
    @Override
    public MatchPolicyType getPolicyType() {
        return this.policyType;
    }
}
