package base.interfaces;

/**
 * The ISkipIterator interface defines a skip iterator of elements.
 */
public interface ISkipIterator<TElement> {
    /*
     * Registers the class type of a skip element.
     * Returns the previous configured status.
     */
    <TSkipElement extends TElement> void registerSkipElement(Class<TSkipElement> classTypeToSkip);

    /*
     * Configures the iterator for skipping over the registered elements.
     * Returns the previous configured status.
     */
    boolean enableSkipElements();

    /*
     * Configures the iterator for including the registered skip elements.
     * Returns the previous configured status.
     */
    boolean disableSkipElements();

    /*
     * Configures the status of skip elements.
     * Returns the previous configured status.
     */
    boolean setSkipElementsStatus(boolean status);

    /*
     * Gets the current status of skip elements.
     */
    boolean getSkipElementsStatus();

    /*
     * Checks whether this is a skip element.
     */
    <TSkipElement extends TElement> boolean isSkipElement(TSkipElement element);
}
