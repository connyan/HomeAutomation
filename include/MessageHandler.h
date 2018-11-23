//
// Created by conny on 11/22/18.
//

#ifndef HOMEAUTOMATION_MESSAGEHANDLER_H
#define HOMEAUTOMATION_MESSAGEHANDLER_H

#include <websocketpp/common/connection_hdl.hpp>

#include "MessageHandlerIF.h"

class MessageHandler : public MessageHandlerIF {
 public:
  MessageHandler();
  void on_message(server *, websocketpp::connection_hdl, server::message_ptr) override;
};

#endif //HOMEAUTOMATION_MESSAGEHANDLER_H
