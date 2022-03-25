package clientserver.core;

import clientserver.interfaces.CircuitBreakerStateType;
import clientserver.interfaces.ILogicRuntimeInformation;

/**
 * The ICircuitBreakerState interface defines a state of a Circuit Breaker.
 */
public interface ICircuitBreakerState {
    /**
     * Gets the state type of a circuit breaker.
     */
    CircuitBreakerStateType getStateType();

    /**
     * Sets the result of an execution of the logic.
     */
    void setLogicExecutionResult(ILogicRuntimeInformation logicRuntimeInformation);

    /**
     * Calculates the next state of a circuit breaker.
     * Returns null in case the next state of a circuit breaker is the current one.
     */
    CircuitBreakerStateType calculateNextState();
}
