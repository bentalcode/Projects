package base.interfaces;

/**
 * The IDestructor interface defines a destructor.
 */
public interface IDestructor {
    /**
     * Destructs an instance of an object.
     */
    void destruct();

    /**
     * Detaches the destructor logic.
     */
    void detach();
}
