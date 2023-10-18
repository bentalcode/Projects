#ifndef I_VERTEX_H_ae4664b1_aabd_4dc5_9490_0c42c1740f0a
#define I_VERTEX_H_ae4664b1_aabd_4dc5_9490_0c42c1740f0a

#include <string>
#include <memory>

namespace datastructures {
    namespace graph {

        /**
         * The IVertex interface defines a vertex of a graph.
         */
        template <typename TKey, typename TValue>
        class IVertex
        {
        public:
            /**
             * The constructor.
             */
            IVertex() = default;

            /**
             * The destructor.
             */
            virtual ~IVertex() = default;

            /**
             * The Copy/move constructors.
             */
            IVertex(const IVertex&) = delete;
            IVertex(IVertex&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IVertex& operator=(const IVertex&) = delete;
            IVertex& operator=(IVertex&&) = delete;

            /**
             * Gets a key of a vertex.
             */
            virtual const TKey& GetKey() const = 0;

            /**
             * Gets a value of a vertex.
             */
            virtual const TValue& GetValue() const = 0;

            /**
             * Gets string representation ofthis instance.
             */
            virtual std::wstring ToString() const = 0;
        };

        /**
         * Defines the SharedPtr ofVertex.
         */
        template <typename TKey, typename TValue>
        using IVertexSharedPtr = std::shared_ptr<IVertex<TKey, TValue>>;

        /**
         * Implements an operator equals for vertexes.
         */
        template <typename TKey, typename TValue>
        inline bool operator==(
            const IVertex<TKey, TValue>& lhs,
            const IVertex<TKey, TValue>& rhs)
        {
            return lhs.GetKey() == rhs.GetKey();
        }

        /**
         * Implements an operator not equals for vertexes.
         */
        template <typename TKey, typename TValue>
        inline bool operator!=(
            const IVertex<TKey, TValue>& lhs,
            const IVertex<TKey, TValue>& rhs)
        {
            return !(lhs == rhs);
        }
        
        /**
         * Defines an operator less than for vertexes.
         */
        template <typename TKey, typename TValue>
        bool operator<(
            const IVertex<TKey, TValue>& lhs, 
            const IVertex<TKey, TValue>& rhs)
        {
            return lhs.GetKey() < rhs.GetKey();
        }

        /**
         * Defines an operator less or equal than for vertexes.
         */
        template <typename TKey, typename TValue>
        bool operator<=(
            const IVertex<TKey, TValue>& lhs, 
            const IVertex<TKey, TValue>& rhs)
        {
            return !(rhs.GetKey() < lhs.GetKey());
        }

        /**
         * Defines an operator grater than for vertexes.
         */
        template <typename TKey, typename TValue>
        bool operator>(
            const IVertex<TKey, TValue>& lhs,
            const IVertex<TKey, TValue>& rhs)
        {
            return rhs.GetKey() < lhs.GetKey();
        }

        /**
         * Defines an operator grater or equal than for vertexes.
         */
        template <typename TKey, typename TValue>
        bool operator>=(
            const IVertex<TKey, TValue>& lhs,
            const IVertex<TKey, TValue>& rhs)
        {
            return !(lhs.GetKey() < rhs.GetKey());
        }

        /**
         * Serializes the object to an output stream.
         */
        template <typename TKey, typename TValue>
        std::wostream& operator<<(std::wostream& stream, const IVertex<TKey, TValue>& vertex)
        {
            stream << vertex.ToString();
            return stream;
        }
    }
}

#endif // I_VERTEX_H_ae4664b1_aabd_4dc5_9490_0c42c1740f0a
