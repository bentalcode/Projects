package command.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The IParameterSet interface defines a metadata of a parameter set.
 */
public interface IParameterSetMetadata extends
    IUnaryComparator<IParameterSetMetadata>,
    IJsonSerialization,
    IIterable<IParameterMetadata> {

    /**
     * Gets indexed parameters of a parameter-set.
     */
    List<IIndexedParameterMetadata> getIndexedParameters();

    /**
     * Gets named parameters of a parameter-set.
     */
    List<INamedParameterMetadata> getNamedParameters();
}
