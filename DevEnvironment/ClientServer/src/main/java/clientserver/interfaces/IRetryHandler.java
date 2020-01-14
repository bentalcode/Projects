package clientserver.interfaces;

/**
 * The IRetryHandler interface defines a retry handler.
 */
public interface IRetryHandler {
    /**
     * Retries to run a logic.
     */
    void retry(IRetryLogic logic);
}
