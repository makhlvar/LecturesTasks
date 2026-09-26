#include "class.h"
#include <cstring>
#include <iostream>
//                 конструктор
FooString::FooString(char* tbuf){
    buf = new char[strlen(tbuf)+ 1]; //баф теперь указывает на буфер
    strcpy(buf, tbuf);//копируем символы в заданный участок памяти через баф
}
//              конструктор копирования
//выделяем свою память
//копируем туда строку
//чтобы два объекта не указывали на один буфер
//теперь у каждого объекта свой собственный buf
FooString::FooString(const FooString& other){
    buf = new char[strlen(other.buf) + 1];
    strcpy(buf, other.buf);
}
//                   деструктор
FooString::~FooString(){
    delete[] buf;
}
//оператор присваивания
//задача оператора чтобы объект слева стал копией объекта справа
FooString& FooString::operator =(const FooString& other){
    if(this == &other){ //защита от самокопирования
        return *this;
    }
    //buf и other.buf это разные области памяти
    //значит можно спокойно очистить старый буфер
    delete[] buf;//освобождаем свой старый буфер
    buf = new char[strlen(other.buf) + 1];//выделяем новый буфер
    strcpy(buf,other.buf);//копируем содержимое
    return *this;
}

void FooString::show(){
    std::cout << buf;
}
//длина строки включая ноль
int FooString::length(){
    return strlen(buf) + 1;
}
//true еслим строки равны
bool FooString::compare(FooString str){
    return compare(str.buf);
}

bool FooString::compare(const char* str){
    return strcmp(buf, str) == 0;
}
//перевыделить память и добавить str в конец
void FooString::add(FooString str){
    add(str.buf);
}
void FooString::add(const char* str){
    int lenFirst = strlen(buf);
    int lenSecond = strlen(str);
    //выделяем новый буфер под обе строки
    char* newbuf = new char[lenFirst + lenSecond + 1];
    //копируем туда старую строку
    strcpy(newbuf, buf);
    //дописываем нашу строку в конец
    strcat(newbuf, str);

    delete[] buf;//освобождаем старый буфер
    buf = newbuf;//переходим на новый

}