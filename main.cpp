#include <iostream>
#include"Classes.h"

int main() {
    BadDude dude1("Alex", "Goodly");
    dude1.Show();
    std::cout << dude1.Gdraw() << std::endl;
    std::cout << dude1.Cdraw() << std::endl;
    return 0;
}
