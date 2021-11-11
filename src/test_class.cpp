
#include "test_class.h"

op_def::Anchor xClass::anh = op_def::Anchor::ANCHOR_TOP_LEFT;

xClass::xClass(int x,std::string y) : x(x),y(y){
}
//成员函数
void xClass::incrementX(){
    x+=1;
} 
//Get Set函数
int xClass::getValueX() const{
    return x;
}
void xClass::setValueX(int val){
    x=val;
}


op_def::Anchor xClass::getAnh() const
{
    return anh;
}

void xClass::setAnh(op_def::Anchor val)
{
    anh = val;
}

//静态方法
//在静态成员函数中，不能访问非静态成员变量，也不能调用非静态成员函数
std::string xClass::getStringValue(const xClass & instance){//这里用到引用的方法 
    return instance.y;
} 

void xClass::PrintNum(){
    std::cout<<"num is value: ";
    std::cout<<num<<std::endl; 

    std::cout << "anh " << anh << std::endl;

}


