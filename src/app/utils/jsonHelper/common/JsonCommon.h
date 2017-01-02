/*****************************************************************************/
/*!
 * @file JsonCommon.h
 * @brief The declaration which is used in JsonBuilder and JsonParser
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail
 *
 * Modified History
 * ---------------
 * 2016-Dec-21 Created tien.nguyenanh94@gmail.com
 * 2016-Dec-22 Modified tien.nguyenanh94@gmail.com
 */
/*****************************************************************************/

#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string.h>
#include <string>
#include <stdint.h>
#include <math.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#define MAX_SENSOR_MESSAGE_LENGTH 24
#define IP_PORT_TOKEN_SIZE 2

#define IP_PORT_REGEX_SPLITTER ":"
#define SENSOR_MESSAGE_SPLITTER ";"
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

enum MESSAGE_TYPE
{
    MESSAGE_TYPE_DEFAULT = -1,
    MESSAGE_TYPE_LIGHT_INTENSITY,
    MESSAGE_TYPE_CONTROL_SMART_PLUG
};

/*!
 * @brief
 * param[in] message
 * return
 */
MESSAGE_TYPE getJSONMessageType(const char* message);

/*!
 * @brief
 * param[in] message
 * return
 */
std::string convertMessageTypeToStr(const MESSAGE_TYPE& messageType);

/*!
 * @brief
 * param[in] message
 * return
 */
bool isSensorMessage(const char* message);

/*!
 * @brief
 * param[in] message
 * return
 */
uint16_t convertToInt16(char LSB, char MSB);

/*!
 * @brief
 * param[in] message
 * return
 */
bool convertArduinoMsgToInt16(const char* msg, uint16_t* value);



#endif
