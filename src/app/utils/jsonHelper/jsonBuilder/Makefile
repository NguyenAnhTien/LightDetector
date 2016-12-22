#-----------------------------------------------------------------------------
#Makefile - src/app/utils/jsonHelper/Makefile
# Copyright (c) Tien Nguyen Anh
# Modification history
# --------------------
#    Created: 2016-Dec-21 tien.nguyenanh94@gmail.com
#-----------------------------------------------------------------------------

ifneq ($(APP), unittest)
    override APP = jsonBuilder
    TARGET = #none
    ARCHIVES = jsonBuilder
endif

#------------------------------------------------------------------------------
#source
SRCS = jsonBuilder.cpp
OBJS = $(SRCS:.cpp=.o)

#------------------------------------------------------------------------------
#include source code
INCS = .

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app