#include <string>
#include <iostream>
#include <functional>

using namespace std;

enum ExeObj{
    ExeObjDef,
    Linux,
    MsgHandle,
    MotionAPI
};

template<typename FunRet, typename... Args>
int calloo(std::function<FunRet(Args ...)>, ExeObj exeObj=ExeObjDef)
{

}

template<typename FunRet, typename... Args>
int calloo(std::function<FunRet(Args ...)>)
{
//    call();
}


int foo_4(int int1, const string &str1, float float1)
{
    cout<< __func__<< int1<< str1<< float1<< endl;
    return 4;
}
int Rpc(const string &sFunName, int int1, const string &str1, float float1)
{
    cout<< __func__<< sFunName<< int1<< str1<< float1<< endl;
    return 100;
}

#define rpc

#ifdef rpc
    //启用rpc
    #define call(sFunName, ...) Rpc(#sFunName, __VA_ARGS__)
#else
    //关闭rpc
    #define call(sFunName, ...) sFunName(__VA_ARGS__)
#endif


void testRpc()
{
    //书写版
    int ret = call(foo_4, 10, "buttonrpc", 10.8);
    cout<< __func__<< ret<< endl;

    //真正结果 1 no rpc; 2 use prc
    //int foo4r =           foo_4  (10, "buttonrpc", 100, (float)10.8);
    //int foo4r = call_fun("foo_4", 10, "buttonrpc", 100, (float)10.8));
}

