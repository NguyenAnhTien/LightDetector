/****************************************************************************/
/*!
 * @file JsonBuilderTest.cpp
 * @brief Unittest for JsonBuilderTest class
 *
 * Copyright (c) Tien Nguyen Anh 2016 
 *
 * @detail The testing file of the implementation of JsonBuilderTest class
 */
/****************************************************************************/
#include <cstdlib>
#include <gtest/gtest.h>

#include <iostream>
#include <string.h>
#include <string>
#include <math.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "JsonBuilder.h"

extern bool buildJsonMessageType(const MESSAGE_TYPE& messageType,
                                boost::property_tree::ptree& messageTypeTree);
extern bool buildLightIntensityJson(const std::string& message,
                                    boost::property_tree::ptree& dataTree);

class JsonBuilderTest : public ::testing::Test
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

TEST_F(JsonBuilderTest, TestbuildJsonMessageType_RESULT_OK)
{
    boost::property_tree::ptree messageTypeTree;
    MESSAGE_TYPE messageType = MESSAGE_TYPE_LIGHT_INTENSITY;
    
    boost::property_tree::ptree expectedTree;
    expectedTree.put("MESSAGE_TYPE", "LIGHT_INTENSITY_VALUE");

    bool status = buildJsonMessageType(messageType, messageTypeTree);

    EXPECT_TRUE(status);
    EXPECT_EQ(expectedTree, messageTypeTree);
}

TEST_F(JsonBuilderTest, TestbuildJsonMessageType_MESSAGE_TYPE_DEFAULT)
{
    boost::property_tree::ptree messageTypeTree;
    MESSAGE_TYPE messageType = MESSAGE_TYPE_DEFAULT;
    
    bool status = buildJsonMessageType(messageType, messageTypeTree);

    EXPECT_FALSE(status);
}

TEST_F(JsonBuilderTest, TestbuildLightIntensityJson_RESULT_OK)
{
    boost::property_tree::ptree dataTree;
    std::string message("L0820");
    
    boost::property_tree::ptree expectedTree;
    expectedTree.put("LIGHT_INTENSITY_VALUE", "640");

    bool status = buildLightIntensityJson(message, dataTree);

    EXPECT_TRUE(status);
    EXPECT_EQ(expectedTree, dataTree);
}

TEST_F(JsonBuilderTest, TestbuildLightIntensityJson_NOT_SENSOR_MESSAGE)
{
    boost::property_tree::ptree dataTree;
    std::string message("RCBD");

    bool status = buildLightIntensityJson(message, dataTree);

    EXPECT_FALSE(status);
}

TEST_F(JsonBuilderTest, TestbuildLightIntensityJson_NOT_LIGHT_MESSAGE)
{
    boost::property_tree::ptree dataTree;
    std::string message("CCBDA");

    bool status = buildLightIntensityJson(message, dataTree);

    EXPECT_FALSE(status);
}

TEST_F(JsonBuilderTest, TestbuildJson_RESULT_OK)
{
    std::string jsonString;
    std::string message("L0820;192.168.1.177:5600");

    boost::property_tree::ptree expectedTree;
    char* rootENV = std::getenv("LIDT_ROOT");
    std::string jsonFilePath(rootENV);
    jsonFilePath.append("/testedData/jsonFiles/");
    jsonFilePath.append("arduinoJsonMessage_2.json");

    boost::property_tree::read_json(jsonFilePath, expectedTree);

    bool status = buildJson(message, jsonString);
    boost::property_tree::ptree actualTree;
    std::stringstream stringStream(jsonString);
    boost::property_tree::read_json(stringStream, actualTree);

    EXPECT_TRUE(status);
    EXPECT_EQ(expectedTree, actualTree);
}

TEST_F(JsonBuilderTest, TestbuildJson_MESSAGE_TYPE_RESULT_FAILURE_1)
{
    std::string jsonString;
    std::string message("LCAD");

    bool status = buildJson(message, jsonString);

    EXPECT_FALSE(status);
}

TEST_F(JsonBuilderTest, TestbuildJson_RESULT_FAILURE_2)
{
    std::string jsonString;
    std::string message("CCBDA");

    bool status = buildJson(message, jsonString);

    EXPECT_FALSE(status);
}

TEST_F(JsonBuilderTest, TestbuildJson_RESULT_FAILURE_3)
{
    std::string jsonString;
    std::string message("LBDA");

    bool status = buildJson(message, jsonString);

    EXPECT_FALSE(status);
}