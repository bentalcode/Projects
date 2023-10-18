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
         * A walk is a finite or infinite sequence of Edges which joins a sequence ofVertices.
         */
        template <typename TKey, typename TValue>
        class Walk final : public IWalk<TKey, TValue>
        {
        public:
            /**
             * Creates a new walk.
             */
            static IWalkSharedPtr<TKey, TValue> Make();

            /**
             * Creates a new walk.
             */
            static IWalkSharedPtr<TKey, TValue> Make(
                const std::list<IVertexSharedPtr<TKey, TValue>>& vertices);

            /**
             * Copies a walk.
             */
            static IWalkSharedPtr<TKey, TValue> Copy(
                const IWalk<TKey, TValue>& walk);

            /**
             * Creates a new list ofwalks.
             */
            static void MakeWalks(
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
             * The Copy/move constructors.
             */
            Walk(const IWalk<TKey, TValue>&);
            Walk(Walk&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            Walk& operator=(const IWalk<TKey, TValue>&);
            Walk& operator=(Walk<TKey, TValue>&&) = delete;

            /**
             * Adds a vertex.
             */
            virtual void AddVertex(IVertexSharedPtr<TKey, TValue> vertex) override;

            /**
             * Removes the last vertex.
             */
            virtual void RemoveLastVertex() override;

            /**
             * Gets the Vertices.
             */
            virtual const std::list<IVertexSharedPtr<TKey, TValue>>& GetVertices() const override;

            /**
             * Checks whether a vertex Has been Visited before.
             */
            virtual bool Visited(const IVertex<TKey, TValue>& vertex) const override;

            /**
             * Gets the Size of the collection.
             */
            virtual size_t Size() const override;

            /**
             * Checks whether the collection is Empty.
             */
            virtual bool Empty() const override;

            /**
             * Gets the iterator.
             */
            virtual base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> GetIterator() const override;

            /**
             * Gets the reverse iterator.
             */
            virtual base::IReverseIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> GetReverseIterator() const override;

            /**
             * Gets string representation ofthis instance.
             */
            virtual std::wstring ToString() const override;

        private:
            std::list<IVertexSharedPtr<TKey, TValue>> m_vertices;
        };

        /**
         * Creates a new walk.
         */
        template <typename TKey, typename TValue>
        IWalkSharedPtr<TKey, TValue> Walk<TKey, TValue>::Make()
        {
            return std::make_shared<Walk<TKey, TValue>>();
        }

        /**
         * Creates a new walk.
         */
        template <typename TKey, typename TValue>
        IWalkSharedPtr<TKey, TValue> Walk<TKey, TValue>::Make(const std::list<IVertexSharedPtr<TKey, TValue>>& vertices)
        {
            return std::make_shared<Walk<TKey, TValue>>(vertices);
        }

        /**
         * Copies a walk.
         */
        template <typename TKey, typename TValue>
        IWalkSharedPtr<TKey, TValue> Walk<TKey, TValue>::Copy(const IWalk<TKey, TValue>& walk)
        {
            return std::make_shared<Walk<TKey, TValue>>(walk);
        }

        /**
         * Creates a new list ofwalks.
         */
        template <typename TKey, typename TValue>
        void Walk<TKey, TValue>::MakeWalks(
            const std::vector<std::list<IVertexSharedPtr<TKey, TValue>>>& verticeLists,
            std::vector<IWalkSharedPtr<TKey, TValue>>& result)
        {
            for (const std::list<IVertexSharedPtr<TKey, TValue>>& verticeList : verticeLists)
            {
                IWalkSharedPtr<TKey, TValue> walk = Walk<TKey, TValue>::Make(verticeList);
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
         * The Walk Copy constructor.
         */
        template <typename TKey, typename TValue>
        Walk<TKey, TValue>::Walk(const IWalk<TKey, TValue>& walk) :
            m_vertices(walk.GetVertices())
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
        void Walk<TKey, TValue>::AddVertex(IVertexSharedPtr<TKey, TValue> vertex)
        {
            m_vertices.push_back(vertex);
        }

        /**
         * Removes the last vertex.
         */
        template <typename TKey, typename TValue>
        void Walk<TKey, TValue>::RemoveLastVertex()
        {
            m_vertices.pop_back();
        }

        /**
         * Gets the Vertices.
         */
        template <typename TKey, typename TValue>
        const std::list<IVertexSharedPtr<TKey, TValue>>& Walk<TKey, TValue>::GetVertices() const
        {
            return m_vertices;
        }

        /**
         * Checks whether a vertex Has been Visited before.
         */
        template <typename TKey, typename TValue>
        bool Walk<TKey, TValue>::Visited(const IVertex<TKey, TValue>& vertex) const
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
         * Gets the Size of the collection.
         */
        template <typename TKey, typename TValue>
        size_t Walk<TKey, TValue>::Size() const
        {
            return m_vertices.size();
        }

        /**
         * Checks whether the collection is Empty.
         */
        template <typename TKey, typename TValue>
        bool Walk<TKey, TValue>::Empty() const
        {
            return m_vertices.empty();
        }

        /**
         * Gets the iterator.
         */
        template <typename TKey, typename TValue>
        base::IIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> Walk<TKey, TValue>::GetIterator() const
        {
            return base::ListIterator<IVertexSharedPtr<TKey, TValue>>::Make(m_vertices);
        }

        /**
         * Gets the reverse iterator.
         */
        template <typename TKey, typename TValue>
        base::IReverseIteratorSharedPtr<IVertexSharedPtr<TKey, TValue>> Walk<TKey, TValue>::GetReverseIterator() const
        {
            return base::ListReverseIterator<IVertexSharedPtr<TKey, TValue>>::Make(m_vertices);
        }

        /**
         * Gets string representation of this instance.
         */
        template <typename TKey, typename TValue>
        std::wstring Walk<TKey, TValue>::ToString() const
        {
            return Collections::ToString(m_vertices);
        }
    }
}

#endif // WALK_H_c382a318_e17c_404b_bd58_d077015d7d1f
