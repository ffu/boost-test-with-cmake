#include "Bar.h"

Bar::Bar() {x_=42; y_=43;}
int Bar::x() {return x_;}
int Bar::y() {return y_;}

void Bar::dump(std::ostream& is) const {
    is << x_ << " " << y_ << std::endl;
}
