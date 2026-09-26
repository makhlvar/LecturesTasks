#pragma once

class FooString {
    char* buf;
public:
    FooString(char* tbuf);//конструктор
    FooString(const FooString& other);//конструктор копирования
    ~FooString();//деструктор

    FooString& operator =(const FooString& other);//оператор присваивания
                                        //для защиты от самоприсваивания
    void show();
    int length();//
    bool compare(FooString str);
    bool compare( const char* str);
    void add(FooString str);
    void add(const char* str);
};