package clientserver.core;

import base.core.Dates;
import base.core.Durations;
import clientserver.interfaces.CircuitBreakerStateType;
import clientserver.interfaces.ICircuitBreakerPolicy;
import clientserver.interfaces.ILogicRuntimeInformation;
import java.time.Duration;
import java.util.Date;

/**
 * The CircuitBreakerClosedState class implements a closed state of a Circuit Breaker.
 */
public final class CircuitBreakerClosedState extends CircuitBreakerState {
    private Date failuresStartTime;
    private int failuresCounter;

    /**
     * The CircuitBreakerClosedState constructor.
     */
    public CircuitBreakerClosedState(ICircuitBreakerPolicy policy) {
        super(policy);
    }

    /**
     * Gets the state type of circuit breaker.
     */
    @Override
    public CircuitBreakerStateType getStateType() {
        return CircuitBreakerStateType.Closed;
    }

    /**
     * Sets the result of an execution of the logic.
     */
    @Override
    public void setLogicExecutionResult(ILogicRuntimeInformation logicRuntimeInformation) {
        //
        // If the logic execution has succeeded or the timeout of the failures' duration
        // has expired, then reset the failures information...
        //
        if (logicRuntimeInformation.getStatus() || this.isFailuresDurationTimeoutExpired()) {
            this.resetFailuresInformation();
        }

        //
        // If the logic execution has failed, then set the failures start time if required
        // and increment the failures counter...
        //
        if (!logicRuntimeInformation.getStatus()) {
            if (this.failuresStartTime == null) {
                this.failuresStartTime = Dates.now();
            }

            ++this.failuresCounter;
        }
    }

    /**
     * Calculates the next state of a circuit breaker.
     * Returns null in case the next state of a circuit breaker is the current one.
     */
    @Override
    public CircuitBreakerStateType calculateNextState() {
        if (this.isFailuresCounterReachedThreshold()) {
            return CircuitBreakerStateType.Open;
        }
        else {
            return null;
        }
    }

    /**
     * Checks whether the timeout of the failures duration has expired.
     */
    private boolean isFailuresDurationTimeoutExpired() {
        Duration failuresDuration = Dates.fromNow(this.failuresStartTime);
        return Durations.isLonger(failuresDuration, this.getPolicy().getFailureThresholdTimeout());
    }

    /**
     * Checks whether the failures count has reached it's threshold.
     */
    private boolean isFailuresCounterReachedThreshold() {
        assert(!this.isFailuresDurationTimeoutExpired());
        return this.failuresCounter >= this.getPolicy().getFailureThreshold();
    }

    /**
     * Resets the failures information.
     */
    private void resetFailuresInformation() {
        this.failuresStartTime = null;
        this.failuresCounter = 0;
    }
}
