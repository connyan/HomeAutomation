//
// Created by conny on 11/21/18.
//
#include <websocketpp/server.hpp>
#include <websocketpp/endpoint.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <functional>

#include "WsServer.h"
#include "ConnectionHandlerIF.h"

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

WsServer::WsServer(ConnectionHandlerIF& connectionHandler, MessageHandlerIF& messageHandler) : connectionHandler_{connectionHandler}, messageHandler_{messageHandler} {
  m_endpoint_.set_error_channels(websocketpp::log::elevel::all);
  m_endpoint_.set_access_channels(websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);
  m_endpoint_.init_asio();

  m_endpoint_.set_open_handler([this] (auto hdl) {connectionHandler_.on_connection(&m_endpoint_, hdl);});
  m_endpoint_.set_message_handler([this] (auto hdl, auto msg) { messageHandler_.on_message(&m_endpoint_, hdl, msg);});
}

void WsServer::run() {
  m_endpoint_.listen(9090);
  m_endpoint_.start_accept();
  m_endpoint_.run();
}
