#pragma once

#include <stdlib.h>
#include <iostream>

//ǰ������
template<typename... Args>
struct Sum;

//��������
template<typename First, typename... Rest>
struct Sum<First, Rest...>
{
    enum { value = Sum<First>::value + Sum<Rest...>::value };
};

//�ݹ���ֹ
template<typename Last>
struct Sum<Last>
{
    enum { value = sizeof(Last) };
};

////ǰ������
//template<typename First, typename... Args>
//struct Sum;
//
////�ݹ���ֹ
//template<typename Last>
//struct Sum<Last> : std::integral_constant<int, sizeof(Last)>  //vs2019����
//{
//};
////��������
//template<typename First, typename... Rest>
//struct Sum<First, Rest...> : std::integral_constant<int, Sum<First>::value + Sum<Rest...>::value>
//{
//};

