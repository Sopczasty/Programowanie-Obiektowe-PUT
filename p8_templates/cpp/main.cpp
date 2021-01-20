#include <iostream>

template <typename T>
T maximum(T const& a, T const& b) {
    return a > b ? a : b;
}

template <typename T>
class X { 
private:
    T x;
public:
    X() {}
    X(T _x) {
        this->x = _x;
    }    
    T getX() const {
        return x;
    }
    friend std::ostream& operator << (std::ostream& os, X const &x) {
        os << x.x;
        return os;
    }
};

template <typename T>
bool operator > (X<T> const & a, X<T> const & b) {
    return a.getX() > b.getX();
}

template <>
bool operator > (X<std::string> const &a, X<std::string> const &b) {
    return a.getX().size() > b.getX().size();
}

template <typename T, typename C = X<T>>
class Y {
    T variable;
    C Xobject;
};

template <typename T>
class A {
    typename T::id i;
    public:
    void f() {i.g();}
};

class B {
public:
    class id {
    public:
        void g() {}
    };
};

auto maxLambda = [](auto a, auto b) {
    return a > b ? a : b;
};

int main() {
    std::cout << maximum(6, 7) << std::endl;
    std::cout << maximum(6.3, 7.3) << std::endl;
    std::cout << maximum<double>(4, 5) << std::endl;
    std::cout << maximum<bool>(4.6, 3) << std::endl;
    std::cout << maximum<std::string>("aaa", "bb") << std::endl;
    std::cout << maximum(X<int>(4), X<int>(3)) << std::endl;
    std::cout << maximum(X<std::string>("aaa"), X<std::string>("bb")) << std::endl;

    Y<int> y;
    Y<int , double> y2;
    A<B> ab;
    ab.f();

    bool b = maxLambda(3, 3.14);
    auto c = maxLambda(3, 3.14);
}