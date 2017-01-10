/****************************************************************************/
/*!
 * @file CommonTest.cpp
 * @brief Unittest for CommonTest class
 *
 * Copyright (c) Tien Nguyen Anh 2016 
 *
 * @detail The testing file of the implementation of CommonTest class
 */
/****************************************************************************/

#include <gtest/gtest.h>

#include "JsonCommonForC.h"

class JsonCommonForCTest : public ::testing::Test
{
public:
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(JsonCommonForCTest, TestisSensorMessage_RESULT_OK)
{
    std::string message("LCADB;192.168.1.177:8787");
    bool status = isSensorMessageForC(message.c_str());
    EXPECT_TRUE(status);
}

TEST_F(JsonCommonForCTest, TestisSensorMessage_RESULT_FAILURE_1)
{
    std::string message("LCAD");
    bool status = isSensorMessageForC(message.c_str());
    EXPECT_FALSE(status);
}

TEST_F(JsonCommonForCTest, TestisSensorMessage_RESULT_FAILURE_2)
{
    std::string message("");
    bool status = isSensorMessageForC(message.c_str());
    EXPECT_FALSE(status);
}

TEST_F(JsonCommonForCTest, TestisSensorMessage_RESULT_FAILURE_3)
{
    std::string message("LCADBF");
    bool status = isSensorMessageForC(message.c_str());
    EXPECT_FALSE(status);
}

TEST_F(JsonCommonForCTest,
						TestgetJSONMessageType_MESSAGE_TYPE_LIGHT_INTENSITY)
{
    std::string message("LCADB");
    MESSAGE_TYPE messageType;
    getJSONMessageTypeForC(message.c_str(), &messageType);

    EXPECT_EQ(messageType, MESSAGE_TYPE_LIGHT_INTENSITY);
}

TEST_F(JsonCommonForCTest, TestgetJSONMessageType_NOT_SENSOR_MESSAGE)
{
    std::string message("RCAD");
    MESSAGE_TYPE messageType;
    getJSONMessageTypeForC(message.c_str(), &messageType);

    EXPECT_EQ(messageType, MESSAGE_TYPE_DEFAULT);
}

TEST_F(JsonCommonForCTest, TestgetJSONMessageType_DEFAULT_TYPE)
{
    std::string message("NCADB");
    MESSAGE_TYPE messageType;
    getJSONMessageTypeForC(message.c_str(), &messageType);

    EXPECT_EQ(messageType, MESSAGE_TYPE_DEFAULT);
}

TEST_F(JsonCommonForCTest, TestconvertArduinoMsgToInt16)
{
    uint16_t value = -1;
    std::string msg("L0820");

    bool status = convertArduinoMsgToInt16ForC(msg.c_str(), &value);

    EXPECT_TRUE(status);
    EXPECT_EQ(value, 640);
}