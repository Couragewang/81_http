#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

class Util{
    public:
        static void MakeKV(std::unordered_map<std::string, std::string> &header_kv, std::string &str){
            std::size_t pos = str.find(": ");
            if(std::string::npos == pos){
                return;
            }

            std::string key = str.substr(0, pos);
            std::string value = str.substr(pos+2);
            header_kv.insert({key, value});
        }//Content-Length: 30

        static int StringToInt(std::string &str){
            std::stringstream ss(str);
            int len = 0;
            ss >> len;
            return len;
        }

        static std::string IntToString(int num){
            std::stringstream ss;
            ss << num;
            return ss.str();
        }
        
        static std::string SuffixToType(std::string suffix){
            if(suffix == ".html" || suffix == "htm"){
                return "text/html";
            }
            else if(suffix == ".js"){
                return "application/x-javascript";
            }
            else if(suffix == ".css"){
                return "text/css";
            }
            else if(suffix == ".jpg"){
                return "application/x-jpg";
            }
            else{
                return "text/html";
            }
        }
        static std::string GetStatusLine(int code)
        {
            switch(code){
                case 200:
                    return "HTTP/1.0 200 OK\r\n";
                case 404:
                    return "HTTP/1.0 404 Not Found\r\n";
                default:
                    return "HTTP/1.0 200 OK\r\n";
            }
        }
};





