#-----------------------------------------------------------------------------
# Makefile - src/app/processor/cffi_interfaces
#
# Copyright (c) Tien Nguyen Anh
#
# Modified History
# ----------------
# 2017-Jan-05 Created tien.nguyenanh94@gmail.com 
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
#cffi targets
CFFI_SRCS = __cffi_jsonCommon.py
CFFI_OBJS = $(CFFI_SRCS:.py=.pyc)

#------------------------------------------------------------------------------
LIBDIRS_jsonCommon  += $(LIDT_ROOT)/src/app/utils/jsonHelper/common/
LIBRARY             += jsonCommon

#-----------------------------------------------------------------------------
CLEAN_DIRS += $(LIDT_ROOT)/src/app/utils/jsonHelper/common

#-----------------------------------------------------------------------------
# compile_jsonCommon:
# 	cd $(LIDT_ROOT)/src/app/utils/jsonHelper/common; make

#-----------------------------------------------------------------------------
# __cffi_jsonCommon.pyc: compile_jsonCommon
# 	$(ECHO) Compile jsonCommon CFFI interfaces.
# 	$(PYTHON) __cffi_jsonCommon.py

#-----------------------------------------------------------------------------
include $(LIDT_MAKEDIR)/Makefile.app 