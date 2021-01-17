//
// Created by conny on 11/22/18.
//

#include <websocketpp/endpoint.hpp>

#include "ConnectionHandler.h"

ConnectionHandler::ConnectionHandler() {
  connections = std::list<websocketpp::connection_hdl>{};
}
void ConnectionHandler::on_connection(server *s, websocketpp::connection_hdl hdl) {
  std::cout << "Connection made" << std::endl;
  server::connection_ptr con = s->get_con_from_hdl(hdl);
  connections.push_back(hdl);
}

std::list<websocketpp::connection_hdl> ConnectionHandler::get_connections() {
  return std::list<websocketpp::connection_hdl>();
}
