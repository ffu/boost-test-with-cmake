#include "Foo.h"
#include "Bar.h"
#include <iostream>

int main(const int argc, char const *argv[]) {
    Foo f{10};
    Bar b;
    f.dump();
    b.dump();

    return 0;
}
