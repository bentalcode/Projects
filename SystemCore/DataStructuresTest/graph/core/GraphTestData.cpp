#include "GraphTestData.h"
#include "Vertex.h"
#include "Edge.h"
#include "Route.h"
#include "Walk.h"
#include "TwoDimensionalVector.h"
#include "BaseLogic.h"

using namespace test::datastructures::graph;

/**
 * The GraphTestData constructor.
 */
GraphTestData::GraphTestData()
{
}

/**
 * The GraphTestData constructor.
 */
GraphTestData::~GraphTestData()
{
}

/**
 * Gets data of graphs.
 */
void GraphTestData::GetGraphsData(std::vector<GraphDataSharedPtr<int, std::wstring>>& result)
{
    result.push_back(GetGraphData1());
    result.push_back(GetGraphData2());
    result.push_back(GetGraphData3());
}

/**
 * Gets data of graphs with loops.
 */
void GraphTestData::GetGraphsDataWithLoops(std::vector<GraphDataSharedPtr<int, std::wstring>>& result)
{
    GraphDataSharedPtr<int, std::wstring> graphData = GetGraphDataWithLoop1();
    result.push_back(graphData);
}

/**
 * Generates a random vertex by integer.
 */
IVertexSharedPtr<int, int> GraphTestData::NextVertexByInteger()
{
    int key = m_randomGenerator.NextInteger();
    int value = m_randomGenerator.NextInteger();

    return Vertex<int, int>::Make(key, value);
}

/**
 * Generates a random vertex by double.
 */
IVertexSharedPtr<double, double> GraphTestData::NextVertexByDouble()
{
    double key = m_randomGenerator.NextDouble();
    double value = m_randomGenerator.NextDouble();

    return Vertex<double, double>::Make(key, value);
}

/**
 * Generates a random vertex by character.
 */
IVertexSharedPtr<char, char> GraphTestData::NextVertexByCharacter()
{
    char key = m_randomGenerator.NextCharacter();
    char value = m_randomGenerator.NextCharacter();

    return Vertex<char, char>::Make(key, value);
}

/**
 * Generates a random vertex by string.
 */
IVertexSharedPtr<std::wstring, std::wstring> GraphTestData::NextVertexByString()
{
    std::wstring key = m_randomGenerator.NextString();
    std::wstring value = m_randomGenerator.NextString();

    return Vertex<std::wstring, std::wstring>::Make(key, value);
}

/**
 * Generates a random edge by integer.
 */
IEdgeSharedPtr<int, int> GraphTestData::NextDirectedEdgeByInteger()
{
    IVertexSharedPtr<int, int> sourceVertex = NextVertexByInteger();
    IVertexSharedPtr<int, int> destinationVertex = NextVertexByInteger();

    IEdgeSharedPtr<int, int> edge = Edge<int, int>::MakeDirected(sourceVertex, destinationVertex);

    return edge;
}

/**
 * Generates a random edge by double.
 */
IEdgeSharedPtr<double, double> GraphTestData::NextDirectedEdgeByDouble()
{
    IVertexSharedPtr<double, double> sourceVertex = NextVertexByDouble();
    IVertexSharedPtr<double, double> destinationVertex = NextVertexByDouble();

    return Edge<double, double>::MakeDirected(sourceVertex, destinationVertex);
}

/**
 * Generates a random edge by character.
 */
IEdgeSharedPtr<char, char> GraphTestData::NextDirectedEdgeByCharacter()
{
    IVertexSharedPtr<char, char> sourceVertex = NextVertexByCharacter();
    IVertexSharedPtr<char, char> destinationVertex = NextVertexByCharacter();

    return Edge<char, char>::MakeDirected(sourceVertex, destinationVertex);
}

/**
 * Generates a random edge by string.
 */
IEdgeSharedPtr<std::wstring, std::wstring> GraphTestData::NextDirectedEdgeByString()
{
    IVertexSharedPtr<std::wstring, std::wstring> sourceVertex = NextVertexByString();
    IVertexSharedPtr<std::wstring, std::wstring> destinationVertex = NextVertexByString();

    return Edge<std::wstring, std::wstring>::MakeDirected(
        sourceVertex,
        destinationVertex);
}

/**
 * Gets data of graph1.
 */
GraphDataSharedPtr<int, std::wstring> GraphTestData::GetGraphData1()
{
    IVertexSharedPtr<int, std::wstring> vertex1 = Vertex<int, std::wstring>::Make(1, L"a");
    IVertexSharedPtr<int, std::wstring> vertex2 = Vertex<int, std::wstring>::Make(2, L"b");
    IVertexSharedPtr<int, std::wstring> vertex3 = Vertex<int, std::wstring>::Make(3, L"c");
    IVertexSharedPtr<int, std::wstring> vertex4 = Vertex<int, std::wstring>::Make(4, L"d");

    std::vector<IVertexSharedPtr<int, std::wstring>> vertices =
    {
        vertex1,
        vertex2,
        vertex3,
        vertex4
    };

    IEdgeSharedPtr<int, std::wstring> edge12 = Edge<int, std::wstring>::MakeDirected(vertex1, vertex2);
    IEdgeSharedPtr<int, std::wstring> edge13 = Edge<int, std::wstring>::MakeDirected(vertex1, vertex3);
    IEdgeSharedPtr<int, std::wstring> edge23 = Edge<int, std::wstring>::MakeDirected(vertex2, vertex3);
    IEdgeSharedPtr<int, std::wstring> edge34 = Edge<int, std::wstring>::MakeDirected(vertex3, vertex4);

    std::vector<IEdgeSharedPtr<int, std::wstring>> edges
    {
        edge12,
        edge13,
        edge23,
        edge34
    };

    EdgeWeightMap<int, std::wstring> weights;
    weights.insert(std::make_pair(edge12, 5));
    weights.insert(std::make_pair(edge23, 2));
    weights.insert(std::make_pair(edge13, 6));
    weights.insert(std::make_pair(edge34, 4));

    std::vector<std::pair<IRouteSharedPtr<int, std::wstring>, std::vector<IWalkSharedPtr<int, std::wstring>>>> paths;
    GetGraphPathsData1(vertices, paths);

    base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> topologicalSearch = GetGraphTopologicalSearchData1(
            vertices);

    GraphShortestPathsMap<int, std::wstring> shortestPaths;
    GetGraphShortestPaths1(
            vertices,
            shortestPaths);

    return GraphData<int, std::wstring>::Make(
            vertices,
            edges,
            weights,
            paths,
            topologicalSearch,
            shortestPaths);
}

/**
 * Gets data of graph2.
 */
GraphDataSharedPtr<int, std::wstring> GraphTestData::GetGraphData2()
{
    IVertexSharedPtr<int, std::wstring> vertex1 = Vertex<int, std::wstring>::Make(1, L"a");
    IVertexSharedPtr<int, std::wstring> vertex2 = Vertex<int, std::wstring>::Make(2, L"b");
    IVertexSharedPtr<int, std::wstring> vertex3 = Vertex<int, std::wstring>::Make(3, L"c");
    IVertexSharedPtr<int, std::wstring> vertex4 = Vertex<int, std::wstring>::Make(4, L"d");
    IVertexSharedPtr<int, std::wstring> vertex5 = Vertex<int, std::wstring>::Make(5, L"e");
    IVertexSharedPtr<int, std::wstring> vertex6 = Vertex<int, std::wstring>::Make(6, L"f");

    std::vector<IVertexSharedPtr<int, std::wstring>> vertices =
    {
        vertex1,
        vertex2,
        vertex3,
        vertex4,
        vertex5,
        vertex6
    };

    IEdgeSharedPtr<int, std::wstring> edge12 = Edge<int, std::wstring>::MakeDirected(vertex1, vertex2);
    IEdgeSharedPtr<int, std::wstring> edge13 = Edge<int, std::wstring>::MakeDirected(vertex1, vertex3);
    IEdgeSharedPtr<int, std::wstring> edge24 = Edge<int, std::wstring>::MakeDirected(vertex2, vertex4);
    IEdgeSharedPtr<int, std::wstring> edge32 = Edge<int, std::wstring>::MakeDirected(vertex3, vertex2);
    IEdgeSharedPtr<int, std::wstring> edge35 = Edge<int, std::wstring>::MakeDirected(vertex3, vertex5);
    IEdgeSharedPtr<int, std::wstring> edge45 = Edge<int, std::wstring>::MakeDirected(vertex4, vertex5);
    IEdgeSharedPtr<int, std::wstring> edge46 = Edge<int, std::wstring>::MakeDirected(vertex4, vertex6);
    IEdgeSharedPtr<int, std::wstring> edge56 = Edge<int, std::wstring>::MakeDirected(vertex5, vertex6);

    std::vector<IEdgeSharedPtr<int, std::wstring>> edges =
    {
        edge12,
        edge13,
        edge24,
        edge32,
        edge35,
        edge45,
        edge46,
        edge56
    };

    EdgeWeightMap<int, std::wstring> weights;
    weights.insert(std::make_pair(edge12, 10));
    weights.insert(std::make_pair(edge13, 8));
    weights.insert(std::make_pair(edge24, 6));
    weights.insert(std::make_pair(edge32, 4));
    weights.insert(std::make_pair(edge35, 7));
    weights.insert(std::make_pair(edge45, 9));
    weights.insert(std::make_pair(edge46, 3));
    weights.insert(std::make_pair(edge56, 2));

    std::vector<std::pair<IRouteSharedPtr<int, std::wstring>, std::vector<IWalkSharedPtr<int, std::wstring>>>> paths;
    GetGraphPathsData2(vertices, paths);

    base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> topologicalSearch = GetGraphTopologicalSearchData2(
            vertices);

    GraphShortestPathsMap<int, std::wstring> shortestPaths;
    GetGraphShortestPaths2(
            vertices,
            shortestPaths);

    return GraphData<int, std::wstring>::Make(
            vertices,
            edges,
            weights,
            paths,
            topologicalSearch,
            shortestPaths);
}

/**
 * Gets data of graph3.
 */
GraphDataSharedPtr<int, std::wstring> GraphTestData::GetGraphData3()
{
    IVertexSharedPtr<int, std::wstring> vertex1 = Vertex<int, std::wstring>::Make(1, L"a");
    IVertexSharedPtr<int, std::wstring> vertex2 = Vertex<int, std::wstring>::Make(2, L"b");
    IVertexSharedPtr<int, std::wstring> vertex3 = Vertex<int, std::wstring>::Make(3, L"c");
    IVertexSharedPtr<int, std::wstring> vertex4 = Vertex<int, std::wstring>::Make(4, L"d");
    IVertexSharedPtr<int, std::wstring> vertex5 = Vertex<int, std::wstring>::Make(5, L"e");

    std::vector<IVertexSharedPtr<int, std::wstring>> vertices =
    {
        vertex1,
        vertex2,
        vertex3,
        vertex4,
        vertex5
    };

    IEdgeSharedPtr<int, std::wstring> edge12 = Edge<int, std::wstring>::MakeDirected(vertex1, vertex2);
    IEdgeSharedPtr<int, std::wstring> edge13 = Edge<int, std::wstring>::MakeDirected(vertex1, vertex3);
    IEdgeSharedPtr<int, std::wstring> edge25 = Edge<int, std::wstring>::MakeDirected(vertex2, vertex5);
    IEdgeSharedPtr<int, std::wstring> edge35 = Edge<int, std::wstring>::MakeDirected(vertex3, vertex5);
    IEdgeSharedPtr<int, std::wstring> edge45 = Edge<int, std::wstring>::MakeDirected(vertex4, vertex5);

    std::vector<IEdgeSharedPtr<int, std::wstring>> edges =
    {
        edge12,
        edge13,
        edge25,
        edge35,
        edge45
    };

    EdgeWeightMap<int, std::wstring> weights =
    {
        {edge12, 7},
        {edge13, 8},
        {edge25, 13},
        {edge35, 6},
        {edge45, 2}
    };

    std::vector<std::pair<IRouteSharedPtr<int, std::wstring>, std::vector<IWalkSharedPtr<int, std::wstring>>>> paths;
    GetGraphPathsData3(vertices, paths);

    base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> topologicalSearch = GetGraphTopologicalSearchData3(
            vertices);

    GraphShortestPathsMap<int, std::wstring> shortestPaths;
    GetGraphShortestPaths3(
            vertices,
            shortestPaths);

    return GraphData<int, std::wstring>::Make(
            vertices,
            edges,
            weights,
            paths,
            topologicalSearch,
            shortestPaths);
}

/**
 * Gets data of graph1.
 */
GraphDataSharedPtr<int, std::wstring> GraphTestData::GetGraphDataWithLoop1()
{
    IVertexSharedPtr<int, std::wstring> vertex1 = Vertex<int, std::wstring>::Make(1, L"a");
    IVertexSharedPtr<int, std::wstring> vertex2 = Vertex<int, std::wstring>::Make(2, L"b");
    IVertexSharedPtr<int, std::wstring> vertex3 = Vertex<int, std::wstring>::Make(3, L"c");
    IVertexSharedPtr<int, std::wstring> vertex4 = Vertex<int, std::wstring>::Make(4, L"d");

    std::vector<IVertexSharedPtr<int, std::wstring>> vertices =
    {
        vertex1,
        vertex2,
        vertex3,
        vertex4
    };

    std::vector<IEdgeSharedPtr<int, std::wstring>> edges =
    {
        Edge<int, std::wstring>::MakeDirected(vertex1, vertex2),
        Edge<int, std::wstring>::MakeDirected(vertex1, vertex3),
        Edge<int, std::wstring>::MakeDirected(vertex2, vertex3),
        Edge<int, std::wstring>::MakeDirected(vertex3, vertex1),
        Edge<int, std::wstring>::MakeDirected(vertex3, vertex4),
        Edge<int, std::wstring>::MakeDirected(vertex4, vertex4)
    };

    GraphDataSharedPtr<int, std::wstring> graphDataPtr = std::make_shared<GraphData<int, std::wstring>>(
        vertices,
        edges);

    return graphDataPtr;
}

/**
 * Gets the paths data of graph1.
 */
void GraphTestData::GetGraphPathsData1(
    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
    std::vector<std::pair<IRouteSharedPtr<int, std::wstring>, std::vector<IWalkSharedPtr<int, std::wstring>>>>& result)
{
    assert(vertices.size() == 4);
    IVertexSharedPtr<int, std::wstring> vertex1 = vertices[0];
    IVertexSharedPtr<int, std::wstring> vertex2 = vertices[1];
    IVertexSharedPtr<int, std::wstring> vertex3 = vertices[2];
    IVertexSharedPtr<int, std::wstring> vertex4 = vertices[3];

    IRouteSharedPtr<int, std::wstring> route12 = Route<int, std::wstring>::Make(vertex1, vertex2);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks12;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex2}
        },
        walks12
    );

    result.push_back(std::make_pair(route12, walks12));

    IRouteSharedPtr<int, std::wstring> route13 = Route<int, std::wstring>::Make(vertex1, vertex3);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks13;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex2, vertex3},
            {vertex1, vertex3}
        },
        walks13
    );

    result.push_back(std::make_pair(route13, walks13));

    IRouteSharedPtr<int, std::wstring> route14 = Route<int, std::wstring>::Make(vertex1, vertex4);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks14;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex2, vertex3, vertex4},
            {vertex1, vertex3, vertex4}
        },
        walks14
    );

    result.push_back(std::make_pair(route14, walks14));

    IRouteSharedPtr<int, std::wstring> route23 = Route<int, std::wstring>::Make(vertex2, vertex3);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks23;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex2, vertex3}
        },
        walks23
    );

    result.push_back(std::make_pair(route23, walks23));

    IRouteSharedPtr<int, std::wstring> route24 = Route<int, std::wstring>::Make(vertex2, vertex4);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks24;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex2, vertex3, vertex4}
        },
        walks24
    );

    result.push_back(std::make_pair(route24, walks24));


    IRouteSharedPtr<int, std::wstring> route34 = Route<int, std::wstring>::Make(vertex3, vertex4);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks34;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex3, vertex4}
        },
        walks34
    );

    result.push_back(std::make_pair(route34, walks34));
}

/**
 * Gets the paths data of graph2.
 */
void GraphTestData::GetGraphPathsData2(
    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
    std::vector<std::pair<IRouteSharedPtr<int, std::wstring>, std::vector<IWalkSharedPtr<int, std::wstring>>>>& result)
{
    assert(vertices.size() == 6);
    IVertexSharedPtr<int, std::wstring> vertex1 = vertices[0];
    IVertexSharedPtr<int, std::wstring> vertex2 = vertices[1];
    IVertexSharedPtr<int, std::wstring> vertex3 = vertices[2];
    IVertexSharedPtr<int, std::wstring> vertex4 = vertices[3];
    IVertexSharedPtr<int, std::wstring> vertex5 = vertices[4];
    IVertexSharedPtr<int, std::wstring> vertex6 = vertices[5];

    IRouteSharedPtr<int, std::wstring> route12 = Route<int, std::wstring>::Make(vertex1, vertex2);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks12;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex2},
            {vertex1, vertex3, vertex2}
        },
        walks12
    );

    result.push_back(std::make_pair(route12, walks12));

    IRouteSharedPtr<int, std::wstring> route13 = Route<int, std::wstring>::Make(vertex1, vertex3);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks13;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex3}
        },
        walks13
    );

    result.push_back(std::make_pair(route13, walks13));

    IRouteSharedPtr<int, std::wstring> route14 = Route<int, std::wstring>::Make(vertex1, vertex4);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks14;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex2, vertex4},
            {vertex1, vertex3, vertex2, vertex4}
        },
        walks14
    );

    result.push_back(std::make_pair(route14, walks14));

    IRouteSharedPtr<int, std::wstring> route15 = Route<int, std::wstring>::Make(vertex1, vertex5);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks15;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex2, vertex4, vertex5},
            {vertex1, vertex3, vertex2, vertex4, vertex5},
            {vertex1, vertex3, vertex5}
        },
        walks15
    );

    result.push_back(std::make_pair(route15, walks15));

    IRouteSharedPtr<int, std::wstring> route16 = Route<int, std::wstring>::Make(vertex1, vertex6);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks16;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex2, vertex4, vertex5, vertex6},
            {vertex1, vertex2, vertex4, vertex6},
            {vertex1, vertex3, vertex2, vertex4, vertex5, vertex6},
            {vertex1, vertex3, vertex2, vertex4, vertex6},
            {vertex1, vertex3, vertex5, vertex6}
        },
        walks16
    );

    result.push_back(std::make_pair(route16, walks16));
}

/**
 * Gets the paths data of graph3.
 */
void GraphTestData::GetGraphPathsData3(
    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
    std::vector<std::pair<IRouteSharedPtr<int, std::wstring>, std::vector<IWalkSharedPtr<int, std::wstring>>>>& result)
{
    assert(vertices.size() == 5);
    IVertexSharedPtr<int, std::wstring> vertex1 = vertices[0];
    IVertexSharedPtr<int, std::wstring> vertex2 = vertices[1];
    IVertexSharedPtr<int, std::wstring> vertex3 = vertices[2];
    IVertexSharedPtr<int, std::wstring> vertex4 = vertices[3];
    IVertexSharedPtr<int, std::wstring> vertex5 = vertices[4];

    IRouteSharedPtr<int, std::wstring> route12 = Route<int, std::wstring>::Make(vertex1, vertex2);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks12;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex2}
        },
        walks12
    );

    result.push_back(std::make_pair(route12, walks12));

    IRouteSharedPtr<int, std::wstring> route13 = Route<int, std::wstring>::Make(vertex1, vertex3);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks13;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex3}
        },
        walks13
    );

    result.push_back(std::make_pair(route13, walks13));

    IRouteSharedPtr<int, std::wstring> route15 = Route<int, std::wstring>::Make(vertex1, vertex5);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks15;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex1, vertex2, vertex5},
            {vertex1, vertex3, vertex5}
        },
        walks15
    );

    result.push_back(std::make_pair(route15, walks15));

    IRouteSharedPtr<int, std::wstring> route25 = Route<int, std::wstring>::Make(vertex2, vertex5);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks25;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex2, vertex5}
        },
        walks25
    );

    result.push_back(std::make_pair(route25, walks25));

    IRouteSharedPtr<int, std::wstring> route35 = Route<int, std::wstring>::Make(vertex3, vertex5);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks35;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex3, vertex5}
        },
        walks35
    );

    result.push_back(std::make_pair(route35, walks35));

    IRouteSharedPtr<int, std::wstring> route45 = Route<int, std::wstring>::Make(vertex4, vertex5);
    std::vector<IWalkSharedPtr<int, std::wstring>> walks45;
    Walk<int, std::wstring>::MakeWalks(
        {
            {vertex4, vertex5}
        },
        walks45
    );

    result.push_back(std::make_pair(route45, walks45));
}

/**
 * Gets the topological search data of graph1.
 */
base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> GraphTestData::GetGraphTopologicalSearchData1(
    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices)
{
    assert(vertices.size() == 4);
    IVertexSharedPtr<int, std::wstring> vertex1 = vertices[0];
    IVertexSharedPtr<int, std::wstring> vertex2 = vertices[1];
    IVertexSharedPtr<int, std::wstring> vertex3 = vertices[2];
    IVertexSharedPtr<int, std::wstring> vertex4 = vertices[3];

    base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> result =
        TwoDimensionalVector<IVertexSharedPtr<int, std::wstring>>::Make();

    result->AddRow({vertex1});
    result->AddRow({vertex2});
    result->AddRow({vertex3});
    result->AddRow({vertex4});

    return result;
}

/**
 * Gets the topological search data of graph2.
 */
base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> GraphTestData::GetGraphTopologicalSearchData2(
    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices)
{
    assert(vertices.size() == 6);
    IVertexSharedPtr<int, std::wstring> vertex1 = vertices[0];
    IVertexSharedPtr<int, std::wstring> vertex2 = vertices[1];
    IVertexSharedPtr<int, std::wstring> vertex3 = vertices[2];
    IVertexSharedPtr<int, std::wstring> vertex4 = vertices[3];
    IVertexSharedPtr<int, std::wstring> vertex5 = vertices[4];
    IVertexSharedPtr<int, std::wstring> vertex6 = vertices[5];

    base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> result =
        TwoDimensionalVector<IVertexSharedPtr<int, std::wstring>>::Make();

    result->AddRow({vertex1});
    result->AddRow({vertex3});
    result->AddRow({vertex2});
    result->AddRow({vertex4});
    result->AddRow({vertex5});
    result->AddRow({vertex6});

    return result;
}

/**
 * Gets the topological search data of graph3.
 */
base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> GraphTestData::GetGraphTopologicalSearchData3(
    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices)
{
    assert(vertices.size() == 5);
    IVertexSharedPtr<int, std::wstring> vertex1 = vertices[0];
    IVertexSharedPtr<int, std::wstring> vertex2 = vertices[1];
    IVertexSharedPtr<int, std::wstring> vertex3 = vertices[2];
    IVertexSharedPtr<int, std::wstring> vertex4 = vertices[3];
    IVertexSharedPtr<int, std::wstring> vertex5 = vertices[4];

    base::ITwoDimensionalVectorSharedPtr<IVertexSharedPtr<int, std::wstring>> result =
        TwoDimensionalVector<IVertexSharedPtr<int, std::wstring>>::Make();

    result->AddRow({vertex4});
    result->AddRow({vertex1});
    result->AddRow({vertex3});
    result->AddRow({vertex2});
    result->AddRow({vertex5});

    return result;
}

/**
 * Gets the shortest paths of graph1.
 */
void GraphTestData::GetGraphShortestPaths1(
    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
    GraphShortestPathsMap<int, std::wstring>& result)
{
    assert(vertices.size() == 4);
    IVertexSharedPtr<int, std::wstring> vertex1 = vertices[0];
    IVertexSharedPtr<int, std::wstring> vertex2 = vertices[1];
    IVertexSharedPtr<int, std::wstring> vertex3 = vertices[2];
    IVertexSharedPtr<int, std::wstring> vertex4 = vertices[3];

    VertexShortestPathsMap<int, std::wstring> shortestPaths1 =
    {
        {vertex1, 0},
        {vertex2, 5},
        {vertex3, 6},
        {vertex4, 10}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths2 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, 0},
        {vertex3, 2},
        {vertex4, 6}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths3 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, 0},
        {vertex4, 4}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths4 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, 0}
    };

    result.insert(std::make_pair(vertex1, shortestPaths1));
    result.insert(std::make_pair(vertex2, shortestPaths2));
    result.insert(std::make_pair(vertex3, shortestPaths3));
    result.insert(std::make_pair(vertex4, shortestPaths4));
}

/**
 * Gets the shortest paths of graph2.
 */
void GraphTestData::GetGraphShortestPaths2(
    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
    GraphShortestPathsMap<int, std::wstring>& result)
{
    assert(vertices.size() == 6);
    IVertexSharedPtr<int, std::wstring> vertex1 = vertices[0];
    IVertexSharedPtr<int, std::wstring> vertex2 = vertices[1];
    IVertexSharedPtr<int, std::wstring> vertex3 = vertices[2];
    IVertexSharedPtr<int, std::wstring> vertex4 = vertices[3];
    IVertexSharedPtr<int, std::wstring> vertex5 = vertices[4];
    IVertexSharedPtr<int, std::wstring> vertex6 = vertices[5];

    VertexShortestPathsMap<int, std::wstring> shortestPaths1 =
    {
        {vertex1, 0},
        {vertex2, 10},
        {vertex3, 8},
        {vertex4, 16},
        {vertex5, 15},
        {vertex6, 17}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths2 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, 0},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, 6},
        {vertex5, 15},
        {vertex6, 9}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths3 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, 4},
        {vertex3, 0},
        {vertex4, 10},
        {vertex5, 7},
        {vertex6, 9}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths4 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, 0},
        {vertex5, 9},
        {vertex6, 3}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths5 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, std::numeric_limits<int>::max()},
        {vertex5, 0},
        {vertex6, 2}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths6 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, std::numeric_limits<int>::max()},
        {vertex5, std::numeric_limits<int>::max()},
        {vertex6, 0}
    };

    result.insert(std::make_pair(vertex1, shortestPaths1));
    result.insert(std::make_pair(vertex2, shortestPaths2));
    result.insert(std::make_pair(vertex3, shortestPaths3));
    result.insert(std::make_pair(vertex4, shortestPaths4));
    result.insert(std::make_pair(vertex5, shortestPaths5));
    result.insert(std::make_pair(vertex6, shortestPaths6));
}

/**
 * Gets the shortest paths of graph3.
 */
void GraphTestData::GetGraphShortestPaths3(
    const std::vector<IVertexSharedPtr<int, std::wstring>>& vertices,
    GraphShortestPathsMap<int, std::wstring>& result)
{
    assert(vertices.size() == 5);

    IVertexSharedPtr<int, std::wstring> vertex1 = vertices[0];
    IVertexSharedPtr<int, std::wstring> vertex2 = vertices[1];
    IVertexSharedPtr<int, std::wstring> vertex3 = vertices[2];
    IVertexSharedPtr<int, std::wstring> vertex4 = vertices[3];
    IVertexSharedPtr<int, std::wstring> vertex5 = vertices[4];

    VertexShortestPathsMap<int, std::wstring> shortestPaths1 =
    {
        {vertex1, 0},
        {vertex2, 7},
        {vertex3, 8},
        {vertex4, std::numeric_limits<int>::max()},
        {vertex5, 14}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths2 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, 0},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, std::numeric_limits<int>::max()},
        {vertex5, 13}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths3 =
    {
       {vertex1, std::numeric_limits<int>::max()},
       {vertex2, std::numeric_limits<int>::max()},
       {vertex3, 0},
       {vertex4, std::numeric_limits<int>::max()},
       {vertex5, 6}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths4 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, 0},
        {vertex5, 2}
    };

    VertexShortestPathsMap<int, std::wstring> shortestPaths5 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, std::numeric_limits<int>::max()},
        {vertex5, 0}
    };

    result.insert(std::make_pair(vertex1, shortestPaths1));
    result.insert(std::make_pair(vertex2, shortestPaths2));
    result.insert(std::make_pair(vertex3, shortestPaths3));
    result.insert(std::make_pair(vertex4, shortestPaths4));
    result.insert(std::make_pair(vertex5, shortestPaths5));
}
