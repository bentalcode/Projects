package clientserver.interfaces;

import clientserver.core.CircuitBreakerClosedState;
import clientserver.core.CircuitBreakerHalfOpenState;
import clientserver.core.CircuitBreakerOpenState;
import clientserver.core.ICircuitBreakerState;

/**
 * The CircuitBreakerStateType enum defines a state of a Circuit Breaker.
 */
public enum CircuitBreakerStateType {
    Closed
    {
        /**
         * Creates the corresponding state.
         */
        @Override
        public ICircuitBreakerState create(ICircuitBreakerPolicy policy) {
            return new CircuitBreakerClosedState(policy);
        }
    },

    Open
    {
        /**
         * Creates the corresponding state.
         */
        @Override
        public ICircuitBreakerState create(ICircuitBreakerPolicy policy) {
            return new CircuitBreakerOpenState(policy);
        }
    },

    HalfOpen
    {
        /**
         * Creates the corresponding state.
         */
        @Override
        public ICircuitBreakerState create(ICircuitBreakerPolicy policy) {
            return new CircuitBreakerHalfOpenState(policy);
        }
    };

    /**
     * Creates a the corresponding state.
     */
    public abstract ICircuitBreakerState create(ICircuitBreakerPolicy policy);
}
