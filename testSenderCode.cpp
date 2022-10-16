#define CATCH_CONFIG_MAIN 


#include "test/catch.hpp"
#include <time.h>
#include <stdlib.h>
#include "senderCode.h"


sensorThresholdValues tempthresoldValues = {.maximumValue = 50.0, .minimumValue=10.0};
sensorThresholdValues socthresoldValues = {.maximumValue = 85.0, .minimumValue=15.0};

void testPrint(float tempData, float socData)
{
    printf("{  tempData = %.2f , socData = %.2f  }\n", tempData, socData);
}

TEST_CASE("TestCase1 : Valid data is being sent on sensor") {

    float tempSensorData[] = {12.0, 20.0, 40.0, 30.0};
    float socSensorData[] = {60.0, 25.0, 45.0, 34.0};
    sensorDataExtract sensorDataInput = {.lengthOfArray = 4, .tempSensorValues = tempSensorData, .socSensorValues = socSensorData};  
    REQUIRE(streamMainFunction(sensorDataInput, tempthresoldValues, socthresoldValues, testPrint)==1);
}

TEST_CASE("TestCase2 : Valid data is being sent on sensor cutoffs values") {

    float tempSensorData[] = {11.0, 29.0, 49.0, 35.0};
    float socSensorData[] = {84.0, 24.0, 64.0, 16.0};
    sensorDataExtract sensorDataInput = {.lengthOfArray = 4, .tempSensorValues = tempSensorData, .socSensorValues = socSensorData};  
    REQUIRE(streamMainFunction(sensorDataInput, tempthresoldValues, socthresoldValues, testPrint)==1);
}


