#ifndef WALK_H_c382a318_e17c_404b_bd58_d077015d7d1f
#define WALK_H_c382a318_e17c_404b_bd58_d077015d7d1f

#include "IWalk.h"
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
            static IWalkSharedPtr<TKey, TValue> make();

            /**
             * Creates a new walk.
             */
            static IWalkSharedPtr<TKey, TValue> make(
                const std::list<IVertexSharedPtr<TKey, TValue>>& vertices);

            /**
             * Copies a walk.
             */
            static IWalkSharedPtr<TKey, TValue> copy(
                const IWalk<TKey, TValue>& walk);

            /**
             * Creates a new list of walks.
             */
            static void makeWalks(
                const std::vector<std::list<IVertexSharedPtr<TKey, TValue>>>& verticeLists,
                std::vector<IWalkSharedPtr<TKey, TValue>>& result);

            /**
             * The Walk constructor.
             */
            Walk();

            /**
             * The Walk constructor.
             */
            explicit Walk(const std::list<IVertexSharedPtr<TKey, TValue>>& vertices);

            /**
             * The Walk destructor.
             */
            virtual ~Walk();

            /**
             * The copy/move constructors.
             */
            Walk(const IWalk<TKey, TValue>&);
            Walk(Walk&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            Walk& operator=(const IWalk<TKey, TValue>&);
            Walk& operator=(Walk<TKey, TValue>&&) = delete;

            /**
             * Adds a vertex.
             */
            virtual void addVertex(IVertexSharedPtr<TKey, TValue> vertex) override;

            /**
             * Removes the last vertex.
             */
            virtual void removeLastVertex() override;

            /**
             * Gets the vertices.
             */
            virtual const std::list<IVertexSharedPtr<TKey, TValue>>& getVertices() const override;

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
            virtual base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> getIterator() const override;

            /**
             * Gets the reverse iterator.
             */
            virtual base::IReverseIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> getReverseIterator() const override;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const override;

        private:
            std::list<IVertexSharedPtr<TKey, TValue>> m_vertices;
        };

        /**
         * Creates a new walk.
         */
        template <typename TKey, typename TValue>
        IWalkSharedPtr<TKey, TValue> Walk<TKey, TValue>::make()
        {
            return std::make_shared<Walk<TKey, TValue>>();
        }

        /**
         * Creates a new walk.
         */
        template <typename TKey, typename TValue>
        IWalkSharedPtr<TKey, TValue> Walk<TKey, TValue>::make(const std::list<IVertexSharedPtr<TKey, TValue>>& vertices)
        {
            return std::make_shared<Walk<TKey, TValue>>(vertices);
        }

        /**
         * Copies a walk.
         */
        template <typename TKey, typename TValue>
        IWalkSharedPtr<TKey, TValue> Walk<TKey, TValue>::copy(const IWalk<TKey, TValue>& walk)
        {
            return std::make_shared<Walk<TKey, TValue>>(walk);
        }

        /**
         * Creates a new list of walks.
         */
        template <typename TKey, typename TValue>
        void Walk<TKey, TValue>::makeWalks(
            const std::vector<std::list<IVertexSharedPtr<TKey, TValue>>>& verticeLists,
            std::vector<IWalkSharedPtr<TKey, TValue>>& result)
        {
            for (const std::list<IVertexSharedPtr<TKey, TValue>>& verticeList : verticeLists)
            {
                IWalkSharedPtr<TKey, TValue> walk = Walk<TKey, TValue>::make(verticeList);
                result.push_back(walk);
            }
        }

        /**
         * The Walk constructor.
         */
        template <typename TKey, typename TValue>
        Walk<TKey, TValue>::Walk()
        {
        }

        /**
         * The Walk constructor.
         */
        template <typename TKey, typename TValue>
        Walk<TKey, TValue>::Walk(const std::list<IVertexSharedPtr<TKey, TValue>>& vertices) :
            m_vertices(vertices)
        {
        }

        /**
         * The Walk copy constructor.
         */
        template <typename TKey, typename TValue>
        Walk<TKey, TValue>::Walk(const IWalk<TKey, TValue>& walk) :
            m_vertices(walk.getVertices())
        {
        }

        /**
         * The Walk assignment operator.
         */
        template <typename TKey, typename TValue>
        Walk<TKey, TValue>& Walk<TKey, TValue>::operator=(const IWalk<TKey, TValue>& other)
        {
            if (this == &other)
            {
                return *this;
            }

            m_vertices = other.m_vertices;

            return *this;
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
        void Walk<TKey, TValue>::addVertex(IVertexSharedPtr<TKey, TValue> vertex)
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
        const std::list<IVertexSharedPtr<TKey, TValue>>& Walk<TKey, TValue>::getVertices() const
        {
            return m_vertices;
        }

        /**
         * Checks whether a vertex has been visited before.
         */
        template <typename TKey, typename TValue>
        bool Walk<TKey, TValue>::visited(const IVertex<TKey, TValue>& vertex) const
        {
            for (typename std::list<IVertexSharedPtr<TKey, TValue>>::const_reverse_iterator vertexIterator = m_vertices.rbegin();
                 vertexIterator != m_vertices.rend();
                 ++vertexIterator)
            {
                IVertexSharedPtr<TKey, TValue> currVertex = *vertexIterator;

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
        base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> Walk<TKey, TValue>::getIterator() const
        {
            return base::ListIterator<IVertexSharedPtr<TKey, TValue>>::make(m_vertices);
        }

        /**
         * Gets the reverse iterator.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> Walk<TKey, TValue>::getReverseIterator() const
        {
            return base::ListReverseIterator<IVertexSharedPtr<TKey, TValue>>::make(m_vertices);
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
