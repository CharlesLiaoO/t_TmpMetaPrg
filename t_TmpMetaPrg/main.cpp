#include <stdlib.h>
#include <iostream>

#include "VArgTmp.h"
#include "function.h"


//�������еĶ���
template<int...>
struct IndexSeq {};

//�̳з�ʽ����ʼչ��������
template<int N, int... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...> {};

// ģ���ػ�����ֹչ��������������
template<int... Indexes>
struct MakeIndexes<0, Indexes...>
{
    typedef IndexSeq<Indexes...> type;
};

int main()
{
    Sum<int, double, short>::value;//ֵΪ14

    using namespace std;
    using T = MakeIndexes<3>::type;
    cout << typeid(T).name() << endl;


    functionTest();


    return 0;
}



