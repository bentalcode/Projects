package clientserver.interfaces;

/**
 * The ICircuitBreaker interface defines a circuit breaker.
 */
public interface ICircuitBreaker {
    /**
     * Resets a circuit breaker.
     * Sets the state of a circuit breaker to Closed.
     */
    void reset();

    /**
     * Trips a circuit breaker.
     * Sets the state of a circuit breaker from a Closed or Half-Open State to an Open State.
     */
    void trip(ILogicRuntimeInformation logicRuntimeInformation);

    /**
     * Invokes the logic of a circuit breaker.
     */
    ILogicRuntimeInformation make(ILogic logic);

    /**
     * Gets the state of a circuit breaker.
     */
    CircuitBreakerStateType getState();
}
