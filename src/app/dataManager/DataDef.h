#ifndef __DATA_STRUCT_DEF_H__
#define __DATA_STRUCT_DEF_H__

#define MAX_SENSOR_MESSAGE_LENGTH 24
#define IP_PORT_TOKEN_SIZE 2

#define IP_PORT_REGEX_SPLITTER ":"
#define SENSOR_MESSAGE_SPLITTER ";"
#define JSON_PATH_SPLITTER "."
#define LIGHT_INTENSITY_MESSAGE_VALUE 'L'
#define ATTR_JSON_MESSAGE_TYPE "MESSAGE_TYPE"
#define ATTR_JSON_DATA "data"
#define ATTR_JSON_LIGHT_INTENSITY "LIGHT_INTENSITY_VALUE"
#define ATTR_JSON_MOMENT "moment"
#define LIGHT_INTENSITY_TOPIC "LIGHT_INTENSITY_TOPIC"
#define CONTROL_SMART_PLUG_TOPIC "LIGHT_CONTROL_SMART_PLUG_TOPIC"
#define ATTR_JSON_IP "IP"
#define ATTR_JSON_PORT "Port"
#define ATTR_JSON_SENDER "Sender"

typedef enum
{
    MESSAGE_TYPE_DEFAULT = -1,
    MESSAGE_TYPE_LIGHT_INTENSITY,
    MESSAGE_TYPE_CONTROL_SMART_PLUG
}MESSAGE_TYPE;

typedef struct
{
    char ip[20];
    long port;
}Sender;

typedef struct
{
    long lightIntensity;
}LightIntensity;

typedef struct
{
    LightIntensity data;
    Sender sender;

}LightIntensityInfo;

#endif