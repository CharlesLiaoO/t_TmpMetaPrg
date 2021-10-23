#pragma once
#include <stdlib.h>
#include <iostream>
#include <functional>

struct int_div {        // 构造一个可以使用"()"进行调用的函数对象类型  
    float operator() (int x, int y) const { return ((float)x) / y; };
    
    //返回参数
    int int_div_RetPar(int x) { return x; };  
};
typedef std::function<int(int_div*, int)> f_2;



void functionTest()
{
    f_2 f2_RetPar = std::mem_fn(&int_div::int_div_RetPar);            // 指向成员函数的当前作用域函数

    int_div int_div_object;
    int v = f2_RetPar(&int_div_object, 5);  //类成员函数的非类对象./->调用形式：在对象int_div_object上用参数5调用int_div::int_div_RetPar()

    std::function<int(int)> ff = std::bind(f2_RetPar, &int_div_object, std::placeholders::_1);    // int_div_object，类对象（执行对象）
    v = ff(12);                // 调用int_div_object.int_div_RetPar(12)
}