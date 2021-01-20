#include <iostream>
#include <memory>
#include "Wezel.h"

int main() {
    for (int i = 0; i < 10; i++) {
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
        std::shared_ptr<Wezel> w2 = std::make_shared<Wezel>();

        std::weak_ptr<Wezel> weak1 = w1;
        std::weak_ptr<Wezel> weak2 = w2;

        w1->next = w2;
        w2->next = w1;
    }

    return 0;
}