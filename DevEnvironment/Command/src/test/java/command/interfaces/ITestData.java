package command.interfaces;

import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets data of commands.
     */
    List<ICommandData> getCommandsData();
}
