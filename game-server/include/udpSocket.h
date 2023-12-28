#ifndef H_UDP_SOCKET_CLASS
#define H_UDP_SOCKET_CLASS

#include "config.h"
#include "dataType.h"
#include "log.h"

#include <boost/asio.hpp>
using boost::asio::ip::udp;

#include <string>
#include <queue>

namespace FluffyMultiplayer
{
  class UdpSocket
  {
    private:
      udp::socket socket;
      udp::endpoint senderEndpoint;
      size_t receive_length;
      char tempData[MC_RECEIVE_BUFFER];
      bool status;
      unsigned short port;
      FluffyMultiplayer::Log log;

    public:
      UdpSocket(boost::asio::io_context& io_context, unsigned short default_port)
          : socket(io_context, udp::endpoint(udp::v4(), default_port))
      {
        socket.non_blocking(true);
        port = default_port;
        log.init(SOCKET_LOG_FILENAME,SOCKET_PRINT_LOGS_LEVEL);
      }
      ~UdpSocket()
      {
        socket.close();
        log.close();
      }

      //update status socket
      void enable();
      void disable();
      bool getStatus() const;


      //port
      void setPort(unsigned short newPort);
      unsigned short getPort() const;


      //send and receive
      void prepareData(const int&, std::string&);


      void sendDirect(std::string& data,
              const FluffyMultiplayer::AnAddress& receiver,
              bool areDataPrepared,
              int& code);

      void send(FluffyMultiplayer::SocketSendData&);
      void broadcast(FluffyMultiplayer::SocketSendData&);
      size_t receive(char* const data, udp::endpoint& senderAddress);
  };
}

#endif
