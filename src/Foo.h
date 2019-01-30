#ifndef FOO_H_
#define FOO_H_

#include <iostream>

class Foo {
public:
    Foo()
        : x_{42}
    { }

    Foo(const int x)
        : x_{x}
    { }

    int x() const {
        return x_;
    }

    void dump(std::ostream& is = std::cout) const;

private:
    int x_;
};

#endif /* end of include guard */
