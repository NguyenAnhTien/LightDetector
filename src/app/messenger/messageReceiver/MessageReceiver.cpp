/*****************************************************************************/
/*!
 * @file MessageReceiver.cpp
 * @brief The implementation of MessageReceive class
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail Using Poco library to implement a UDP server.
 *         Using ZeroMQ to implement a publisher who
 *               publish the message to subscribers.
 *
 * Modified History
 * ---------------
 * 2016-Dec-08 Created tien.nguyenanh94@gmail.com
 */
/*****************************************************************************/

#include "MessageReceiver.h"


MessageReceiver::MessageReceiver(int bufferSize):
    thread("MessageReceiver"),
    stop(false),
    bufferSize(bufferSize)
{
    this->socket.bind(Poco::Net::SocketAddress(), true);
    this->thread.start(*this);
    this->ready.wait();
}

MessageReceiver::MessageReceiver(const Poco::Net::SocketAddress& sa, int bufferSize):
    thread("MessageReceiver"),
    stop(false),
    bufferSize(bufferSize)
{
    this->socket.bind(sa, true);
    this->thread.start(*this);
    this->ready.wait();
}

MessageReceiver::~MessageReceiver()
{
    this->stop = true;
    this->thread.join();
    
    zmq_close(this->publisher);
    zmq_ctx_destroy(this->zmq_context);
}

Poco::UInt16 MessageReceiver::port() const
{
    return this->socket.address().port();
}

void MessageReceiver::run()
{
    std::cout << "Starting here!!!" << std::endl;
    this->ready.set();
    Poco::Timespan span(250000);
    char* pBuffer = new char[this->bufferSize];

    void *context = zmq_ctx_new ();
    void *publisher = zmq_socket (context, ZMQ_PUB);
    zmq_bind(publisher, "tcp://*:5563");

    while(!this->stop)
    {
        if (this->socket.poll(span, Poco::Net::Socket::SELECT_READ))
        {
            try
            {
                Poco::Net::SocketAddress sender;
                int n = this->socket.receiveFrom(pBuffer, this->bufferSize, sender);
                std::cout << "Message is: " << pBuffer << std::endl;

                std::string message(pBuffer);
                std::string jsonString;

                if (isSensorMessage(message))
                {
                    if (!buildJson(message, jsonString))
                    {
                        continue;
                    }

                    MESSAGE_TYPE messageType = getJSONMessageType(message);

                    // char typeOfMessage = pBuffer[0];
                    // char LSB = pBuffer[1];
                    // char MSB = pBuffer[2];

                    // uint16_t lightIntensity = LSB | uint16_t(MSB) << 8;

                    // std::cout << "Light Intensity is: " << lightIntensity << std::endl;
                    // char message[256] = {};
                    // sprintf(message, "%u", lightIntensity);
                    
                    std::string topic = convertMessageTypeToStr(messageType); 
                    s_sendmore (publisher, (char*)topic.c_str());
                    s_send (publisher, (char*)jsonString.c_str());
                    sleep (1);
                }

            }
            catch(Poco::Exception& ex)
            {
                std::cout << "MessageReceiver: " << ex.displayText() << std::endl;
            }
        }
    }

    if (pBuffer != NULL)
    {
        delete pBuffer;
    }
}

Poco::Net::SocketAddress MessageReceiver::address() const
{
    return this->socket.address();
}

