#include "../../include/states.h"

namespace FluffyMultiplayer
{
  //login form
  StateWaitForResponse::StateWaitForResponse(std::string _text,
    FluffyMultiplayer::AppState* retry,
    FluffyMultiplayer::LoginFormData _loginData,
    std::vector<FluffyMultiplayer::AppState*> bannedstates,
    FluffyMultiplayer::AppState* successstate,
    std::vector<int> bannedCodes,int successCode)
    {
      registerData_ptr=nullptr;
      lobbyData_ptr=nullptr;
      createLobbyData_ptr=nullptr;
      //hold passed data into varaible for when need to pass into another state.
      loginData_ptr = new FluffyMultiplayer::LoginFormData;
      loginData_ptr->_inputs = _loginData._inputs;
      loginData_ptr->_errors = _loginData._errors;
      loginData_ptr->_saveLoginStatus = _loginData._saveLoginStatus;
      loginData_ptr->identity = _loginData.identity;

      requestSent=false; //turn off flag, will help to run receiveDataQueue.push once
      timeoutCounter=MC_REQUEST_TIMEOUT;

      //retry button
      state1 = retry;


      //second button
      state2 = bannedstates;
      responseCodeAcceptor = bannedCodes;

      //third button
      state3 = successstate;
      responseCodeAcceptor2 = successCode;

      //split data from LoginFormData into a string req


      //get computer host id
      long hostId = gethostid();


      // choose is it login or relogin
      std::string temp;
      if(_loginData._inputs[0].empty() && _loginData._inputs[1].empty())
      {
        temp =  std::to_string(MC_REQUEST_RELOGIN);
        temp += std::to_string(hostId) + MC_REQUEST_DELIMITER; //hardwareId
        temp += loginData_ptr->identity + MC_REQUEST_DELIMITER;
        temp += MC_REQUEST_CLOSER;
      }
      else
      {
        temp =  std::to_string(MC_REQUEST_LOGIN) +  _loginData._inputs[0]+ MC_REQUEST_DELIMITER;
        temp += _loginData._inputs[1] +MC_REQUEST_DELIMITER;
        temp += std::to_string(hostId) + MC_REQUEST_DELIMITER; //hardwareId
        temp += loginData_ptr->identity + MC_REQUEST_DELIMITER; //identity for first time is empty, this is used when trying to relogin
        temp += MC_REQUEST_CLOSER;
      }
      requestData = temp;

      std::string fontPath = MC_PATH_TO_FONTS MC_DEFAULT_FONT;
      text = "Wait for response:\n"+ _text;
      initSimpleText(fontPath, text);

      timeouttxt.setFont(theFont);
      timeouttxt.setString("timedout press enter to retry.");
      buttonRetry.init("Retry", 200.0,200.0, sf::Color::Black,sf::Color::White, 60,30, 22);
    }


  //register Form
  StateWaitForResponse::StateWaitForResponse(std::string _text,
    FluffyMultiplayer::AppState* retry,
    FluffyMultiplayer::RegisterFormData _registerFormData,
    FluffyMultiplayer::AppState* successState,
    int successCode)
    {
      loginData_ptr=nullptr;
      createLobbyData_ptr=nullptr;
      lobbyData_ptr=nullptr;
      //hold passed data into varaible for when need to pass into another state.
      registerData_ptr = new FluffyMultiplayer::RegisterFormData;
      registerData_ptr->_inputs = _registerFormData._inputs;
      registerData_ptr->_errors = _registerFormData._errors;

      requestSent=false; //turn off flag, will help to run receiveDataQueue.push once
      timeoutCounter=MC_REQUEST_TIMEOUT;

      //retry button
      state1 = retry;

      //second button
      state2.push_back(successState);
      responseCodeAcceptor.push_back( successCode );

      //third button
      state3 = nullptr;



      //split data from LoginFormData into a string req
      //get computer host id
      long hostId = gethostid();


      std::string temp = std::to_string(MC_REQUEST_REGISTER) +  registerData_ptr->_inputs[2]+ MC_REQUEST_DELIMITER;
      temp += registerData_ptr->_inputs[0] +MC_REQUEST_DELIMITER;
      temp += registerData_ptr->_inputs[1] +MC_REQUEST_DELIMITER;
      temp += std::to_string(hostId) + MC_REQUEST_DELIMITER; //hardwareId
      temp += MC_REQUEST_CLOSER;
      requestData = temp;


      std::string fontPath = MC_PATH_TO_FONTS MC_DEFAULT_FONT;
      text = "Wait for response:\n"+ _text;
      initSimpleText(fontPath, text);

      timeouttxt.setFont(theFont);
      timeouttxt.setString("timedout press enter to retry.");
      buttonRetry.init("Retry", 200.0,200.0, sf::Color::Black,sf::Color::White, 60,30, 22);
    }


    //get lobby info by lobby id
    StateWaitForResponse::StateWaitForResponse(std::string _text,
      FluffyMultiplayer::AppState* retry,
      FluffyMultiplayer::LobbyData _lobbyInfo,
      FluffyMultiplayer::AppState* notfoundState,
      int notfoundCode,
      FluffyMultiplayer::AppState* successState,
      int successCode)
      {
        registerData_ptr=nullptr;
        createLobbyData_ptr=nullptr;
        loginData_ptr=nullptr;
        //hold passed data into varaible for when need to pass into another state.
        lobbyData_ptr = new FluffyMultiplayer::LobbyData;
        lobbyData_ptr->id = _lobbyInfo.id;
        lobbyData_ptr->isLocked = _lobbyInfo.isLocked;
        lobbyData_ptr->isVoiceChatForbidden = _lobbyInfo.isVoiceChatForbidden;
        lobbyData_ptr->isTextChatForbidden = _lobbyInfo.isTextChatForbidden;
        lobbyData_ptr->isSpecterForbidden = _lobbyInfo.isSpecterForbidden;
        lobbyData_ptr->lobbyStatusInGame = _lobbyInfo.lobbyStatusInGame;
        lobbyData_ptr->showLobbyInList = _lobbyInfo.showLobbyInList;
        lobbyData_ptr->maxPlayers = _lobbyInfo.maxPlayers;
        lobbyData_ptr->currentPlayers = _lobbyInfo.currentPlayers;
        lobbyData_ptr->gameMode = _lobbyInfo.gameMode;
        lobbyData_ptr->address = _lobbyInfo.address;

        requestSent=false; //turn off flag, will help to run receiveDataQueue.push once
        timeoutCounter=MC_REQUEST_TIMEOUT;

        //retry button
        state1 = retry;

        //second button
        state2.push_back(notfoundState);
        responseCodeAcceptor.push_back(notfoundCode);

        //third button
        state3 = successState;
        responseCodeAcceptor2 = successCode;

        //split data from LoginFormData into a string req
        std::string temp = std::to_string(MC_REQUEST_GET_LOBBY_INFO);
        temp += std::to_string(lobbyData_ptr->id) + MC_REQUEST_DELIMITER;
        temp += MC_REQUEST_CLOSER;
        requestData = temp;


        std::string fontPath = MC_PATH_TO_FONTS MC_DEFAULT_FONT;
        text = "Wait for response:\n"+ _text;
        initSimpleText(fontPath, text);

        timeouttxt.setFont(theFont);
        timeouttxt.setString("timedout press enter to retry.");
        buttonRetry.init("Retry", 200.0,200.0, sf::Color::Black,sf::Color::White, 60,30, 22);
      }


    //create lobby form
    StateWaitForResponse::StateWaitForResponse(std::string _text,
      FluffyMultiplayer::AppState* retry,
      FluffyMultiplayer::CreateLobbyFormData _lobby,
      FluffyMultiplayer::AppState* accountlimited,
      int accountlimitedCode,
      FluffyMultiplayer::AppState* successState,
      int successCode)
      {
        registerData_ptr=nullptr;
        lobbyData_ptr=nullptr;
        loginData_ptr=nullptr;

        //hold passed data into varaible for when need to pass into another state.
        createLobbyData_ptr = new FluffyMultiplayer::CreateLobbyFormData;
        createLobbyData_ptr->clientIdentity= _lobby.clientIdentity;
        createLobbyData_ptr->gameMode = _lobby.gameMode;
        createLobbyData_ptr->maxPlayers = _lobby.maxPlayers;
        createLobbyData_ptr->isTextChatAllowed = _lobby.isTextChatAllowed;
        createLobbyData_ptr->isVoiceChatAllowed = _lobby.isVoiceChatAllowed;
        createLobbyData_ptr->isSpecterAllowed = _lobby.isSpecterAllowed;
        createLobbyData_ptr->password = _lobby.password;
        createLobbyData_ptr->globalErrors = _lobby.globalErrors;

        requestSent=false; //turn off flag, will help to run receiveDataQueue.push once
        timeoutCounter=MC_REQUEST_TIMEOUT;

        //retry button
        state1 = retry;

        //second button
        state2.push_back(accountlimited);
        responseCodeAcceptor.push_back( accountlimitedCode );

        //third button
        state3 = successState;
        responseCodeAcceptor2 = successCode;

        //create request
        std::string temp = std::to_string(MC_REQUEST_CREATE_LOBBY);
        temp += createLobbyData_ptr->clientIdentity + MC_REQUEST_DELIMITER;
        temp += std::to_string(createLobbyData_ptr->gameMode) + MC_REQUEST_DELIMITER;
        temp += std::to_string(createLobbyData_ptr->maxPlayers) + MC_REQUEST_DELIMITER;
        temp += std::to_string(createLobbyData_ptr->isTextChatAllowed) + MC_REQUEST_DELIMITER;
        temp += std::to_string(createLobbyData_ptr->isVoiceChatAllowed) + MC_REQUEST_DELIMITER;
        temp += std::to_string(createLobbyData_ptr->isSpecterAllowed) + MC_REQUEST_DELIMITER;
        temp += createLobbyData_ptr->password + MC_REQUEST_DELIMITER;
        temp += MC_REQUEST_CLOSER;
        requestData = temp;


        std::string fontPath = MC_PATH_TO_FONTS MC_DEFAULT_FONT;
        text = "Wait for response:\n"+ _text;
        initSimpleText(fontPath, text);

        timeouttxt.setFont(theFont);
        timeouttxt.setString("timedout press enter to retry.");
        buttonRetry.init("Retry", 200.0,200.0, sf::Color::Black,sf::Color::White, 60,30, 22);
      }



  //other
  StateWaitForResponse::StateWaitForResponse(std::string _text,
                       const std::string& request,
                       FluffyMultiplayer::AppState* retryState,
                       FluffyMultiplayer::AppState* acceptedState,
                       int responseCodeAccepts)
  {
    loginData_ptr=nullptr;
    registerData_ptr = nullptr;
    lobbyData_ptr=nullptr;
    createLobbyData_ptr=nullptr;

    requestSent=false;
    timeoutCounter=MC_REQUEST_TIMEOUT;
    state1 = retryState;
    state2.push_back(acceptedState);
    state3 = nullptr;
    responseCodeAcceptor.push_back( responseCodeAccepts );
    requestData = request;


    std::string fontPath = MC_PATH_TO_FONTS MC_DEFAULT_FONT;
    text = "Wait for response:\n"+ _text;
    initSimpleText(fontPath, text);

    timeouttxt.setFont(theFont);
    timeouttxt.setString("timedout press enter to retry.");
    buttonRetry.init("Retry", 200.0,200.0, sf::Color::Black,sf::Color::White, 60,30, 22);
  }

  StateWaitForResponse::StateWaitForResponse(std::string _text,
                      const std::string& request,
                      FluffyMultiplayer::AppState* retryState,
                      FluffyMultiplayer::AppState* acceptedState,
                      FluffyMultiplayer::AppState* acceptedState2,
                      int responseCodeAccepts,int responseCodeAccepts2)
  {
    StateWaitForResponse(text,request,retryState,acceptedState,responseCodeAccepts);
    responseCodeAcceptor2 = responseCodeAccepts2;
    state3 = acceptedState2;

    std::string fontPath = MC_PATH_TO_FONTS MC_DEFAULT_FONT;
    text = "Wait for response:\n"+ _text;
    initSimpleText(fontPath, text);

    timeouttxt.setFont(theFont);
    timeouttxt.setString("timedout press enter to retry.");
    buttonRetry.init("Retry", 200.0,200.0, sf::Color::Black,sf::Color::White, 60,30, 22);
  }


  StateWaitForResponse::~StateWaitForResponse()
  {

  }

  int StateWaitForResponse::checkResponseCode(const std::string& _data)
  {
    std::string tempStr = _data.substr(MC_RESPONSE_POSITION_MIN_INDEX,MC_RESPONSE_POSITION_MAX_INDEX);
    const char* temp = tempStr.c_str();
    int code = std::atoi(temp);
    std::cout << "checkResponseCode=" << code << ";~;" << std::endl;
    if(code>=MC_MINUMUM_RESPONSE_CODE)
      return code;
    return -1;
  }


  std::string StateWaitForResponse::getIdentityFromResponsedData(const std::string& _data,std::string delimiter,std::string closer)
  {
    return _data.substr(MC_DATA_START_AT_INDEX, _data.length() - 6);
  }

  std::string StateWaitForResponse::getServerAddressFromResponseData(const std::string& _data,std::string delimiter,std::string closer)
  {
    std::string re = _data.substr(MC_DATA_START_AT_INDEX, _data.length() - 6);
    std::cout << "getServerAddressFromResponseData() = " << re << std::endl;
    return re;
  }

  void StateWaitForResponse::render(sf::RenderWindow& window)
  {
    if(timeoutCounter<=0)
    {
      window.draw(timeouttxt);
      buttonRetry.render(window);
    }
    else
    {
      window.draw(theText);
    }
  }


  FluffyMultiplayer::AppState* StateWaitForResponse::update(FluffyMultiplayer::App& app,
                    std::queue<std::string>& receiveDataQueue,
                    std::queue<std::string>& sendDataQueue)

  {
    if(requestSent==false)
    {
      sendDataQueue.push(requestData);
      requestSent=true;
    }

    //do counter minus to make timeout zero and left this state.
    if(timeoutCounter>0)
    {
      timeoutCounter--;
      theText.setString(text+"\nTimeout=("+std::to_string(timeoutCounter)+")");

      //check for received data.
      if(receiveDataQueue.size()>=1)
      {
        receivedData = receiveDataQueue.front();
        receiveDataQueue.pop();
        int resultRC = checkResponseCode(receivedData);

        for(int i = 0; i < responseCodeAcceptor.size(); i++)
        {
            if(resultRC == responseCodeAcceptor[i])
            {
              if(registerData_ptr!=nullptr)
              {
                registerData_ptr->identity = getIdentityFromResponsedData(receivedData,MC_RESPONSE_DELIMITER,MC_RESPONSE_CLOSER);
                app.setIdentity(registerData_ptr->identity); //save identity for app
              }
              else if(responseCodeAcceptor[i] == MS_RESPONSE_SUCCESS_GET_LOBBY_LIST) //means lobby list received
              {
                //remove closer and addiotional deliimter from data
                receivedData = receivedData.substr(0, receivedData.length()-3);

                //pass received data (lobbies) into MainPage to show as lobbyList
                return new FluffyMultiplayer::StateMainPage(receivedData);
              }
              return state2[i]; //accepted (first state passed) successfully
            }
            else if(resultRC == responseCodeAcceptor2 && state3!=nullptr)
            {
              if(loginData_ptr!=nullptr)
              {
                  loginData_ptr->identity = getIdentityFromResponsedData(receivedData,MC_RESPONSE_DELIMITER,MC_RESPONSE_CLOSER);
                  app.setIdentity(loginData_ptr->identity); //save identity for app
              }

                if(createLobbyData_ptr!=nullptr)
                {
                  createLobbyData_ptr->address = getServerAddressFromResponseData(receivedData,MC_RESPONSE_DELIMITER,MC_RESPONSE_CLOSER);
                  return new FluffyMultiplayer::StateJoinLobby(createLobbyData_ptr->address);
                }
                return state3; //second state passed successfully
              }

              /*
              get lobby info by entered lobby id:
              we have to pass lobbyData into StateShowLobbyDetails, can not pass same
              empty from StateMainPage so make state3 that is success to nullptr to
              create a new situation to do this down condition
              */
              else if(resultRC == responseCodeAcceptor2 && state3==nullptr && lobbyData_ptr!=nullptr)
              {
                return new FluffyMultiplayer::StateShowLobbyDetails(*lobbyData_ptr);
              }

              else
              {
                //login form
                if(state1==nullptr && loginData_ptr!=nullptr && timeoutCounter<=0)
                {
                  switch (resultRC)
                  {
                    case MS_ERROR_FAILED_TO_LOGIN_INCORRECT:
                    case MS_ERROR_FAILED_TO_LOGIN_NOT_EXISTS:
                    case MS_ERROR_FAILED_TO_LOGIN_BAD_DATA_SYNTAX:
                    default:
                    /*
                    dont know these failed resposne code belongs to where?
                    username or password?
                    so this part wrote on index _error[0],  for later changes
                    */
                    loginData_ptr->_errors[0] = resultRC;
                  }

                  return new FluffyMultiplayer::StateLoginForm(*loginData_ptr);
                }

                //register form
                else if(state3==nullptr && registerData_ptr!=nullptr && timeoutCounter<=0)
                {
                  switch (resultRC)
                  {
                    case MS_ERROR_FAILED_TO_REGISTER_USERNAME_EXISTS: registerData_ptr->_errors[0]=resultRC;break;
                    case MS_ERROR_FAILED_TO_REGISTER_EMIAL_EXISTS: registerData_ptr->_errors[1]=resultRC;break;
                    case MS_ERROR_FAILED_TO_REGISTER_EASY_PASSWORD: registerData_ptr->_errors[2]=resultRC;break;
                    case MS_ERROR_FAILED_TO_REGISTER_BAD_DATA_SYNTAX:
                    default:
                    /*
                    dont know other failed resposne code belongs to where?
                    username or email or password?
                    so this part wrote on index _error[0],  for later changes
                    */
                    registerData_ptr->_errors[0]=resultRC;break;
                  }
                  return new FluffyMultiplayer::StateRegisterForm(*registerData_ptr);
                }

                //create lobby form
                else if(state3!=nullptr && createLobbyData_ptr!=nullptr && timeoutCounter<=0)
                {
                  switch (resultRC)
                  {
                    case MS_ERROR_FAILED_TO_LOBBY_CREATION_INVALID_IDENTITY:
                    case MS_ERROR_FAILED_TO_LOBBY_CREATION_CANT_OWN_TWO_LOBBY:
                    case MS_ERROR_FAILED_TO_LOBBY_CREATION_BAD_DATA_SYNTAX:
                    case MS_ERROR_FAILED_TO_CREATE_LOBBY:
                    default:
                    createLobbyData_ptr->globalErrors = resultRC;
                  }
                  return new FluffyMultiplayer::StateCreateLobbyForm(*createLobbyData_ptr);
                }


                //-------------------------
              }
        } //for loop
      }
    }
    return this; //keep this state
  }


  FluffyMultiplayer::AppState* StateWaitForResponse::eventHandle(FluffyMultiplayer::App& app,
                            sf::Event& event)
  {
    //mouse realtime
    if(event.type == sf::Event::MouseButtonPressed)
    {
        mousePosition = app.appWindow.mapPixelToCoords(sf::Mouse::getPosition(app.appWindow));

        if(buttonRetry.getButtonBound().contains(mousePosition))
        {
          if(state1!=nullptr)
            return state1;
        }
    }

    switch(event.type)
    {
      //keyboard
      case sf::Event::KeyPressed:
        {
          if(event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Return)
          {
              if(timeoutCounter<=0)
              {
                if(state1!=nullptr)
                  return state1;
              }

          }
        }
        break;
    }
    return this;
  }
}
