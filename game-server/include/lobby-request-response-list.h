#ifndef LOBBY_REQUEST_RESPONSE_LIST
#define LOBBY_REQUEST_RESPONSE_LIST


// ------------------------- request, range: 100 -> 200

//lobby
#define REQUEST_CONNECT_TO_LOBBY 100
#define REQUEST_RECONNECT_TO_LOBBY 101
#define REQUEST_DISCONNECT_FROM_LOBBY 102
#define REQUEST_JOIN_TO_LOBBY 103
#define REQUEST_GET_LOBBY_SETTINGS 104
#define REQUEST_UPDATE_LOBBY_SETTINGS 105
#define REQUEST_STOP_START_GAME 106
#define REQUEST_DELETE_LOBBY 108
#define REQUEST_KICK_PLAYER 109
#define REQUEST_BAN_PLAYER 110
//text chat
#define REQUEST_SEND_TEXT_CHAT 112
//voice chat
#define REQUEST_SEND_VOICE_CHAT 113
#define REQUEST_ENABLE_DISABLE_VOICE_CHAT 114 //add/remoev client to/from voice chats



// ------------------------- responses, range: 201 -> 500
//if there is no comment after resposne code that will be send only to sender
// = = = success 201 (to all or sender)
#define RESPONSE_CONNECTION_ACCEPTED 201 //to sender (connection accepted not mean joint lobby)
#define RESPONSE_PLAYER_RECONNECTED_INTO_LOBBY 202 //to all
#define RESPONSE_PLAYER_DISCONNECTED 203//to all
#define RESPONSE_PLAYER_JOINT_INTO_LOBBY 204//to all (correct password)
#define RESPONSE_YOU_ARE_JOINT_INTO_LOBBY 205
#define RESPONSE_PLAYER_KICKED_FROM_LOBBY 206 //to all
#define RESPONSE_PLAYER_BANNED_FROM_LOBBY 207 //to all
#define RESPONSE_GAME_STOPPED 208 //to all
#define RESPONSE_GAME_STARTED 209 //to all
#define RESPONSE_PLAYER_VOICE_CHAT_ENABLED 210 // to all
#define RESPONSE_PLAYER_VOICE_CHAT_DISABLED 211 // to all
#define RESPONSE_PLAYER_SENT_VOICE_MESSAGE 212 // to all
#define RESPONSE_PLAYER_SENT_TEXT_MESSAGE 213  // to all
#define RESPONSE_PLAYER_CONNECTION_LOST 214 // to all
#define RESPONSE_LOBBY_DELETED 215 //to all
#define RESPONSE_LOBBY_SETTINGS_UPDATED 216 //to all
#define RESPONSE_LOBBY_SETTINGS_IS 217
#define RESPONSE_LOBBY_OWNER_CHANGED 218 //to all
#define RESPONSE_LOBBY_PLAYERS_ARE 219

#define RESPONSE_UNKNOWN_REQUEST_GAME_PAUSED_OR_NOT_STARTED 220
#define RESPONSE_UNKNOWN_REQUEST_GAME_IS_NOT_STARTED 221

// = = = errors 301 (to sender)
#define RESPONSE_ERROR_CONNECTION_EXISTS 301
#define RESPONSE_ERROR_CONNECTION_BLOCKED 302//maybe because of spam
#define RESPONSE_ERROR_CONNECTION_REJECTED 303
#define RESPONSE_ERROR_CONNECTION_NOT_EXISTS 304
// #define RESPONSE_ERROR_CONNECTION_USING_VPN_FORBIDDEN 305
#define RESPONSE_ERROR_RECONNECT_INVALID_IDENTITY 306
#define RESPONSE_ERROR_DISCONNECT_YOU_ARE_NOT_CONNECTED 307
#define RESPONSE_ERROR_JOIN_LOBBY_PASSWORD_INCORRECT 308
#define RESPONSE_ERROR_JOIN_LOBBY_INVALID_IDENTITY 309 //identity not found
#define RESPONSE_ERROR_JOIN_LOBBY_YOU_ARE_BANNED 310
#define RESPONSE_ERROR_JOIN_LOBBY_YOU_ARE_ALREADY_JOINT 311
#define RESPONSE_ERROR_GET_LOBBY_SETTINGS_NO_PERMISSION 312
#define RESPONSE_ERROR_UPDATE_LOBBY_SETTINGS_NO_PERMISSION 313
#define RESPONSE_ERROR_START_GAME_NO_PERMISSION 314
#define RESPONSE_ERROR_START_GAME_ALREADY_RUN 315
#define RESPONSE_ERROR_STOP_GAME_NO_PERMISSION 316
#define RESPONSE_ERROR_STOP_GAME_NOT_STARTED 317
#define RESPONSE_ERROR_DELETE_LOBBY_NO_PERMISSION 318
#define RESPONSE_ERROR_KICK_PLAYER_NO_PERMISSION 319
#define RESPONSE_ERROR_KICK_PLAYER_INVALID_TARGET 320
#define RESPONSE_ERROR_BAN_PLAYER_NO_PERMISSION 321
#define RESPONSE_ERROR_BAN_PLAYER_INVALID_TARGET 322
#define RESPONSE_ERROR_TRANSFER_OWNERSHIP_NO_PERMISSION 323
#define RESPONSE_ERROR_TRANSFER_OWNERSHIP_INVALID_TARGET 324
#define RESPONSE_ERROR_SEND_TEXT_CHAT_DISABLED 325
#define RESPONSE_ERROR_SEND_VOICE_CHAT_DISABLED 326
#define RESPONSE_ERROR_INVALID_DATA_SYNTAX 327
#define RESPONSE_ERROR_YOUR_GAME_CLIENT_VERSION_IS_OUT_OF_DATE 328

// = = = internal errors 401 (to sender)
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_CONNECT 401
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_DISCONNECT 402
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_RECONNECT 403
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_JOIN_INTO_LOBBY 404
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_GET_LOBBY_SETTINGS 405
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_UPDATE_LOBBY_SETTINGS 406
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_START_GAME 407
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_STOP_GAME 408
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_DELETE_LOBBY 409
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_KICK_PLAYER 410
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_BAN_PLAYER 411
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_TRANSFER_LOBBY_OWNERSHIP 412
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_TEXT_CHAT 413
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_VOICE_CHAT 414
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_ENABLE_VOICE_CHAT 415
#define RESPONSE_INTERNAL_ERROR_FAILED_TO_DISABLE_VOICE_CHAT 416

#endif
