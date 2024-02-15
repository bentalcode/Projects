#ifndef I_POSITION_QUEENS_H_b91590fa_e0b3_4e6f_965c_95e281a3fdc1
#define I_POSITION_QUEENS_H_b91590fa_e0b3_4e6f_965c_95e281a3fdc1

#include <string>
#include <vector>

namespace problems
{
    /**
     * The IQueensPositioning interface defines a queens positioning problem.
     */
    class IQueensPositioning {
    public:
        /**
         * The constructor.
         */
        IQueensPositioning() = default;

        /**
         * The destructor.
         */
        virtual ~IQueensPositioning() = default;

        /**
         * The copy/move constructors.
         */
        IQueensPositioning(const IQueensPositioning&) = delete;
        IQueensPositioning(IQueensPositioning&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IQueensPositioning& operator=(const IQueensPositioning&) = delete;
        IQueensPositioning& operator=(IQueensPositioning&&) = delete;

        /**
         * Positions queens.
         */
        virtual std::vector<std::vector<std::wstring>> PositionQueens(size_t size) = 0;
    };

}

#endif // I_POSITION_QUEENS_H_b91590fa_e0b3_4e6f_965c_95e281a3fdc1
