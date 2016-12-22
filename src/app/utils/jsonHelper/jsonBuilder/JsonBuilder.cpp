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
 */
/*****************************************************************************/

#include "JsonBuilder.h"

#ifdef UNITTEST
#define STATIC
#else
#define STATIC static
#endif

/*!
 * @internal
 */
bool buildJson(const std::string& message, std::string& jsonString)
{
    boost::property_tree::ptree root;
    boost::property_tree::ptree messageTypeTree;
    boost::property_tree::ptree dataTree;

    MESSAGE_TYPE messageType = getMessageType(message);
    if (messageType == MESSAGE_TYPE.DEFAULT)
    {
        return false;
    }

    if (!buildJsonMessageType(messageType, messageTypeTree))
    {
        return false;
    }

    if (messageType == LIGHT_INTENSITY)
    {
        if (!buildLightIntensityJson(message, dataTree))
        {
            return false;
        }
    }

    root.add_child(ATTR_JSON_MESSAGE_TYPE, messageTypeTree);
    root.add_child(ATTR_JSON_DATA, dataTree);

    if (!writeJsonToString(root, jsonString))
    {
        return false;
    }

    return true;
}

/*!
 * @internal
 */
static bool buildJsonMessageType(const MESSAGE_TYPE& messageType,
                                boost::property_tree::ptree& messageTypeTree)
{
    if (messageTypeTree == NULL)
    {
        return false;
    }

    messageTypeTree.put(ATTR_JSON_MESSAGE_TYPE, ATTR_JSON_LIGHT_INTENSITY);

    return true;
}

/*!
 * @internal
 */
bool buildLightIntensityJson(const std::string& message,
                                    boost::property_tree::ptree& dataTree)
{
    if (!isSensorMessage(message))
    {
        return false;
    }

    if (getJSONMessageType(message) != LIGHT_INTENSITY_MESSAGE)
    {
        return false;
    }


    int lightIntensity = convertToInt16(message[1], message[2]);
    int moment = convertToInt16(message[3], message[4]);

    dataTree.put(ATTR_JSON_LIGHT_INTENSITY, lightIntensity);
    dataTree.put(ATTR_JSON_MOMENT, moment);   
    
    return true;
}

/*!
 * @internal
 */
 bool writeJsonToString(boost::property_tree::ptree& pTree,
                                                    std::string& jsonString)
 {
    std::ostringstream buffer; 
    boost::property_tree::ptree::write_json(buffer, pTree, false); 
    jsonString = buffer.str();

    return true;
 }