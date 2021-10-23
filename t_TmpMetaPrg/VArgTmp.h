#pragma once

#include <stdlib.h>
#include <iostream>

//前向声明
template<typename... Args>
struct Sum;

//基本定义
template<typename First, typename... Rest>
struct Sum<First, Rest...>
{
    enum { value = Sum<First>::value + Sum<Rest...>::value };
};

//递归终止
template<typename Last>
struct Sum<Last>
{
    enum { value = sizeof(Last) };
};

////前向声明
//template<typename First, typename... Args>
//struct Sum;
//
////递归终止
//template<typename Last>
//struct Sum<Last> : std::integral_constant<int, sizeof(Last)>  //vs2019不行
//{
//};
////基本定义
//template<typename First, typename... Rest>
//struct Sum<First, Rest...> : std::integral_constant<int, Sum<First>::value + Sum<Rest...>::value>
//{
//};

