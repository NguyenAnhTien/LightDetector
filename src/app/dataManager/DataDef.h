#ifndef __DATA_STRUCT_DEF_H__
#define __DATA_STRUCT_DEF_H__

struct Sender
{
    char ip[20];
    long port;
};

struct LightIntensity
{
    long lightIntensity;
};

struct LightIntensityInfo
{
    LightIntensity data;
    Sender sender;

};

#endif