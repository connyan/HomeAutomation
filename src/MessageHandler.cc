//
// Created by conny on 11/22/18.
//

#include "MessageHandler.h"

MessageHandler::MessageHandler() {}

void MessageHandler::on_message(server *s, websocketpp::connection_hdl hdl, server::message_ptr msg) {
  std::cout << "Message received" << std::endl;
  std::cout << msg->get_payload() << std::endl;
  server::connection_ptr con = s->get_con_from_hdl(hdl);
  if (msg->get_payload() == "stop") {
    s->stop();
  }
}
