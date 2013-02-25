# Project: Statistic (Static library)
# Target: Linux

include ../../cbp$(Build_Suffix).mk

MF_DIR=.

### Compiler/linker options

Global_CFLAGS=$(cflags)

Project_CFLAGS= \
-Wall \
-g \
-W \
-Winvalid-pch \
-include "gccPrecompile.h" \
-DNO_GCC_PRAGMA \
-DUSE_PCH \
-Wall

All_CFLAGS=$(Project_CFLAGS) $(Global_CFLAGS) $(CXXCFLAGS)

OBJ_DEPS=-MT$@ -MF$@.d -MD -MP

Project_INCS= \
-I$(MF_DIR)/ \
-I$(MF_DIR)/../StatisticLib \
-I$(MF_DIR)/Include

Project_LIB=ar -r

RM=rm -rf

### Objects used in this Makefile

Project_OUT=$(MF_DIR)/../Lib/gcc_linux$(Build_Suffix)/libStatistic.a

ifndef OBJ_DIR
   OBJ_DIR=$(MF_DIR)/Obj/gcc_linux$(Build_Suffix)
endif

Project_OBJS= \
$(OBJ_DIR)/Source/Statistic.o \

Project_DEPS=$(patsubst %.o,%.o.d,$(Project_OBJS))

Include_DIR=$(MF_DIR)/Include

ifndef Install_DIR
   Install_DIR=$(MF_DIR)/../../../Distributive
endif
ifndef Inst_Out_DIR
  Inst_Out_DIR=$(Install_DIR)/Statistic/Lib/gcc_linux$(Build_Suffix)
endif
ifndef Inst_Include_DIR
Inst_Include_DIR=$(Install_DIR)/Statistic/StatisticLib/Include
endif

all: Make_DIRS $(Project_OUT)

install:
	mkdir -p "$(Inst_Out_DIR)"
	$(InstallCmd) "$(Project_OUT)" "$(Inst_Out_DIR)/libStatistic.a"
	mkdir -p "$(Inst_Include_DIR)"
	$(InstallCmd) "$(Include_DIR)/MovingAverage.h" "$(Inst_Include_DIR)/MovingAverage.h"
	$(InstallCmd) "$(Include_DIR)/Statistic.h" "$(Inst_Include_DIR)/Statistic.h"
	$(InstallCmd) "$(Include_DIR)/StatisticEvaluations.h" "$(Inst_Include_DIR)/StatisticEvaluations.h"
	$(InstallCmd) "$(Include_DIR)/StatisticEvents.h" "$(Inst_Include_DIR)/StatisticEvents.h"
	$(InstallCmd) "$(Include_DIR)/Statistic.h" "$(Inst_Include_DIR)/Statistic.h"

clean:
	$(RM) $(Project_OUT) $(Project_OBJS) $(Project_DEPS)

Make_DIRS:
	mkdir -p "$(MF_DIR)/../Lib/gcc_linux$(Build_Suffix)"
	mkdir -p "$(OBJ_DIR)/Source"

$(Project_OUT): $(Project_OBJS)
	$(Project_LIB) $(Project_OUT) $(Project_OBJS)

$(OBJ_DIR)/Source/Statistic.o: $(MF_DIR)/Source/Statistic.cpp
	$(CXX) $(All_CFLAGS) $(Project_INCS) -c -o $@ $(OBJ_DEPS) $<

-include $(OBJ_DIR)/Source/*.d