#ifndef ORIENT_127f14f6_af61_4c7f_8c96_8655e6846a29
#define ORIENT_127f14f6_af61_4c7f_8c96_8655e6846a29

#include "wx\defs.h"

namespace WXWidgets {

    /**
     * The Orient enum defines orientation of a GUI component.
     */
    enum class Orient {
	    HORIZONTAL,
	    VERTICAL
    };

    /**
     * Gets orient value.
     */
    inline int OrientValue(Orient orient) {
        return orient == Orient::HORIZONTAL ? wxHORIZONTAL : wxVERTICAL;
    }

}  // namespace WXWidgets

#endif // ORIENT_127f14f6_af61_4c7f_8c96_8655e6846a29
