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
            static IGraphDefinitionPtr<TKey, TValue> make(
                const std::vector<IVertexPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgePtr<TKey, TValue>>& edges);

            /**
             * The GraphDefinition constructor.
             */
            GraphDefinition(
                const std::vector<IVertexPtr<TKey, TValue>>& vertices,
                const std::vector<IEdgePtr<TKey, TValue>>& edges);

            /**
             * The GraphDefinition destructor.
             */
            virtual ~GraphDefinition();

            /**
             * The copy/move constructors.
             */
            GraphDefinition(const GraphDefinition&) = delete;
            GraphDefinition(GraphDefinition&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            GraphDefinition& operator=(const GraphDefinition&) = delete;
            GraphDefinition& operator=(GraphDefinition&&) = delete;

            /**
             * Gets the vertices of the graph.
             */
            virtual const std::vector<IVertexPtr<TKey, TValue>>& vertices() const override;

            /**
             * Gets the edges of the graph.
             */
            virtual const std::vector<IEdgePtr<TKey, TValue>>& edges() const override;

        private:
            std::vector<IVertexPtr<TKey, TValue>> m_vertices;
            std::vector<IEdgePtr<TKey, TValue>> m_edges;
        };

        /**
         * Creates new graph definition.
         */
        template <typename TKey, typename TValue>
        IGraphDefinitionPtr<TKey, TValue> GraphDefinition<TKey, TValue>::make(
            const std::vector<IVertexPtr<TKey, TValue>>& vertices,
            const std::vector<IEdgePtr<TKey, TValue>>& edges)
        {
            return std::make_shared<GraphDefinition>(vertices, edges);
        }

        /**
         * The GraphDefinition constructor.
         */
        template <typename TKey, typename TValue>
        GraphDefinition<TKey, TValue>::GraphDefinition(
            const std::vector<IVertexPtr<TKey, TValue>>& vertices,
            const std::vector<IEdgePtr<TKey, TValue>>& edges) :
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
         * Gets the vertices of the graph.
         */
        template <typename TKey, typename TValue>
        const std::vector<IVertexPtr<TKey, TValue>>& GraphDefinition<TKey, TValue>::vertices() const
        {
            return m_vertices;
        }

        /**
         * Gets the edges of the graph.
         */
        template <typename TKey, typename TValue>
        const std::vector<IEdgePtr<TKey, TValue>>& GraphDefinition<TKey, TValue>::edges() const
        {
            return m_edges;
        }

    }
}

#endif // GRAPH_DEFINITION_H_130aac71_5741_462d_aff4_988e398d8f44
