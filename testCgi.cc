#include <iostream>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include "Util.hpp"

using namespace std;
  
void GetSubString(string str, int &x, int &y)
{
    bool result = true;
    //data1=100111&data2=200222
    size_t pos_start = str.find("=");
    size_t pos_end = str.find("&");

    if(pos_start != string::npos && pos_end != string::npos){
        string sub = str.substr(pos_start+1, pos_end - pos_start + 1);
        x = Util::StringToInt(sub);
    }else{
        result = false;
    }

    size_t pos = str.rfind("=");
    if(pos != string::npos){
        string sub = str.substr(pos+1);
        y = Util::StringToInt(sub);
    }else{
        result = false;
    }
    
    if(!result){
        cout << "args parse error, please check your args!" << endl;
    }
}

int main()
{
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
        int x, y;
        GetSubString(args, x, y);
        cout << "data1 + data2 = " << x + y << "<br/>"<< endl;
        cout << "data1 - data2 = " << x - y <<"<br/>"<< endl;
        cout << "data1 * data2 = " << x * y << endl;
        if(y == 0){
            cout << "data1 / data2 = " << "div zero!" << endl;
        }else{
            cout << "data1 / data2 = " << x/y<< endl;
        }
        cout << "</h3></html>" << endl;
    }else{
        cout << "get content length error!" << endl;
    }
    return 0;
}
