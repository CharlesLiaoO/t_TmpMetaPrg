#include <string>
#include <iostream>
using namespace std;


string foo_4(int int1, const string &str1, float float1)
{
    cout<< __func__<< int1<< str1<< float1<< endl;
    return "loc";
}
int Rpc(string& sResp, const string &sFunName, int int1, const string &str1, float float1)
{
    cout<< __func__<< sFunName<< int1<< str1<< float1<< endl;
    sResp = "rpc";
    return 100;
}

#define rpc

#ifdef rpc
    //启用rpc
    #define Call(Resp, FunName, ...) Rpc(Resp, #FunName, ##__VA_ARGS__)
#else
    //关闭rpc
    #define Call(Resp, FunName, ...) 0; Resp = FunName(##__VA_ARGS__)
#endif


void testRpc()
{
    //以Rpc形式书写
    string sResp;
    int ret = Call(sResp, foo_4, 10, "buttonrpc", 10.8);
    cout<< __func__<< ret<< sResp<< endl;

    //开关Rpc宏的选择结果
    //int ret = 0;  sResp = foo_4  (10, "buttonrpc", 100, 10.8);  //本地调用
    //int ret = Rpc(sResp, "foo_4", 10, "buttonrpc", 100, 10.8));  //rpc
}

