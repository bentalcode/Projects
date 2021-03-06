#ifndef I_VERTEX_H_ae4664b1_aabd_4dc5_9490_0c42c1740f0a
#define I_VERTEX_H_ae4664b1_aabd_4dc5_9490_0c42c1740f0a

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
             * The copy/move constructors.
             */
            IVertex(const IVertex&) = delete;
            IVertex(IVertex&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IVertex& operator=(const IVertex&) = delete;
            IVertex& operator=(IVertex&&) = delete;

            /**
             * Gets a key of a vertex.
             */
            virtual const TKey& getKey() const = 0;

            /**
             * Gets a value of a vertex.
             */
            virtual const TValue& getValue() const = 0;

            /**
             * Gets string representation of this instance.
             */
            virtual std::string toString() const = 0;
        };

        template <typename TKey, typename TValue>
        using IVertexPtr = std::shared_ptr<IVertex<TKey, TValue>>;

        /**
         * Defines the equivalent operator.
         */
        template <typename TKey, typename TValue>
        bool operator<(const IVertex<TKey, TValue>& left, const IVertex<TKey, TValue>& right)
        {
            return left.getKey() < right.getKey();
        }

        /**
         * Serializes the object to an output stream.
         */
        template <typename TKey, typename TValue>
        std::ostream& operator<<(std::ostream& stream, const IVertex<TKey, TValue>& vertex)
        {
            stream << vertex.toString();
            return stream;
        }
    }
}

#endif // I_VERTEX_H_ae4664b1_aabd_4dc5_9490_0c42c1740f0a
