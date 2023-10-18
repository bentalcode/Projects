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
std::vector<BinaryTreeDataSharedPtr<int, std::wstring>> BinaryTreeTestData::GetData() const
{
    std::vector<BinaryTreeDataSharedPtr<int, std::wstring>> data;

    data.push_back(GetTreeData1());
    data.push_back(GetTreeData2());
    data.push_back(GetTreeData3());
    data.push_back(GetTreeData4());

    return data;
}

/**
 * Gets the data of tree1.
 */
BinaryTreeDataSharedPtr<int, std::wstring> BinaryTreeTestData::GetTreeData1() const
{
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> creationData;
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> levelOrder;
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> inorder;
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> preorder;
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> postorder;

    return BinaryTreeDataSharedPtr<int, std::wstring>(
        new BinaryTreeData<int, std::wstring>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder));
}

/**
 * Gets the data of tree2.
 */
BinaryTreeDataSharedPtr<int, std::wstring> BinaryTreeTestData::GetTreeData2() const
{
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> creationData = {BinaryTreeNodes::Make<int, std::wstring>(1, L"a")};
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> levelOrder = {BinaryTreeNodes::Make<int, std::wstring>(1, L"a")};
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> inorder = {BinaryTreeNodes::Make<int, std::wstring>(1, L"a")};
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> preorder = {BinaryTreeNodes::Make<int, std::wstring>(1, L"a")};
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> postorder = {BinaryTreeNodes::Make<int, std::wstring>(1, L"a")};

    return BinaryTreeDataSharedPtr<int, std::wstring>(
        new BinaryTreeData<int, std::wstring>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder));
}

/**
 * Gets the data of tree3.
 */
BinaryTreeDataSharedPtr<int, std::wstring> BinaryTreeTestData::GetTreeData3() const
{
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> creationData;

    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(1, L"a"));
    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(2, L"b"));
    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(3, L"c"));
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(4, L"d"));
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(5, L"e"));
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());

    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> levelOrder =
    {
        BinaryTreeNodes::Make<int, std::wstring>(1, L"a"),
        BinaryTreeNodes::Make<int, std::wstring>(2, L"b"),
        BinaryTreeNodes::Make<int, std::wstring>(5, L"e"),
        BinaryTreeNodes::Make<int, std::wstring>(3, L"c"),
        BinaryTreeNodes::Make<int, std::wstring>(4, L"d")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> inorder =
    {
        BinaryTreeNodes::Make<int, std::wstring>(3, L"c"),
        BinaryTreeNodes::Make<int, std::wstring>(2, L"b"),
        BinaryTreeNodes::Make<int, std::wstring>(4, L"d"),
        BinaryTreeNodes::Make<int, std::wstring>(1, L"a"),
        BinaryTreeNodes::Make<int, std::wstring>(5, L"e")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> preorder =
    {
        BinaryTreeNodes::Make<int, std::wstring>(1, L"a"),
        BinaryTreeNodes::Make<int, std::wstring>(2, L"b"),
        BinaryTreeNodes::Make<int, std::wstring>(3, L"c"),
        BinaryTreeNodes::Make<int, std::wstring>(4, L"d"),
        BinaryTreeNodes::Make<int, std::wstring>(5, L"e")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> postorder =
    {
        BinaryTreeNodes::Make<int, std::wstring>(3, L"c"),
        BinaryTreeNodes::Make<int, std::wstring>(4, L"d"),
        BinaryTreeNodes::Make<int, std::wstring>(2, L"b"),
        BinaryTreeNodes::Make<int, std::wstring>(5, L"e"),
        BinaryTreeNodes::Make<int, std::wstring>(1, L"a")
    };

    return BinaryTreeDataSharedPtr<int, std::wstring>(
        new BinaryTreeData<int, std::wstring>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder));
}

/**
 * Gets the data of tree4.
 */
BinaryTreeDataSharedPtr<int, std::wstring> BinaryTreeTestData::GetTreeData4() const
{
    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> creationData;

    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(1, L"a"));
    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(2, L"b"));
    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(4, L"d"));
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(5, L"e"));
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(3, L"c"));
    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(6, L"f"));
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::Make<int, std::wstring>(7, L"h"));
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());
    creationData.push_back(BinaryTreeNodes::EndNode<int, std::wstring>());

    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> levelOrder =
    {
        BinaryTreeNodes::Make<int, std::wstring>(1, L"a"),
        BinaryTreeNodes::Make<int, std::wstring>(2, L"b"),
        BinaryTreeNodes::Make<int, std::wstring>(3, L"c"),
        BinaryTreeNodes::Make<int, std::wstring>(4, L"d"),
        BinaryTreeNodes::Make<int, std::wstring>(5, L"e"),
        BinaryTreeNodes::Make<int, std::wstring>(6, L"f"),
        BinaryTreeNodes::Make<int, std::wstring>(7, L"h")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> inorder =
    {
        BinaryTreeNodes::Make<int, std::wstring>(4, L"d"),
        BinaryTreeNodes::Make<int, std::wstring>(2, L"b"),
        BinaryTreeNodes::Make<int, std::wstring>(5, L"e"),
        BinaryTreeNodes::Make<int, std::wstring>(1, L"a"),
        BinaryTreeNodes::Make<int, std::wstring>(6, L"f"),
        BinaryTreeNodes::Make<int, std::wstring>(3, L"c"),
        BinaryTreeNodes::Make<int, std::wstring>(7, L"h")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> preorder =
    {
        BinaryTreeNodes::Make<int, std::wstring>(1, L"a"),
        BinaryTreeNodes::Make<int, std::wstring>(2, L"b"),
        BinaryTreeNodes::Make<int, std::wstring>(4, L"d"),
        BinaryTreeNodes::Make<int, std::wstring>(5, L"e"),
        BinaryTreeNodes::Make<int, std::wstring>(3, L"c"),
        BinaryTreeNodes::Make<int, std::wstring>(6, L"f"),
        BinaryTreeNodes::Make<int, std::wstring>(7, L"h")
    };

    std::vector<IBinaryTreeNodeSharedPtr<int, std::wstring>> postorder =
    {
        BinaryTreeNodes::Make<int, std::wstring>(4, L"d"),
        BinaryTreeNodes::Make<int, std::wstring>(5, L"e"),
        BinaryTreeNodes::Make<int, std::wstring>(2, L"b"),
        BinaryTreeNodes::Make<int, std::wstring>(6, L"f"),
        BinaryTreeNodes::Make<int, std::wstring>(7, L"h"),
        BinaryTreeNodes::Make<int, std::wstring>(3, L"c"),
        BinaryTreeNodes::Make<int, std::wstring>(1, L"a")
    };

    return BinaryTreeDataSharedPtr<int, std::wstring>(
        new BinaryTreeData<int, std::wstring>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder));
}
