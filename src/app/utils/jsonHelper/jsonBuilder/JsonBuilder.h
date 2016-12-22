/*****************************************************************************/
/*!
 * @file JsonBuilder.h
 * @brief The declaration of JsonBuilder.
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail The JsonBuilder can convert a array format message to JSON format.
 *             It's duty is convert a message of Arduino to JSON.
 *
 * Modified History
 * ---------------
 * 2016-Dec-21 Created tien.nguyenanh94@gmail.com
 */
/*****************************************************************************/

#ifndef __JSON_BUILDER_H__
#define __JSON_BUILDER_H__

#include "common.h"

/*!
 * @brief
 * param[in] message
 * return
 */
std::string buildJson(const std::string& message);

#endif
