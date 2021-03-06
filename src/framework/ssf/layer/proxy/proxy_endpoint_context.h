#ifndef SSF_LAYER_PROXY_PROXY_ENDPOINT_CONTEXT_H_
#define SSF_LAYER_PROXY_PROXY_ENDPOINT_CONTEXT_H_

#include <string>

#include <boost/asio/ip/tcp.hpp>

namespace ssf {
namespace layer {
namespace proxy {

struct Proxy {
  Proxy();

  boost::asio::ip::tcp::endpoint ToTcpEndpoint(
      boost::asio::io_service& io_service);

  std::string host;
  std::string port;
  std::string username;
  std::string password;
  std::string domain;
  bool reuse_ntlm;
  bool reuse_kerb;
};

struct ProxyEndpointContext {
  ProxyEndpointContext();

  bool IsProxyEnabled() const;

  bool HttpProxyEnabled() const;

  bool operator==(const ProxyEndpointContext& rhs) const;

  bool operator!=(const ProxyEndpointContext& rhs) const;

  bool operator<(const ProxyEndpointContext& rhs) const;

  bool proxy_enabled;
  Proxy http_proxy;
};

}  // proxy
}  // layer
}  // ssf

#endif  // SSF_LAYER_PROXY_PROXY_ENDPOINT_CONTEXT_H_