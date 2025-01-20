#include "net_address.h"
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
}
}