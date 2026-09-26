#include "class.h"
#include <iostream>

int main(){
    FooString f("meow");
    FooString s("bark");
    std::cout << s.length() << std::endl;

    //Проверим безопасность копирования
    FooString copy = s;//делаем копию одной из строк
    copy.add(".");

    std::cout << "Проверка безопасности копирования:\n";
    std::cout << "Строка = "; s.show(); std::cout << "\n";
    std::cout << "копия строки с точкой = "; copy.show();
    std::cout << "\n";

    return 0;
}