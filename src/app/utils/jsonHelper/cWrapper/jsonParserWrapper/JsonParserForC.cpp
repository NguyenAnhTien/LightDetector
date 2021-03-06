/***************************************************************************/
/*!
 * @file JsonParserForC.c
 * @brief
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail
 *
 * Modified History
 * ---------------
 * 2017-Jan-07 Created tien.nguyenanh94@gmail.com
 */
/***************************************************************************/

#include "JsonParserForC.h"
#include "JsonParser.h"

/*!
 * @internal
 */
bool parseLightInteJsonForC(const char* jsonString, LightIntensityInfo* info)
{
    return parseLightInteJson(std::string(jsonString), *info);
}