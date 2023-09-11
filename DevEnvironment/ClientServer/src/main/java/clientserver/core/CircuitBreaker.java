package clientserver.core;

import base.core.Conditions;
import base.core.Dates;
import clientserver.interfaces.CircuitBreakerStateType;
import clientserver.interfaces.ICircuitBreaker;
import clientserver.interfaces.ICircuitBreakerPolicy;
import clientserver.interfaces.IErrorInformation;
import clientserver.interfaces.ILogic;
import clientserver.interfaces.ILogicRuntimeInformation;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Date;

/**
 * The CircuitBreaker class implements a circuit breaker.
 */
public final class CircuitBreaker implements ICircuitBreaker {
    private final ICircuitBreakerPolicy policy;
    private final CircuitBreakerData data;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CircuitBreaker constructor.
     */
    public CircuitBreaker(ICircuitBreakerPolicy policy) {
        Conditions.validateNotNull(
            policy,
            "The policy of a circuit breaker.");

        this.policy = policy;
        this.data = new CircuitBreakerData(new CircuitBreakerClosedState(policy));
    }

    /**
     * Resets a circuit breaker.
     * Sets the state of a circuit breaker to Closed.
     */
    @Override
    public void reset() {
        this.data.setState(new CircuitBreakerClosedState(this.policy));
    }

    /**
     * Trips a circuit breaker.
     * Sets the state of a circuit breaker from a Closed or Half-Open State to an Open State.
     */
    @Override
    public void trip(ILogicRuntimeInformation logicRuntimeInformation) {
        Conditions.validateNotNull(
            logicRuntimeInformation,
            "The logic runtime information.");

        this.data.setState(new CircuitBreakerOpenState(this.policy));
        this.data.setLastLogicRuntimeInformation(logicRuntimeInformation);
    }

    /**
     * Invokes the logic of a circuit breaker.
     */
    @Override
    public ILogicRuntimeInformation make(ILogic logic) {
        Conditions.validateNotNull(
            logic,
            "The logic of a circuit breaker.");

        //
        // Invoke the logic of the circuit breaker...
        //
        IErrorInformation errorInformation = null;

        Date startTime = Dates.now();

        try {
            logic.run();
        }
        catch (Exception e) {
            String errorMessage =
                "The Circuit Breaker failed invoking the logic: " + logic +
                ", due to the following error: " + e.getMessage();

            this.log.error(errorMessage, e);

            errorInformation = ErrorInformation.create(e);
        }

        Date endTime = Dates.now();

        //
        // Create the logic run time information...
        //
        ILogicRuntimeInformation logicRuntimeInformation = new LogicRuntimeInformation(
            logic.name(),
            startTime,
            endTime,
            errorInformation);

        //
        // Set the logic execution result...
        //
        this.data.getState().setLogicExecutionResult(logicRuntimeInformation);

        //
        // Calculate the next state, and move to it if required...
        //
        CircuitBreakerStateType nextStateType = this.data.getState().calculateNextState();

        if (nextStateType != null) {
            ICircuitBreakerState nextState = nextStateType.create(this.policy);
            this.data.setState(nextState);
        }

        return logicRuntimeInformation;
    }

    /**
     * Gets the state of a circuit breaker.
     */
    @Override
    public CircuitBreakerStateType getState() {
        return data.getState().getStateType();
    }
}
