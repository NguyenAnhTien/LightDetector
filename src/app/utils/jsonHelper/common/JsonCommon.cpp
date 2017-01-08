/*****************************************************************************/
/*!
 * @file JsonCommon.cpp
 * @brief The implementation of JsonCommon.h
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

#include "JsonCommon.h"

/*!
 * @internal
 */
bool isSensorMessage(const std::string& message)
{
    std::string messageStr(message);

    if (messageStr.length() > MAX_SENSOR_MESSAGE_LENGTH
        || messageStr.length() <= 0)
    {
        return false;
    }

    if (messageStr.find(SENSOR_MESSAGE_SPLITTER) == std::string::npos)
    {
        return false;
    }

    if (messageStr.find(IP_PORT_REGEX_SPLITTER) == std::string::npos)
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
std::string convertMessageTypeToStr(const MESSAGE_TYPE& messageType)
{
    switch(messageType)
    {
    case MESSAGE_TYPE_LIGHT_INTENSITY:
        return std::string(LIGHT_INTENSITY_TOPIC);
    case MESSAGE_TYPE_CONTROL_SMART_PLUG:
        return std::string(CONTROL_SMART_PLUG_TOPIC);
    default:
        return std::string("MESSAGE_TYPE_DEFAULT");
    }
}

/*!
 * @internal
 */
uint16_t convertHexDigitToInt16(char digit)
{
    switch(digit)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    }
    return -1;
}

/*!
 * @internal
 */
bool convertArduinoMsgToInt16(const std::string& msg, uint16_t& value)
{
    if (msg.compare("") == 0)
    {
        value = -1;
        return false;
    }
    
    uint16_t tmp = -1;

    value = 0;

    for (int i = msg.length() - 1; i > 0; i--)
    {
        tmp = convertHexDigitToInt16(msg[i]);
        if (tmp <= -1)
        {
            value = -1;
            return false;
        }
        
        value += tmp * pow(16, i - 1);
    }

    return true;
}

bool convertJsonStrToPtree(const std::string& jsonString,
                                    boost::property_tree::ptree& dataTree)
{
    std::istringstream buffer(jsonString);
    boost::property_tree::read_json(buffer, dataTree);

    return true;
}