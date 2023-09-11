package command.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IIndexedParameterMetadata interface defines meta-data of an index parameter.
 */
public interface IIndexedParameterMetadata extends IParameterMetadata,
    IUnaryComparator<IIndexedParameterMetadata> {
}
