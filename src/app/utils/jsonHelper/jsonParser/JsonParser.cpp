/*****************************************************************************/
/*!
 * @file JsonParser.cpp
 * @brief
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail 
 *
 * Modified History
 * ---------------
 * 2017-Jan-03 Created tien.nguyenanh94@gmail.com
 */
/*****************************************************************************/

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "JsonParser.h"

#ifdef UNITTEST
#define STATIC
#else
#define STATIC static
#endif

/*!
 * @internal
 */
STATIC std::string getJsonPath(const std::string& source,
                                            const std::string& destination)
{
    std::string jsonPath;
    jsonPath.append(source);
    jsonPath.append(JSON_PATH_SPLITTER);
    jsonPath.append(destination);

    return jsonPath;
}

/*!
 * @internal
 */
bool parseLightInteJson(const std::string& jsonString,
                                                LightIntensityInfo& info)
{
    boost::property_tree::ptree pTree;
    
    if (jsonString.compare("") == 0)
    {
        return false;
    }

    if (!convertJsonStrToPtree(jsonString, pTree))
    {
        return false;
    }

    /*!
     * Parse Information of Sender
     */
    std::string jsonIPPath = getJsonPath(ATTR_JSON_SENDER, ATTR_JSON_IP);
    std::string jsonPortPath = getJsonPath(ATTR_JSON_SENDER, ATTR_JSON_PORT);
    std::string ipStr = pTree.get<std::string>(jsonIPPath);
    std::string portStr = pTree.get<std::string>(jsonPortPath);

    /*!
     * Parse Light Intensity
     */
    std::string jsonLightIntPath = getJsonPath(ATTR_JSON_DATA,
                                                ATTR_JSON_LIGHT_INTENSITY);
    std::string lightIntenStr = 
                        pTree.get<std::string>(jsonLightIntPath);

    info.data.lightIntensity = std::stol(lightIntenStr);
    info.sender.port = std::stol(portStr);
    strcpy(info.sender.ip, ipStr.c_str());
}