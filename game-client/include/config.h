#ifndef H_MAIN_CLIENT_CONFIG_FILE
#define H_MAIN_CLIENT_CONFIG_FILE

#define GAME_CLIENT_VERSION "2.0.0"
//MC means MainClient

//window
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Fluffy Multiplayer Lobby"
#define WINDOW_STYLE sf::Style::Default
#define WINDOW_MAX_FPS 60

#define DEFAULT_TEXT_PORT 4657
#define DEFAULT_VOICE_PORT 4658
#define VOICE_CHAT_BUFFER_SIZE 1024
#define TEXT_CHAT_BUFFER_SIZE 1024

#define DEFAULT_PLAYER_NAME "?player?"
#define PLAYER_NAME_NOT_FOUND_NAME "?player?"
#define DEFAULT_PLAYER_VOICE_ENABLE false


#define APP_LOG_FILENAME "game.log"
#define APP_PRINT_LOGS_LEVEL FluffyMultiplayer::LogType::All

#define SOCKET_LOG_FILENAME "socket.log"
#define SOCKET_PRINT_LOGS_LEVEL FluffyMultiplayer::LogType::All

#define WINDOW_BACKGROUND_COLOR sf::Color(40,42,48)
#define FORM_HIDE_CHARECTER '*'
#define STATES_ASSET_PATH "./assets/states/"

#define MS_DATA_ENCRYPT_DECRYPT_SHIFT 5

#define MC_PATH_TO_FONTS "./assets/fonts/"
#define MC_DEFAULT_FONT "arial.ttf"

#define GAME_CLIENT_APPLICATION_PATH "./"
#define GAME_CLIENT_APPLICATION_NAME "game.run"

#define MC_SHOW_ERROR_NOTIFICATIONS true
#define MC_SHOW_SUCCESS_NOTIFICATIONS false

#define MC_RECEIVE_BUFFER 1024
#define CLIENT_LOCAL_SERVER_LIST_FILE "serverlist.txt"
#define CLIENT_LOCAL_APP_CONFIG_FILE "identity.ini"

#define MC_IP_PORT_SEPARATOR ":"
#define MC_IP_PORT_ENDLINE ";"
#define APP_EMPTY_DATA_SEND ""


#define MC_APP_CONFIG_IDENTITY_KEY "identity"
#define MC_APP_CONFIG_SEPERATOR "="
#define MC_APP_CONFIG_ENDLINE ";"
#define MC_IDENTITY_MIN_LENGTH 59
#define MC_IDENTITY_MAX_LENGTH 60

#define MC_DATA_START_AT_INDEX 3

#define MC_REQUEST_DELIMITER ",&"
#define MC_REQUEST_CLOSER "~"
#define MC_RESPONSE_DELIMITER MC_REQUEST_DELIMITER
#define MC_RESPONSE_CLOSER MC_REQUEST_CLOSER


#define MC_SERVER_DEFAULT_IP "127.0.0.1"
#define MC_SERVER_DEFAULT_PORT 8888
#define MC_SERVER_IP_NOT_ALLOWED_LIST {"0.0.0.0"}

#define MC_DEFAULT_PORT 64001

#define MS_RECEIVED_DATA_MINIMUM_LENGTH 1
#define MS_DATA_DELIMITER ",&"
#define MS_REQUEST_CLOSER "~"
#define MS_DATA_CODE_INDEX_A 0
#define MS_DATA_CODE_INDEX_B 1
#define MS_DATA_CODE_INDEX_C 2

#define MC_REQUEST_TIMEOUT 100
#define MC_STATE_BIND_PICK_PORT_TRY_COUNT 10

#define MC_MINUMUM_RESPONSE_CODE 100
//internal and external erros included
#define MC_ERROR_RESPONSE_CODE_MIN 301
#define MC_ERROR_RESPONSE_CODE_MAX 500
#define MC_SUCCESS_RESPONSE_CODE_MIN 201
#define MC_SUCCESS_RESPONSE_CODE_MAX 300
#define MC_RESPONSE_POSITION_MIN_INDEX 0
#define MC_RESPONSE_POSITION_MAX_INDEX 3

#define GAME_MODE_MENSCH_ID 1

#define GAME_MODE_LIST {"Mensch","Chess","TicTacToe"}
#define GAME_MODE_TEXTURE_LIST {"gm-mensch.png","gm-chess.png","gm-tictatoe.png"}
#define MAX_PLAYER_LIST {"2","4","6","8","10"}

#define MS_GET_LOBBY_LIST_COUNT_OF_RESULTS 10
#define MS_GET_LOBBY_LIST_LOBBY_FILEDS 12
#define MS_MAINPAGE_LOBBY_CELL_X_PADDING 100.0
#define MS_MAINPAGE_LOBBY_CELL_Y_PADDING 50.0

#define UI_COMPONENT_TEXTURE_DEFAULT "./somewhere/componentTextureNotFound.png"
#define UI_COMPONENT_FONT_DEFAULT "./somewhere/componentFontNotFound.ttf"

#define MAX_PLAYERS_IN_LOBBY 5
#define PLAYERS_LOBBY_EMPTY_SLOT_NAME "empty"
#define PLACE_HOLDER_TEXT_CHAT "enter text"
//state main page elements: 48x48
#define ICON_OWNER "iconOwner.png"
#define ICON_SPECTER "iconSpecter.png"
#define ICON_ADMIN "iconAdmin.png"
#define ICON_SETTINGS "iconSettings.png"
#define ICON_CLOSE "iconClose.png"
#define ICON_VOICECHAT "iconVoiceChat.png"
#define ICON_SEND "iconSend.png"
#define ICON_KICK "iconKick.png"
#define ICON_BAN "iconBan.png"
#define ICON_PIECE "iconPiece.png"
#define ICON_PAUSE "iconPause.png"
#define ICON_RESUME "iconResume.png"
#define ICON_BACKGROUND_GAMEMODE_MENSCH "mensch-bg.png"
#define ICON_VOICECHAT_DISABLED_TEXTURE "lobbyVoiceChatDisabled.png"
#define ICON_VOICECHAT_ENABLED_TEXTURE "lobbyVoiceChatEnabled.png"

//---------------------------- Form Elements
#define FE_PATH_TO_ASSETS "./assets/uiComponents/"

//TI means Text Input
#define TI_DEFAULT_FONT_PATH MC_PATH_TO_FONTS MC_DEFAULT_FONT
#define TI_DEFAULT_FONT_SIZE 17
#define TI_DEFAULT_FORGROUND_COLOR sf::Color::White
#define TI_DEFAULT_BACKGROUND_COLOR sf::Color::White
#define TI_DEFAULT_SIZE 100,70
#define TI_DEFAULT_STYLE sf::Text::Bold
#define TI_DEFAULT_POSITION_X 400
#define TI_DEFAULT_POSITION_Y 250

#define TI_TITLE_PADDING_X 0.0
#define TI_TITLE_PADDING_Y 25.0
#define TI_ERROR_PADDING_X 200.0
#define TI_ERROR_PADDING_Y 25.0
#define TI_INPUTBOX_PADDING_X 0.0 //also mainText will this this
#define TI_INPUTBOX_PADDING_Y 0.0 //also mainText will this this
#define TI_TEXTURE_INPUT_BOX "textInputTexture.png"


//TIP means Text Input Password
#define TIP_BUTTON_VISIBLE_PASSWORD_PADDING_X (0.0,0.0)
#define TIP_BUTTON_VISIBLE_PASSWORD_PADDING_Y (0.0,0.0)
#define TIP_TEXTURE_BUTTON_VISIBLE_PASSWORD_ON "passwordVisibleButtonTexture.png"
#define TIP_TEXTURE_BUTTON_VISIBLE_PASSWORD_OFF "passwordInvisbleButtonTexture.png"


//button component
#define BUTTON_TEXTURE "buttonTexture.png"
#define BUTTON_DEFAULT_BACKGROUND_COLOR sf::Color::White
#define BUTTON_DEFAULT_FORGROUND_COLOR sf::Color::Black
#define BUTTON_DEFAULT_SIZE_WIDTH 20
#define BUTTON_DEFAULT_SIZE_HEIGHT 10
#define BUTTON_DEFAULT_STYLE sf::Text::Bold
#define BUTTON_DEFAULT_FONT_SIZE 17
#define BUTTON_DEFAULT_POS_X 10.0
#define BUTTON_DEFAULT_POS_Y 10.0


//picture button component
#define PICTURE_BUTTON_REFRESH_LOBBY_LIST_TEXTURE "pictureButtonRefreshLobbyListTexture.png"
#define PICTURE_BUTTON_LOGOUT_TEXTURE "pictureButtonLogoutTexture.png"
#define PICTURE_BUTTON_QUIT_TEXTURE "pictureButtonQuitTexture.png"
#define PICTURE_BUTTON_TEXT_POS_X 0.0
#define PICTURE_BUTTON_TEXT_POS_Y 35.0

//checkBox component
#define CHECKBOX_DEFAULT_TEXT "checkbox"
#define CHECKBOX_CHECKED_TEXTURE "checkBoxCheckedTexture.png"
#define CHECKBOX_UNCHECKED_TEXTURE "checkBoxUncheckedTexture.png"
#define CHECKBOX_DEFAULT_FORGROUND_COLOR sf::Color::White
#define CHECKBOX_DEFAULT_BACKGROUND_COLOR sf::Color::Black
#define CHECKBOX_DEFAULT_POS_X 10.0
#define CHECKBOX_DEFAULT_POS_Y 10.0
#define CHECKBOX_DEFAULT_SIZE_WIDTH 20
#define CHECKBOX_DEFAULT_SIZE_HEIGHT 10
#define CHECKBOX_DEFAULT_FONT_SIZE 17
#define CHECKBOX_DEFAULT_STATUS false
#define CHECKBOX_DEFAULT_STYLE sf::Text::Bold
#define CHECKBOX_BOX_PADDING_X 125


//spinBox component
#define SPINBOX_DEFAULT_TEXT "spinbox"
#define SPINBOX_DEAULT_ITEMS {"exampleA","exampleB","exampleC"}
#define SPINBOX_TEXTURE "spinBoxTexture.png"
#define SPINBOX_DEFAULT_FORGROUND_COLOR sf::Color::White
#define SPINBOX_DEFAULT_BACKGROUND_COLOR sf::Color::Black
#define SPINBOX_DEFAULT_POS_X 10.0
#define SPINBOX_DEFAULT_POS_Y 10.0
#define SPINBOX_DEFAULT_SIZE_WIDTH 20
#define SPINBOX_DEFAULT_SIZE_HEIGHT 10
#define SPINBOX_DEFAULT_FONT_SIZE 17
#define SPINBOX_DEFAULT_ITEM 0
#define SPINBOX_DEFAULT_STYLE sf::Text::Bold
#define SPINBOX_SPIN_BUTTON_PADDING_X 225
#define SPINBOX_SPIN_BUTTON_PADDING_Y 35


//icon text component
#define ICON_TEXT_TEXT_PADDING_X +0.0
#define ICON_TEXT_TEXT_PADDING_Y +30.0
#define ICON_TEXT_DEFAULT_FONT_SIZE 17
#define ICON_TEXT_DEFAULT_STYLE sf::Text::Bold


#define NOTIFICATIONBOX_BACKGROUND_TEXTURE "notificationBackgroundTexture.png"
#define NOTIFICATIONBOX_CLOSE_BUTTON_TEXTURE "notificationCloseButtonTexture.png"
#define NOTIFICATIONBOX_COPY_ERROR_BUTTON_TEXTURE "notificationCopyButtonTexture.png"

#define NOTIFICATIONBOX_BACK_OF_BACKGROUND_COLOR sf::Color::Transparent
#define NOTIFICATIONBOX_BACK_OF_BACKGROUND_WIDTH_PERCENT 100
#define NOTIFICATIONBOX_BACK_OF_BACKGROUND_HEIGHT_PERCENT 100


#define NOTIFICATIONBOX_TITLE_FONT_SIZE 18
#define NOTIFICATIONBOX_MESSAGE_FONT_SIZE 17

#define NOTIFICATIONBOX_BACKGROUND_PADDING_X +0.0
#define NOTIFICATIONBOX_BACKGROUND_PADDING_Y +0.0

#define NOTIFICATIONBOX_TITLE_PADDING_X +5.0
#define NOTIFICATIONBOX_TITLE_PADDING_Y +5.0

#define NOTIFICATIONBOX_MESSAGE_PADDING_X +5.0
#define NOTIFICATIONBOX_MESSAGE_PADDING_Y +25.0

#define NOTIFICATIONBOX_CLOSEBUTTON_PADDING_X +280.0
#define NOTIFICATIONBOX_CLOSEBUTTON_PADDING_Y +5.0

#define NOTIFICATIONBOX_COPYBUTTON_PADDING_X +240.0
#define NOTIFICATIONBOX_COPYBUTTON_PADDING_Y +5.0





#define THIS_CLIENT_PLYARE_LOBBY_INDEX 0

#define PLAYER_LIST_BOX_PER_PLAYER_Y 50.0
#define PLAYER_LIST_X 27.0
//player list paddings
#define PLAYER_LIST_ID_PADDING_X +0.0
#define PLAYER_LIST_ID_PADDING_Y +5.0

#define PLAYER_LIST_NAME_PADDING_X +35.0
#define PLAYER_LIST_NAME_PADDING_Y +5.0

#define PLAYER_LIST_VOICECHAT_PADDING_X +120.0
#define PLAYER_LIST_VOICECHAT_PADDING_Y +5.0

#define PLAYER_LIST_OWNER_PADDING_X +155.0
#define PLAYER_LIST_OWNER_PADDING_Y +5.0

#define PLAYER_LIST_ADMIN_PADDING_X +195.0
#define PLAYER_LIST_ADMIN_PADDING_Y +5.0

#define PLAYER_LIST_SPECTER_PADDING_X +230.0
#define PLAYER_LIST_SPECTER_PADDING_Y +5.0


#define TEXT_CHAT_BOX_MAXIMUM_LINES 15

#endif
