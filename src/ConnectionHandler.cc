//
// Created by conny on 11/22/18.
//

#include <ConnectionHandler.h>

#include "ConnectionHandler.h"

ConnectionHandler::ConnectionHandler() {
  connections = std::list<websocketpp::connection_hdl>{};
}
void ConnectionHandler::on_connection(server *s, websocketpp::connection_hdl connection_hdl) {
  std::cout << "Connection made" << std::endl;
  connections.push_back(connection_hdl);
}

std::list<websocketpp::connection_hdl> ConnectionHandler::get_connections() {
  return std::list<websocketpp::connection_hdl>();
}
