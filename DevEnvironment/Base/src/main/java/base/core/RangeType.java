package base.core;

import base.interfaces.IRange;

/**
 * The RangeType enum defines various types of ranges.
 */
public enum RangeType {
    InclusiveToInclusive() {

        /**
         * Checks whether a value is in the defined range.
         */
        @Override
        public <T extends Comparable<T>> boolean inRange(IRange<T> range, T value) {
            return
                (range.start().compareTo(value) <= 0 &&
                 value.compareTo(range.end()) <= 0);
        }

        /**
         * Gets the string representation of a range.
         */
        @Override
        public <T extends Comparable<T>> String toString(IRange<T> range) {
            return "(" + range.start() + "-" + range.end() + ")";
        }
    },

    InclusiveToExclusive() {

        /**
         * Checks whether a value is in the defined range.
         */
        @Override
        public <T extends Comparable<T>> boolean inRange(IRange<T> range, T value) {
            return
                (range.start().compareTo(value) <= 0 &&
                 value.compareTo(range.end()) < 0);
        }

        /**
         * Gets the string representation of a range.
         */
        @Override
        public <T extends Comparable<T>> String toString(IRange<T> range) {
            return "(" + range.start() + "-" + range.end() + "]";
        }

    },

    ExclusiveToInclusive() {

        /**
         * Checks whether a value is in the defined range.
         */
        @Override
        public <T extends Comparable<T>> boolean inRange(IRange<T> range, T value) {
            return
                (range.start().compareTo(value) < 0 &&
                 value.compareTo(range.end()) <= 0);
        }

        /**
         * Gets the string representation of a range.
         */
        @Override
        public <T extends Comparable<T>> String toString(IRange<T> range) {
            return "[" + range.start().toString() + "-" + range.end().toString() + ")";
        }

    },

    ExclusiveToExclusive() {

        /**
         * Checks whether a value is in the defined range.
         */
        @Override
        public <T extends Comparable<T>> boolean inRange(IRange<T> range, T value) {
            return
                (range.start().compareTo(value) < 0 &&
                 value.compareTo(range.end()) < 0);
        }

        /**
         * Gets the string representation of a range.
         */
        @Override
        public <T extends Comparable<T>> String toString(IRange<T> range) {
            return "[" + range.start().toString() + "-" + range.end().toString() + "]";
        }

    };

    /**
     * Checks whether a value is in the defined range.
     */
    public abstract <T extends Comparable<T>> boolean inRange(IRange<T> range, T value);

    /**
     * Gets the string representation of a range.
     */
    public abstract <T extends Comparable<T>> String toString(IRange<T> range);
}
