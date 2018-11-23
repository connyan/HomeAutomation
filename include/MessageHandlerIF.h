//
// Created by conny on 11/22/18.
//

#ifndef HOMEAUTOMATION_MESSAGEHANDLERIF_H
#define HOMEAUTOMATION_MESSAGEHANDLERIF_H

#include <list>
#include <websocketpp/common/connection_hdl.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

typedef websocketpp::server<websocketpp::config::asio> server;

class MessageHandlerIF {
 public:
  virtual void on_message(server *, websocketpp::connection_hdl, server::message_ptr) = 0;
};

#endif //HOMEAUTOMATION_MESSAGEHANDLERIF_H
