package base.core;

import base.interfaces.ISkipIterator;
import java.util.ArrayList;
import java.util.List;

/**
 * The SkipIterator class implements a skip iterator of elements.
 */
public final class SkipIterator<TElement> implements ISkipIterator<TElement> {
    private final List<Class<?>> elementsToSkip = new ArrayList<>();
    private boolean skipElements;

    /**
     * The SkipIterator constructor.
     */
    public SkipIterator() {
    }

    /*
     * Registers the class type of a generic skip element.
     */
    @Override
    public void registerGenericSkipElement(Class<?> classTypeToSkip) {
        this.registerSkipElement(Casting.cast(classTypeToSkip));
    }

    /*
     * Registers the class type of a skip element.
     */
    @Override
    public <TSkipElement extends TElement> void registerSkipElement(Class<TSkipElement> classTypeToSkip) {
        Conditions.validateNotNull(
            classTypeToSkip,
            "The class type of an element to skip.");

        this.elementsToSkip.add(classTypeToSkip);
    }

    /*
     * Configures the iterator for skipping over the registered elements.
     * Returns the previous configured status.
     */
    @Override
    public boolean enableSkipElements() {
        return this.setSkipElementsStatus(true);
    }

    /*
     * Configures the iterator for including the registered skip elements.
     * Returns the previous configured status.
     */
    @Override
    public boolean disableSkipElements() {
        return this.setSkipElementsStatus(false);
    }

    /*
     * Configures the status of skip elements.
     * Returns the previous configured status.
     */
    @Override
    public boolean setSkipElementsStatus(boolean status) {
        boolean previousStatus = this.skipElements;
        this.skipElements = status;
        return previousStatus;
    }

    /*
     * Returns whether processing an element.
     */
    @Override
    public boolean processingElement() {
        return !this.skippingElement();
    }

    /*
     * Returns whether skipping an element.
     */
    @Override
    public boolean skippingElement() {
        return this.skipElements;
    }

    /*
     * Checks whether this is a skip element.
     */
    @Override
    public <TSkipElement extends TElement> boolean isSkipElement(TSkipElement element) {
        if (element == null) {
            return false;
        }

        for (Class<?> classType : this.elementsToSkip) {
            if (element.getClass().isAssignableFrom(classType)) {
                return true;
            }
        }

        return false;
    }
}
