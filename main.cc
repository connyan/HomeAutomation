#include <iostream>

#include "UtilityServer.h"

void open_handler(websocketpp::connection_hdl connection) {
  std::cout << "Connection made" << std::endl;
}

void message_handler(server* s, websocketpp::connection_hdl hdl, server::message_ptr msg) {
  std::cout << "Message received" << std::endl;
  std::cout << msg->get_payload() << std::endl;
  if (msg->get_payload() == "stop") {
    s->stop();
  }
}

int main() {
  std::cout << "Server start" << std::endl;
  UtilityServer s;
  s.register_open_handler(open_handler);
  s.register_message_handler(message_handler);
  s.run();
  return 0;
}