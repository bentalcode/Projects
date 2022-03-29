package clientserver.core;

import base.core.Dates;
import base.core.Durations;
import clientserver.interfaces.CircuitBreakerStateType;
import clientserver.interfaces.ICircuitBreakerPolicy;
import clientserver.interfaces.ILogicRuntimeInformation;
import java.time.Duration;
import java.util.Date;

/**
 * The CircuitBreakerHalfOpenState class implements a half-open state of a Circuit Breaker.
 */
public final class CircuitBreakerHalfOpenState extends CircuitBreakerState {
    private Date successStartTime;
    private int successCounter;

    /**
     * The CircuitBreakerHalfOpenState constructor.
     */
    public CircuitBreakerHalfOpenState(ICircuitBreakerPolicy policy) {
        super(policy);
    }

    /**
     * Gets the state type of circuit breaker.
     */
    @Override
    public CircuitBreakerStateType getStateType() {
        return CircuitBreakerStateType.HalfOpen;
    }

    /**
     * Sets the result of an execution of the logic.
     */
    @Override
    public void setLogicExecutionResult(ILogicRuntimeInformation logicRuntimeInformation) {
        //
        // If the logic execution has failed or the timeout of the success duration has expired,
        // then reset the success information...
        //
        if (!logicRuntimeInformation.getStatus() || this.isSuccessDurationTimeoutExpired()) {
            this.resetSuccessInformation();
        }

        //
        // If the logic execution has succeeded, then set the success start time if required
        // and increment the success counter...
        //
        if (logicRuntimeInformation.getStatus()) {
            if (this.successStartTime == null) {
                this.successStartTime = Dates.now();
            }

            ++this.successCounter;
        }
    }

    /**
     * Calculates the next state of a circuit breaker.
     * Returns null in case the next state of a circuit breaker is the current one.
     */
    @Override
    public CircuitBreakerStateType calculateNextState() {
        if (this.isSuccessCounterReachedThreshold()) {
            return CircuitBreakerStateType.Closed;
        }
        else {
            return CircuitBreakerStateType.HalfOpen;
        }
    }

    /**
     * Checks whether the timeout of the success duration has expired.
     */
    private boolean isSuccessDurationTimeoutExpired() {
        Duration successDuration = Dates.fromNow(this.successStartTime);
        return Durations.isLonger(successDuration, this.getPolicy().getSuccessThresholdTimeout());
    }

    /**
     * Checks whether the success count has reached its threshold.
     */
    private boolean isSuccessCounterReachedThreshold() {
        assert(!this.isSuccessDurationTimeoutExpired());
        return this.successCounter >= this.getPolicy().getSuccessThreshold();
    }

    /**
     * Resets the success information.
     */
    private void resetSuccessInformation() {
        this.successStartTime = null;
        this.successCounter = 0;
    }
}
