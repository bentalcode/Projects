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
             * The Copy/move constructors.
             */
            IPathFinder(const IPathFinder&) = delete;
            IPathFinder(IPathFinder&&) = delete;

            /**
             * The Copy/move assignment operators.
             */
            IPathFinder& operator=(const IPathFinder&) = delete;
            IPathFinder& operator=(IPathFinder&&) = delete;

            /**
             * Finds paths.
             */
            virtual void FindPaths(
                const IRoute<TKey, TValue>& route,
                std::list<IWalkSharedPtr<TKey, TValue>>& result) = 0;
        };

        /**
         * Defines the SharedPtr Of Path Finder.
         */
        template <typename TKey, typename TValue>
        using IPathFinderSharedPtr = std::shared_ptr<IPathFinder<TKey, TValue>>;

    }
}

#endif // I_PATH_FINDER_H_9915194f_07ef_474c_a5fe_4d1d995175d6
