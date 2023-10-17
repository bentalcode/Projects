#ifndef GRAPH_EXCEPTION_H_81920fcf_f1d8_4e7b_b231_c090b4a62ffe
#define GRAPH_EXCEPTION_H_81920fcf_f1d8_4e7b_b231_c090b4a62ffe

#include "DataStructureException.h"

namespace datastructures {
    namespace graph {

        /**
         * The GraphException captured errors in the graph module.
         */
        class GraphException : public DataStructureException
        {
        public:
            /**
             * The GraphException constructor.
             */
            GraphException(
                long statusCode,
                const std::string& errorMessage) :
                DataStructureException(statusCode, errorMessage)
            {
            }
        };
    }
};


#endif // GRAPH_EXCEPTION_H_81920fcf_f1d8_4e7b_b231_c090b4a62ffe
