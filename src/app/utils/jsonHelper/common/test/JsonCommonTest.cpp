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

#include "JsonCommon.h"

class JsonCommonTest : public ::testing::Test
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

TEST_F(JsonCommonTest, TestisSensorMessage_RESULT_OK)
{
    std::string message("LCADB;192.168.1.177:8787");
    bool status = isSensorMessage(message);
    EXPECT_TRUE(status);
}

TEST_F(JsonCommonTest, TestisSensorMessage_RESULT_FAILURE_1)
{
    std::string message("LCAD");
    bool status = isSensorMessage(message);
    EXPECT_FALSE(status);
}

TEST_F(JsonCommonTest, TestisSensorMessage_RESULT_FAILURE_2)
{
    std::string message("");
    bool status = isSensorMessage(message);
    EXPECT_FALSE(status);
}

TEST_F(JsonCommonTest, TestisSensorMessage_RESULT_FAILURE_3)
{
    std::string message("LCADBF");
    bool status = isSensorMessage(message);
    EXPECT_FALSE(status);
}

TEST_F(JsonCommonTest, TestgetJSONMessageType_MESSAGE_TYPE_LIGHT_INTENSITY)
{
    std::string message("LCADB");
    MESSAGE_TYPE messageType = getJSONMessageType(message);
    EXPECT_EQ(messageType, MESSAGE_TYPE_LIGHT_INTENSITY);
}

TEST_F(JsonCommonTest, TestgetJSONMessageType_NOT_SENSOR_MESSAGE)
{
    std::string message("RCAD");
    MESSAGE_TYPE messageType = getJSONMessageType(message);
    EXPECT_EQ(messageType, MESSAGE_TYPE_DEFAULT);
}

TEST_F(JsonCommonTest, TestgetJSONMessageType_DEFAULT_TYPE)
{
    std::string message("NCADB");
    MESSAGE_TYPE messageType = getJSONMessageType(message);
    EXPECT_EQ(messageType, MESSAGE_TYPE_DEFAULT);
}

TEST_F(JsonCommonTest, TestconvertArduinoMsgToInt16)
{
    uint16_t value = -1;
    std::string msg("L0820");
    bool status = convertArduinoMsgToInt16(msg, value);
    EXPECT_TRUE(status);
    EXPECT_EQ(value, 640);
}