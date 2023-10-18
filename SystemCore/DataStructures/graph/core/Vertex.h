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
            static IVertexSharedPtr<TKey, TValue> Make(
                const TKey& key,
                const TValue& value);

            /**
             * Copies an instance of a vertex.
             */
            static IVertexSharedPtr<TKey, TValue> Copy(const IVertex<TKey, TValue>& vertex);

            /**
             * The Vertex constructor.
             */
            Vertex(const TKey& key, const TValue& value);

            /**
             * The Vertex destructor.
             */
            virtual ~Vertex();

            /**
             * The Copy/move constructors.
             */
            Vertex(const Vertex&) = delete;
            Vertex(Vertex&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            Vertex& operator=(const Vertex&) = delete;
            Vertex& operator=(Vertex&&) = delete;

            /**
             * Gets a key of a vertex.
             */
            virtual const TKey& GetKey() const override;

            /**
             * Gets a value of a vertex.
             */
            virtual const TValue& GetValue() const override;

            /**
             * Gets string representation ofthis instance.
             */
            virtual std::wstring ToString() const override;

        private:
            TKey m_key;
            TValue m_value;
        };

        /**
         * Creates a new instance of a vertex.
         */
        template <typename TKey, typename TValue>
        IVertexSharedPtr<TKey, TValue> Vertex<TKey, TValue>::Make(const TKey& key, const TValue& value)
        {
            return std::make_shared<Vertex<TKey, TValue>>(key, value);
        }

        /**
         * Copies an instance of a vertex.
         */
        template <typename TKey, typename TValue>
        IVertexSharedPtr<TKey, TValue> Vertex<TKey, TValue>::Copy(const IVertex<TKey, TValue>& vertex)
        {
            return std::make_shared<Vertex<TKey, TValue>>(vertex.getkey(), vertex.GetValue());
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
        const TKey& Vertex<TKey, TValue>::GetKey() const
        {
            return m_key;
        }

        /**
         * Gets a value of a vertex.
         */
        template <typename TKey, typename TValue>
        const TValue& Vertex<TKey, TValue>::GetValue() const
        {
            return m_value;
        }

        /**
         * Gets string representation ofthis instance.
         */
        template <typename TKey, typename TValue>
        std::wstring Vertex<TKey, TValue>::ToString() const
        {
            std::wstringstream stream;
            stream << L"(Key = " << m_key << L", Value = " << m_value << L")";
            return stream.str();
        }
    }
}

#endif // VERTEX_H_67f48eb1_8204_4f84_bb03_724f61edd240
