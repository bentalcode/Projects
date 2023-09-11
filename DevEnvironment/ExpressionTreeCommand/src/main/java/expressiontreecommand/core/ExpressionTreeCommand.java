package expressiontreecommand.core;

import base.core.Conditions;
import datastructures.expressiontree.core.ExpressionTree;
import datastructures.expressiontree.interfaces.IExpressionTree;
import expressiontreecommand.interfaces.IExpressionTreeCommand;
import expressiontreecommand.interfaces.IExpressionTreeResult;
import expressiontreecommand.interfaces.IExpressionTreeResults;
import java.util.Scanner;

/**
 * The ExpressionTreeCommand class implements a command for processing expression tree.
 */
public final class ExpressionTreeCommand implements IExpressionTreeCommand {
    /**
     * The ExpressionTreeCommand constructor.
     */
    public ExpressionTreeCommand() {
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
