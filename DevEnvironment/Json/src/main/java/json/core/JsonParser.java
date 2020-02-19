package json.core;

import base.core.Conditions;

import java.io.Reader;
import java.util.Stack;

import base.core.DestructorHandler;
import base.interfaces.ICloseable;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The JsonParser class implements a json parser.
 */
public final class JsonParser implements IJsonParser, ICloseable {
    private final IJsonTokenizer tokenizer;

    private IJsonTree jsonTree;
    private final Stack<IJsonElement> elementsStack = new Stack<>();
    private String currentPropertyName;

    private final DestructorHandler destructorHandler = new DestructorHandler();

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The JsonParser constructor.
     */
    public JsonParser(IJsonFactory factory, Reader reader) {
        Conditions.validateNotNull(
                factory,
                "The json factory.");

        Conditions.validateNotNull(
                reader,
                "The json reader.");

        this.tokenizer = factory.createTokenizer(reader);
    }

    /**
     * Closes the parser.
     */
    @Override
    public void close() {
        this.destructorHandler.close();
    }

    /**
     * Parses a json into a tree.
     */
    @Override
    public IJsonTree parse() {

        while (true) {
            JsonToken token = this.tokenizer.next();

            if (token == null) {
                break;
            }

            if (token.equals(JsonToken.NOT_AVAILABLE)) {
                this.unsupportedToken(JsonToken.NOT_AVAILABLE);
            }

            if (token.equals(JsonToken.START_OBJECT)) {
                this.startObject();
                this.resetPropertyName();
            } else if (token.equals(JsonToken.END_OBJECT)) {
                this.endObject();
            }
            if (token.equals(JsonToken.START_ARRAY)) {
                this.startArray();
                this.resetPropertyName();
            } else if (token.equals(JsonToken.END_ARRAY)) {
                this.endArray();
            } else if (token.equals(JsonToken.FIELD_NAME)) {
                this.setPropertyName();
            } else if (token.equals(JsonToken.VALUE_EMBEDDED_OBJECT)) {
                this.unsupportedToken(JsonToken.VALUE_EMBEDDED_OBJECT);
            } else if (token.equals(JsonToken.VALUE_STRING)) {
                this.setStringValue();
                this.resetPropertyName();
            } else if (token.equals(JsonToken.VALUE_NUMBER_INTEGER)) {
                this.setIntegerValue();
                this.resetPropertyName();
            } else if (token.equals(JsonToken.VALUE_NUMBER_DOUBLE)) {
                this.setDoubleValue();
                this.resetPropertyName();
            } else if (token.equals(JsonToken.VALUE_TRUE)) {
                this.setTrueValue();
                this.resetPropertyName();
            } else if (token.equals(JsonToken.VALUE_FALSE)) {
                this.setFalseValue();
                this.resetPropertyName();
            } else if (token.equals(JsonToken.VALUE_NULL)) {
                this.setNullValue();
                this.resetPropertyName();
            }
        }

        return this.jsonTree;
    }

    /**
     * Starts an object.
     */
    private void startObject() {
        //
        // If the object is the root, then create it and set it as the root of the json tree...
        //
        if (this.jsonTree == null) {
            this.jsonTree = JsonTree.createWithRootObject();
            IJsonObject rootObject = this.jsonTree.getRootObject();
            this.elementsStack.push(rootObject);

            return;
        }

        //
        // Otherwise, create the object and set it to it's parent...
        //
        IJsonObject currentObject = this.jsonTree.createObject();
        IJsonValue currentObjectValue = new JsonObjectValue(currentObject);

        IJsonElement parentElement = this.currentElement();
        this.elementsStack.push(currentObject);

        parentElement.setValue(this.currentPropertyName, currentObjectValue);
    }

    /**
     * Ends an object.
     */
    private void endObject() {
        this.elementsStack.pop();
    }

    /**
     * Starts an array.
     */
    private void startArray() {
        //
        // If the array is the root, then create it and set it as the root of the json tree...
        //
        if (this.jsonTree == null) {
            this.jsonTree = JsonTree.createWithRootArray();
            IJsonArray rootArray = this.jsonTree.getRootArray();
            this.elementsStack.push(rootArray);

            return;
        }

        //
        // Otherwise, create the array and set it to it's parent...
        //
        IJsonArray currentArray = this.jsonTree.createArray();
        IJsonValue currentArrayValue = new JsonArrayValue(currentArray);

        IJsonElement parentElement = this.currentElement();
        this.elementsStack.push(currentArray);

        parentElement.setValue(this.currentPropertyName, currentArrayValue);
    }

    /**
     * Ends an array.
     */
    private void endArray() {
        this.elementsStack.pop();
    }

    /**
     * Gets the current element.
     */
    private IJsonElement currentElement() {
        return this.elementsStack.peek();
    }

    /**
     * Sets a property name.
     */
    private void setPropertyName() {
        this.currentPropertyName = this.tokenizer.currentName();
    }

    /**
     * Resets a property name.
     */
    private void resetPropertyName() {
        this.currentPropertyName = null;
    }

    /**
     * Sets a string value.
     */
    private void setStringValue() {
        String currentValue = this.tokenizer.currentStringValue();
        IJsonElement currentElement = this.currentElement();
        currentElement.setValue(this.currentPropertyName, new JsonStringValue(currentValue));
    }

    /**
     * Sets an integer value.
     */
    private void setIntegerValue() {
        long value = this.tokenizer.currentLongValue();
        IJsonElement currentElement = this.currentElement();
        currentElement.setValue(this.currentPropertyName, new JsonLongValue(value));
    }

    /**
     * Sets a double value.
     */
    private void setDoubleValue() {
        double value = this.tokenizer.currentDoubleValue();
        IJsonElement currentElement = this.currentElement();
        currentElement.setValue(this.currentPropertyName, new JsonDoubleValue(value));
    }

    /**
     * Sets a true value.
     */
    private void setTrueValue() {
        IJsonElement currentElement = this.currentElement();
        currentElement.setValue(this.currentPropertyName, new JsonBooleanValue(true));
    }

    /**
     * Sets a false value.
     */
    private void setFalseValue() {
        IJsonElement currentElement = this.currentElement();
        currentElement.setValue(this.currentPropertyName, new JsonBooleanValue(false));
    }

    /**
     * Sets a null value.
     */
    private void setNullValue() {
    }

    /**
     * Unsupported token.
     */
    private void unsupportedToken(JsonToken token) {
        String errorMessage = "The Json Parser is not supporting token: " + token;

        this.log.error(errorMessage);
        throw new JsonException(errorMessage);
    }
}
