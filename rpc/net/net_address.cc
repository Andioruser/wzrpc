#include "net_address.h"
#include <iostream>
namespace rpc {

bool IPAddress::CheckIvalidIPAddr(const std::string& addr)
{
    std::size_t i = addr.find_first_of(":"); 
    if ( i == addr.npos) {
        return false;
    }

    int port = std::atoi(addr.substr(i+1, addr.size()-i-1).c_str());
    
    if (port < 0 || port > 65535) {
        return false;
    }

    if(inet_addr(addr.substr(0, i).c_str()) == INADDR_NONE) {
        return false;
    }
    return true;

    std::cout << "create ipv4 address succ [" << addr << "]";
}

IPAddress::IPAddress(const std::string& ip, uint16_t port) 
    : m_ip(ip), m_port(port)
{
    memset(&m_addr, 0, sizeof(m_addr));
    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    m_addr.sin_port = htons(port);
}

IPAddress::IPAddress(sockaddr_in addr): m_addr(addr)
{
  m_ip = inet_ntoa(m_addr.sin_addr);
  m_port = ntohs(m_addr.sin_port);
}

IPAddress::IPAddress(const std::string& addr)
{
    std::size_t i = addr.find_first_of(":"); 
    if ( i == addr.npos) {
        return ;
    }
    int port = std::atoi(addr.substr(i+1, addr.size()-i-1).c_str());
    if (port < 0 || port > 65535) {
        return ;
    }
    if(inet_addr(addr.substr(0, i).c_str()) == INADDR_NONE) {
        return ;
    }
    return ;

    std::cout << "create ipv4 address succ [" << addr << "]";
}


}
