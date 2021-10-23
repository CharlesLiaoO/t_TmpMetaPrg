#include <stdlib.h>
#include <iostream>

#include "VArgTmp.h"
#include "function.h"


//整型序列的定义
template<int...>
struct IndexSeq {};

//继承方式，开始展开参数包
template<int N, int... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...> {};

// 模板特化，终止展开参数包的条件
template<int... Indexes>
struct MakeIndexes<0, Indexes...>
{
    typedef IndexSeq<Indexes...> type;
};

int main()
{
    Sum<int, double, short>::value;//值为14

    using namespace std;
    using T = MakeIndexes<3>::type;
    cout << typeid(T).name() << endl;


    functionTest();


    return 0;
}



