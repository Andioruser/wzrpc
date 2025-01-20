#include <memory>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
int main() {
    std::string ip = "127.0.0.1";
    std::string addr = "127.0.0.1:8080";
    std::cout<<"size: "<<addr.size()<<std::endl;
    int i = addr.find(":");
    std::cout<<"index: "<<i<<std::endl;
    u_int16_t port = std::atoi(addr.substr(i+1, addr.size()-i-1).c_str());
    
}