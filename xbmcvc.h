/*********************************************
* Constants and things
*********************************************/


/* Constants */
#define VERSION            "0.4"
#define USAGE_MESSAGE         "\n" \
               "Usage: xbmcvc [ -H host ] [ -P port ] [ -V ] [ -h ]\n" \
               "\n" \
               "    -H hostname  Hostname or IP address of the XBMC instance you want to control (default: localhost)\n" \
               "    -P port      Port number the XBMC instance you want to control is listening on (default: 8080)\n" \
               "    -U username  Username for XBMC\n" \
               "    -p password  Password for XBMC\n" \
               "    -D device    Name of ALSA device to capture speech from\n" \
               "    -V           Print version information and exit\n" \
               "    -h           Print this help message\n" \
               "\n"

#define MAX_ACTIONS        5
#define MAX_LISTEN_TIME    3 //In Seconds
#define JSON_RPC_DEFAULT_HOST    "localhost"
#define JSON_RPC_DEFAULT_PORT    8080
#define JSON_RPC_USER_URL        "http://%s:%s@%s:%s/jsonrpc"
#define JSON_RPC_URL          "http://%s:%s/jsonrpc"
#define JSON_RPC_POST         "{\"jsonrpc\":\"2.0\",\"method\":\"%s\",\"id\":1}"
#define JSON_RPC_POST_WITH_PARAMS   "{\"jsonrpc\":\"2.0\",\"method\":\"%s\",\"params\":{%s},\"id\":1}"
#define EVENTSERVER_URL       "http://%s:%s/xbmcCmds/xbmcHttp?command="
#define EVENTSERVER_USER_URL  "http://%s:%s@%s:%s/xbmcCmds/xbmcHttp?command="

/* Macros */
#define DIE(message)       { printf("Fatal error at %s:%d: %s\n", __FILE__, __LINE__, message); exit(1); }

/* structure passed to CURL callback */
typedef struct {
   char**   dst;  /* destination buffer */
   int   dst_s;   /* destination buffer size */
} curl_userdata_t;

/* Global configuration variables */
char* config_json_rpc_user;
char* config_json_rpc_pass;
char* config_json_rpc_host;
char* config_json_rpc_port;
char* config_alsa_device;

/* Exit flag */
volatile int exit_flag = 0;

