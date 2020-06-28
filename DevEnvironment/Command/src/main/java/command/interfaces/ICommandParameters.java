package command.interfaces;

import base.interfaces.IIterable;
import java.util.List;

/**
 * The ICommandParameters interface defines parameters of a command.
 */
public interface ICommandParameters extends IIterable<IParameter> {
    /**
     * Gets the parameters of the command.
     */
    List<IParameter> getParameters();
}
