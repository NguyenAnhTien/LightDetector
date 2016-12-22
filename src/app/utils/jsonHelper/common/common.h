/*****************************************************************************/
/*!
 * @file common.h
 * @brief The declaration which is used in JsonBuilder and JsonParser
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail
 *
 * Modified History
 * ---------------
 * 2016-Dec-21 Created tien.nguyenanh94@gmail.com
 */
/*****************************************************************************/

#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string.h>
#include <string>
#include <stdint.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#define MAX_SENSOR_MESSAGE_LENGTH 5
#define LIGHT_INTENSITY_MESSAGE 'L'
#define ATTR_JSON_MESSAGE_TYPE "MESSAGE_TYPE"
#define ATTR_JSON_DATA "data"
#define ATTR_JSON_LIGHT_INTENSITY "LIGHT_INTENSITY"
#define ATTR_JSON_MOMENT "moment"

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
MESSAGE_TYPE getJSONMessageType(std::string message);

/*!
 * @brief
 * param[in] message
 * return
 */
bool isSensorMessage(const std::string& message);

/*!
 * @brief
 * param[in] message
 * return
 */
uint16_t convertToInt16(char LSB, char MSB);

#endif
