package basicio.core;

import base.core.Conditions;
import base.core.Pair;
import base.interfaces.IPair;
import basicio.interfaces.ILineMatcher;
import basicio.interfaces.ILineReader;
import basicio.interfaces.IMatchingRecord;
import basicio.interfaces.IMatchingRecordResult;
import basicio.interfaces.MatchPolicyType;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.regex.Matcher;

/**
 * The AbstractLineMatcher class implements an abstract line matcher.
 */
abstract class AbstractLineMatcher implements ILineMatcher {
    private final ILineReader reader;

    /**
     * The AbstractLineMatcher constructor.
     */
    protected AbstractLineMatcher(ILineReader reader) {
        Conditions.validateNotNull(
            reader,
            "The line reader.");

        this.reader = reader;
    }

    /**
     * Matches lines by a matching record and returns its matching result.
     */
    @Override
    public IMatchingRecordResult match(IMatchingRecord matchingRecord) {
        Conditions.validateNotNull(
            matchingRecord,
            "The matching record.");

        IMatchingRecordResult result = new MatchingRecordResult();

        while (this.reader.hasNext()) {
            String line = this.reader.next();
            long lineNumber = this.reader.currentLineNumber();

            if (match(line, lineNumber, matchingRecord, result)) {
                if (matchingRecord.getPolicyType() == MatchPolicyType.FirstMatch) {
                    break;
                }
            }
        }

        return result;
    }

    /**
     * Matches lines by matching records and returns its matching results.
     */
    @Override
    public List<IMatchingRecordResult> match(List<IMatchingRecord> matchingRecords) {
        Conditions.validateNotNull(
            matchingRecords,
            "The matching records.");

        List<IMatchingRecordResult> result = new ArrayList<>(matchingRecords.size());

        //
        // Create the queue for processing the matching records...
        //
        Queue<IPair<IMatchingRecord, IMatchingRecordResult>> queue = new LinkedList<>();

        for (IMatchingRecord matchingRecord : matchingRecords) {
            IMatchingRecordResult matchingRecordResult = new MatchingRecordResult();
            IPair<IMatchingRecord, IMatchingRecordResult> recordInformation = Pair.make(
                matchingRecord,
                matchingRecordResult);

            queue.offer(recordInformation);
            result.add(matchingRecordResult);
        }

        //
        // Evaluate each line with the current matching records...
        //
        while (this.reader.hasNext() && !queue.isEmpty()) {
            String line = this.reader.next();
            long lineNumber = this.reader.currentLineNumber();

            int queueSize = queue.size();

            for (int i = 0; i < queueSize; ++i) {
                IPair<IMatchingRecord, IMatchingRecordResult> recordInformation = queue.poll();
                assert(recordInformation != null);

                IMatchingRecord matchingRecord = recordInformation.first();
                IMatchingRecordResult matchingRecordResult = recordInformation.second();

                if (match(line, lineNumber, matchingRecord, matchingRecordResult)) {
                    if (matchingRecord.getPolicyType() == MatchPolicyType.AllMatches) {
                        queue.offer(recordInformation);
                    }
                }
                else {
                    queue.offer(recordInformation);
                }
            }
        }

        return result;
    }

    /**
     * Matches a line by a matching record.
     */
    private static boolean match(
        String line,
        long lineNumber,
        IMatchingRecord matchingRecord,
        IMatchingRecordResult matchingRecordResult) {

        Matcher matcher = matchingRecord.getMatchingPattern().matcher(line);

        if (matcher.matches()) {
            matchingRecordResult.addMatchingLine(lineNumber);
            return true;
        }

        return false;
    }
}
