#ifndef I_PATH_FINDER_H_9915194f_07ef_474c_a5fe_4d1d995175d6
#define I_PATH_FINDER_H_9915194f_07ef_474c_a5fe_4d1d995175d6

#include "IVertex.h"

namespace datastructures {
    namespace graph {

        /**
         * The IPathFinder interface defines a path finder.
         */
        template <typename TKey, typename TValue>
        class IPathFinder
        {
        public:
            /**
             * The constructor.
             */
            IPathFinder() = default;

            /**
             * The destructor.
             */
            virtual ~IPathFinder() = default;

            /**
             * The copy/move constructors.
             */
            IPathFinder(const IPathFinder&) = delete;
            IPathFinder(IPathFinder&&) = delete;

            /**
             * The copy/move assignment operators.
             */
            IPathFinder& operator=(const IPathFinder&) = delete;
            IPathFinder& operator=(IPathFinder&&) = delete;

            /**
             * Finds paths.
             */
            virtual void findPaths(
                const IRoute<TKey, TValue>& route,
                std::list<IWalkPtr<TKey, TValue>>& result) = 0;
        };

        template <typename TKey, typename TValue>
        using IPathFinderPtr = std::shared_ptr<IPathFinder<TKey, TValue>>;

    }
}

#endif // I_PATH_FINDER_H_9915194f_07ef_474c_a5fe_4d1d995175d6
