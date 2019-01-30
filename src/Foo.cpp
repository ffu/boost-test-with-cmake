#include "Foo.h"

void Foo::dump(std::ostream& is) const {
    is << x_ << std::endl;
}
