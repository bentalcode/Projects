package clientserver.core;

import base.core.Conditions;
import clientserver.interfaces.IHttpHandler;
import clientserver.interfaces.IHttpHandlerConfiguration;
import clientserver.interfaces.IHttpHandlerImpl;

/**
 * The AbstractHttpHandler class implements an abstract Http Handler
 * for making http requests.
 */
public abstract class AbstractHttpHandler implements IHttpHandler {
    private final IHttpHandlerConfiguration configuration;
    private final IHttpHandlerImpl implementation;

    /**
     * The AbstractHttpHandler constructor.
     */
    public AbstractHttpHandler(
        IHttpHandlerConfiguration configuration,
        IHttpHandlerImpl implementation) {

        Conditions.validateNotNull(
            configuration,
            "The configuration of a Http Handler.");

        Conditions.validateNotNull(
            implementation,
            "The implementation of a Http Handler.");

        this.configuration = configuration;
        this.implementation = implementation;
    }

    /**
     * Gets the configuration.
     */
    @Override
    public IHttpHandlerConfiguration getConfiguration() {
        return this.configuration;
    }

    /**
     * Gets the implementation.
     */
    protected IHttpHandlerImpl getImplementation() {
        return this.implementation;
    }
}
