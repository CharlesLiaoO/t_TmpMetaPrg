#pragma once
#include <stdlib.h>
#include <iostream>
#include <functional>

struct int_div {        // ����һ������ʹ��"()"���е��õĺ�����������  
    float operator() (int x, int y) const { return ((float)x) / y; };
    
    //���ز���
    int int_div_RetPar(int x) { return x; };  
};
typedef std::function<int(int_div*, int)> f_2;



void functionTest()
{
    f_2 f2_RetPar = std::mem_fn(&int_div::int_div_RetPar);            // ָ���Ա�����ĵ�ǰ��������

    int_div int_div_object;
    int v = f2_RetPar(&int_div_object, 5);  //���Ա�����ķ������./->������ʽ���ڶ���int_div_object���ò���5����int_div::int_div_RetPar()

    std::function<int(int)> ff = std::bind(f2_RetPar, &int_div_object, std::placeholders::_1);    // int_div_object�������ִ�ж���
    v = ff(12);                // ����int_div_object.int_div_RetPar(12)
}