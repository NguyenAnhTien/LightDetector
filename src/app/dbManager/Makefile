#-----------------------------------------------------------------------------
#Makefile - src/app/dbManager
# Copyright (c) Tien Nguyen Anh
# Modification history
# --------------------
#    Created: 2016-Dec-03 tien.nguyenanh94@gmail.com
#-----------------------------------------------------------------------------

ifneq ($(APP), unittest)
    override APP = dbManager
    TARGET = #none
    ARCHIVES = dbManager
endif

#------------------------------------------------------------------------------
#source
SRCS = DBManager.cpp
OBJS = $(SRCS:.cpp=.o)

#------------------------------------------------------------------------------
#include source code
INCS = .

#------------------------------------------------------------------------------
#include makefile
include $(LIDT_MAKEDIR)/Makefile.app

