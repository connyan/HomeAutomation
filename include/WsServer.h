//
// Created by conny on 11/21/18.
//

#ifndef HOMEAUTOMATION_WSSERVER_H
#define HOMEAUTOMATION_WSSERVER_H

#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>

#include "ConnectionHandlerIF.h"
#include "MessageHandlerIF.h"

typedef websocketpp::server<websocketpp::config::asio> server;

class WsServer {
 public:
  explicit WsServer(ConnectionHandlerIF& connectionHandler, MessageHandlerIF& messageHandler_);

  void run();

 private:
  server m_endpoint_;
  ConnectionHandlerIF& connectionHandler_;
  MessageHandlerIF& messageHandler_;

};

#endif //HOMEAUTOMATION_WSSERVER_H
