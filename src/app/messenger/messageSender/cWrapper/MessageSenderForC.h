/***************************************************************************/
/*!
 * @file JsonSenderForC.h
 * @brief
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail
 *
 * Modified History
 * ---------------
 * 2017-Jan-08 Created tien.nguyenanh94@gmail.com
 */
/***************************************************************************/

#ifndef __MESSAGE_SENDER_FOR_C_H__
#define __MESSAGE_SENDER_FOR_C_H__

bool sendMessageUDPForC(const char* data, const char* host,
                                                        unsigned int port);
bool sendMessageTCPForC(const char* data, const char* host,
                                                        unsigned int port);

#endif