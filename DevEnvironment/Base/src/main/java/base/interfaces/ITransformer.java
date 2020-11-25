package base.interfaces;

/**
 * The ITransformer interface defines a generic transformer.
 */
public interface ITransformer<TFromObject, TToObject> {
    /**
     * Transforms an object.
     */
    TToObject transform(TFromObject obj);
}
