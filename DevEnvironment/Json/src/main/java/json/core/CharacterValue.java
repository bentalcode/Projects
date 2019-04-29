package json.core;

/**
 * The CharacterValue class implements a json value of type character.
 */
public final class CharacterValue implements ICharacterValue {
    private final char value;

    /**
     * The CharacterValue constructor.
     */
    public CharacterValue(char value) {
        this.value = value;
    }
}
