package datastructures.trie;

import datastructures.DataStructureException;

/**
 * The TrieException class implements an exception for capturing errors in the trie module.
 */
public class TrieException extends DataStructureException {
    /**
     * The TrieException constructor.
     */
    public TrieException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The TrieException constructor.
     */
    public TrieException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
