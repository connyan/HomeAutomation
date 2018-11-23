//
// Created by conny on 11/22/18.
//

#ifndef HOMEAUTOMATION_CONNECTIONHANDLERIF_H
#define HOMEAUTOMATION_CONNECTIONHANDLERIF_H

#include <list>
#include <websocketpp/common/connection_hdl.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

typedef websocketpp::server<websocketpp::config::asio> server;

class ConnectionHandlerIF {
 public:
  virtual void on_connection(server *, websocketpp::connection_hdl) = 0;
  virtual std::list<websocketpp::connection_hdl> get_connections() = 0;
};

#endif //HOMEAUTOMATION_CONNECTIONHANDLERIF_H
