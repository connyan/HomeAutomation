//
// Created by conny on 11/21/18.
//
#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <functional>

#include "UtilityServer.h"

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

UtilityServer::UtilityServer() {
  m_endpoint.set_error_channels(websocketpp::log::elevel::all);
  m_endpoint.set_access_channels(websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);
  m_endpoint.init_asio();
}

void UtilityServer::run() {
  m_endpoint.listen(9090);
  m_endpoint.start_accept();
  m_endpoint.run();
}

void UtilityServer::register_message_handler(void (&handler)(server*, websocketpp::connection_hdl, server::message_ptr msg)) {
  m_endpoint.set_message_handler(std::bind(&handler, &m_endpoint, _1, _2));
}

void UtilityServer::register_open_handler(websocketpp::open_handler handler) {
  m_endpoint.set_open_handler(handler);
}
