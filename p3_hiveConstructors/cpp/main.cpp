#include <iostream>

#include "ul.hpp"


void foo(ul Ul) {
    Ul.changeBeeAmount(70);
    std::cout << Ul.getAmountOfBees() << "\n";
}

void bar(const ul &Ul) {
    std::cout << Ul.getAmountOfBees() << "\n";
}

void baz(ul &Ul) {
    std::cout << Ul.getAmountOfBees() << "\n";    
}

void qux(ul &&Ul) {
    std::cout << Ul.getAmountOfBees() << "\n";    
}

int main() {
    ul hive;

    hive.setName("Itworks");
    std::cout<<hive.getName()<<"\n";
    hive.setPosition(0, 3);
    hive.honeyMade(24);
    std::cout<<hive.getAverageHoney()<<"\n";
    hive.honeyMade(1);
    std::cout<<hive.getAverageHoney()<<"\n";
    hive.changeBeeAmount(20);
    int convert = 5;
    //foo wywoluje konstruktor i tworzy nowy obiekt lokalny
    //kolejno: kopiujący, przenoszący
    
    ul forfoo(hive);
    ul forbar(hive);
    ul forbaz(hive); 
    ul forqux(hive);

    foo(forfoo);
    //foo(std::move(forfoo));

    foo(convert);

    //nie tworzu obiektu, ale w funkcji z racji const wartości obiektu są stałe - zmiany nie są widocznie globalnie
    //z racji przekazania obiektu l-wartością, brak wywołania konstryktorów innych niż konwertujący.
    std::cout<<"bar\n";
    bar(forbar);
    bar(std::move(forbar));
    bar(convert);
    
    std::cout<<"baz\n";
    //baz uzywa obiektu i moze na nim dokonywac zmian, ktore beda widoczne globalnie
    //stad niemozliwa jest ponowna konstrukcja tego obiektu, std::move jak i konwersja nie dziala
    baz(forbaz);

    std::cout<<"qux\n";
    //argument to r-wartosc, stad niemozliwe jest wywolanie obiektu jako argument bez semantyki move lub konstruktora konwertujacego.
    qux(std::move(forqux));
    qux(convert);

    return 0;
}

//zad 32:
//a) Ryzykiem jakie ponosimy dziedzicząc z wielu klas, jest fakt, że w nadklasach pola lub metody mogą mieć identyczne nazwy chociaż inne funkcjonalności
//b) W Javie brak możliwości wielokrotnego dziedziczenia, w Javie możemy zamiast tego korzystać z interfejsów oraz podklas umożliwiających wielokrotne dziedziczenie