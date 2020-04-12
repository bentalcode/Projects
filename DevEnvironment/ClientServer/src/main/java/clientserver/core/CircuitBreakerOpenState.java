package clientserver.core;

import base.core.Conditions;
import base.core.Dates;
import base.core.Durations;
import clientserver.interfaces.CircuitBreakerStateType;
import clientserver.interfaces.ICircuitBreakerPolicy;
import clientserver.interfaces.ILogicRuntimeInformation;
import java.time.Duration;

/**
 * The CircuitBreakerOpenState class implements an open state of a Circuit Breaker.
 */
public final class CircuitBreakerOpenState extends CircuitBreakerState {
    /**
     * The CircuitBreakerClosedState constructor.
     */
    public CircuitBreakerOpenState(ICircuitBreakerPolicy policy) {
        super(policy);
    }

    /**
     * Gets the state type of a circuit breaker.
     */
    @Override
    public CircuitBreakerStateType getStateType() {
        return CircuitBreakerStateType.Open;
    }

    /**
     * Sets the result of an execution of the logic.
     */
    @Override
    public void setLogicExecutionResult(ILogicRuntimeInformation logicExecutionResult) {
        String errorMessage = "The Circuit Breaker can not execute logic in the Open State.";
        Conditions.fail(errorMessage);
    }

    /**
     * Calculates the next state of a circuit breaker.
     * Returns null in case the next state of a circuit breaker is the current one.
     */
    @Override
    public CircuitBreakerStateType calculateNextState() {
        Duration durationInThisState = Dates.fromNow(this.getStartTime());

        if (Durations.isLonger(durationInThisState, this.getPolicy().getRecoveryDuration())) {
            return CircuitBreakerStateType.HalfOpen;
        }
        else {
            return CircuitBreakerStateType.Open;
        }
    }
}
