package expressiontree.core;

import base.core.Conditions;
import base.core.Pair;
import base.interfaces.IPair;
import ExpressionTreeCommand.interfaces.IAggregationResult;
import ExpressionTreeCommand.interfaces.IAggregationResults;
import ExpressionTreeCommand.interfaces.IExpressionTreeCommand;
import ExpressionTreeCommand.interfaces.IExpressionTreeCommandParameters;
import ExpressionTreeCommand.interfaces.IDataResult;
import java.util.Scanner;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The ExpressionTreeCommand class implements a command for processing data.
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
     * Processes the stream of data.
     */
    @Override
    public IExpressionTreeResult process(Scanner scanner) {
        Conditions.validateNotNull(
            scanner,
            "The scanner of data.");

        return new ExpressionTreeResult();
    }
}
