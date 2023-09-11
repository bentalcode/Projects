package base.interfaces;

/**
 * The IConverter interface defines a generic converter.
 */
public interface IConverter<TypeA, TypeB> {
    /**
     * Registers a mapping.
     */
    IConverter<TypeA, TypeB> register(TypeA type1, TypeB type2);

    /**
     * Converts to a corresponding type.
     */
    TypeB convert(TypeA type1);
}
