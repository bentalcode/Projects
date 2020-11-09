#include "PreCompiled.h"

#include "GraphTestData.h"
#include "Vertex.h"
#include "Edge.h"
#include "Route.h"
#include "Walk.h"
#include "TwoDimensionalVector.h"

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
void GraphTestData::getGraphsData(std::vector<GraphDataPtr<int, std::string>>& result)
{
    result.push_back(getGraphData1());
    result.push_back(getGraphData2());
    result.push_back(getGraphData3());
}

/**
 * Gets data of graphs with loops.
 */
void GraphTestData::getGraphsDataWithLoops(std::vector<GraphDataPtr<int, std::string>>& result)
{
    GraphDataPtr<int, std::string> graphData = getGraphDataWithLoop1();
    result.push_back(graphData);
}

/**
 * Generates a random vertex by integer.
 */
IVertexPtr<int, int> GraphTestData::nextVertexByInteger()
{
    int key = m_randomGenerator.nextInteger();
    int value = m_randomGenerator.nextInteger();

    return Vertex<int, int>::make(key, value);
}

/**
 * Generates a random vertex by double.
 */
IVertexPtr<double, double> GraphTestData::nextVertexByDouble()
{
    double key = m_randomGenerator.nextDouble();
    double value = m_randomGenerator.nextDouble();

    return Vertex<double, double>::make(key, value);
}

/**
 * Generates a random vertex by character.
 */
IVertexPtr<char, char> GraphTestData::nextVertexByCharacter()
{
    char key = m_randomGenerator.nextCharacter();
    char value = m_randomGenerator.nextCharacter();

    return Vertex<char, char>::make(key, value);
}

/**
 * Generates a random vertex by string.
 */
IVertexPtr<std::string, std::string> GraphTestData::nextVertexByString()
{
    std::string key = m_randomGenerator.nextString();
    std::string value = m_randomGenerator.nextString();

    return Vertex<std::string, std::string>::make(key, value);
}

/**
 * Generates a random edge by integer.
 */
IEdgePtr<int, int> GraphTestData::nextDirectedEdgeByInteger()
{
    IVertexPtr<int, int> sourceVertex = nextVertexByInteger();
    IVertexPtr<int, int> destinationVertex = nextVertexByInteger();

    IEdgePtr<int, int> edge = Edge<int, int>::makeDirected(sourceVertex, destinationVertex);

    return edge;
}

/**
 * Generates a random edge by double.
 */
IEdgePtr<double, double> GraphTestData::nextDirectedEdgeByDouble()
{
    IVertexPtr<double, double> sourceVertex = nextVertexByDouble();
    IVertexPtr<double, double> destinationVertex = nextVertexByDouble();

    return Edge<double, double>::makeDirected(sourceVertex, destinationVertex);
}

/**
 * Generates a random edge by character.
 */
IEdgePtr<char, char> GraphTestData::nextDirectedEdgeByCharacter()
{
    IVertexPtr<char, char> sourceVertex = nextVertexByCharacter();
    IVertexPtr<char, char> destinationVertex = nextVertexByCharacter();

    return Edge<char, char>::makeDirected(sourceVertex, destinationVertex);
}

/**
 * Generates a random edge by string.
 */
IEdgePtr<std::string, std::string> GraphTestData::nextDirectedEdgeByString()
{
    IVertexPtr<std::string, std::string> sourceVertex = nextVertexByString();
    IVertexPtr<std::string, std::string> destinationVertex = nextVertexByString();

    return Edge<std::string, std::string>::makeDirected(
        sourceVertex,
        destinationVertex);
}

/**
 * Gets data of graph1.
 */
GraphDataPtr<int, std::string> GraphTestData::getGraphData1()
{
    IVertexPtr<int, std::string> vertex1 = Vertex<int, std::string>::make(1, "a");
    IVertexPtr<int, std::string> vertex2 = Vertex<int, std::string>::make(2, "b");
    IVertexPtr<int, std::string> vertex3 = Vertex<int, std::string>::make(3, "c");
    IVertexPtr<int, std::string> vertex4 = Vertex<int, std::string>::make(4, "d");

    std::vector<IVertexPtr<int, std::string>> vertices =
    {
        vertex1,
        vertex2,
        vertex3,
        vertex4
    };

    IEdgePtr<int, std::string> edge12 = Edge<int, std::string>::makeDirected(vertex1, vertex2);
    IEdgePtr<int, std::string> edge13 = Edge<int, std::string>::makeDirected(vertex1, vertex3);
    IEdgePtr<int, std::string> edge23 = Edge<int, std::string>::makeDirected(vertex2, vertex3);
    IEdgePtr<int, std::string> edge34 = Edge<int, std::string>::makeDirected(vertex3, vertex4);

    std::vector<IEdgePtr<int, std::string>> edges
    {
        edge12,
        edge13,
        edge23,
        edge34
    };

    std::map<IEdgePtr<int, std::string>, int> weights;
    weights.insert(std::make_pair(edge12, 5));
    weights.insert(std::make_pair(edge23, 2));
    weights.insert(std::make_pair(edge13, 6));
    weights.insert(std::make_pair(edge34, 4));

    std::vector<std::pair<IRoutePtr<int, std::string>, std::vector<IWalkPtr<int, std::string>>>> paths;
    getGraphPathsData1(vertices, paths);

    base::ITwoDimensionalVectorPtr<IVertexPtr<int, std::string>> topologicalSearch = getGraphTopologicalSearchData1(
        vertices);

    std::map<IVertexPtr<int, std::string>, std::map<IVertexPtr<int, std::string>, size_t>> shortestPaths;
    getGraphShortestPaths1(
        vertices,
        shortestPaths);

    return GraphData<int, std::string>::make(
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
GraphDataPtr<int, std::string> GraphTestData::getGraphData2()
{
    IVertexPtr<int, std::string> vertex1 = Vertex<int, std::string>::make(1, "a");
    IVertexPtr<int, std::string> vertex2 = Vertex<int, std::string>::make(2, "b");
    IVertexPtr<int, std::string> vertex3 = Vertex<int, std::string>::make(3, "c");
    IVertexPtr<int, std::string> vertex4 = Vertex<int, std::string>::make(4, "d");
    IVertexPtr<int, std::string> vertex5 = Vertex<int, std::string>::make(5, "e");
    IVertexPtr<int, std::string> vertex6 = Vertex<int, std::string>::make(6, "f");

    std::vector<IVertexPtr<int, std::string>> vertices =
    {
        vertex1,
        vertex2,
        vertex3,
        vertex4,
        vertex5,
        vertex6
    };

    IEdgePtr<int, std::string> edge12 = Edge<int, std::string>::makeDirected(vertex1, vertex2);
    IEdgePtr<int, std::string> edge13 = Edge<int, std::string>::makeDirected(vertex1, vertex3);
    IEdgePtr<int, std::string> edge24 = Edge<int, std::string>::makeDirected(vertex2, vertex4);
    IEdgePtr<int, std::string> edge32 = Edge<int, std::string>::makeDirected(vertex3, vertex2);
    IEdgePtr<int, std::string> edge35 = Edge<int, std::string>::makeDirected(vertex3, vertex5);
    IEdgePtr<int, std::string> edge45 = Edge<int, std::string>::makeDirected(vertex4, vertex5);
    IEdgePtr<int, std::string> edge46 = Edge<int, std::string>::makeDirected(vertex4, vertex6);
    IEdgePtr<int, std::string> edge56 = Edge<int, std::string>::makeDirected(vertex5, vertex6);

    std::vector<IEdgePtr<int, std::string>> edges =
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

    std::map<IEdgePtr<int, std::string>, int> weights;
    weights.insert(std::make_pair(edge12, 10));
    weights.insert(std::make_pair(edge13, 8));
    weights.insert(std::make_pair(edge24, 6));
    weights.insert(std::make_pair(edge32, 4));
    weights.insert(std::make_pair(edge35, 7));
    weights.insert(std::make_pair(edge45, 9));
    weights.insert(std::make_pair(edge46, 3));
    weights.insert(std::make_pair(edge56, 2));

    std::vector<std::pair<IRoutePtr<int, std::string>, std::vector<IWalkPtr<int, std::string>>>> paths;
    getGraphPathsData2(vertices, paths);

    base::ITwoDimensionalVectorPtr<IVertexPtr<int, std::string>> topologicalSearch = getGraphTopologicalSearchData2(
        vertices);

    std::map<IVertexPtr<int, std::string>, std::map<IVertexPtr<int, std::string>, size_t>> shortestPaths;
    getGraphShortestPaths2(
        vertices,
        shortestPaths);

    return GraphData<int, std::string>::make(
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
GraphDataPtr<int, std::string> GraphTestData::getGraphData3()
{
    IVertexPtr<int, std::string> vertex1 = Vertex<int, std::string>::make(1, "a");
    IVertexPtr<int, std::string> vertex2 = Vertex<int, std::string>::make(2, "b");
    IVertexPtr<int, std::string> vertex3 = Vertex<int, std::string>::make(3, "c");
    IVertexPtr<int, std::string> vertex4 = Vertex<int, std::string>::make(4, "d");
    IVertexPtr<int, std::string> vertex5 = Vertex<int, std::string>::make(5, "e");

    std::vector<IVertexPtr<int, std::string>> vertices =
    {
        vertex1,
        vertex2,
        vertex3,
        vertex4,
        vertex5
    };

    IEdgePtr<int, std::string> edge12 = Edge<int, std::string>::makeDirected(vertex1, vertex2);
    IEdgePtr<int, std::string> edge13 = Edge<int, std::string>::makeDirected(vertex1, vertex3);
    IEdgePtr<int, std::string> edge25 = Edge<int, std::string>::makeDirected(vertex2, vertex5);
    IEdgePtr<int, std::string> edge35 = Edge<int, std::string>::makeDirected(vertex3, vertex5);
    IEdgePtr<int, std::string> edge45 = Edge<int, std::string>::makeDirected(vertex4, vertex5);

    std::vector<IEdgePtr<int, std::string>> edges =
    {
        edge12,
        edge13,
        edge25,
        edge35,
        edge45
    };

    std::map<IEdgePtr<int, std::string>, int> weights =
    {
        {edge12, 7},
        {edge13, 8},
        {edge25, 13},
        {edge35, 6},
        {edge45, 2}
    };

    std::vector<std::pair<IRoutePtr<int, std::string>, std::vector<IWalkPtr<int, std::string>>>> paths;
    getGraphPathsData3(vertices, paths);

    base::ITwoDimensionalVectorPtr<IVertexPtr<int, std::string>> topologicalSearch = getGraphTopologicalSearchData3(
        vertices);

    std::map<IVertexPtr<int, std::string>, std::map<IVertexPtr<int, std::string>, size_t>> shortestPaths;
    getGraphShortestPaths3(
        vertices,
        shortestPaths);

    return GraphData<int, std::string>::make(
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
GraphDataPtr<int, std::string> GraphTestData::getGraphDataWithLoop1()
{
    IVertexPtr<int, std::string> vertex1 = Vertex<int, std::string>::make(1, "a");
    IVertexPtr<int, std::string> vertex2 = Vertex<int, std::string>::make(2, "b");
    IVertexPtr<int, std::string> vertex3 = Vertex<int, std::string>::make(3, "c");
    IVertexPtr<int, std::string> vertex4 = Vertex<int, std::string>::make(4, "d");

    std::vector<IVertexPtr<int, std::string>> vertices =
    {
        vertex1,
        vertex2,
        vertex3,
        vertex4
    };

    std::vector<IEdgePtr<int, std::string>> edges =
    {
        Edge<int, std::string>::makeDirected(vertex1, vertex2),
        Edge<int, std::string>::makeDirected(vertex1, vertex3),
        Edge<int, std::string>::makeDirected(vertex2, vertex3),
        Edge<int, std::string>::makeDirected(vertex3, vertex1),
        Edge<int, std::string>::makeDirected(vertex3, vertex4),
        Edge<int, std::string>::makeDirected(vertex4, vertex4)
    };

    GraphDataPtr<int, std::string> graphDataPtr = std::make_shared<GraphData<int, std::string>>(
        vertices,
        edges);

    return graphDataPtr;
}

/**
 * Gets the paths data of graph1.
 */
void GraphTestData::getGraphPathsData1(
    const std::vector<IVertexPtr<int, std::string>>& vertices,
    std::vector<std::pair<IRoutePtr<int, std::string>, std::vector<IWalkPtr<int, std::string>>>>& result)
{
    assert(vertices.size() == 4);
    IVertexPtr<int, std::string> vertex1 = vertices[0];
    IVertexPtr<int, std::string> vertex2 = vertices[1];
    IVertexPtr<int, std::string> vertex3 = vertices[2];
    IVertexPtr<int, std::string> vertex4 = vertices[3];

    IRoutePtr<int, std::string> route12 = Route<int, std::string>::make(vertex1, vertex2);
    std::vector<IWalkPtr<int, std::string>> walks12;
    Walk<int, std::string>::makeWalks(
        {
            {vertex1, vertex2}
        },
        walks12
    );

    result.push_back(std::make_pair(route12, walks12));

    IRoutePtr<int, std::string> route13 = Route<int, std::string>::make(vertex1, vertex3);
    std::vector<IWalkPtr<int, std::string>> walks13;
    Walk<int, std::string>::makeWalks(
        {
            {vertex1, vertex2, vertex3},
            {vertex1, vertex3}
        },
        walks13
    );

    result.push_back(std::make_pair(route13, walks13));

    IRoutePtr<int, std::string> route14 = Route<int, std::string>::make(vertex1, vertex4);
    std::vector<IWalkPtr<int, std::string>> walks14;
    Walk<int, std::string>::makeWalks(
        {
            {vertex1, vertex2, vertex3, vertex4},
            {vertex1, vertex3, vertex4}
        },
        walks14
    );

    result.push_back(std::make_pair(route14, walks14));

    IRoutePtr<int, std::string> route23 = Route<int, std::string>::make(vertex2, vertex3);
    std::vector<IWalkPtr<int, std::string>> walks23;
    Walk<int, std::string>::makeWalks(
        {
            {vertex2, vertex3}
        },
        walks23
    );

    result.push_back(std::make_pair(route23, walks23));

    IRoutePtr<int, std::string> route24 = Route<int, std::string>::make(vertex2, vertex4);
    std::vector<IWalkPtr<int, std::string>> walks24;
    Walk<int, std::string>::makeWalks(
        {
            {vertex2, vertex3, vertex4}
        },
        walks24
    );

    result.push_back(std::make_pair(route24, walks24));


    IRoutePtr<int, std::string> route34 = Route<int, std::string>::make(vertex3, vertex4);
    std::vector<IWalkPtr<int, std::string>> walks34;
    Walk<int, std::string>::makeWalks(
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
void GraphTestData::getGraphPathsData2(
    const std::vector<IVertexPtr<int, std::string>>& vertices,
    std::vector<std::pair<IRoutePtr<int, std::string>, std::vector<IWalkPtr<int, std::string>>>>& result)
{
    assert(vertices.size() == 6);
    IVertexPtr<int, std::string> vertex1 = vertices[0];
    IVertexPtr<int, std::string> vertex2 = vertices[1];
    IVertexPtr<int, std::string> vertex3 = vertices[2];
    IVertexPtr<int, std::string> vertex4 = vertices[3];
    IVertexPtr<int, std::string> vertex5 = vertices[4];
    IVertexPtr<int, std::string> vertex6 = vertices[5];

    IRoutePtr<int, std::string> route12 = Route<int, std::string>::make(vertex1, vertex2);
    std::vector<IWalkPtr<int, std::string>> walks12;
    Walk<int, std::string>::makeWalks(
        {
            {vertex1, vertex2},
            {vertex1, vertex3, vertex2}
        },
        walks12
    );

    result.push_back(std::make_pair(route12, walks12));

    IRoutePtr<int, std::string> route13 = Route<int, std::string>::make(vertex1, vertex3);
    std::vector<IWalkPtr<int, std::string>> walks13;
    Walk<int, std::string>::makeWalks(
        {
            {vertex1, vertex3}
        },
        walks13
    );

    result.push_back(std::make_pair(route13, walks13));

    IRoutePtr<int, std::string> route14 = Route<int, std::string>::make(vertex1, vertex4);
    std::vector<IWalkPtr<int, std::string>> walks14;
    Walk<int, std::string>::makeWalks(
        {
            {vertex1, vertex2, vertex4},
            {vertex1, vertex3, vertex2, vertex4}
        },
        walks14
    );

    result.push_back(std::make_pair(route14, walks14));

    IRoutePtr<int, std::string> route15 = Route<int, std::string>::make(vertex1, vertex5);
    std::vector<IWalkPtr<int, std::string>> walks15;
    Walk<int, std::string>::makeWalks(
        {
            {vertex1, vertex2, vertex4, vertex5},
            {vertex1, vertex3, vertex2, vertex4, vertex5},
            {vertex1, vertex3, vertex5}
        },
        walks15
    );

    result.push_back(std::make_pair(route15, walks15));

    IRoutePtr<int, std::string> route16 = Route<int, std::string>::make(vertex1, vertex6);
    std::vector<IWalkPtr<int, std::string>> walks16;
    Walk<int, std::string>::makeWalks(
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
void GraphTestData::getGraphPathsData3(
    const std::vector<IVertexPtr<int, std::string>>& vertices,
    std::vector<std::pair<IRoutePtr<int, std::string>, std::vector<IWalkPtr<int, std::string>>>>& result)
{
    assert(vertices.size() == 5);
    IVertexPtr<int, std::string> vertex1 = vertices[0];
    IVertexPtr<int, std::string> vertex2 = vertices[1];
    IVertexPtr<int, std::string> vertex3 = vertices[2];
    IVertexPtr<int, std::string> vertex4 = vertices[3];
    IVertexPtr<int, std::string> vertex5 = vertices[4];

    IRoutePtr<int, std::string> route12 = Route<int, std::string>::make(vertex1, vertex2);
    std::vector<IWalkPtr<int, std::string>> walks12;
    Walk<int, std::string>::makeWalks(
        {
            {vertex1, vertex2}
        },
        walks12
    );

    result.push_back(std::make_pair(route12, walks12));

    IRoutePtr<int, std::string> route13 = Route<int, std::string>::make(vertex1, vertex3);
    std::vector<IWalkPtr<int, std::string>> walks13;
    Walk<int, std::string>::makeWalks(
        {
            {vertex1, vertex3}
        },
        walks13
    );

    result.push_back(std::make_pair(route13, walks13));

    IRoutePtr<int, std::string> route15 = Route<int, std::string>::make(vertex1, vertex5);
    std::vector<IWalkPtr<int, std::string>> walks15;
    Walk<int, std::string>::makeWalks(
        {
            {vertex1, vertex2, vertex5},
            {vertex1, vertex3, vertex5}
        },
        walks15
    );

    result.push_back(std::make_pair(route15, walks15));

    IRoutePtr<int, std::string> route25 = Route<int, std::string>::make(vertex2, vertex5);
    std::vector<IWalkPtr<int, std::string>> walks25;
    Walk<int, std::string>::makeWalks(
        {
            {vertex2, vertex5}
        },
        walks25
    );

    result.push_back(std::make_pair(route25, walks25));

    IRoutePtr<int, std::string> route35 = Route<int, std::string>::make(vertex3, vertex5);
    std::vector<IWalkPtr<int, std::string>> walks35;
    Walk<int, std::string>::makeWalks(
        {
            {vertex3, vertex5}
        },
        walks35
    );

    result.push_back(std::make_pair(route35, walks35));

    IRoutePtr<int, std::string> route45 = Route<int, std::string>::make(vertex4, vertex5);
    std::vector<IWalkPtr<int, std::string>> walks45;
    Walk<int, std::string>::makeWalks(
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
base::ITwoDimensionalVectorPtr<IVertexPtr<int, std::string>> GraphTestData::getGraphTopologicalSearchData1(
    const std::vector<IVertexPtr<int, std::string>>& vertices)
{
    assert(vertices.size() == 4);
    IVertexPtr<int, std::string> vertex1 = vertices[0];
    IVertexPtr<int, std::string> vertex2 = vertices[1];
    IVertexPtr<int, std::string> vertex3 = vertices[2];
    IVertexPtr<int, std::string> vertex4 = vertices[3];

    base::ITwoDimensionalVectorPtr<IVertexPtr<int, std::string>> result =
        TwoDimensionalVector<IVertexPtr<int, std::string>>::make();

    result->addRow({vertex1});
    result->addRow({vertex2});
    result->addRow({vertex3});
    result->addRow({vertex4});

    return result;
}

/**
 * Gets the topological search data of graph2.
 */
base::ITwoDimensionalVectorPtr<IVertexPtr<int, std::string>> GraphTestData::getGraphTopologicalSearchData2(
    const std::vector<IVertexPtr<int, std::string>>& vertices)
{
    assert(vertices.size() == 6);
    IVertexPtr<int, std::string> vertex1 = vertices[0];
    IVertexPtr<int, std::string> vertex2 = vertices[1];
    IVertexPtr<int, std::string> vertex3 = vertices[2];
    IVertexPtr<int, std::string> vertex4 = vertices[3];
    IVertexPtr<int, std::string> vertex5 = vertices[4];
    IVertexPtr<int, std::string> vertex6 = vertices[5];

    base::ITwoDimensionalVectorPtr<IVertexPtr<int, std::string>> result =
        TwoDimensionalVector<IVertexPtr<int, std::string>>::make();

    result->addRow({vertex1});
    result->addRow({vertex3});
    result->addRow({vertex2});
    result->addRow({vertex4});
    result->addRow({vertex5});
    result->addRow({vertex6});

    return result;
}

/**
 * Gets the topological search data of graph3.
 */
base::ITwoDimensionalVectorPtr<IVertexPtr<int, std::string>> GraphTestData::getGraphTopologicalSearchData3(
    const std::vector<IVertexPtr<int, std::string>>& vertices)
{
    assert(vertices.size() == 5);
    IVertexPtr<int, std::string> vertex1 = vertices[0];
    IVertexPtr<int, std::string> vertex2 = vertices[1];
    IVertexPtr<int, std::string> vertex3 = vertices[2];
    IVertexPtr<int, std::string> vertex4 = vertices[3];
    IVertexPtr<int, std::string> vertex5 = vertices[4];

    base::ITwoDimensionalVectorPtr<IVertexPtr<int, std::string>> result =
        TwoDimensionalVector<IVertexPtr<int, std::string>>::make();

    result->addRow({vertex4});
    result->addRow({vertex1});
    result->addRow({vertex3});
    result->addRow({vertex2});
    result->addRow({vertex5});

    return result;
}

/**
 * Gets the shortest paths of graph1.
 */
void GraphTestData::getGraphShortestPaths1(
    const std::vector<IVertexPtr<int, std::string>>& vertices,
    std::map<IVertexPtr<int, std::string>, std::map<IVertexPtr<int, std::string>, size_t>>& result)
{
    assert(vertices.size() == 4);
    IVertexPtr<int, std::string> vertex1 = vertices[0];
    IVertexPtr<int, std::string> vertex2 = vertices[1];
    IVertexPtr<int, std::string> vertex3 = vertices[2];
    IVertexPtr<int, std::string> vertex4 = vertices[3];

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths1 =
    {
        {vertex1, 0},
        {vertex2, 5},
        {vertex3, 6},
        {vertex4, 10}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths2 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, 0},
        {vertex3, 2},
        {vertex4, 6}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths3 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, 0},
        {vertex4, 4}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths4 =
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
void GraphTestData::getGraphShortestPaths2(
    const std::vector<IVertexPtr<int, std::string>>& vertices,
    std::map<IVertexPtr<int, std::string>, std::map<IVertexPtr<int, std::string>, size_t>>& result)
{
    assert(vertices.size() == 6);
    IVertexPtr<int, std::string> vertex1 = vertices[0];
    IVertexPtr<int, std::string> vertex2 = vertices[1];
    IVertexPtr<int, std::string> vertex3 = vertices[2];
    IVertexPtr<int, std::string> vertex4 = vertices[3];
    IVertexPtr<int, std::string> vertex5 = vertices[4];
    IVertexPtr<int, std::string> vertex6 = vertices[5];

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths1 =
    {
        {vertex1, 0},
        {vertex2, 10},
        {vertex3, 8},
        {vertex4, 16},
        {vertex5, 15},
        {vertex6, 17}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths2 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, 0},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, 6},
        {vertex5, 15},
        {vertex6, 9}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths3 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, 4},
        {vertex3, 0},
        {vertex4, 10},
        {vertex5, 7},
        {vertex6, 9}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths4 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, 0},
        {vertex5, 9},
        {vertex6, 3}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths5 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, std::numeric_limits<int>::max()},
        {vertex5, 0},
        {vertex6, 2}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths6 =
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
void GraphTestData::getGraphShortestPaths3(
    const std::vector<IVertexPtr<int, std::string>>& vertices,
    std::map<IVertexPtr<int, std::string>, std::map<IVertexPtr<int, std::string>, size_t>>& result)
{
    assert(vertices.size() == 5);

    IVertexPtr<int, std::string> vertex1 = vertices[0];
    IVertexPtr<int, std::string> vertex2 = vertices[1];
    IVertexPtr<int, std::string> vertex3 = vertices[2];
    IVertexPtr<int, std::string> vertex4 = vertices[3];
    IVertexPtr<int, std::string> vertex5 = vertices[4];

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths1 =
    {
        {vertex1, 0},
        {vertex2, 7},
        {vertex3, 8},
        {vertex4, std::numeric_limits<int>::max()},
        {vertex5, 14}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths2 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, 0},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, std::numeric_limits<int>::max()},
        {vertex5, 13}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths3 =
    {
       {vertex1, std::numeric_limits<int>::max()},
       {vertex2, std::numeric_limits<int>::max()},
       {vertex3, 0},
       {vertex4, std::numeric_limits<int>::max()},
       {vertex5, 6}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths4 =
    {
        {vertex1, std::numeric_limits<int>::max()},
        {vertex2, std::numeric_limits<int>::max()},
        {vertex3, std::numeric_limits<int>::max()},
        {vertex4, 0},
        {vertex5, 2}
    };

    std::map<IVertexPtr<int, std::string>, size_t> shortestPaths5 =
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
