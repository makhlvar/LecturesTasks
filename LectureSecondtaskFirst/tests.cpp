#include "class.h"
#include <cassert>
#include <iostream>

int main() {
    //         length()
    // Вариант 1: длина включая '\0'
    assert(FooString("hello").length() == 6);   // 5 + '\0'
    assert(FooString("").length() == 1);        // 0 + '\0'
    assert(FooString("a").length() == 2);       // 1 + '\0'
    assert(FooString("abcdefghij").length() == 11);

    //        compare(FooString)
    // Вариант 2: true, если строки равны
    {
        FooString a("hello");
        FooString b("hello");
        FooString c("world");
        assert(a.compare(b) == true);
        assert(a.compare(c) == false);
        assert(a.compare(a) == true);
    }

    //       compare(char*) 
    // Вариант 3: true, если строки равны
    {
        FooString a("hello");
        assert(a.compare("hello") == true);
        assert(a.compare("world") == false);
        assert(a.compare("") == false);
        assert(a.compare("hell") == false);      // префикс не равен
        assert(a.compare("hello!") == false);    // длиннее — не равен
    }
        //      add(FooString)
    // Вариант 4: перевыделить память и добавить str в конец
    {
        FooString a("too");
        FooString b("bar");
        a.add(b);
        assert(a.compare("toobar") == true);
        assert(b.compare("bar") == true);        // источник не изменился

        FooString empty("");
        FooString x("x");
        x.add(empty);
        assert(x.compare("x") == true);
    }

    //         add(char*)
    // Вариант 5: перевыделить память и добавить str в конец
    {
        FooString s("hello");
        s.add(" world");
        assert(s.compare("hello world") == true);

        FooString empty("");
        empty.add("abc");
        assert(empty.compare("abc") == true);

        FooString sSecond("hi");
        sSecond.add("");
        assert(sSecond.compare("hi") == true);

        FooString sThird("a");
        sThird.add("b");
        sThird.add("c");
        assert(sThird.compare("abc") == true);       // два add подряд
    }
//          копирование и присваивание 
    {
        FooString a("hello");
        FooString b = a;                    // конструктор копирования
        assert(b.compare("hello") == true);

        FooString c("xxx");
        c = a;                              // оператор присваивания
        assert(c.compare("hello") == true);

        // меняем b — a не должен измениться
        b.add("!");
        assert(a.compare("hello") == true);
        assert(b.compare("hello!") == true);

        // самоприсваивание — не должно падать
        a = a;
        assert(a.compare("hello") == true);
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}