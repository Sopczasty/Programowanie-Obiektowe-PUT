#include <iostream>
#include <string>

int main()
{
    std::string fellow = "world";
    std::cout<< "Hello " << fellow << std::endl;
    while(fellow != "exit")
    {
        std::cout << "Introduce yourself: ";
        std::cout.flush();
        std::getline(std::cin, fellow);
        std::cout << "Hello "<< fellow << std::endl;
    }
}