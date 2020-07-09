#ifndef WORD_FINDER_H_665511ad_ded4_4713_b3e3_7200ab10d4f7
#define WORD_FINDER_H_665511ad_ded4_4713_b3e3_7200ab10d4f7

#include "IFinder.h"
#include "Matrix.h"
#include "Position.h"

namespace problems
{
    /**
     * The WordFinder class implements a word finder problem.
     */
    class WordFinder final : public base::IFinder<std::vector<std::vector<base::Position>>>
    {
    public:
        /**
         * The constructor.
         */
        WordFinder(
            const base::Matrix<char>& matrix,
            const std::string& word);

        /**
         * The destructor.
         */
        virtual ~WordFinder() = default;

        /**
         * The copy/move constructors.
         */
        WordFinder(const WordFinder&) = delete;
        WordFinder(WordFinder&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        WordFinder& operator=(const WordFinder&) = delete;
        WordFinder& operator=(WordFinder&&) = delete;

        /**
         * Finds all paths of a word in a matrix.
         */
        virtual std::vector<std::vector<base::Position>> find();

    private:
        /**
         * Finds all paths of a word in a matrix.
         */
        void find(
            const base::Position& currPosition,
            std::vector<base::Position>& currPath,
            std::set<base::Position>& visited,
            std::vector<std::vector<base::Position>>& result) const;

        /**
         * Gets the next positions.
         */
        std::vector<base::Position> getNextPositions(const base::Position& currPosition) const;

        base::Matrix<char> m_matrix;
        std::string m_word;
        std::vector<base::Position> m_directions;
    };
}

#endif // WORD_FINDER_H_665511ad_ded4_4713_b3e3_7200ab10d4f7
