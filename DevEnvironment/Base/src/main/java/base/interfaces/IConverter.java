package base.interfaces;

/**
 * The IConverter interface defines a generic converter.
 */
public interface IConverter<Type1, Type2> {
    /**
     * Registers a mapping.
     */
    IConverter<Type1, Type2> register(Type1 type1, Type2 type2);

    /**
     * Converts to a corresponding type.
     */
    Type2 convert(Type1 type1);
}
