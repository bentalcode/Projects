#ifndef I_GRAPH_DEFINITION_H_d740ccaa_aca3_49f8_8f95_e14597618e91
#define I_GRAPH_DEFINITION_H_d740ccaa_aca3_49f8_8f95_e14597618e91

#include "IVertex.h"
#include "IEdge.h"

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
             * The copy/move constructors.
             */
            IGraphDefinition(const IGraphDefinition&) = delete;
            IGraphDefinition(IGraphDefinition&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IGraphDefinition& operator=(const IGraphDefinition&) = delete;
            IGraphDefinition& operator=(IGraphDefinition&&) = delete;

            /**
             * Gets the vertices of the graph.
             */
            virtual const std::vector<IVertexPtr<TKey, TValue>>& vertices() const = 0;

            /**
             * Gets the edges of the graph.
             */
            virtual const std::vector<IEdgePtr<TKey, TValue>>& edges() const = 0;
        };

        template <typename TKey, typename TValue>
        using IGraphDefinitionPtr = std::shared_ptr<IGraphDefinition<TKey, TValue>>;

        template <typename TKey, typename TValue>
        using VertexShortestPathsMap = std::map<IVertexPtr<TKey, TValue>, long, base::DereferenceLess<IVertexPtr<TKey, TValue>>>;

        template <typename TKey, typename TValue>
        using GraphShortestPathsMap = std::map<IVertexPtr<TKey, TValue>, VertexShortestPathsMap<TKey, TValue>>;

        template <typename TKey, typename TValue>
        using EdgeWeightMap = std::map<IEdgePtr<TKey, TValue>, long, base::DereferenceLess<IEdgePtr<TKey, TValue>>>;

        template <typename TKey, typename TValue>
        using RoutesPaths = std::vector<std::pair<IRoutePtr<TKey, TValue>, std::vector<IWalkPtr<TKey, TValue>>>>;
    }
}

#endif // I_GRAPH_DEFINITION_H_d740ccaa_aca3_49f8_8f95_e14597618e91
