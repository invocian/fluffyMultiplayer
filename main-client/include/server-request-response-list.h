#ifndef H_MAIN_SERVER_REQUEST_RESPONSE_LIST
#define H_MAIN_SERVER_REQUEST_RESPONSE_LIST

//= = = = = = = = = = = = = = = main client rquests = = = = = = = = = = = = = = =
#define MC_REQUEST_CONNECT 100
#define MC_REQUEST_DISCONNECT 101
#define MC_REQUEST_LOGIN 102
#define MC_REQUEST_REGISTER 103
#define MC_REQUEST_CREATE_LOBBY 104
#define MC_REQUEST_GET_LOBBY_LIST 105
#define MC_REQUEST_GET_LOBBY_INFO 106
#define MC_REQUEST_LATEST_VERSION 107


//= = = = = = = = = = = = = = = main server response success = = = = = = = = = = = = = = =
#define MS_RESPONSE_CONNECTION_ACCEPTED 200
#define MS_RESPONSE_DISCONNECTED 201
#define MS_RESPONSE_SUCCESS_LOGIN 202
#define MS_RESPONSE_SUCCESS_REGISTER 203
#define MS_RESPONSE_SUCCESS_LOBBY_CREATED 204
#define MS_RESPONSE_SUCCESS_GET_LOBBY_LIST 205
#define MS_RESPONSE_SUCCESS_GET_LOBBY_INFO 206
#define MS_RESPONSE_SUCCESS_LATEST_VERSION 207


//= = = = = = = = = = = = = = = main server response errors = = = = = = = = = = = = = = =
#define MS_ERROR_CONNECTION_EXISTS 400
// #define MS_ERROR_CONNECTION_REJECTED_USING_VPN 401
#define MS_ERROR_CONNECTION_REJECTED 402
#define MS_ERROR_CONNECTION_NOT_EXISTS 403

#define MS_ERROR_FAILED_TO_LOGIN_INCORRECT 404
#define MS_ERROR_FAILED_TO_LOGIN_NOT_EXISTS 405
#define MS_ERROR_FAILED_TO_LOGIN_BANNED 406
#define MS_ERROR_FAILED_TO_LOGIN_BAD_DATA_SYNTAX 407

#define MS_ERROR_FAILED_TO_REGISTER_USERNAME_EXISTS 408
#define MS_ERROR_FAILED_TO_REGISTER_EMIAL_EXISTS 409
#define MS_ERROR_FAILED_TO_REGISTER_EASY_PASSWORD 410
#define MS_ERROR_FAILED_TO_REGISTER_BAD_DATA_SYNTAX 411

#define MS_ERROR_FAILED_TO_LOBBY_CREATION_INVALID_IDENTITY 412
#define MS_ERROR_FAILED_TO_LOBBY_CREATION_CANT_OWN_TWO_LOBBY 413
#define MS_ERROR_FAILED_TO_LOBBY_CREATION_FORBIDDEN_FOR_YOU 414
#define MS_ERROR_FAILED_TO_LOBBY_CREATION_BAD_DATA_SYNTAX 415

#define MS_ERROR_FAILED_TO_GET_LOBBY_LIST_NO_LOBBY_AVAIABLE 416
#define MS_ERROR_FAILED_TO_GET_LOBBY_INFO_LOBBY_NOT_FOUND 417
#define MS_ERROR_FAILED_TO_GET_LOBBY_INFO_BAD_DATA_SYNTAX 418

//= = = = = = = = = = = = = = = main server internal errors = = = = = = = = = = = = = = =
#define MS_ERROR_FAILED_TO_INSERT_CLIENT_IDENTITY 500
#define MS_ERROR_FAILED_TO_REGISTER_CLIENT 501
#define MS_ERROR_FAILED_TO_CREATE_LOBBY 502
#define MS_ERROR_FAILED_TO_GET_LOBBY_LIST 503
#define MS_ERROR_FAILED_TO_GET_LOBBY_INFO 504
#define MS_ERROR_FAILED_TO_LOGIN_CLIENT 505

#endif
