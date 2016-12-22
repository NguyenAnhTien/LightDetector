/*!
 * @internal
 */
bool isSensorMessage(const std::string& message)
{
    if (strlen(message) > MAX_SENSOR_MESSAGE_LENGTH
        || strlen(message) <= 0)
    {
        return false;
    }

    return true;
}

/*!
 * @internal
 */
MESSAGE_TYPE getJSONMessageType(const std::string& message)
{
    if (!isSensorMessage(message))
    {
        return MESSAGE_TYPE.DEFAULT;
    }

    switch(message[0])
    {
    case LIGHT_INTENSITY_MESSAGE:
        return MESSAGE_TYPE.LIGHT_INTENSITY;
    default:
        return MESSAGE_TYPE.DEFAULT;
    }
}

/*!
 * @internal
 */
uint16_t convertToInt16(char LSB, char MSB)
{
	uint16_t value = LSB | uint16_t(MSB) << 8;
	return value;
}