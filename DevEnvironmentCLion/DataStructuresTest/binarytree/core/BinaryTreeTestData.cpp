#include "PreCompiled.h"

#include "BinaryTreeTestData.h"
#include "BinaryTreeData.h"
#include "BinaryTreeNodes.h"

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
std::vector<BinaryTreeDataSharedPtr<int, std::string>> BinaryTreeTestData::getData() const
{
    std::vector<BinaryTreeDataSharedPtr<int, std::string>> data;

    data.push_back(getTreeData1());
    data.push_back(getTreeData2());
    data.push_back(getTreeData3());
    data.push_back(getTreeData4());

    return data;
}

/**
 * Gets the data of tree1.
 */
BinaryTreeDataSharedPtr<int, std::string> BinaryTreeTestData::getTreeData1() const
{
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> creationData;
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> levelOrder;
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> inorder;
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> preorder;
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> postorder;

    return BinaryTreeDataSharedPtr<int, std::string>(
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
BinaryTreeDataSharedPtr<int, std::string> BinaryTreeTestData::getTreeData2() const
{
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> creationData = {BinaryTreeNodes::make<int, std::string>(1, "a")};
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> levelOrder = {BinaryTreeNodes::make<int, std::string>(1, "a")};
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> inorder = {BinaryTreeNodes::make<int, std::string>(1, "a")};
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> preorder = {BinaryTreeNodes::make<int, std::string>(1, "a")};
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> postorder = {BinaryTreeNodes::make<int, std::string>(1, "a")};

    return BinaryTreeDataSharedPtr<int, std::string>(
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
BinaryTreeDataSharedPtr<int, std::string> BinaryTreeTestData::getTreeData3() const
{
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> creationData;

    creationData.push_back(BinaryTreeNodes::make<int, std::string>(1, "a"));
    creationData.push_back(BinaryTreeNodes::make<int, std::string>(2, "b"));
    creationData.push_back(BinaryTreeNodes::make<int, std::string>(3, "c"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::make<int, std::string>(4, "d"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::make<int, std::string>(5, "e"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());

    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> levelOrder =
    {
        BinaryTreeNodes::make<int, std::string>(1, "a"),
        BinaryTreeNodes::make<int, std::string>(2, "b"),
        BinaryTreeNodes::make<int, std::string>(5, "e"),
        BinaryTreeNodes::make<int, std::string>(3, "c"),
        BinaryTreeNodes::make<int, std::string>(4, "d")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> inorder =
    {
        BinaryTreeNodes::make<int, std::string>(3, "c"),
        BinaryTreeNodes::make<int, std::string>(2, "b"),
        BinaryTreeNodes::make<int, std::string>(4, "d"),
        BinaryTreeNodes::make<int, std::string>(1, "a"),
        BinaryTreeNodes::make<int, std::string>(5, "e")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> preorder =
    {
        BinaryTreeNodes::make<int, std::string>(1, "a"),
        BinaryTreeNodes::make<int, std::string>(2, "b"),
        BinaryTreeNodes::make<int, std::string>(3, "c"),
        BinaryTreeNodes::make<int, std::string>(4, "d"),
        BinaryTreeNodes::make<int, std::string>(5, "e")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> postorder =
    {
        BinaryTreeNodes::make<int, std::string>(3, "c"),
        BinaryTreeNodes::make<int, std::string>(4, "d"),
        BinaryTreeNodes::make<int, std::string>(2, "b"),
        BinaryTreeNodes::make<int, std::string>(5, "e"),
        BinaryTreeNodes::make<int, std::string>(1, "a")
    };

    return BinaryTreeDataSharedPtr<int, std::string>(
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
BinaryTreeDataSharedPtr<int, std::string> BinaryTreeTestData::getTreeData4() const
{
    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> creationData;

    creationData.push_back(BinaryTreeNodes::make<int, std::string>(1, "a"));
    creationData.push_back(BinaryTreeNodes::make<int, std::string>(2, "b"));
    creationData.push_back(BinaryTreeNodes::make<int, std::string>(4, "d"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::make<int, std::string>(5, "e"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::make<int, std::string>(3, "c"));
    creationData.push_back(BinaryTreeNodes::make<int, std::string>(6, "f"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::make<int, std::string>(7, "h"));
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());
    creationData.push_back(BinaryTreeNodes::endNode<int, std::string>());

    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> levelOrder =
    {
        BinaryTreeNodes::make<int, std::string>(1, "a"),
        BinaryTreeNodes::make<int, std::string>(2, "b"),
        BinaryTreeNodes::make<int, std::string>(3, "c"),
        BinaryTreeNodes::make<int, std::string>(4, "d"),
        BinaryTreeNodes::make<int, std::string>(5, "e"),
        BinaryTreeNodes::make<int, std::string>(6, "f"),
        BinaryTreeNodes::make<int, std::string>(7, "h")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> inorder =
    {
        BinaryTreeNodes::make<int, std::string>(4, "d"),
        BinaryTreeNodes::make<int, std::string>(2, "b"),
        BinaryTreeNodes::make<int, std::string>(5, "e"),
        BinaryTreeNodes::make<int, std::string>(1, "a"),
        BinaryTreeNodes::make<int, std::string>(6, "f"),
        BinaryTreeNodes::make<int, std::string>(3, "c"),
        BinaryTreeNodes::make<int, std::string>(7, "h")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> preorder =
    {
        BinaryTreeNodes::make<int, std::string>(1, "a"),
        BinaryTreeNodes::make<int, std::string>(2, "b"),
        BinaryTreeNodes::make<int, std::string>(4, "d"),
        BinaryTreeNodes::make<int, std::string>(5, "e"),
        BinaryTreeNodes::make<int, std::string>(3, "c"),
        BinaryTreeNodes::make<int, std::string>(6, "f"),
        BinaryTreeNodes::make<int, std::string>(7, "h")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::string>> postorder =
    {
        BinaryTreeNodes::make<int, std::string>(4, "d"),
        BinaryTreeNodes::make<int, std::string>(5, "e"),
        BinaryTreeNodes::make<int, std::string>(2, "b"),
        BinaryTreeNodes::make<int, std::string>(6, "f"),
        BinaryTreeNodes::make<int, std::string>(7, "h"),
        BinaryTreeNodes::make<int, std::string>(3, "c"),
        BinaryTreeNodes::make<int, std::string>(1, "a")
    };

    return BinaryTreeDataSharedPtr<int, std::string>(
        new BinaryTreeData<int, std::string>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder));
}
