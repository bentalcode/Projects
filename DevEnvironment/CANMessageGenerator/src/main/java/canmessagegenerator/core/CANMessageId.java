package canmessagegenerator.core;

import canmessagegenerator.interfaces.ICANMessageId;

/**
 * The CANMessageId class implements an id of a controller area network message.
 */
public final class CANMessageId implements ICANMessageId {
    private final int mainId;
    private final int extendedId;

    /**
     * The CANMessageId Constructor.
     */
    public CANMessageId(int mainId, int extendedId) {
        this.mainId = mainId;
        this.extendedId = extendedId;
    }

    /**
     * Gets the main id. Bits: {28, 27, 26, ... 0}.
     */
    @Override
    public int getMainId() {
        return this.mainId;
    }

    /**
     * Gets the extended id. Bits: {31, 30, 29}.
     */
    @Override
    public int getExtendedId() {
        return this.extendedId;
    }

    /**
     * Gets the id.
     */
    @Override
    public int getId() {
        return this.mainId | this.extendedId;
    }

    @Override
    public String toString() {
        int id = this.getId();
        return String.valueOf(id);
    }
}
