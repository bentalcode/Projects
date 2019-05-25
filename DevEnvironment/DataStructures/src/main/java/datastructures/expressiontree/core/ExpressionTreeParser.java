package datastructures.expressiontree.core;

import base.core.*;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.expressiontree.ExpressionTreeException;
import datastructures.expressiontree.interfaces.IExpressionTree;
import datastructures.expressiontree.interfaces.IExpressionTreeElement;
import datastructures.expressiontree.interfaces.IOperand;
import datastructures.expressiontree.interfaces.IExpressionTreeParser;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * The IExpressionTreeParser class implements a parser of an expression tree.
 */
public final class ExpressionTreeParser implements IExpressionTreeParser {
    private static final Pattern DoublePattern1 = Pattern.compile("([\\d+])");
    private static final Pattern DoublePattern2 = Pattern.compile("([\\d+])/([\\d+])");
    private static final Pattern DoublePattern3 = Pattern.compile("([\\d+])_([\\d+])/([\\d+])");

    private final String expression;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The ExpressionTree constructor.
     */
    public ExpressionTreeParser(String expression) {
        Conditions.validateNotNull(
            expression,
            "The expression string.");

        this.expression = expression;
    }

    /**
     * Gets the corresponding binary tree.
     */
    @Override
    public IBinaryTree<String, IExpressionTreeElement> parse() {
        String[] tokens = this.expression.split(" ");
        List<String> postfixTokens = transformInfixToPostfix(tokens);

        IBinaryTree<String, IExpressionTreeElement> tree = this.buildExpressionTree(postfixTokens);

        return tree;
    }

    /**
     * Builds an expression tree from postfix tokens.
     */
    private IBinaryTree<String, IExpressionTreeElement> buildExpressionTree(List<String> postfixTokens) {
        Stack<IExpressionTreeElement> stack = new Stack<>();

        for (String token : postfixTokens) {

            //
            // If the current token is an operand, then simply add it to the stack...
            //
            if (ExpressionTreeElement.isOperand(token)) {
                IOperand operand = this.parseOperand(token);
                stack.push(operand);
            }

        }

        return null;
    }

    /**
     * Parses an operand.
     */
    private IOperand parseOperand(String token) {
        Integer integerValue = this.tryParseInteger(token);

        if (integerValue == null) {
            return new IntegerOperand(integerValue);
        }

        Double doubleValue = this.tryParseDouble(token);

        if (doubleValue == null) {
            String errorMessage = "The parser of an expression tree failed parsing operand: " + token;

            this.log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return null;
    }

    /**
     * Transforms an infix to postfix form.
     */
    private List<String> transformInfixToPostfix(String[] infix) {
        List<String> result = new ArrayList<>();

        List<String> tokens = Lists.fromArray(infix);
        tokens.add(")");

        Stack<String> stack = new Stack<>();
        stack.push("(");

        for (String token : tokens) {

            if (ExpressionTreeElement.isOperand(token)) {
                //
                // If the current encountered token is an operand, then append it to the result...
                //
                result.add(token);
            }
            else if (ExpressionTreeElement.isOpenParentheses(token)) {
                //
                // If the current encountered token is an open parentheses,
                // then push it to the stack...
                //
                stack.push(token);
            }
            else if (ExpressionTreeElement.isCloseParentheses(token)) {
                //
                // If the current encountered token is a close parentheses,
                // then pop from the stack all operators up to the corresponding open parentheses
                // and append all those operators to the result.
                //
                // Remove the open parentheses from the stack...
                //
                while (!stack.empty() && !ExpressionTreeElement.isOpenParentheses(stack.peek())) {
                    String currOperator = stack.pop();

                    result.add(currOperator);
                }

                if (stack.empty()) {
                    String errorMessage =
                        "Invalid open/close parentheses sequence in an expression tree.";

                    this.log.error(errorMessage);
                    throw new ExpressionTreeException(errorMessage);
                }
                else {
                    stack.pop();
                }
            }
            else if (ExpressionTreeElement.isOperator(token)) {
                //
                // If the current encountered token is an operator,
                // then pop from the stack all operators which has the same precedence or higher than
                // the current encountered operator, and append those operators to the result.
                //
                // Add the current encountered operator to the stack...
                while (!stack.empty() && this.precedence(stack.peek()) >= this.precedence(token)) {
                    String currOperator = stack.pop();

                    this.validateOperator(currOperator);

                    result.add(currOperator);
                }

                stack.push(token);

            }
            else {
                String errorMessage =
                    "Unsupported token: " + token + ", has been encountered in the expression tree.";

                this.log.error(errorMessage);
                throw new ExpressionTreeException(errorMessage);
            }
        }

        while (!stack.empty()) {
            String currOperator = stack.pop();

            this.validateOperator(currOperator);

            result.add(currOperator);
        }

        return result;
    }

    /**
     * Determines a precedence of an operator.
     */
    private int precedence(String operator) {
        if (AddOperator.isOperator(operator) ||
            SubtractOperator.isOperator(operator)) {
            return 1;
        }
        else if (MultiplyOperator.isOperator(operator) ||
                 DivideOperator.isOperator(operator)) {
            return 2;
        }
        else if (PowOperator.isOperator(operator)) {
            return 3;
        }
        else {
            return -1;
        }
    }

    /**
     * Validates an operator.
     */
    private void validateOperator(String token) {
        if (!ExpressionTreeElement.isOperator(token)) {
            String errorMessage =
                "Unexpected token: " + token + ", has been encountered in the expression tree." +
                " Expecting an operator.";

            this.log.error(errorMessage);
            throw new ExpressionTreeException(errorMessage);
        }
    }

    /**
     * Tries to parse an integer.
     */
    private Integer tryParseInteger(String token) {
        Integer result = Conversion.integerConversion().tryParse(token);

        return result;
    }

    /**
     * Tries to parse a double.
     */
    private Double tryParseDouble(String token) {
        String integerToken = null;
        String numeratorToken = null;
        String denominatorToken = null;

        RegexMatcher regexMatcher = new RegexMatcher();

        Pair<Integer, Matcher> matchingResult = regexMatcher.tryFirstMatch(
            token,
            ArrayLists.of(
                ExpressionTreeParser.DoublePattern1,
                ExpressionTreeParser.DoublePattern2,
                ExpressionTreeParser.DoublePattern3));

        if (matchingResult == null) {
            return null;
        }

        int index = matchingResult.first();
        Matcher matcher = matchingResult.second();

        if (index == 0) {
            integerToken = matcher.group(0);
        } else if (index == 1) {
            numeratorToken = matcher.group(0);
            denominatorToken = matcher.group(1);
        } else if (index == 2) {
            integerToken = matcher.group(0);
            numeratorToken = matcher.group(1);
            denominatorToken = matcher.group(2);
        } else {
            assert(false);
        }

        double integer = 0.0;
        double fraction = 0.0;

        if (integerToken != null) {
            integer = Conversion.doubleConversion().parse(integerToken);
        }

        if (numeratorToken != null && denominatorToken != null) {
            double numerator = Conversion.doubleConversion().parse(numeratorToken);
            double denominator = Conversion.doubleConversion().parse(denominatorToken);

            fraction = numerator / denominator;
        }

        double result = integer + fraction;

        return result;
    }
}
