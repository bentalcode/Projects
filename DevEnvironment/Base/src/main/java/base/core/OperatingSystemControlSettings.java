package base.core;

import base.interfaces.IOperatingSystemControlSettings;
import base.interfaces.IOperatingSystemPathSettings;

/**
 * The OperatingSystemControlSettings class implements a control settings of an operating system.
 */
public final class OperatingSystemControlSettings implements IOperatingSystemControlSettings {
    private final IOperatingSystemPathSettings pathSettings;

    /**
     * The OperatingSystemControlSettings constructor.
     */
    public OperatingSystemControlSettings(IOperatingSystemPathSettings pathSettings) {
        Conditions.validateNotNull(
            pathSettings,
            "The path settings.");

        this.pathSettings = pathSettings;
    }

    /**
     * Gets paths settings.
     */
    @Override
    public IOperatingSystemPathSettings pathSettings() {
        return this.pathSettings;
    }
}
