package base.core;

import java.util.concurrent.atomic.AtomicBoolean;
import base.interfaces.IRunnable;

/**
 * The AbstractRunnable base class implements an abstract runnable.
 */
public abstract class AbstractRunnable implements IRunnable {
    private final AtomicBoolean running = new AtomicBoolean(true);

    /**
     * The AbstractRunnable constructor.
     */
    protected AbstractRunnable() {
    }

    /**
     * Checks whether an instance is in a running state.
     */
    @Override
    public boolean isRunning() {
        return this.running.get();
    }

    /**
     * Checks whether an instance is in a shutdown state.
     */
    @Override
    public boolean isShutdown() {
        return !this.running.get();
    }

    /**
     * Shutdowns an instance.
     */
    @Override
    public void shutdown() {
        //
        // Mark an instance in a shutdown state...
        //
        this.running.set(false);
    }
}
