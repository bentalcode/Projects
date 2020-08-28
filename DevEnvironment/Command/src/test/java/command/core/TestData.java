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
    private static final String dataDirectoryName = "data";
    private static final String manifestsDirectoryName = "manifests";

    private static final String commandManifest1 = "manifest1.json";
    private static final String commandManifest2 = "manifest2.json";
    private static final List<String> commandLines1 = ArrayLists.make(
        "-h",
        "--help",
        "C:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\interfaces\\DateTime.h",
        "-file:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base\\interfaces\\DateTime.h",
        "-dir:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base",
        "--directory:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base",
        "-dir:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base -r",
        "--directory:=C:\\repositories\\Projects\\DevEnvironmentCLion\\Base --recurse"
    );

    private static final List<String> commandLines2 = ArrayLists.make(
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
            dataDirectoryName,
            manifestsDirectoryName,
            commandManifest1);

        return new CommandData(manifestPath, commandLines1);
    }

    /**
     * Gets data of command2.
     */
    private ICommandData getCommandData2() {
        Path manifestPath = ResourcePaths.create(
            dataDirectoryName,
            manifestsDirectoryName,
            commandManifest2);

        return new CommandData(manifestPath, commandLines2);
    }
}
