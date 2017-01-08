"""
File: processor.py
=========================

Copyright (c) Tien Nguyen Anh

Modified History
----------------
2016-Dec-19 Created tien.nguyenanh94@gmail.com
"""

import zmq

from cffi_interfaces.__cffi_jsonCommon import jsonCommon_c
from cffi_interfaces.__cffi_jsonCommon import jsonCommon_cffi

# ZeroMQ Context
context = zmq.Context()

# Define the socket using the "Context"
sock = context.socket(zmq.SUB)

# Define subscription and messages with prefix to accept.
sock.setsockopt_string(zmq.SUBSCRIBE, "LIGHT_INTENSITY_TOPIC")
sock.connect("tcp://127.0.0.1:5563")

while True:
    message= sock.recv()
    print("Message: ", message)
    # topic, messagedata = message.split()
    # print("Topic: %s Message: %s" %(topic, message))
