package base.core;

import base.interfaces.IOperatingSystemControlSettings;
import base.interfaces.OperatingSystemType;
import java.util.HashMap;
import java.util.Map;

/**
 * The OperatingSystemControlSettingHolder class implements
 * a holder of control settings of operating systems.
 */
public final class OperatingSystemControlSettingHolder {
    private static class InstanceHolder {
        private static final OperatingSystemControlSettingHolder instance =
            new OperatingSystemControlSettingHolder();
    }

    private final Map<OperatingSystemType, IOperatingSystemControlSettings> operatingSystemsControlSettings = new HashMap<>();

    /**
     * The OperatingSystemControlSettingHolder constructor.
     */
    private OperatingSystemControlSettingHolder() {
    }

    /**
     * Gets the instance of this class.
     */
    public static OperatingSystemControlSettingHolder instance() {
        return InstanceHolder.instance;
    }

    /**
     * Gets control settings of a specific operating system.
     */
    public synchronized IOperatingSystemControlSettings getControlSettings(OperatingSystemType operatingSystemType) {
        IOperatingSystemControlSettings controlSettings;

        if (!this.operatingSystemsControlSettings.containsKey(operatingSystemType)) {
            controlSettings = operatingSystemType.createControlSettings();
            this.operatingSystemsControlSettings.put(operatingSystemType, controlSettings);
        }
        else {
            controlSettings = this.operatingSystemsControlSettings.get(operatingSystemType);
        }

        return controlSettings;
    }
}
