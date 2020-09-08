cmake_minimum_required(VERSION 3.13)

project(DataStructuresTest VERSION 1.0)

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

set(DATA_STRUCTURES_TEST_INCLUDES_FILES
    ./binarytree/interfaces/BinaryTreeData.h
    ./binarytree/interfaces/BinaryTreeTestData.h
    ./binarytree/interfaces/BinaryTreeUnitTest.h
    ./bitarray/interfaces/BitArrayData.h
    ./bitarray/interfaces/BitArrayTestData.h
    ./bitarray/interfaces/BitArrayUnitTest.h
    ./core/PreCompiled.h
    ./doublylinkedlist/interfaces/DoublyLinkedListData.h
    ./doublylinkedlist/interfaces/DoublyLinkedListTestData.h
    ./doublylinkedlist/interfaces/DoublyLinkedListUnitTest.h
    ./interfaces/IteratorOfIteratorCollectionUnitTest.h
    ./interfaces/TestData.h
    ./linkedlist/interfaces/LinkedListData.h
    ./linkedlist/interfaces/LinkedListTestData.h
    ./linkedlist/interfaces/LinkedListUnitTest.h
)

set(DATA_STRUCTURES_TEST_SOURCES_FILES
    ./binarytree/core/BinaryTreeTestData.cpp
    ./binarytree/core/BinaryTreeUnitTest.cpp
    ./bitarray/core/BitArrayData.cpp
    ./bitarray/core/BitArrayTestData.cpp
    ./bitarray/core/BitArrayUnitTest.cpp
    ./core/IteratorOfIteratorCollectionUnitTest.cpp
    ./core/PreCompiled.cpp
    ./core/TestData.cpp
    ./doublylinkedlist/core/DoublyLinkedListTestData.cpp
    ./doublylinkedlist/core/DoublyLinkedListUnitTest.cpp
    ./linkedlist/core/LinkedListTestData.cpp
    ./linkedlist/core/LinkedListUnitTest.cpp
    ./main.cpp
)

set(DATA_STRUCTURES_TEST_SOURCES
    ${DATA_STRUCTURES_TEST_INCLUDES_FILES}
    ${DATA_STRUCTURES_TEST_SOURCES_FILES}
)

set(DATA_STRUCTURES_TEST_INCLUDES
    ./binarytree/interfaces
    ./bitarray/interfaces
    ./core
    ./doublylinkedlist/interfaces
    ./interfaces
    ./linkedlist/interfaces
)

set(BASE_INCLUDES_FILES
    ../Base/BaseException.h
    ../Base/NotImplementedException.h
    ../Base/core/AndBitOperator.h
    ../Base/core/BaseDependencies.h
    ../Base/core/BaseLogic.h
    ../Base/core/ClassType.h
    ../Base/core/ComparableComparator.h
    ../Base/core/DereferenceComparableComparator.h
    ../Base/core/DereferenceComparableComparator2.h
    ../Base/core/DereferenceEquatableComparator.h
    ../Base/core/DereferenceEquatableComparator2.h
    ../Base/core/EquatableComparator.h
    ../Base/core/IntervalMap.h
    ../Base/core/IntervalMapIterator.h
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
    ../Base/interfaces/IMatrix.h
    ../Base/interfaces/IReverseIterable.h
    ../Base/interfaces/IReverseIterator.h
    ../Base/interfaces/ISizableCollection.h
    ../Base/interfaces/ISkipIterator.h
    ../Base/interfaces/ITwoDimensionalList.h
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

set(TEST_BASE_INCLUDES_FILES
    ../TestBase/TestBaseException.h
    ../TestBase/core/PreCompiled.h
    ../TestBase/interfaces/Assertion.h
    ../TestBase/interfaces/IterationTest.h
)

set(TEST_BASE_SOURCES_FILES
    ../TestBase/core/Assertion.cpp
    ../TestBase/core/IterationTest.cpp
    ../TestBase/core/PreCompiled.cpp
)

set(TEST_BASE_SOURCES
    ${TEST_BASE_INCLUDES_FILES}
    ${TEST_BASE_SOURCES_FILES}
)

set(TEST_BASE_INCLUDES
    ../TestBase
    ../TestBase/core
    ../TestBase/interfaces
)

add_library(TestBase STATIC
    ${BASE_SOURCES}
    ${TEST_BASE_SOURCES}
)

set(UNIT_TESTING_INCLUDES_FILES
    ../UnitTesting/UnitTestingException.h
    ../UnitTesting/core/PreCompiled.h
    ../UnitTesting/core/TestRunningResult.h
    ../UnitTesting/core/TestRunningResults.h
    ../UnitTesting/core/UnitTestFunction.h
    ../UnitTesting/core/UnitTestHandler.h
    ../UnitTesting/core/UnitTestManager.h
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
    ../UnitTesting/core/PreCompiled.cpp
    ../UnitTesting/core/TestRunningResult.cpp
    ../UnitTesting/core/TestRunningResults.cpp
    ../UnitTesting/core/UnitTestBase.cpp
    ../UnitTesting/core/UnitTestHandler.cpp
    ../UnitTesting/core/UnitTestManager.cpp
)

set(UNIT_TESTING_SOURCES
    ${UNIT_TESTING_INCLUDES_FILES}
    ${UNIT_TESTING_SOURCES_FILES}
)

set(UNIT_TESTING_INCLUDES
    ../UnitTesting
    ../UnitTesting/core
    ../UnitTesting/interfaces
)

add_library(UnitTesting STATIC
    ${BASE_SOURCES}
    ${TEST_BASE_SOURCES}
    ${UNIT_TESTING_SOURCES}
)

set(DATA_STRUCTURES_INCLUDES_FILES
    ../DataStructures/DataStructureException.h
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
    ../DataStructures/binarytree/core/BinaryTreePreorderIterator.h
    ../DataStructures/binarytree/core/BinaryTreeStreamBuilder.h
    ../DataStructures/binarytree/interfaces/IBinaryTree.h
    ../DataStructures/binarytree/interfaces/IBinaryTreeLogic.h
    ../DataStructures/binarytree/interfaces/IBinaryTreeNode.h
    ../DataStructures/binarytree/interfaces/IBinaryTreeNodeIterator.h
    ../DataStructures/binarytree/interfaces/IBinaryTreeNodeReverseIterator.h
    ../DataStructures/binarytree/interfaces/IBinaryTreeTraversal.h
    ../DataStructures/bitarray/core/Bit32Array.h
    ../DataStructures/bitarray/core/Bit32ArrayIterator.h
    ../DataStructures/bitarray/core/Bit32ArrayReverseIterator.h
    ../DataStructures/bitarray/core/BitArray.h
    ../DataStructures/bitarray/core/BitArrayException.h
    ../DataStructures/bitarray/interfaces/IBit32Array.h
    ../DataStructures/bitarray/interfaces/IBitArray.h
    ../DataStructures/core/PreCompiled.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedList.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListException.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListNode.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListNodeIterator.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListNodeReverseIterator.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListNodeValueIterator.h
    ../DataStructures/doublylinkedlist/core/DoublyLinkedListNodeValueReverseIterator.h
    ../DataStructures/doublylinkedlist/interfaces/IDoublyLinkedList.h
    ../DataStructures/doublylinkedlist/interfaces/IDoublyLinkedListNode.h
    ../DataStructures/interfaces/IteratorOfIteratorCollection.h
    ../DataStructures/linkedlist/core/LinkedList.h
    ../DataStructures/linkedlist/core/LinkedListException.h
    ../DataStructures/linkedlist/core/LinkedListNode.h
    ../DataStructures/linkedlist/core/LinkedListNodeIterator.h
    ../DataStructures/linkedlist/core/LinkedListNodeValueIterator.h
    ../DataStructures/linkedlist/interfaces/ILinkedList.h
    ../DataStructures/linkedlist/interfaces/ILinkedListNode.h
)

set(DATA_STRUCTURES_SOURCES_FILES
    ../DataStructures/bitarray/core/Bit32Array.cpp
    ../DataStructures/bitarray/core/Bit32ArrayIterator.cpp
    ../DataStructures/bitarray/core/Bit32ArrayReverseIterator.cpp
    ../DataStructures/core/PreCompiled.cpp
)

set(DATA_STRUCTURES_SOURCES
    ${DATA_STRUCTURES_INCLUDES_FILES}
    ${DATA_STRUCTURES_SOURCES_FILES}
)

set(DATA_STRUCTURES_INCLUDES
    ../DataStructures
    ../DataStructures/binarytree/core
    ../DataStructures/binarytree/interfaces
    ../DataStructures/bitarray/core
    ../DataStructures/bitarray/interfaces
    ../DataStructures/core
    ../DataStructures/doublylinkedlist/core
    ../DataStructures/doublylinkedlist/interfaces
    ../DataStructures/interfaces
    ../DataStructures/linkedlist/core
    ../DataStructures/linkedlist/interfaces
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
