package cheadercommand.core;

import base.core.ArrayLists;
import base.core.Conditions;
import base.core.DestructorHandler;
import basicio.core.FileLineUpdater;
import basicio.core.LineMatcher;
import basicio.core.LineReverseMatcher;
import basicio.core.MatchingRecord;
import base.interfaces.FileNameType;
import base.core.FileNames;
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
     * Return -1 if the file header can not get updated.
     */
    @Override
    public long update() {
        if (!this.canUpdateFileHeader(this.path)) {
            return -1;
        }

        return updateFileHeader(this.path);
    }

    /**
     * Checks whether the file header can get updated.
     */
    private boolean canUpdateFileHeader(Path path) {
        String formattedFileName = formatFileName(path);
        String fileNameRegex = getFileNameRegex(formattedFileName);

        String ifndefRegex = createIfndefRegex(fileNameRegex);
        String defineRegex = createDefineRegex(fileNameRegex);
        String endifRegex = createEndifRegex(fileNameRegex);

        IMatchingRecord ifndefMatchingRecord = new MatchingRecord(ifndefRegex);
        IMatchingRecord defineMatchingRecord = new MatchingRecord(defineRegex);
        IMatchingRecord endifMatchingRecord = new MatchingRecord(endifRegex);

        List<IMatchingRecord> startHeaderMatchingRecord = ArrayLists.make(
            ifndefMatchingRecord,
            defineMatchingRecord);

        int numberOfMatchingRecords = 0;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            //
            // Update the header start...
            //
            LineMatcher lineMatcher = LineMatcher.createFileLineMatcher(path);
            destructorHandler.register(lineMatcher);

            List<IMatchingRecordResult> result = lineMatcher.match(startHeaderMatchingRecord);

            for (IMatchingRecordResult matchingRecordResult : result) {
                numberOfMatchingRecords += matchingRecordResult.matchingLinesSize();
            }

            if (numberOfMatchingRecords != 2) {
                String warningMessage =
                    "The file: " + path + " does not include the following matching lines:" +
                    " ifndefRegex = " + ifndefRegex +
                    ", defineRegex = " + defineRegex;

                this.log.warn(warningMessage);
            }

            LineReverseMatcher lineReverseMatcher = LineReverseMatcher.createFileLineReverseMatcher(path);
            destructorHandler.register(lineReverseMatcher);

            IMatchingRecordResult matchingRecordResult = lineReverseMatcher.match(endifMatchingRecord);
            numberOfMatchingRecords += matchingRecordResult.matchingLinesSize();

            if (numberOfMatchingRecords != 3) {
                String warningMessage =
                    "The file: " + path + " does not include the following matching line:" +
                    " endifRegex = " + endifRegex;

                this.log.warn(warningMessage);
            }
        }

        return numberOfMatchingRecords == 3;
    }

    /**
     * Updates file header.
     */
    private static long updateFileHeader(Path path) {
        long numberOfUpdates;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            FileLineUpdater lineUpdater = new FileLineUpdater(path);
            destructorHandler.register(lineUpdater);

            String formattedFileName = formatFileName(path);
            String fileNameRegex = getFileNameRegex(formattedFileName);
            String newFileName = newFileName(formattedFileName);

            List<IUpdateRecord> startUpdateData = createHeaderStartUpdateData(fileNameRegex, newFileName);
            numberOfUpdates = lineUpdater.update(startUpdateData);

            IUpdateRecord endUpdateData = createHeaderEndUpdateData(fileNameRegex, newFileName);
            numberOfUpdates += lineUpdater.updateFromEnd(endUpdateData);
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
        IUpdateRecord ifndefUpdateRecord = new UpdateRecord(ifndefRegex, ifndefData, MatchPolicyType.FirstMatch);

        String defineRegex = createDefineRegex(fileNameRegex);
        String defineData = "#define " + newFileName;
        IUpdateRecord defineUpdateRecord = new UpdateRecord(defineRegex, defineData, MatchPolicyType.FirstMatch);

        return ArrayLists.make(
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
        IUpdateRecord endifUpdateRecord = new UpdateRecord(endifRegex, endifData, MatchPolicyType.FirstMatch);

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
    private static String formatFileName(Path path) {
        String fileName = path.getFileName().toString();
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
