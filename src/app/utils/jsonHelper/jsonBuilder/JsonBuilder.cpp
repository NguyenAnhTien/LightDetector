/*****************************************************************************/
/*!
 * @file JsonBuilder.cpp
 * @brief The implementation of JsonBuilder.
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

#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <regex>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "JsonBuilder.h"

#ifdef UNITTEST
#define STATIC
#else
#define STATIC static
#endif

/*!
 * @internal
 */
STATIC bool buildJsonMessageType(const MESSAGE_TYPE& messageType,
                                boost::property_tree::ptree& messageTypeTree)
{
    if (messageType == MESSAGE_TYPE_DEFAULT)
    {
        return false;
    }

    messageTypeTree.put(ATTR_JSON_MESSAGE_TYPE, ATTR_JSON_LIGHT_INTENSITY);

    return true;
}

/*!
 * @internal
 */
STATIC bool buildLightIntensityJson(const std::string& message,
                                    boost::property_tree::ptree& dataTree)
{
    if (getJSONMessageType(message) != MESSAGE_TYPE_LIGHT_INTENSITY)
    {
        return false;
    }

    uint16_t lightIntensity = -1;

    if (!convertArduinoMsgToInt16(message, lightIntensity))
    {
        return false;
    }

    dataTree.put(ATTR_JSON_LIGHT_INTENSITY, lightIntensity);
    
    return true;
}

/*!
 * @internal
 */
std::vector<std::string> splitWordRegex(const std::string& message,
                            const std::string& splitter)
{
    std::regex rgxSplitter(splitter);
    std::vector<std::string> token;
    std::sregex_token_iterator iter(message.begin(),
                                    message.end(),
                                    rgxSplitter,
                                    -1);

    std::sregex_token_iterator end;
    for(; iter != end; iter++)
    {
        token.push_back(*iter);
    }

    return token;
}

/*!
 * @internal
 */
STATIC bool buildIPSenderJSON(const std::string& ipAddress,
                                boost::property_tree::ptree& senderTree)
{
    boost::property_tree::ptree senderDataTree;

    std::vector<std::string> token = splitWordRegex(ipAddress,
                                    std::string(IP_PORT_REGEX_SPLITTER));

    if (token.size() != IP_PORT_TOKEN_SIZE)
    {
        return false;
    }

    senderTree.put(ATTR_JSON_IP, token[0]);
    senderTree.put(ATTR_JSON_PORT, token[1]);

    return true;
}

/*!
 * @internal
 */
std::string writeJsonToString(boost::property_tree::ptree& pTree)
{
    std::ostringstream buffer; 
    boost::property_tree::write_json(buffer, pTree, false); 
    
    return buffer.str();
}

/*!
 * @internal Using Regex to break message down into two part:
 *                 Data and IP of sender
 */
bool buildJson(const std::string& message, std::string& jsonString)
{
    boost::property_tree::ptree root;
    boost::property_tree::ptree messageTypeTree;
    boost::property_tree::ptree dataTree;
    boost::property_tree::ptree senderTree;

    std::vector<std::string> token = splitWordRegex(message,
                                    std::string(SENSOR_MESSAGE_SPLITTER));

    if (token.size() < 2)
    {
        return false;
    }

    MESSAGE_TYPE messageType = getJSONMessageType(token[0].c_str());

    if (!buildJsonMessageType(messageType, root))
    {
        return false;
    }

    if (!buildLightIntensityJson(token[0].c_str(), dataTree))
    {
        return false;
    }

    if (!buildIPSenderJSON(token[1].c_str(), senderTree))
    {
        return false;
    }

    root.add_child(ATTR_JSON_DATA, dataTree);
    root.add_child(ATTR_JSON_SENDER, senderTree);

    jsonString = writeJsonToString(root);

    return true;
}
