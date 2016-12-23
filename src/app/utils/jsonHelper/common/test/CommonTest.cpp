/****************************************************************************/
/*!
 * @file LightIntensityTest.cpp
 * @brief Unittest for LightIntensity class
 *
 * Copyright (c) Tien Nguyen Anh 2016 
 *
 * @detail The testing file of the implementation of LightIntensity class
 */
/****************************************************************************/

#include <gtest/gtest.h>

#include "common.h"

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

TEST_F(JsonCommonTest, TestisSensorMessage)
{
    std::string message("LCADB");
    isSensorMessage(message);
}