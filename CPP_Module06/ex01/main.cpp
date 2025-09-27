#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data d(123, '*');
    Data* p = &d;

    std::cout << "original pointer: " << p << std::endl;

    uintptr_t raw = Serializer::serialize(p);
    std::cout << "raw (as uintptr_t, hex): 0x" << std::hex << raw << std::dec << std::endl;

    Data* p2 = Serializer::deserialize(raw);
    std::cout << "deserialized pointer: " << p2 << std::endl;
    std::cout << "same pointer? " << (p2 == p ? "YES" : "NO") << std::endl;
    std::cout << "data: value=" << p2->value << ", ch='" << p2->ch << "'" << std::endl;

    return 0;
}
