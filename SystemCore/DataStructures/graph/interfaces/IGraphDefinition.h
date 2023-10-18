#ifndef I_GRAPH_DEFINITION_H_d740ccaa_aca3_49f8_8f95_e14597618e91
#define I_GRAPH_DEFINITION_H_d740ccaa_aca3_49f8_8f95_e14597618e91

#include "IVertex.h"
#include "IEdge.h"
#include "BaseLogic.h"

namespace datastructures {
    namespace graph {

        /**
         * The IGraphDefinition interface defines a graph definition.
         */
        template <typename TKey, typename TValue>
        class IGraphDefinition
        {
        public:
            /**
             * The constructor.
             */
            IGraphDefinition() = default;

            /**
             * The destructor.
             */
            virtual ~IGraphDefinition() = default;

            /**
             * The Copy/move constructors.
             */
            IGraphDefinition(const IGraphDefinition&) = delete;
            IGraphDefinition(IGraphDefinition&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IGraphDefinition& operator=(const IGraphDefinition&) = delete;
            IGraphDefinition& operator=(IGraphDefinition&&) = delete;

            /**
             * Gets the Vertices of the graph.
             */
            virtual const std::vector<IVertexSharedPtr<TKey, TValue>>& Vertices() const = 0;

            /**
             * Gets the Edges of the graph.
             */
            virtual const std::vector<IEdgeSharedPtr<TKey, TValue>>& Edges() const = 0;
        };

        /**
         * Defines the SharedPtr ofGraph Definition.
         */
        template <typename TKey, typename TValue>
        using IGraphDefinitionSharedPtr = std::shared_ptr<IGraphDefinition<TKey, TValue>>;

        /**
         * Defines Vertex Shortest Paths Map.
         */
        template <typename TKey, typename TValue>
        using VertexShortestPathsMap = std::map<IVertexSharedPtr<TKey, TValue>, long, base::DereferenceLess<IVertexSharedPtr<TKey, TValue>>>;

        /**
         * Defines Graph Shortest Paths Map.
         */
        template <typename TKey, typename TValue>
        using GraphShortestPathsMap = std::map<IVertexSharedPtr<TKey, TValue>, VertexShortestPathsMap<TKey, TValue>>;

        /**
         * Defines Edge Weight Map.
         */
        template <typename TKey, typename TValue>
        using EdgeWeightMap = std::map<IEdgeSharedPtr<TKey, TValue>, long, base::DereferenceLess<IEdgeSharedPtr<TKey, TValue>>>;

        /**
         * Defines Routs Paths.
         */
        template <typename TKey, typename TValue>
        using RoutesPaths = std::vector<std::pair<IRouteSharedPtr<TKey, TValue>, std::vector<IWalkSharedPtr<TKey, TValue>>>>;
    }
}

#endif // I_GRAPH_DEFINITION_H_d740ccaa_aca3_49f8_8f95_e14597618e91
