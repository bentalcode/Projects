package clientserver.core;

import base.core.Conditions;
import base.core.Dates;
import clientserver.interfaces.ICircuitBreakerPolicy;
import java.util.Date;

/**
 * The CircuitBreakerState abstract class implements a state of a Circuit Breaker.
 */
public abstract class CircuitBreakerState implements ICircuitBreakerState {
    private final ICircuitBreakerPolicy policy;
    private final Date startTime;

    /**
     * The CircuitBreakerState constructor.
     */
    protected CircuitBreakerState(ICircuitBreakerPolicy policy) {
        Conditions.validateNotNull(
            policy,
            "The policy of a circuit breaker");

        this.policy = policy;
        this.startTime = Dates.now();
    }

    /**
     * Gets the policy of a circuit breaker.
     */
    protected ICircuitBreakerPolicy getPolicy() {
        return this.policy;
    }

    /**
     * Gets the start time.
     */
    protected Date getStartTime() {
        return this.startTime;
    }
}
