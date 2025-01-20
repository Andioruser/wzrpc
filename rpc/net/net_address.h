#ifndef RPC_NET_NET_ADDRESS_H
#define RPC_NET_NET_ADDRESS_H

#include <memory>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

namespace rpc {

class NetAddress {

public:

    typedef std::shared_ptr<NetAddress> ptr;
    
    virtual sockaddr* getSocketAddr() = 0;

    virtual int getFamily() const = 0;

    virtual std::string toString() const = 0;

    virtual socklen_t getSockLen() const = 0;

};

class IPAddress : public NetAddress {

public:
    IPAddress(const std::string&ip, uint16_t port);

    IPAddress(const std::string& addr);

    IPAddress(u_int16_t port);

    IPAddress(sockaddr_in addr);

    sockaddr* getSocketAddr();

    int getFamily() const;

    std::string toString() const;

    socklen_t getSockLen() const;

    std::string get_ip() const {return m_ip;}

    uint16_t get_port() const {return m_port;}

public:
    static bool CheckIvalidIPAddr(const std::string& ip);

private:

    std::string m_ip;
    uint16_t m_port;
    sockaddr_in m_addr;
};


}
#endif

