package clientserver.core;

import clientserver.ClientServerException;

/**
 * The CircuitBreakerException class implements an exception for capturing errors
 * in the Circuit Breaker module.
 */
public class CircuitBreakerException extends ClientServerException {
    /**
     * The CircuitBreakerException constructor.
     */
    public CircuitBreakerException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The CircuitBreakerException constructor.
     */
    public CircuitBreakerException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
