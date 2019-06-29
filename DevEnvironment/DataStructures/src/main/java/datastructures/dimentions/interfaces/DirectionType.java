package datastructures.dimentions.interfaces;

import datastructures.dimentions.core.Direction;

/**
 * The DirectionType enum defines types of 2D directions.
 */
public enum DirectionType {
    North {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(0.0);
        }
    },

    NorthNorthEast {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(22.5);
        }
    },

    NorthEast {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(45.0);
        }
    },

    EastNorthEast {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(67.5);
        }
    },

    East {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(90.0);
        }
    },

    EastSouthEast {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(112.5);
        }
    },

    SouthEast {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(135.0);
        }
    },

    SouthSouthEast {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(157.5);
        }
    },

    South {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(180.0);
        }
    },

    SouthSouthWest {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(202.5);
        }
    },

    SouthWest {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(225.0);
        }
    },

    WestSouthWest {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(247.5);
        }
    },

    West {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(270.0);
        }
    },

    WestNorthWest {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(292.5);
        }
    },

    NorthWest {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(315.0);
        }
    },

    NorthNorthWest {
        /**
         * Gets the direction.
         */
        public IDirection asDirection() {
            return new Direction(337.5);
        }
    };

    /**
     * Gets the direction.
     */
    public abstract IDirection asDirection();
}
