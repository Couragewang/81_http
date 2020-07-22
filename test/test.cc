#include <iostream>
#include <unistd.h>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;


int main()
{
    execl("/bin/ls", "/bin/ls",nullptr);

//    std::stringstream ss;
//    int len = 1234;
//    ss << len;
//    std::string str = ss.str();
//    cout << str <<endl;
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
