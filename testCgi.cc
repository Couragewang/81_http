#include <iostream>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include "Util.hpp"

using namespace std;

int main()
{
    //
    cout <<"cout: http run 第三方程序 testCgi begin" << endl;
    cerr <<"cerr: http run 第三方程序 testCgi begin" << endl;
    char *content_length = getenv("Content-Length");
    if(nullptr != content_length){
        std::string str = content_length;
        int cl = Util::StringToInt(str);
        char c;
        std::string args;
        for(auto i = 0; i < cl; i++){
            read(0, &c, 1);
            args.push_back(c);
        }

        cout << "<html><h3>";
        //data1=100111&data2=200222
        cout << args << " : " << cl << endl;
        cout << "</h3></html>" << endl;
    }else{
        cout << "get content length error!" << endl;
    }
    return 0;
}
