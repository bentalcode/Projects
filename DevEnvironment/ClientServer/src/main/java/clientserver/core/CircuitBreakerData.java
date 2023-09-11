package clientserver.core;

import base.core.Conditions;
import clientserver.interfaces.ILogicRuntimeInformation;

/**
 * The CircuitBreakerData class implements the current data of a circuit breaker.
 */
public final class CircuitBreakerData {
    private ICircuitBreakerState state;
    private ILogicRuntimeInformation logicRuntimeInformation;

    /**
     * The CircuitBreakerData constructor.
     */
    public CircuitBreakerData(CircuitBreakerState state) {
        this.setState(state);
    }

    /**
     * Sets the state of a circuit breaker.
     */
    public void setState(ICircuitBreakerState state) {
        Conditions.validateNotNull(
            state,
            "The state of a circuit breaker.");

        this.state = state;
    }

    /**
     * Gets the state of a circuit breaker.
     */
    public ICircuitBreakerState getState() {
        return this.state;
    }

    /**
     * Sets the last logic runtime information.
     */
    public void setLastLogicRuntimeInformation(ILogicRuntimeInformation logicRuntimeInformation) {
        Conditions.validateNotNull(
            logicRuntimeInformation,
            "The runtime information of the logic.");

        this.logicRuntimeInformation = logicRuntimeInformation;
    }

    /**
     * Gets the last logic runtime information.
     */
    public ILogicRuntimeInformation getLastLogicRuntimeInformation() {
        return this.logicRuntimeInformation;
    }
}
