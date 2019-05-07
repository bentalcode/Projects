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
            }
            else if (token.equals(JsonToken.END_OBJECT)) {
                this.endObject();
            }
            if (token.equals(JsonToken.START_ARRAY)) {
                this.startArray();
            }
            else if (token.equals(JsonToken.END_ARRAY)) {
                this.endArray();
            }
            else if (token.equals(JsonToken.FIELD_NAME)) {
                this.setPropertyName();
            }
            else if (token.equals(JsonToken.VALUE_EMBEDDED_OBJECT)) {
                this.unsupportedToken(JsonToken.VALUE_EMBEDDED_OBJECT);
            }
            else if (token.equals(JsonToken.VALUE_STRING)) {
                this.setStringValue();
            }
            else if (token.equals(JsonToken.VALUE_NUMBER_INTEGER)) {
                this.setIntegerValue();
            }
            else if (token.equals(JsonToken.VALUE_NUMBER_DOUBLE)) {
                this.setDoubleValue();
            }
            else if (token.equals(JsonToken.VALUE_TRUE)) {
                 this.setTrueValue();
            }
            else if (token.equals(JsonToken.VALUE_FALSE)) {
                this.setFalseValue();
            }
            else if (token.equals(JsonToken.VALUE_NULL)) {
                this.setNullValue();
            }

            if (!token.equals(JsonToken.FIELD_NAME)) {
                this.currentPropertyName = null;
            }
        }

        return this.jsonTree;
    }

    /**
     * Starts an object.
     */
    private void startObject() {
        IJsonElement currentElement;

        if (this.jsonTree == null) {
            this.jsonTree = JsonTree.createWithRootObject();
            currentElement = this.jsonTree.getRootObject();
        }
        else {
            currentElement = this.jsonTree.createObject();
        }

        this.elementsStack.push(currentElement);
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
        IJsonElement currentObject;

        if (this.jsonTree == null) {
            this.jsonTree = JsonTree.createWithRootArray();
            currentObject = this.jsonTree.getRootArray();
        }
        else {
            currentObject = this.jsonTree.createObject();
        }

        this.elementsStack.push(currentObject);
    }

    /**
     * Ends an array.
     */
    private void endArray() {
        this.elementsStack.pop();
    }

    /**
     * Gets the current object.
     */
    private IJsonElement currentObject() {
        return this.elementsStack.peek();
    }

    /**
     * Sets a property name.
     */
    private void setPropertyName() {
        this.currentPropertyName = this.tokenizer.currentName();
    }

    /**
     * Sets a string value.
     */
    private void setStringValue() {
        String currentValue = this.tokenizer.currentStringValue();
        IJsonElement currentElement = this.currentObject();
        currentElement.setValue(this.currentPropertyName, new JsonStringValue(currentValue));
    }

    /**
     * Sets an integer value.
     */
    private void setIntegerValue() {
        long value = this.tokenizer.currentLongValue();
        IJsonElement currentElement = this.currentObject();
        currentElement.setValue(this.currentPropertyName, new JsonIntegerValue(value));
    }

    /**
     * Sets a double value.
     */
    private void setDoubleValue() {
        double value = this.tokenizer.currentDoubleValue();
        IJsonElement currentElement = this.currentObject();
        currentElement.setValue(this.currentPropertyName, new JsonDoubleValue(value));
    }

    /**
     * Sets a true value.
     */
    private void setTrueValue() {
        IJsonElement currentElement = this.currentObject();
        currentElement.setValue(this.currentPropertyName, new JsonBooleanValue(true));
    }

    /**
     * Sets a false value.
     */
    private void setFalseValue() {
        IJsonElement currentElement = this.currentObject();
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
