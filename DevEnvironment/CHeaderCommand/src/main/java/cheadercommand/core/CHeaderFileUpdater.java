package cheadercommand.core;

import base.core.ArrayLists;
import base.core.Conditions;
import basicio.interfaces.FileNameType;
import basicio.core.FileNames;
import base.interfaces.IConstants;
import basicio.core.FileLineUpdater;
import basicio.core.UpdateRecord;
import basicio.interfaces.ILineUpdater;
import basicio.interfaces.IUpdateRecord;
import basicio.interfaces.UpdatePolicyType;
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
    public void update() {
        this.updateFileHeader();
    }

    /**
     * Updates file header.
     */
    private void updateFileHeader() {
        ILineUpdater lineUpdater = new FileLineUpdater(this.path);

        String formattedFileName = this.getFormattedFileName();
        String fileNameRegex = this.getFileNameRegex(formattedFileName);
        String newFileName = this.newFileName(formattedFileName);

        List<IUpdateRecord> startUpdateData = this.createHeaderStartUpdateData(fileNameRegex, newFileName);
        lineUpdater.update(startUpdateData, UpdatePolicyType.AllMatches);

        List<IUpdateRecord> endUpdateData = this.createHeaderStartUpdateData(fileNameRegex, newFileName);
        // lineUpdater.update(endUpdateData, UpdatePolicyType.AllMatches);
    }

    /**
     * Creates start-update data for a header.
     */
    private List<IUpdateRecord> createHeaderStartUpdateData(
        String fileNameRegex,
        String newFileName) {

        String ifndefRegex = "#ifndef " + fileNameRegex;
        String ifndefData = "#ifndef " + newFileName;
        IUpdateRecord ifndefUpdateRecord = new UpdateRecord(ifndefRegex, ifndefData);

        String defineRegex = "#define " + fileNameRegex;
        String defineData = "#define " + newFileName;
        IUpdateRecord defineUpdateRecord = new UpdateRecord(defineRegex, defineData);

        return ArrayLists.of(
            ifndefUpdateRecord,
            defineUpdateRecord);
    }

    /**
     * Creates end-update data for a header.
     */
    private List<IUpdateRecord> createHeaderEndUpdateData(
        String fileNameRegex,
        String newFileName) {

        String endifRegex = "#endif" + " // " + fileNameRegex;
        String endifData = "#endif" + " // " + newFileName;
        IUpdateRecord endifUpdateRecord = new UpdateRecord(endifRegex, endifData);

        return ArrayLists.of(endifUpdateRecord);
    }

    /**
     * Gets a regex of a file name.
     */
    private String getFileNameRegex(String formattedFileName) {
        return formattedFileName + FileNames.snakeCasedSeparator + IConstants.guidRegex;
    }

    /**
     * Gets a new file name.
     */
    private String newFileName(String formattedFileName) {
        String guid = UUID.randomUUID().toString();
        return formattedFileName + FileNames.snakeCasedSeparator + guid;
    }

    /**
     * Gets formatted file name.
     */
    private String getFormattedFileName() {
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
