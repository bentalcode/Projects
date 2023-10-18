cmake_minimum_required(VERSION 3.6)

project(DataStructuresTest VERSION 1.0)

set(CMAKE_CXX_STANDARD
    14
)
set(RESOURCES_DIRECTORY_NAME
    resources
)

#
# Configure build properties...
#
set(VERSION_MAJOR "1")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")


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
    set(BOOST_PATH "c:\\Boost\\boost_1_78_0")
endif()

add_compile_definitions(WINDOWS=1)


set(DATA_STRUCTURES_TEST_INCLUDES_FILES
    ./binarytree/interfaces/BinaryTreeData.h
    ./binarytree/interfaces/BinaryTreeTestData.h
    ./binarytree/interfaces/BinaryTreeTraversalBuilderUnitTest.h
    ./binarytree/interfaces/BinaryTreeUnitTest.h
    ./bitarray/interfaces/BitArrayData.h
    ./bitarray/interfaces/BitArrayTestData.h
    ./bitarray/interfaces/BitArrayUnitTest.h
    ./cache/interfaces/CacheTestData.h
    ./cache/interfaces/CacheUnitTest.h
    ./doublylinkedlist/interfaces/DoublyLinkedListData.h
    ./doublylinkedlist/interfaces/DoublyLinkedListTestData.h
    ./doublylinkedlist/interfaces/DoublyLinkedListUnitTest.h
    ./graph/interfaces/GraphData.h
    ./graph/interfaces/GraphTestData.h
    ./graph/interfaces/GraphUnitTest.h
    ./interfaces/IteratorOfIteratorCollectionUnitTest.h
    ./interfaces/TestData.h
    ./linkedlist/interfaces/LinkedListData.h
    ./linkedlist/interfaces/LinkedListTestData.h
    ./linkedlist/interfaces/LinkedListUnitTest.h
    ./priorityqueue/interfaces/PriorityQueueData.h
    ./priorityqueue/interfaces/PriorityQueueTestData.h
    ./priorityqueue/interfaces/PriorityQueueUnitTest.h
)

set(DATA_STRUCTURES_TEST_SOURCES_FILES
    ./binarytree/core/BinaryTreeTestData.cpp
    ./binarytree/core/BinaryTreeTraversalBuilderUnitTest.cpp
    ./binarytree/core/BinaryTreeUnitTest.cpp
    ./bitarray/core/BitArrayData.cpp
    ./bitarray/core/BitArrayTestData.cpp
    ./bitarray/core/BitArrayUnitTest.cpp
    ./cache/core/CacheTestData.cpp
    ./cache/core/CacheUnitTest.cpp
    ./core/IteratorOfIteratorCollectionUnitTest.cpp
    ./core/TestData.cpp
    ./doublylinkedlist/core/DoublyLinkedListTestData.cpp
    ./doublylinkedlist/core/DoublyLinkedListUnitTest.cpp
    ./graph/core/GraphTestData.cpp
    ./graph/core/GraphUnitTest.cpp
    ./linkedlist/core/LinkedListTestData.cpp
    ./linkedlist/core/LinkedListUnitTest.cpp
    ./main.cpp
    ./priorityqueue/core/PriorityQueueTestData.cpp
    ./priorityqueue/core/PriorityQueueUnitTest.cpp
)

set(DATA_STRUCTURES_TEST_INCLUDES
    ./binarytree/interfaces
    ./bitarray/interfaces
    ./cache/interfaces
    ./doublylinkedlist/interfaces
    ./graph/interfaces
    ./interfaces
    ./linkedlist/interfaces
    ./priorityqueue/interfaces
)

set(DATA_STRUCTURES_TEST_SOURCES
    ${DATA_STRUCTURES_TEST_INCLUDES_FILES}
    ${DATA_STRUCTURES_TEST_SOURCES_FILES}
)

set(BASE_INCLUDES_FILES
    ../Base/core/AlmostComparator.h
    ../Base/core/AndBitOperator.h
    ../Base/core/BaseException.h
    ../Base/core/BaseLogic.h
    ../Base/core/Bits.h
    ../Base/core/ClassType.h
    ../Base/core/ClassTypes.h
    ../Base/core/CollectionComparator.h
    ../Base/core/Collections.h
    ../Base/core/ComparableComparator.h
    ../Base/core/Comparator.h
    ../Base/core/ComparatorFactory.h
    ../Base/core/CompareToBuilder.h
    ../Base/core/ConsoleColorSetter.h
    ../Base/core/DereferenceComparableComparator.h
    ../Base/core/DereferenceComparableComparator2.h
    ../Base/core/DereferenceEquatableComparator.h
    ../Base/core/DereferenceEquatableComparator2.h
    ../Base/core/EqualBuilder.h
    ../Base/core/EquatableComparator.h
    ../Base/core/ErrorCodes.h
    ../Base/core/ErrorMessages.h
    ../Base/core/Indexes.h
    ../Base/core/Interval.h
    ../Base/core/IntervalMap.h
    ../Base/core/IntervalMapIterator.h
    ../Base/core/InvertComparator.h
    ../Base/core/IterableComparator.h
    ../Base/core/IterableObject.h
    ../Base/core/IteratorComparator.h
    ../Base/core/KmpStringSearch.h
    ../Base/core/List.h
    ../Base/core/ListIterator.h
    ../Base/core/ListReverseIterator.h
    ../Base/core/MapComparator.h
    ../Base/core/Matrix.h
    ../Base/core/MessageWriter.h
    ../Base/core/NotBitOperator.h
    ../Base/core/NotImplementedException.h
    ../Base/core/OrBitOperator.h
    ../Base/core/Pair.h
    ../Base/core/RandomGenerator.h
    ../Base/core/Range.h
    ../Base/core/ReferenceCounterHolder.h
    ../Base/core/SetIterator.h
    ../Base/core/SharedPtr.h
    ../Base/core/SkipIterator.h
    ../Base/core/Sorting.h
    ../Base/core/StringComparable.h
    ../Base/core/StringConversion.h
    ../Base/core/StringEquality.h
    ../Base/core/StringSearch.h
    ../Base/core/StringUtils.h
    ../Base/core/Strings.h
    ../Base/core/ToString.h
    ../Base/core/TwoDimensionalVector.h
    ../Base/core/TwoDimensionalVectorIterator.h
    ../Base/core/UnexpectedException.h
    ../Base/core/Uuid.h
    ../Base/core/VectorIterator.h
    ../Base/core/VectorReverseIterator.h
    ../Base/core/WindowsConsoleColorHandler.h
    ../Base/core/XorBitOperator.h
    ../Base/interfaces/ColorType.h
    ../Base/interfaces/Colors.h
    ../Base/interfaces/DateTime.h
    ../Base/interfaces/DateTimeInterval.h
    ../Base/interfaces/Duration.h
    ../Base/interfaces/IBinaryBitOperator.h
    ../Base/interfaces/IBinaryComparator.h
    ../Base/interfaces/IBitOperator.h
    ../Base/interfaces/IBuilder.h
    ../Base/interfaces/ICalculator.h
    ../Base/interfaces/IClassType.h
    ../Base/interfaces/IClone.h
    ../Base/interfaces/ICollection.h
    ../Base/interfaces/IComparableComparator.h
    ../Base/interfaces/IComparatorFactory.h
    ../Base/interfaces/IConsoleColorHandler.h
    ../Base/interfaces/IEquatableComparator.h
    ../Base/interfaces/IHashCodeProvider.h
    ../Base/interfaces/IIntervalMap.h
    ../Base/interfaces/IIterable.h
    ../Base/interfaces/IIterator.h
    ../Base/interfaces/IKeyIterable.h
    ../Base/interfaces/IKeyReverseIterable.h
    ../Base/interfaces/IList.h
    ../Base/interfaces/IMatch.h
    ../Base/interfaces/IMatrix.h
    ../Base/interfaces/IMessageWriter.h
    ../Base/interfaces/IRandomGenerator.h
    ../Base/interfaces/IResourceReader.h
    ../Base/interfaces/IReverseIterable.h
    ../Base/interfaces/IReverseIterator.h
    ../Base/interfaces/ISizableCollection.h
    ../Base/interfaces/ISkipIterator.h
    ../Base/interfaces/IStringConversion.h
    ../Base/interfaces/IToString.h
    ../Base/interfaces/ITwoDimensionalVector.h
    ../Base/interfaces/IUnaryBitOperator.h
    ../Base/interfaces/IUuid.h
    ../Base/interfaces/IValueIterable.h
    ../Base/interfaces/IValueReverseIterable.h
    ../Base/interfaces/IVisitor.h
    ../Base/interfaces/ReferenceCounter.h
    ../Base/interfaces/ReferenceCounterHolder.h
    ../Base/interfaces/SmartPointers.h
    ../Base/interfaces/StandardFileDescriptor.h
    ../Base/interfaces/StringComparisonType.h
    ../Base/interfaces/TimeUnit.h
    ../Base/interfaces/TimeUtils.h
)

set(BASE_SOURCES_FILES
    ../Base/core/AndBitOperator.cpp
    ../Base/core/Bits.cpp
    ../Base/core/ClassType.cpp
    ../Base/core/Collections.cpp
    ../Base/core/ComparatorFactory.cpp
    ../Base/core/CompareToBuilder.cpp
    ../Base/core/ConsoleColorSetter.cpp
    ../Base/core/DateTime.cpp
    ../Base/core/EqualBuilder.cpp
    ../Base/core/ErrorCodes.cpp
    ../Base/core/ErrorMessages.cpp
    ../Base/core/KmpStringSearch.cpp
    ../Base/core/MessageWriter.cpp
    ../Base/core/NotBitOperator.cpp
    ../Base/core/OrBitOperator.cpp
    ../Base/core/RandomGenerator.cpp
    ../Base/core/ReferenceCounter.cpp
    ../Base/core/SkipIterator.cpp
    ../Base/core/StringComparable.cpp
    ../Base/core/StringConversion.cpp
    ../Base/core/StringEquality.cpp
    ../Base/core/StringSearch.cpp
    ../Base/core/StringUtils.cpp
    ../Base/core/Strings.cpp
    ../Base/core/Tests.cpp
    ../Base/core/TimeUnit.cpp
    ../Base/core/TimeUtils.cpp
    ../Base/core/ToString.cpp
    ../Base/core/Uuid.cpp
    ../Base/core/WindowsConsoleColorHandler.cpp
    ../Base/core/XorBitOperator.cpp
)

set(BASE_INCLUDES
    ../Base/core
    ../Base/interfaces
)

set(BASE_SOURCES
    ${BASE_INCLUDES_FILES}
    ${BASE_SOURCES_FILES}
)

add_library(Base STATIC
    ${BASE_SOURCES}
)

set(TEST_BASE_INCLUDES_FILES
    ../TestBase/core/TestBaseException.h
    ../TestBase/interfaces/Assertion.h
    ../TestBase/interfaces/IterationTest.h
    ../TestBase/interfaces/ResourcePaths.h
)

set(TEST_BASE_SOURCES_FILES
    ../TestBase/core/Assertion.cpp
    ../TestBase/core/IterationTest.cpp
)

set(TEST_BASE_INCLUDES
    ../TestBase/core
    ../TestBase/interfaces
)

set(TEST_BASE_SOURCES
    ${TEST_BASE_INCLUDES_FILES}
    ${TEST_BASE_SOURCES_FILES}
)

add_library(TestBase STATIC
    ${BASE_SOURCES}
    ${TEST_BASE_SOURCES}
)

set(UNIT_TESTING_INCLUDES_FILES
    ../UnitTesting/core/TestRunningResult.h
    ../UnitTesting/core/TestRunningResults.h
    ../UnitTesting/core/UnitTestFunction.h
    ../UnitTesting/core/UnitTestHandler.h
    ../UnitTesting/core/UnitTestManager.h
    ../UnitTesting/core/UnitTestingConsts.h
    ../UnitTesting/core/UnitTestingException.h
    ../UnitTesting/interfaces/ITestFunction.h
    ../UnitTesting/interfaces/ITestRegistration.h
    ../UnitTesting/interfaces/ITestRunningResult.h
    ../UnitTesting/interfaces/ITestRunningResults.h
    ../UnitTesting/interfaces/IUnitTest.h
    ../UnitTesting/interfaces/IUnitTestHandler.h
    ../UnitTesting/interfaces/IUnitTestManager.h
    ../UnitTesting/interfaces/UnitTestBase.h
    ../UnitTesting/interfaces/UnitTestException.h
)

set(UNIT_TESTING_SOURCES_FILES
    ../UnitTesting/core/TestRunningResult.cpp
    ../UnitTesting/core/TestRunningResults.cpp
    ../UnitTesting/core/UnitTestBase.cpp
    ../UnitTesting/core/UnitTestHandler.cpp
    ../UnitTesting/core/UnitTestManager.cpp
    ../UnitTesting/core/UnitTestingConsts.cpp
)

set(UNIT_TESTING_INCLUDES
    ../UnitTesting/core
    ../UnitTesting/interfaces
)

set(UNIT_TESTING_SOURCES
    ${UNIT_TESTING_INCLUDES_FILES}
    ${UNIT_TESTING_SOURCES_FILES}
)

add_library(UnitTesting STATIC
    ${BASE_SOURCES}
    ${TEST_BASE_SOURCES}
    ${UNIT_TESTING_SOURCES}
)

set(DATA_STRUCTURES_INCLUDES_FILES
    ../DataStructures/binarytree/BinaryTreeException.h
    ../DataStructures/binarytree/core/BinaryTree.h
    ../DataStructures/binarytree/core/BinaryTreeEndNode.h
    ../DataStructures/binarytree/core/BinaryTreeInorderIterator.h
    ../DataStructures/binarytree/core/BinaryTreeInorderReverseIterator.h
    ../DataStructures/binarytree/core/BinaryTreeLevelOrderIterator.h
    ../DataStructures/binarytree/core/BinaryTreeLevelOrderWithEndNodesIterator.h
    ../DataStructures/binarytree/core/BinaryTreeLogic.h
    ../DataStructures/binarytree/core/BinaryTreeNode.h
    ../DataStructures/binarytree/core/BinaryTreeNodeListIterator.h
    ../DataStructures/binarytree/core/BinaryTreeNodeListReverseIterator.h
    ../DataStructures/binarytree/core/BinaryTreeNodes.h
    ../DataStructures/binarytree/core/BinaryTreePostorderIterator.h
    ../DataStructures/binarytree/core/BinaryTreePreorderInorderTraversalBuilder.h
    ../DataStructures/binarytree/core/BinaryTreePreorderIterator.h
    ../DataStructures/binarytree/core/BinaryTreePreorderPostorderTraversalBuilder.h
    ../DataStructures/binarytree/core/BinaryTreeStreamBuilder.h
    ../DataStructures/binarytree/core/BinaryTreeTraversalBuilder.h
    ../DataStructures/binarytree/core/BinaryTreeTraversalsBuilder.h
    ../DataStructures/binarytree/interfaces/IBinaryTree.h
    ../DataStructures/binarytree/interfaces/IBinaryTreeLogic.h
    ../DataStructures/binarytree/interfaces/IBinaryTreeNode.h
    ../DataStructures/binarytree/interfaces/IBinaryTreeNodeIterator.h
    ../DataStructures/binarytree/interfaces/IBinaryTreeNodeReverseIterator.h
    ../DataStructures/binarytree/interfaces/IBinaryTreeTraversal.h
    ../DataStructures/bitarray/BitArrayException.h
    ../DataStructures/bitarray/core/Bit32Array.h
    ../DataStructures/bitarray/core/Bit32ArrayIterator.h
    ../DataStructures/bitarray/core/Bit32ArrayReverseIterator.h
    ../DataStructures/bitarray/core/BitArray.h
    ../DataStructures/bitarray/core/BitArrayIterator.h
    ../DataStructures/bitarray/core/BitArrayReverseIterator.h
    ../DataStructures/bitarray/interfaces/IBit32Array.h
    ../DataStructures/bitarray/interfaces/IBitArray.h
    ../DataStructures/cache/CacheException.h
    ../DataStructures/cache/core/AbstractCache.h
    ../DataStructures/cache/core/CacheProperties.h
    ../DataStructures/cache/interfaces/ICache.h
    ../DataStructures/cache/interfaces/ICacheProperties.h
    ../DataStructures/cache/interfaces/LRUCache.h
    ../DataStructures/cache/interfaces/MRUCache.h
    ../DataStructures/core/DataStructureException.h
    ../DataStructures/doublylinkedlist/DoublyLinkedListException.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedList.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListKeyValueNodeIterator.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListKeyValueNodeReverseIterator.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListNode.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListNodeIterator.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListNodeReverseIterator.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListNodeValueIterator.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListNodeValueReverseIterator.h
    ../DataStructures/doublylinkedlist/interfaces/IDoublyLinkedList.h
    ../DataStructures/doublylinkedlist/interfaces/IDoublyLinkedListNode.h
    ../DataStructures/graph/GraphException.h
    ../DataStructures/graph/core/AdjacencyMatrix.h
    ../DataStructures/graph/core/Edge.h
    ../DataStructures/graph/core/Graph.h
    ../DataStructures/graph/core/GraphBuilder.h
    ../DataStructures/graph/core/GraphDefinition.h
    ../DataStructures/graph/core/GraphLogic.h
    ../DataStructures/graph/core/Route.h
    ../DataStructures/graph/core/Vertex.h
    ../DataStructures/graph/core/Walk.h
    ../DataStructures/graph/interfaces/IAdjacencyMatrix.h
    ../DataStructures/graph/interfaces/IEdge.h
    ../DataStructures/graph/interfaces/IGraph.h
    ../DataStructures/graph/interfaces/IGraphBuilder.h
    ../DataStructures/graph/interfaces/IGraphDefinition.h
    ../DataStructures/graph/interfaces/IGraphLogic.h
    ../DataStructures/graph/interfaces/IGraphTraversal.h
    ../DataStructures/graph/interfaces/IPathFinder.h
    ../DataStructures/graph/interfaces/IRoute.h
    ../DataStructures/graph/interfaces/IVertex.h
    ../DataStructures/graph/interfaces/IWalk.h
    ../DataStructures/interfaces/IteratorOfIteratorCollection.h
    ../DataStructures/linkedlist/LinkedListException.h
    ../DataStructures/linkedlist/core/LinkedList.h
    ../DataStructures/linkedlist/core/LinkedListNode.h
    ../DataStructures/linkedlist/core/LinkedListNodeIterator.h
    ../DataStructures/linkedlist/core/LinkedListNodeValueIterator.h
    ../DataStructures/linkedlist/interfaces/ILinkedList.h
    ../DataStructures/linkedlist/interfaces/ILinkedListNode.h
    ../DataStructures/node/NodeException.h
    ../DataStructures/node/core/KeyIterator.h
    ../DataStructures/node/core/KeyReverseIterator.h
    ../DataStructures/node/core/KeyValueNode.h
    ../DataStructures/node/core/ValueIterator.h
    ../DataStructures/node/core/ValueReverseIterator.h
    ../DataStructures/node/interfaces/IKeyValueNode.h
    ../DataStructures/priorityqueue/PriorityQueueException.h
    ../DataStructures/priorityqueue/core/AbstractPriorityQueue.h
    ../DataStructures/priorityqueue/core/PriorityQueue.h
    ../DataStructures/priorityqueue/interfaces/IPriorityQueue.h
)

set(DATA_STRUCTURES_SOURCES_FILES
    ../DataStructures/bitarray/core/Bit32Array.cpp
    ../DataStructures/bitarray/core/Bit32ArrayIterator.cpp
    ../DataStructures/bitarray/core/Bit32ArrayReverseIterator.cpp
    ../DataStructures/bitarray/core/BitArray.cpp
    ../DataStructures/bitarray/core/BitArrayIterator.cpp
    ../DataStructures/bitarray/core/BitArrayReverseIterator.cpp
    ../DataStructures/cache/core/CacheProperties.cpp
)

set(DATA_STRUCTURES_INCLUDES
    ../DataStructures/binarytree
    ../DataStructures/binarytree/core
    ../DataStructures/binarytree/interfaces
    ../DataStructures/bitarray
    ../DataStructures/bitarray/core
    ../DataStructures/bitarray/interfaces
    ../DataStructures/cache
    ../DataStructures/cache/core
    ../DataStructures/cache/interfaces
    ../DataStructures/core
    ../DataStructures/doublylinkedlist
    ../DataStructures/doublylinkedlist/core
    ../DataStructures/doublylinkedlist/interfaces
    ../DataStructures/graph
    ../DataStructures/graph/core
    ../DataStructures/graph/interfaces
    ../DataStructures/interfaces
    ../DataStructures/linkedlist
    ../DataStructures/linkedlist/core
    ../DataStructures/linkedlist/interfaces
    ../DataStructures/node
    ../DataStructures/node/core
    ../DataStructures/node/interfaces
    ../DataStructures/priorityqueue
    ../DataStructures/priorityqueue/core
    ../DataStructures/priorityqueue/interfaces
)

set(DATA_STRUCTURES_SOURCES
    ${DATA_STRUCTURES_INCLUDES_FILES}
    ${DATA_STRUCTURES_SOURCES_FILES}
)

add_library(DataStructures STATIC
    ${BASE_SOURCES}
    ${DATA_STRUCTURES_SOURCES}
)

include_directories(DataStructuresTest
    ${BASE_INCLUDES}
    ${DATA_STRUCTURES_INCLUDES}
    ${DATA_STRUCTURES_TEST_INCLUDES}
    ${TEST_BASE_INCLUDES}
    ${UNIT_TESTING_INCLUDES}
)

add_executable(DataStructuresTest
    ${BASE_SOURCES}
    ${DATA_STRUCTURES_SOURCES}
    ${DATA_STRUCTURES_TEST_SOURCES}
    ${TEST_BASE_SOURCES}
    ${UNIT_TESTING_SOURCES}
)

target_link_libraries(DataStructuresTest
    PRIVATE Base TestBase UnitTesting DataStructures
)

include_directories(
    ${BOOST_PATH}
)
