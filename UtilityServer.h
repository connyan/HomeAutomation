//
// Created by conny on 11/21/18.
//

#ifndef HOMEAUTOMATION_UTILITY_SERVER_H
#define HOMEAUTOMATION_UTILITY_SERVER_H

#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>

typedef websocketpp::server<websocketpp::config::asio> server;

class UtilityServer {
 public:
  UtilityServer();

  void run();
  void register_open_handler(websocketpp::open_handler);
  void register_message_handler(void (&handler)(server*, websocketpp::connection_hdl, server::message_ptr));

 private:
  server m_endpoint;
};

#endif //HOMEAUTOMATION_UTILITY_SERVER_H
