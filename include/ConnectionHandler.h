//
// Created by conny on 11/22/18.
//

#ifndef HOMEAUTOMATION_CONNECTIONHANDLER_H
#define HOMEAUTOMATION_CONNECTIONHANDLER_H

#include <list>
#include <websocketpp/common/connection_hdl.hpp>

#include "ConnectionHandlerIF.h"

class ConnectionHandler : public ConnectionHandlerIF {
 public:
  ConnectionHandler();
  void on_connection(server *, websocketpp::connection_hdl) override;
  std::list<websocketpp::connection_hdl> get_connections() override;
 private:
  std::list<websocketpp::connection_hdl> connections;
};

#endif //HOMEAUTOMATION_CONNECTIONHANDLER_H
