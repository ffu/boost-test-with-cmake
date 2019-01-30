#ifndef BAR_H_
#define BAR_H_

#include <iostream>

class Bar {
public:
    Bar();
    int x();
    int y();

    void dump(std::ostream& is = std::cout) const;

private:
    int x_;
    int y_;
};

#endif /* end of include guard */
