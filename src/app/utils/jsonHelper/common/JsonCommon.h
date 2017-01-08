/***************************************************************************/
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
/***************************************************************************/

#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "DataDef.h"

/*!
 * @brief
 * param[in] message
 * return
 */
MESSAGE_TYPE getJSONMessageType(const std::string& message);

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
bool isSensorMessage(const std::string& message);

/*!
 * @brief
 * param[in] message
 * return
 */
bool convertArduinoMsgToInt16(const std::string& msg, uint16_t& value);


/*!
 * @brief
 * param[in] message
 * return
 */
bool convertJsonStrToPtree(const std::string& jsonString,
                                    boost::property_tree::ptree& dataTree);

#endif
