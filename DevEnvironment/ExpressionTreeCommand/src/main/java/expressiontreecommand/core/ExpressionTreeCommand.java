package expressiontreecommand.core;

import testbase.core.Conditions;
import datastructures.expressiontree.core.ExpressionTree;
import datastructures.expressiontree.interfaces.IExpressionTree;
import expressiontreecommand.interfaces.IExpressionTreeCommand;
import expressiontreecommand.interfaces.IExpressionTreeCommandParameters;
import expressiontreecommand.interfaces.IExpressionTreeResult;
import expressiontreecommand.interfaces.IExpressionTreeResults;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.Scanner;

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
    public IExpressionTreeResults process(Scanner scanner) {
        Conditions.validateNotNull(
            scanner,
            "The scanner of data.");

        IExpressionTreeResults result = new ExpressionTreeResults();

        while (scanner.hasNextLine()) {
            String expression = scanner.nextLine();

            IExpressionTree expressionTree = ExpressionTree.parse(expression);
            double expressionResult = expressionTree.evaluate();

            IExpressionTreeResult currResult = new ExpressionTreeResult(expression, expressionResult);

            result.add(currResult);
        }

        return result;
    }
}
