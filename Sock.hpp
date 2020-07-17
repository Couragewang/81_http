#pragma once

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include "Log.hpp"

class Sock{
    public:
        static int Socket(){
            int sock = socket(AF_INET, SOCK_STREAM, 0);
            if(sock < 0){
                LOG(Fatal, "create stream socket error!");
                exit(SOCKET_CREATE);
            }
            int opt = 1;
            setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

            return sock;
        }
        static void Bind(int sock, int port){
            struct sockaddr_in local;
            bzero(&local, sizeof(local));

            local.sin_family = AF_INET;
            local.sin_port = htons(port);
            local.sin_addr.s_addr = htonl(INADDR_ANY);

            if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0){
                LOG(Fatal, "bind socket error!");
                exit(BIND_ERROR);
            }
        }
        static void Listen(int sock){
            if(listen(sock, NUM) < 0){
                LOG(Fatal, "listen socket error!");
                exit(LISTEN_ERROR);
            }
        }
        static int Accept(int sock){
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);

            int _sock = accept(sock, (struct sockaddr*)&peer, &len);
            if(_sock < 0){
                LOG(Error, "accept new socket error!");
            }
            return _sock;
        }
};






