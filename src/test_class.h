#include <emscripten/bind.h>
#include <iostream>
#include <string> 
#include "def.pb.h"

using namespace emscripten;

class xClass {
private:
    int x;
    std::string y;
    static const int num = 6;
    static const op_def::Anchor anh = op_def::Anchor::ANCHOR_TOP_LEFT;

public:
    //构造函数 
    xClass(int x,std::string y);
    //成员函数
    void incrementX();
    //Get Set函数
    int getValueX() const;
    void setValueX(int val);
    //静态方法
    //在静态成员函数中，不能访问非静态成员变量，也不能调用非静态成员函数
    static std::string getStringValue(const xClass & instance);
    static void PrintNum();

};



//使用EMSCRIPTEN_BINDINGS宏参数进行函数绑定
//把c++的函数绑定到js环境中 
EMSCRIPTEN_BINDINGS(module){
    //绑定类 
    emscripten::class_<xClass>("xClass")
    //绑定构造函数 
    .constructor<int,std::string>()
    //绑定成员函数
    .function("incrementX",&xClass::incrementX)
    //绑定私有成员变量的setter和getter方法
    .property("x",&xClass::getValueX,&xClass::setValueX) 
    //绑定类的静态方法
    .class_function("getStringValue",&xClass::getStringValue)
    .class_function("PrintNum",&xClass::PrintNum); 
}
