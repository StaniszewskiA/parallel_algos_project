#include <iostream>

#include <openrand/philox.h>

int main() {
    using RNG = openrand::Philox;  
    
    RNG rng(1, 0);

    return 0;
}