package base.interfaces;

/**
 * The ITransformer interface defines a transformer.
 */
public interface ITransformer<FROM_OBJECT, TO_OBJECT> {
    /**
     * Transforms the object.
     */
    TO_OBJECT transform(FROM_OBJECT obj);
}
