#include "PreCompiled.h"

#include "BinaryTreeTestData.h"
#include "BinaryTreeData.h"
#include "BinaryTreeNode.h"
#include "BinaryTreeNodes.h"

using namespace test::datastructures;
using namespace test::datastructures::binarytree;

/**
 * The BinaryTreeTestData constructor.
 */
BinaryTreeTestData::BinaryTreeTestData()
{
}

/**
 * The BinaryTreeTestData constructor.
 */
BinaryTreeTestData::~BinaryTreeTestData()
{
}

/**
 * Gets the data of the trees.
 */
std::vector<BinaryTreeDataPtr<int, std::string>> BinaryTreeTestData::getData() const {
    std::vector<BinaryTreeDataPtr<int, std::string>> data;

    data.push_back(getTreeData1());
    data.push_back(getTreeData2());
    data.push_back(getTreeData3());
    data.push_back(getTreeData4());

    return data;
}

/**
 * Gets the data of tree1.
 */
BinaryTreeDataPtr<int, std::string> BinaryTreeTestData::getTreeData1() const {
    std::vector<IBinaryTreeNodePtr<int, std::string>> creationData;
    std::vector<IBinaryTreeNodePtr<int, std::string>> levelOrder;
    std::vector<IBinaryTreeNodePtr<int, std::string>> inorder;
    std::vector<IBinaryTreeNodePtr<int, std::string>> preorder;
    std::vector<IBinaryTreeNodePtr<int, std::string>> postorder;

    return BinaryTreeDataPtr<int, std::string>(
        new BinaryTreeData<int, std::string>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder));
}

/**
 * Gets the data of tree2.
 */
BinaryTreeDataPtr<int, std::string> BinaryTreeTestData::getTreeData2() const {
    std::vector<IBinaryTreeNodePtr<int, std::string>> creationData = {BinaryTreeNodes::nodePtr<int, std::string>(1, "a")};
    std::vector<IBinaryTreeNodePtr<int, std::string>> levelOrder = {BinaryTreeNodes::nodePtr<int, std::string>(1, "a")};
    std::vector<IBinaryTreeNodePtr<int, std::string>> inorder = {BinaryTreeNodes::nodePtr<int, std::string>(1, "a")};
    std::vector<IBinaryTreeNodePtr<int, std::string>> preorder = {BinaryTreeNodes::nodePtr<int, std::string>(1, "a")};
    std::vector<IBinaryTreeNodePtr<int, std::string>> postorder = {BinaryTreeNodes::nodePtr<int, std::string>(1, "a")};

    return BinaryTreeDataPtr<int, std::string>(
        new BinaryTreeData<int, std::string>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder));
}

/**
 * Gets the data of tree3.
 */
BinaryTreeDataPtr<int, std::string> BinaryTreeTestData::getTreeData3() const {
    std::vector<IBinaryTreeNodePtr<int, std::string>> creationData;

    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(1, "a"));
    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(2, "b"));
    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(3, "c"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(4, "d"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(5, "e"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());

    std::vector<IBinaryTreeNodePtr<int, std::string>> levelOrder = {
        BinaryTreeNodes::nodePtr<int, std::string>(1, "a"),
        BinaryTreeNodes::nodePtr<int, std::string>(2, "b"),
        BinaryTreeNodes::nodePtr<int, std::string>(5, "e"),
        BinaryTreeNodes::nodePtr<int, std::string>(3, "c"),
        BinaryTreeNodes::nodePtr<int, std::string>(4, "d")
    };

    std::vector<IBinaryTreeNodePtr<int, std::string>> inorder = {
        BinaryTreeNodes::nodePtr<int, std::string>(3, "c"),
        BinaryTreeNodes::nodePtr<int, std::string>(2, "b"),
        BinaryTreeNodes::nodePtr<int, std::string>(4, "d"),
        BinaryTreeNodes::nodePtr<int, std::string>(1, "a"),
        BinaryTreeNodes::nodePtr<int, std::string>(5, "e")
    };

    std::vector<IBinaryTreeNodePtr<int, std::string>> preorder = {
        BinaryTreeNodes::nodePtr<int, std::string>(1, "a"),
        BinaryTreeNodes::nodePtr<int, std::string>(2, "b"),
        BinaryTreeNodes::nodePtr<int, std::string>(3, "c"),
        BinaryTreeNodes::nodePtr<int, std::string>(4, "d"),
        BinaryTreeNodes::nodePtr<int, std::string>(5, "e")
    };

    std::vector<IBinaryTreeNodePtr<int, std::string>> postorder = {
        BinaryTreeNodes::nodePtr<int, std::string>(3, "c"),
        BinaryTreeNodes::nodePtr<int, std::string>(4, "d"),
        BinaryTreeNodes::nodePtr<int, std::string>(2, "b"),
        BinaryTreeNodes::nodePtr<int, std::string>(5, "e"),
        BinaryTreeNodes::nodePtr<int, std::string>(1, "a")
    };

    return BinaryTreeDataPtr<int, std::string>(
        new BinaryTreeData<int, std::string>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder));
}

/**
 * Gets the data of tree4.
 */
BinaryTreeDataPtr<int, std::string> BinaryTreeTestData::getTreeData4() const {
    std::vector<IBinaryTreeNodePtr<int, std::string>> creationData;

    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(1, "a"));
    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(2, "b"));
    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(4, "d"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(5, "e"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(3, "c"));
    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(6, "f"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::nodePtr<int, std::string>(7, "h"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());

    std::vector<IBinaryTreeNodePtr<int, std::string>> levelOrder = {
        BinaryTreeNodes::nodePtr<int, std::string>(1, "a"),
        BinaryTreeNodes::nodePtr<int, std::string>(2, "b"),
        BinaryTreeNodes::nodePtr<int, std::string>(3, "c"),
        BinaryTreeNodes::nodePtr<int, std::string>(4, "d"),
        BinaryTreeNodes::nodePtr<int, std::string>(5, "e"),
        BinaryTreeNodes::nodePtr<int, std::string>(6, "f"),
        BinaryTreeNodes::nodePtr<int, std::string>(7, "h")
    };

    std::vector<IBinaryTreeNodePtr<int, std::string>> inorder = {
        BinaryTreeNodes::nodePtr<int, std::string>(4, "d"),
        BinaryTreeNodes::nodePtr<int, std::string>(2, "b"),
        BinaryTreeNodes::nodePtr<int, std::string>(5, "e"),
        BinaryTreeNodes::nodePtr<int, std::string>(1, "a"),
        BinaryTreeNodes::nodePtr<int, std::string>(6, "f"),
        BinaryTreeNodes::nodePtr<int, std::string>(3, "c"),
        BinaryTreeNodes::nodePtr<int, std::string>(7, "h")
    };

    std::vector<IBinaryTreeNodePtr<int, std::string>> preorder = {
        BinaryTreeNodes::nodePtr<int, std::string>(1, "a"),
        BinaryTreeNodes::nodePtr<int, std::string>(2, "b"),
        BinaryTreeNodes::nodePtr<int, std::string>(4, "d"),
        BinaryTreeNodes::nodePtr<int, std::string>(5, "e"),
        BinaryTreeNodes::nodePtr<int, std::string>(3, "c"),
        BinaryTreeNodes::nodePtr<int, std::string>(6, "f"),
        BinaryTreeNodes::nodePtr<int, std::string>(7, "h")
    };

    std::vector<IBinaryTreeNodePtr<int, std::string>> postorder = {
        BinaryTreeNodes::nodePtr<int, std::string>(4, "d"),
        BinaryTreeNodes::nodePtr<int, std::string>(5, "e"),
        BinaryTreeNodes::nodePtr<int, std::string>(2, "b"),
        BinaryTreeNodes::nodePtr<int, std::string>(6, "f"),
        BinaryTreeNodes::nodePtr<int, std::string>(7, "h"),
        BinaryTreeNodes::nodePtr<int, std::string>(3, "c"),
        BinaryTreeNodes::nodePtr<int, std::string>(1, "a")
    };

    return BinaryTreeDataPtr<int, std::string>(
        new BinaryTreeData<int, std::string>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder));
}
