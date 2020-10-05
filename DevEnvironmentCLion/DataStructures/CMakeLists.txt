cmake_minimum_required(VERSION 3.13)

project(DataStructures VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

print_all_variables()

#
# Configure boost library...
#
if (NOT $ENV{BOOST_ROOT})
    set(BOOST_PATH $ENV{BOOST_ROOT})
else()
    set(BOOST_PATH "c:\\Boost\\boost_1_70_0")
endif()

set(DATA_STRUCTURES_INCLUDES_FILES
    ./DataStructureException.h
    ./binarytree/BinaryTreeException.h
    ./binarytree/core/BinaryTree.h
    ./binarytree/core/BinaryTreeEndNode.h
    ./binarytree/core/BinaryTreeInorderIterator.h
    ./binarytree/core/BinaryTreeInorderReverseIterator.h
    ./binarytree/core/BinaryTreeLevelOrderIterator.h
    ./binarytree/core/BinaryTreeLevelOrderWithEndNodesIterator.h
    ./binarytree/core/BinaryTreeLogic.h
    ./binarytree/core/BinaryTreeNode.h
    ./binarytree/core/BinaryTreeNodeListIterator.h
    ./binarytree/core/BinaryTreeNodeListReverseIterator.h
    ./binarytree/core/BinaryTreeNodes.h
    ./binarytree/core/BinaryTreePostorderIterator.h
    ./binarytree/core/BinaryTreePreorderInorderTraversalBuilder.h
    ./binarytree/core/BinaryTreePreorderIterator.h
    ./binarytree/core/BinaryTreePreorderPostorderTraversalBuilder.h
    ./binarytree/core/BinaryTreeStreamBuilder.h
    ./binarytree/core/BinaryTreeTraversalBuilder.h
    ./binarytree/core/BinaryTreeTraversalsBuilder.h
    ./binarytree/interfaces/IBinaryTree.h
    ./binarytree/interfaces/IBinaryTreeLogic.h
    ./binarytree/interfaces/IBinaryTreeNode.h
    ./binarytree/interfaces/IBinaryTreeNodeIterator.h
    ./binarytree/interfaces/IBinaryTreeNodeReverseIterator.h
    ./binarytree/interfaces/IBinaryTreeTraversal.h
    ./bitarray/BitArrayException.h
    ./bitarray/core/Bit32Array.h
    ./bitarray/core/Bit32ArrayIterator.h
    ./bitarray/core/Bit32ArrayReverseIterator.h
    ./bitarray/core/BitArray.h
    ./bitarray/core/BitArrayIterator.h
    ./bitarray/core/BitArrayReverseIterator.h
    ./bitarray/interfaces/IBit32Array.h
    ./bitarray/interfaces/IBitArray.h
    ./core/PreCompiled.h
    ./doublylinkedlist/DoublyLinkedListException.h
    ./doublylinkedlist/core/DoublyLinkedList.h
    ./doublylinkedlist/core/DoublyLinkedListNode.h
    ./doublylinkedlist/core/DoublyLinkedListNodeIterator.h
    ./doublylinkedlist/core/DoublyLinkedListNodeReverseIterator.h
    ./doublylinkedlist/core/DoublyLinkedListNodeValueIterator.h
    ./doublylinkedlist/core/DoublyLinkedListNodeValueReverseIterator.h
    ./doublylinkedlist/interfaces/IDoublyLinkedList.h
    ./doublylinkedlist/interfaces/IDoublyLinkedListNode.h
    ./interfaces/IteratorOfIteratorCollection.h
    ./linkedlist/LinkedListException.h
    ./linkedlist/core/LinkedList.h
    ./linkedlist/core/LinkedListNode.h
    ./linkedlist/core/LinkedListNodeIterator.h
    ./linkedlist/core/LinkedListNodeValueIterator.h
    ./linkedlist/interfaces/ILinkedList.h
    ./linkedlist/interfaces/ILinkedListNode.h
    ./priorityqueue/PriorityQueueException.h
    ./priorityqueue/core/AbstractPriorityQueue.h
    ./priorityqueue/core/PriorityQueue.h
    ./priorityqueue/interfaces/IPriorityQueue.h
)

set(DATA_STRUCTURES_SOURCES_FILES
    ./bitarray/core/Bit32Array.cpp
    ./bitarray/core/Bit32ArrayIterator.cpp
    ./bitarray/core/Bit32ArrayReverseIterator.cpp
    ./bitarray/core/BitArray.cpp
    ./bitarray/core/BitArrayIterator.cpp
    ./bitarray/core/BitArrayReverseIterator.cpp
    ./core/PreCompiled.cpp
)

set(DATA_STRUCTURES_SOURCES
    ${DATA_STRUCTURES_INCLUDES_FILES}
    ${DATA_STRUCTURES_SOURCES_FILES}
)

set(DATA_STRUCTURES_INCLUDES
    .
    ./binarytree
    ./binarytree/core
    ./binarytree/interfaces
    ./bitarray
    ./bitarray/core
    ./bitarray/interfaces
    ./core
    ./doublylinkedlist
    ./doublylinkedlist/core
    ./doublylinkedlist/interfaces
    ./interfaces
    ./linkedlist
    ./linkedlist/core
    ./linkedlist/interfaces
    ./priorityqueue
    ./priorityqueue/core
    ./priorityqueue/interfaces
)

set(BASE_INCLUDES_FILES
    ../Base/BaseException.h
    ../Base/NotImplementedException.h
    ../Base/core/AndBitOperator.h
    ../Base/core/BaseDependencies.h
    ../Base/core/BaseLogic.h
    ../Base/core/ClassType.h
    ../Base/core/ComparableComparator.h
    ../Base/core/Comparator.h
    ../Base/core/DereferenceComparableComparator.h
    ../Base/core/DereferenceComparableComparator2.h
    ../Base/core/DereferenceEquatableComparator.h
    ../Base/core/DereferenceEquatableComparator2.h
    ../Base/core/EquatableComparator.h
    ../Base/core/IntervalMap.h
    ../Base/core/IntervalMapIterator.h
    ../Base/core/InvertComparator.h
    ../Base/core/IterableObject.h
    ../Base/core/KmpStringSearch.h
    ../Base/core/List.h
    ../Base/core/ListIterator.h
    ../Base/core/ListReverseIterator.h
    ../Base/core/Matrix.h
    ../Base/core/NotBitOperator.h
    ../Base/core/OrBitOperator.h
    ../Base/core/Position.h
    ../Base/core/PreCompiled.h
    ../Base/core/ReferenceCount.h
    ../Base/core/ReferenceCountHolder.h
    ../Base/core/SkipIterator.h
    ../Base/core/StringIterator.h
    ../Base/core/TwoDimensionalList.h
    ../Base/core/TwoDimensionalListIterator.h
    ../Base/core/TwoDimensionalVector.h
    ../Base/core/VectorIterator.h
    ../Base/core/VectorReverseIterator.h
    ../Base/core/XorBitOperator.h
    ../Base/interfaces/Bits.h
    ../Base/interfaces/ClassTypes.h
    ../Base/interfaces/ComparatorFactory.h
    ../Base/interfaces/CompareToBuilder.h
    ../Base/interfaces/DateTime.h
    ../Base/interfaces/Dimensions.h
    ../Base/interfaces/Duration.h
    ../Base/interfaces/EqualBuilder.h
    ../Base/interfaces/IBinaryBitOperator.h
    ../Base/interfaces/IBinaryComparator.h
    ../Base/interfaces/IBitOperator.h
    ../Base/interfaces/IBuilder.h
    ../Base/interfaces/ICalculator.h
    ../Base/interfaces/IClassType.h
    ../Base/interfaces/ICollection.h
    ../Base/interfaces/IComparableComparator.h
    ../Base/interfaces/IEquatableComparator.h
    ../Base/interfaces/IFinder.h
    ../Base/interfaces/IHashCodeProvider.h
    ../Base/interfaces/IIntervalMap.h
    ../Base/interfaces/IIterable.h
    ../Base/interfaces/IIterator.h
    ../Base/interfaces/IList.h
    ../Base/interfaces/IMatch.h
    ../Base/interfaces/IMatrix.h
    ../Base/interfaces/IReverseIterable.h
    ../Base/interfaces/IReverseIterator.h
    ../Base/interfaces/ISizableCollection.h
    ../Base/interfaces/ISkipIterator.h
    ../Base/interfaces/ITwoDimensionalList.h
    ../Base/interfaces/ITwoDimensionalVector.h
    ../Base/interfaces/IUnaryBitOperator.h
    ../Base/interfaces/IValidator.h
    ../Base/interfaces/IValueIterable.h
    ../Base/interfaces/IValueReverseIterable.h
    ../Base/interfaces/IVisitor.h
    ../Base/interfaces/Indexes.h
    ../Base/interfaces/Interval.h
    ../Base/interfaces/Intervals.h
    ../Base/interfaces/IterableComparator.h
    ../Base/interfaces/IteratorComparator.h
    ../Base/interfaces/LogStreamWriter.h
    ../Base/interfaces/Pair.h
    ../Base/interfaces/SharedPtr.h
    ../Base/interfaces/StringComparable.h
    ../Base/interfaces/StringEquality.h
    ../Base/interfaces/StringSearch.h
    ../Base/interfaces/Strings.h
    ../Base/interfaces/Triple.h
)

set(BASE_SOURCES_FILES
    ../Base/core/AndBitOperator.cpp
    ../Base/core/Bits.cpp
    ../Base/core/ClassType.cpp
    ../Base/core/CompareToBuilder.cpp
    ../Base/core/DateTime.cpp
    ../Base/core/EqualBuilder.cpp
    ../Base/core/Indexes.cpp
    ../Base/core/KmpStringSearch.cpp
    ../Base/core/LogStreamWriter.cpp
    ../Base/core/NotBitOperator.cpp
    ../Base/core/OrBitOperator.cpp
    ../Base/core/Position.cpp
    ../Base/core/PreCompiled.cpp
    ../Base/core/SkipIterator.cpp
    ../Base/core/StringComparable.cpp
    ../Base/core/StringEquality.cpp
    ../Base/core/StringSearch.cpp
    ../Base/core/Strings.cpp
    ../Base/core/XorBitOperator.cpp
)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES}
)

set(BASE_INCLUDES
    ../Base
    ../Base/core
    ../Base/interfaces
)

add_library(Base STATIC
    ${BASE_SOURCES}
)

include_directories(DataStructures
    ${BASE_INCLUDES}
    ${DATA_STRUCTURES_INCLUDES}
)

add_library(DataStructures STATIC
    ${BASE_SOURCES}
    ${DATA_STRUCTURES_SOURCES}
)

include_directories(
    ${BOOST_PATH}
)
