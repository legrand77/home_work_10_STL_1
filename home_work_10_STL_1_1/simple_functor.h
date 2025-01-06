#pragma once

class simple_functor {
public:
    simple_functor() = default;
    int operator()(int a, int b) {
        return a > b;
    }
};
