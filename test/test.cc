#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;


int main()
{
    std::string str = "1234";
    std::stringstream ss(str);
    int len = 0;
    ss >> len;

    cout << len  << endl;
//    string str = "Content-Length: 30";
//    std::size_t pos = str.find(": ");
//    if(std::string::npos == pos){
//        return 1;
//    }
//
//    string key = str.substr(0, pos);
//    string value = str.substr(pos+2);
//
//    cout <<"key : " << key << endl;
//    cout << "value : " << value << endl;
//
//    unordered_map<string, string> m;
//    m.insert(std::make_pair(key, value));
 //   m.insert({key, value});

    return 0;

}
