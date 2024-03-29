#ifndef GRAPH_DEFINITION_H_130aac71_5741_462d_aff4_988e398d8f44
#define GRAPH_DEFINITION_H_130aac71_5741_462d_aff4_988e398d8f44

#include "IGraphDefinition.h"
#include "IGraph.h"

namespace datastructures {
    namespace graph {

        /**
         * The GraphDefinition class implements a definition of a graph.
         */
        template <typename TKey, typename TValue>
        class GraphDefinition final : public IGraphDefinition<TKey, TValue>
        {
        public:
            /**
             * Creates new graph definition.
             */
            static IGraphDefinitionSharedPtr<TKey, TValue> Make(
                const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges);

            /**
             * The GraphDefinition constructor.
             */
            GraphDefinition(
                const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges);

            /**
             * The GraphDefinition destructor.
             */
            virtual ~GraphDefinition();

            /**
             * The Copy/move constructors.
             */
            GraphDefinition(const GraphDefinition&) = delete;
            GraphDefinition(GraphDefinition&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            GraphDefinition& operator=(const GraphDefinition&) = delete;
            GraphDefinition& operator=(GraphDefinition&&) = delete;

            /**
             * Gets the Vertices of the graph.
             */
            virtual const std::vector<IVertexSharedPtr<TKey, TValue>>& Vertices() const override;

            /**
             * Gets the Edges of the graph.
             */
            virtual const std::vector<IEdgeSharedPtr<TKey, TValue>>& Edges() const override;

        private:
            std::vector<IVertexSharedPtr<TKey, TValue>> m_vertices;
            std::vector<IEdgeSharedPtr<TKey, TValue>> m_edges;
        };

        /**
         * Creates new graph definition.
         */
        template <typename TKey, typename TValue>
        IGraphDefinitionSharedPtr<TKey, TValue> GraphDefinition<TKey, TValue>::Make(
            const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices,
            const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges)
        {
            return std::make_shared<GraphDefinition>(vertices, edges);
        }

        /**
         * The GraphDefinition constructor.
         */
        template <typename TKey, typename TValue>
        GraphDefinition<TKey, TValue>::GraphDefinition(
            const std::vector<IVertexSharedPtr<TKey, TValue>>& vertices,
            const std::vector<IEdgeSharedPtr<TKey, TValue>>& edges) :
            m_vertices(vertices),
            m_edges(edges)
        {
        }

        /**
         * The GraphDefinition destructor.
         */
        template <typename TKey, typename TValue>
        GraphDefinition<TKey, TValue>::~GraphDefinition()
        {
        }

        /**
         * Gets the Vertices of the graph.
         */
        template <typename TKey, typename TValue>
        const std::vector<IVertexSharedPtr<TKey, TValue>>& GraphDefinition<TKey, TValue>::Vertices() const
        {
            return m_vertices;
        }

        /**
         * Gets the Edges of the graph.
         */
        template <typename TKey, typename TValue>
        const std::vector<IEdgeSharedPtr<TKey, TValue>>& GraphDefinition<TKey, TValue>::Edges() const
        {
            return m_edges;
        }

    }
}

#endif // GRAPH_DEFINITION_H_130aac71_5741_462d_aff4_988e398d8f44
