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
    if (!isSensorMessage(message))
    {
        return false;
    }

    if (getJSONMessageType(message) != MESSAGE_TYPE_LIGHT_INTENSITY)
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
std::string writeJsonToString(boost::property_tree::ptree& pTree)
{
    std::ostringstream buffer; 
    boost::property_tree::write_json(buffer, pTree, false); 
    
    return buffer.str();
}

/*!
 * @internal
 */
bool buildJson(const std::string& message, std::string& jsonString)
{
    boost::property_tree::ptree root;
    boost::property_tree::ptree messageTypeTree;
    boost::property_tree::ptree dataTree;

    MESSAGE_TYPE messageType = getJSONMessageType(message);

    if (!buildJsonMessageType(messageType, root))
    {
        return false;
    }

    if (!buildLightIntensityJson(message, dataTree))
    {
        return false;
    }

    root.add_child(ATTR_JSON_DATA, dataTree);

    jsonString = writeJsonToString(root);

    return true;
}
