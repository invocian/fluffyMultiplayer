#ifndef H_GAMEMODE_CLASS
#define H_GAMEMODE_CLASS

#include "app.h"
#include "dataType.h"

namespace FluffyMultiplayer
{
  class App;
  class GameMode
  {
    protected:
      int gameModeId;

    public:
      virtual FluffyMultiplayer::GameMode* process(FluffyMultiplayer::App& app,
                            const FluffyMultiplayer::SocketReceiveData& currentItem,
                            const std::vector<std::string>& cData //to avoid re-process data just pass seperated data into gameMode
                            ) = 0;
  };
}

#endif
