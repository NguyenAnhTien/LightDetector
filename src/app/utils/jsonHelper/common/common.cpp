/*****************************************************************************/
/*!
 * @file common.cpp
 * @brief The implementation of common.h
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

#include "common.h"

/*!
 * @internal
 */
bool isSensorMessage(const std::string& message)
{
    if (message.length() != MAX_SENSOR_MESSAGE_LENGTH
        || message.length() <= 0)
    {
        return false;
    }

    return true;
}

/*!
 * @internal
 */
MESSAGE_TYPE getJSONMessageType(const std::string& message)
{
    if (!isSensorMessage(message))
    {
        return MESSAGE_TYPE_DEFAULT;
    }

    switch(message[0])
    {
    case LIGHT_INTENSITY_MESSAGE_VALUE:
        return MESSAGE_TYPE_LIGHT_INTENSITY;
    default:
        return MESSAGE_TYPE_DEFAULT;
    }
}

/*!
 * @internal
 */
uint16_t convertToInt16(char LSB, char MSB)
{
	uint16_t value = LSB | uint16_t(MSB) << 8;
	return value;
}
