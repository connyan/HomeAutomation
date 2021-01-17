#include <iostream>

#include "WsServer.h"
#include "ConnectionHandler.h"
#include "MessageHandler.h"

const static int PORT_NUMBER = 9090;

int main() {
  std::unique_ptr<ConnectionHandlerIF> connectionHandler = std::make_unique<ConnectionHandler>();
  std::unique_ptr<MessageHandlerIF> messageHandler = std::make_unique<MessageHandler>();
  std::cout << "Server start" << std::endl;
  WsServer ws_server(PORT_NUMBER, *(connectionHandler.get()), *(messageHandler.get()));
  ws_server.run();
  return 0;
}