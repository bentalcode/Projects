#ifndef WALK_H_c382a318_e17c_404b_bd58_d077015d7d1f
#define WALK_H_c382a318_e17c_404b_bd58_d077015d7d1f

#include "Walk.h"
#include "ListIterator.h"
#include "ListReverseIterator.h"
#include "Collections.h"

using namespace base;

namespace datastructures {
    namespace graph {

        /**
         * The Walk class implements a walk in a graph.
         * A walk is a finite or infinite sequence of edges which joins a sequence of vertices.
         */
        template <typename TKey, typename TValue>
        class Walk final : public IWalk<TKey, TValue>
        {
        public:
            /**
             * Creates a new walk.
             */
            static IWalkPtr<TKey, TValue> make(
                const std::list<IVertexPtr<TKey, TValue>>& vertices);

            /**
             * Creates a new list of walks.
             */
            static void makeWalks(
                const std::vector<std::list<IVertexPtr<TKey, TValue>>>& verticeLists,
                std::vector<IWalkPtr<TKey, TValue>>& result);

            /**
             * The Walk constructor.
             */
            explicit Walk(const std::list<IVertexPtr<TKey, TValue>>& vertices);

            /**
             * The Walk destructor.
             */
            virtual ~Walk();

            /**
             * The copy/move constructors.
             */
            Walk(const Walk&) = delete;
            Walk(Walk&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            Walk& operator=(const Walk&) = delete;
            Walk& operator=(Walk&&) = delete;

            /**
             * Adds a vertex.
             */
            virtual void addVertex(IVertexPtr<TKey, TValue> vertex) override;

            /**
             * Removes the last vertex.
             */
            virtual void removeLastVertex() override;

            /**
             * Gets the vertices.
             */
            virtual const std::list<IVertexPtr<TKey, TValue>>& getVertices() const override;

            /**
             * Checks whether a vertex has been visited before.
             */
            virtual bool visited(const IVertex<TKey, TValue>& vertex) const override;

            /**
             * Gets the size of the collection.
             */
            virtual size_t size() const override;

            /**
             * Checks whether the collection is empty.
             */
            virtual bool empty() const override;

            /**
             * Gets the iterator.
             */
            virtual base::IIteratorPtr<IVertexPtr<TKey, TValue>> getIterator() const override;

            /**
             * Gets the reverse iterator.
             */
            virtual base::IReverseIteratorPtr<IVertexPtr<TKey, TValue>> getReverseIterator() const override;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const override;

        private:
            std::list<IVertexPtr<TKey, TValue>> m_vertices;
        };

        /**
         * Creates a new walk.
         */
        template <typename TKey, typename TValue>
        IWalkPtr<TKey, TValue> Walk<TKey, TValue>::make(const std::list<IVertexPtr<TKey, TValue>>& vertices)
        {
            return std::make_shared<Walk<TKey, TValue>>(vertices);
        }

        /**
         * Creates a new list of walks.
         */
        template <typename TKey, typename TValue>
        void Walk<TKey, TValue>::makeWalks(
            const std::vector<std::list<IVertexPtr<TKey, TValue>>>& verticeLists,
            std::vector<IWalkPtr<TKey, TValue>>& result)
        {
            for (const std::list<IVertexPtr<TKey, TValue>>& verticeList : verticeLists)
            {
                IWalkPtr<TKey, TValue> walk = Walk<TKey, TValue>::make(verticeList);
                result.push_back(walk);
            }
        }

        /**
         * The Walk constructor.
         */
        template <typename TKey, typename TValue>
        Walk<TKey, TValue>::Walk(const std::list<IVertexPtr<TKey, TValue>>& vertices) :
            m_vertices(vertices)
        {
        }

        /**
         * The Walk destructor.
         */
        template <typename TKey, typename TValue>
        Walk<TKey, TValue>::~Walk()
        {
        }

        /**
         * Adds a vertex.
         */
        template <typename TKey, typename TValue>
        void Walk<TKey, TValue>::addVertex(IVertexPtr<TKey, TValue> vertex)
        {
            m_vertices.push_back(vertex);
        }

        /**
         * Removes the last vertex.
         */
        template <typename TKey, typename TValue>
        void Walk<TKey, TValue>::removeLastVertex()
        {
            m_vertices.pop_back();
        }

        /**
         * Gets the vertices.
         */
        template <typename TKey, typename TValue>
        const std::list<IVertexPtr<TKey, TValue>>& Walk<TKey, TValue>::getVertices() const
        {
            return m_vertices;
        }

        /**
         * Checks whether a vertex has been visited before.
         */
        template <typename TKey, typename TValue>
        bool Walk<TKey, TValue>::visited(const IVertex<TKey, TValue>& vertex) const
        {
            for (typename std::list<IVertexPtr<TKey, TValue>>::const_reverse_iterator vertexIterator = m_vertices.rbegin();
                 vertexIterator != m_vertices.rend();
                 ++vertexIterator)
            {
                IVertexPtr<TKey, TValue> currVertex = *vertexIterator;

                if (*currVertex == vertex)
                {
                    return true;
                }
            }

            return false;
        }

        /**
         * Gets the size of the collection.
         */
        template <typename TKey, typename TValue>
        size_t Walk<TKey, TValue>::size() const
        {
            return m_vertices.size();
        }

        /**
         * Checks whether the collection is empty.
         */
        template <typename TKey, typename TValue>
        bool Walk<TKey, TValue>::empty() const
        {
            return m_vertices.empty();
        }

        /**
         * Gets the iterator.
         */
        template <typename TKey, typename TValue>
        base::IIteratorPtr<IVertexPtr<TKey, TValue>> Walk<TKey, TValue>::getIterator() const
        {
            return base::ListIterator<IVertexPtr<TKey, TValue>>::make(m_vertices);
        }

        /**
         * Gets the reverse iterator.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorPtr<IVertexPtr<TKey, TValue>> Walk<TKey, TValue>::getReverseIterator() const
        {
            return base::ListReverseIterator<IVertexPtr<TKey, TValue>>::make(m_vertices);
        }

        /**
         * Gets string representation of this instance.
         */
        template <typename TKey, typename TValue>
        std::string Walk<TKey, TValue>::toString() const
        {
            return Collections::toString(m_vertices);
        }
    }
}

#endif // WALK_H_c382a318_e17c_404b_bd58_d077015d7d1f
