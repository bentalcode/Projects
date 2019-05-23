package expressiontreecommand.core;

import base.core.Conditions;
import java.util.Scanner;
import expressiontreecommand.interfaces.IExpressionTreeCommand;
import expressiontreecommand.interfaces.IExpressionTreeCommandParameters;
import expressiontreecommand.interfaces.IExpressionTreeResult;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The ExpressionTreeCommand class implements a command for processing expression tree.
 */
public final class ExpressionTreeCommand implements IExpressionTreeCommand {
    private final IExpressionTreeCommandParameters parameters;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The ExpressionTreeCommandParameters constructor.
     */
    public ExpressionTreeCommand(IExpressionTreeCommandParameters parameters) {
        Conditions.validateNotNull(
            parameters,
            "The parameters of expression tree command.");

        this.parameters = parameters;
    }

    /**
     * Processes a stream of data.
     */
    @Override
    public IExpressionTreeResult process(Scanner scanner) {
        Conditions.validateNotNull(
            scanner,
            "The scanner of data.");

        return new ExpressionTreeResult();
    }
}
