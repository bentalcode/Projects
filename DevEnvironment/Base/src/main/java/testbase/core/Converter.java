package testbase.core;

import base.interfaces.IConverter;
import java.util.HashMap;
import java.util.Map;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Converter class implements a generic converter.
 */
public final class Converter<Type1, Type2> implements IConverter<Type1, Type2> {
    private final Map<Type1, Type2> mapping = new HashMap<>();
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The Converter constructor.
     */
    public Converter() {
    }

    /**
     * Registers a mapping.
     */
    @Override
    public IConverter<Type1, Type2> register(Type1 type1, Type2 type2) {
        this.mapping.put(type1, type2);
        return this;
    }

    /**
     * Converts to a corresponding type.
     */
    @Override
    public Type2 convert(Type1 type1) {
        if (type1 == null) {
            return null;
        }

        if (!this.mapping.containsKey(type1)) {
            String errorMessage = "The converter does not contain mapping for type: " + type1;

            this.log.error(errorMessage);
            throw new BaseException(errorMessage);
        }

        return this.mapping.get(type1);
    }
}
