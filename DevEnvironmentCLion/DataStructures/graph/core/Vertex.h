#ifndef VERTEX_H_67f48eb1_8204_4f84_bb03_724f61edd240
#define VERTEX_H_67f48eb1_8204_4f84_bb03_724f61edd240

#include "IVertex.h"

namespace datastructures {
    namespace graph {

        /**
         * The Vertex class implements a vertex of a graph.
         */
        template <typename TKey, typename TValue>
        class Vertex final : public IVertex<TKey, TValue>
        {
        public:
            /**
             * Creates a new instance of a vertex.
             */
            static IVertexPtr<TKey, TValue> make(
                const TKey& key,
                const TValue& value);

            /**
             * Copies an instance of a vertex.
             */
            static IVertexPtr<TKey, TValue> copy(const IVertex<TKey, TValue>& vertex);

            /**
             * The Vertex constructor.
             */
            Vertex(const TKey& key, const TValue& value);

            /**
             * The Vertex destructor.
             */
            virtual ~Vertex();

            /**
             * The copy/move constructors.
             */
            Vertex(const Vertex&) = delete;
            Vertex(Vertex&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            Vertex& operator=(const Vertex&) = delete;
            Vertex& operator=(Vertex&&) = delete;

            /**
             * Gets a key of a vertex.
             */
            virtual const TKey& getKey() const override;

            /**
             * Gets a value of a vertex.
             */
            virtual const TValue& getValue() const override;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const override;

        private:
            TKey m_key;
            TValue m_value;
        };

        /**
         * Creates a new instance of a vertex.
         */
        template <typename TKey, typename TValue>
        IVertexPtr<TKey, TValue> Vertex<TKey, TValue>::make(const TKey& key, const TValue& value)
        {
            return std::make_shared<Vertex<TKey, TValue>>(key, value);
        }

        /**
         * Copies an instance of a vertex.
         */
        template <typename TKey, typename TValue>
        IVertexPtr<TKey, TValue> Vertex<TKey, TValue>::copy(const IVertex<TKey, TValue>& vertex)
        {
            return std::make_shared<Vertex<TKey, TValue>>(vertex.getkey(), vertex.getValue());
        }

        /**
         * The Vertex constructor.
         */
        template <typename TKey, typename TValue>
        Vertex<TKey, TValue>::Vertex(const TKey& key, const TValue& value) :
            m_key(key),
            m_value(value)
        {
        }

        /**
         * The Vertex destructor.
         */
        template <typename TKey, typename TValue>
        Vertex<TKey, TValue>::~Vertex()
        {
        }

        /**
         * Gets a key of a vertex.
         */
        template <typename TKey, typename TValue>
        const TKey& Vertex<TKey, TValue>::getKey() const
        {
            return m_key;
        }

        /**
         * Gets a value of a vertex.
         */
        template <typename TKey, typename TValue>
        const TValue& Vertex<TKey, TValue>::getValue() const
        {
            return m_value;
        }

        /**
         * Gets string representation of this instance.
         */
        template <typename TKey, typename TValue>
        std::string Vertex<TKey, TValue>::toString() const
        {
            std::stringstream stream;
            stream << "(Key = " << m_key << ", Value = " << m_value << ")";
            return stream.str();
        }
    }
}

#endif // VERTEX_H_67f48eb1_8204_4f84_bb03_724f61edd240
