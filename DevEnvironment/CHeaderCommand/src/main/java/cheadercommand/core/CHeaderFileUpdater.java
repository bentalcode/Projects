package cheadercommand.core;

import base.core.ArrayLists;
import base.core.Conditions;
import base.core.DestructorHandler;
import basicio.core.FileLineUpdater;
import basicio.core.LineMatcher;
import basicio.core.LineReverseMatcher;
import basicio.core.MatchingRecord;
import basicio.interfaces.FileNameType;
import basicio.core.FileNames;
import base.interfaces.IConstants;
import basicio.core.UpdateRecord;
import basicio.interfaces.IMatchingRecord;
import basicio.interfaces.IMatchingRecordResult;
import basicio.interfaces.IUpdateRecord;
import basicio.interfaces.MatchPolicyType;
import cheadercommand.interfaces.IFileUpdater;
import java.nio.file.Path;
import java.util.List;
import java.util.UUID;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CHeaderFileUpdater class implements an updater of a c-header.
 */
public final class CHeaderFileUpdater implements IFileUpdater {
    private final Path path;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CHeaderFileUpdater constructor.
     */
    public CHeaderFileUpdater(Path path) {
        Conditions.validateNotNull(
            path,
            "The path.");

        this.path = path;
    }

    /**
     * Updates the file.
     */
    @Override
    public long update() {
        if (!this.canUpdateFileHeader()) {
            String warningMessage =
                "The header of file: " + this.path + " can not get updated." +
                "; Skipping the file header.";

            this.log.warn(warningMessage);

            return 0;
        }

        return this.updateFileHeader();
    }

    /**
     * Checks whether the file header can get updated.
     */
    private boolean canUpdateFileHeader() {
        String formattedFileName = this.formatFileName();
        String fileNameRegex = getFileNameRegex(formattedFileName);

        String ifndefRegex = createIfndefRegex(fileNameRegex);
        String defineRegex = createDefineRegex(fileNameRegex);
        String endifRegex = createEndifRegex(fileNameRegex);

        IMatchingRecord ifndefMatchingRecord = new MatchingRecord(ifndefRegex);
        IMatchingRecord defineMatchingRecord = new MatchingRecord(defineRegex);
        IMatchingRecord endifMatchingRecord = new MatchingRecord(endifRegex);

        int numberOfMatchingRecords = 0;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            LineMatcher lineMatcher = LineMatcher.createFileLineMatcher(this.path);
            destructorHandler.register(lineMatcher);

            LineReverseMatcher lineReverseMatcher = LineReverseMatcher.createFileLineReverseMatcher(this.path);
            destructorHandler.register(lineReverseMatcher);

            List<IMatchingRecordResult> result = lineMatcher.match(ArrayLists.of(
                ifndefMatchingRecord,
                defineMatchingRecord));

            for (IMatchingRecordResult matchingRecordResult : result) {
                numberOfMatchingRecords += matchingRecordResult.matchingLinesSize();
            }

            IMatchingRecordResult matchingRecordResult = lineReverseMatcher.match(endifMatchingRecord);

            numberOfMatchingRecords += matchingRecordResult.matchingLinesSize();
        }

        return numberOfMatchingRecords == 3;
    }

    /**
     * Updates file header.
     */
    private long updateFileHeader() {
        long numberOfUpdates;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            FileLineUpdater lineUpdater = new FileLineUpdater(this.path);
            destructorHandler.register(lineUpdater);

            String formattedFileName = this.formatFileName();
            String fileNameRegex = getFileNameRegex(formattedFileName);
            String newFileName = newFileName(formattedFileName);

            List<IUpdateRecord> startUpdateData = createHeaderStartUpdateData(fileNameRegex, newFileName);
            numberOfUpdates = lineUpdater.update(startUpdateData, MatchPolicyType.AllMatches);

            IUpdateRecord endUpdateData = createHeaderEndUpdateData(fileNameRegex, newFileName);
            if (lineUpdater.updateFromEnd(endUpdateData)) {
                ++numberOfUpdates;
            }
        }

        return numberOfUpdates;
    }

    /**
     * Creates start-update data for a header.
     */
    private static List<IUpdateRecord> createHeaderStartUpdateData(
        String fileNameRegex,
        String newFileName) {

        String ifndefRegex = createIfndefRegex(fileNameRegex);
        String ifndefData = "#ifndef " + newFileName;
        IUpdateRecord ifndefUpdateRecord = new UpdateRecord(ifndefRegex, ifndefData);

        String defineRegex = createDefineRegex(fileNameRegex);
        String defineData = "#define " + newFileName;
        IUpdateRecord defineUpdateRecord = new UpdateRecord(defineRegex, defineData);

        return ArrayLists.of(
            ifndefUpdateRecord,
            defineUpdateRecord);
    }

    /**
     * Creates end-update data for a header.
     */
    private static IUpdateRecord createHeaderEndUpdateData(
        String fileNameRegex,
        String newFileName) {

        String endifRegex = createEndifRegex(fileNameRegex);
        String endifData = "#endif" + " // " + newFileName;
        IUpdateRecord endifUpdateRecord = new UpdateRecord(endifRegex, endifData);

        return endifUpdateRecord;
    }

    /**
     * Creates ifndef regex.
     */
    private static String createIfndefRegex(String fileNameRegex) {
        return "#ifndef " + fileNameRegex;
    }

    /**
     * Creates define regex.
     */
    private static String createDefineRegex(String fileNameRegex) {
        return "#define " + fileNameRegex;
    }

    /**
     * Creates endif regex.
     */
    private static String createEndifRegex(String fileNameRegex) {
        return "#endif" + " // " + fileNameRegex;
    }

    /**
     * Gets a regex of a file name.
     */
    private static String getFileNameRegex(String formattedFileName) {
        return formattedFileName + FileNames.snakeCasedSeparator + IConstants.guidRegex;
    }

    /**
     * Gets a new file name.
     */
    private static String newFileName(String formattedFileName) {
        String guid = UUID.randomUUID().toString();
        guid = guid.replace('-', '_');
        return formattedFileName + FileNames.snakeCasedSeparator + guid;
    }

    /**
     * Formats a file name.
     */
    private String formatFileName() {
        String fileName = this.path.getFileName().toString();
        String extension = FileNames.getExtension(fileName);

        FileNameType fileNameType = FileNames.getFileNameType(fileName);
        String[] tokens = fileNameType.getTokens(fileName);

        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 0; i < tokens.length; ++i) {
            if (i > 0) {
                stringBuilder.append(FileNames.snakeCasedSeparator);
            }

            String token = tokens[i];
            token = token.toUpperCase();
            stringBuilder.append(token);
        }

        if (stringBuilder.length() > 0) {
            stringBuilder.append(FileNames.snakeCasedSeparator);
        }

        extension = extension.toUpperCase();
        stringBuilder.append(extension);

        return stringBuilder.toString();
    }
}
