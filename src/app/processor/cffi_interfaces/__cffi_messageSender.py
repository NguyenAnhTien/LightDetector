"""
File: __cffi_messageSender.py
=========================

Copyright (c) Tien Nguyen Anh

Modified History
----------------
2017-Jan-05 Created tien.nguyenanh94@gmail.com
"""

import cffi
import os

#LIDT declare
LIDT_ROOT = os.getenv('LIDT_ROOT')
LIDT_LIBS = os.path.sep.join((LIDT_ROOT, 'obj', 'libs'))

JSON_BUILDER_FOR_C_INCLUDES = os.path.sep.join((LIDT_ROOT, 'src', 
                            'app', 'utils', 'jsonHelper', 'cWrapper',
                            'jsonBuilderWrapper'))
JSON_BUILDER_FOR_C_LIBS = ["jsonBuilderForC"]


jsonCommon_cffi = cffi.FFI()
jsonCommon_cffi.cdef("""
    bool buildJsonForC(const char* message, char** jsonString);
""")

jsonCommon_c = jsonCommon_cffi.verify("""

                #include "JsonBuilderForC.h"

                """,
                include_dirs = [JSON_BUILDER_FOR_C_INCLUDES],
                libraries = JSON_BUILDER_FOR_C_LIBS,
                library_dirs = [LIDT_LIBS],
                modulename = "__cffi_jsonBuilder")
