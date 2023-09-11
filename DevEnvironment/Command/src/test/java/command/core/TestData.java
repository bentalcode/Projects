package command.core;

import base.core.ArrayLists;
import command.interfaces.ICommandData;
import command.interfaces.ITestData;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import testbase.core.ResourcePaths;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DATA_DIRECTORY_NAME = "data";
    private static final String MANIFESTS_DIRECTORY_NAME = "manifests";
    private static final String COMMAND_MANIFEST1 = "manifest1.json";
    private static final String COMMAND_MANIFEST2 = "manifest2.json";

    private static final List<String> COMMAND_LINES1 = ArrayLists.make(
        "-h",
        "--help",
        "C:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\interfaces\\DateTime.h",
        "-file:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\interfaces\\DateTime.h",
        "-dir:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base",
        "--directory:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base",
        "-dir:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base -r",
        "--directory:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base --recurse"
    );

    private static final List<String> COMMAND_LINES2 = ArrayLists.make(
        "-h",
        "--help",
        "C:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\interfaces\\DateTime.h",
        "C:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\interfaces\\DateTime.h --initialPrime:=2",
        "-file:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\interfaces\\DateTime.h",
        "-file:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\interfaces\\DateTime.h -prime:=2",
        "-dir:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base",
        "-dir:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base -prime:=2",
        "--directory:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base",
        "--directory:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base --initialPrime:=2",
        "-dir:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base -r",
        "-dir:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base -r -prime:=2"
    );

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets data of commands.
     */
    @Override
    public List<ICommandData> getCommandsData() {
        List<ICommandData> result = new ArrayList<>();
        result.add(this.getCommandData1());
        result.add(this.getCommandData2());
        return result;
    }

    /**
     * Gets data of command1.
     */
    private ICommandData getCommandData1() {
        Path manifestPath = ResourcePaths.create(
                DATA_DIRECTORY_NAME,
                MANIFESTS_DIRECTORY_NAME,
                COMMAND_MANIFEST1);

        return new CommandData(manifestPath, COMMAND_LINES1);
    }

    /**
     * Gets data of command2.
     */
    private ICommandData getCommandData2() {
        Path manifestPath = ResourcePaths.create(
                DATA_DIRECTORY_NAME,
                MANIFESTS_DIRECTORY_NAME,
                COMMAND_MANIFEST2);

        return new CommandData(manifestPath, COMMAND_LINES2);
    }
}
