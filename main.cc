#include "HttpServer.hpp"

static void Usage(std::string proc){
    std::cout << "Usage : " << proc << " port[ default:8080 ]" << std::endl;
}

//http_server 8080
int main(int argc, char *argv[])
{
    HttpServer *svr = nullptr; 
    if(argc == 1){
        svr = new HttpServer();
        LOG(Normal, "create server success, usage default port!");
    }
    else if(argc == 2){
        svr = new HttpServer(atoi(argv[1]));
        LOG(Normal, "create server success, usage assign port!");
    }
    else{
        Usage(argv[0]);
        exit(ARG_ERR);
    }

    svr->InitServer();
    LOG(Normal, "Init server success!");
    svr->Start();

    return 0;
}
