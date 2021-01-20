#pragma once

class Wezel {
    public:
    Wezel();
    ~Wezel();

    std::shared_ptr<Wezel> next;
};
