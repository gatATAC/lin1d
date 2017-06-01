#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=TestBox
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include nb-Makefile.mk

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/mainnb.o \
	${OBJECTDIR}/src/FM1DRE.o \
	${OBJECTDIR}/src/FM1lin1dFSM.o \
	${OBJECTDIR}/src/FM1lin1dFSM_CI.o \
	${OBJECTDIR}/src/POLDRE.o \
	${OBJECTDIR}/src/POLlin1dFSM.o \
	${OBJECTDIR}/src/POLlin1dFSM_CI.o \
	${OBJECTDIR}/src/ProjectFunctions.o \
	${OBJECTDIR}/src/PwmServoCtrl.o \
	${OBJECTDIR}/src/monitor.o \
	${OBJECTDIR}/src/prj_input.o \
	${OBJECTDIR}/src/prj_output.o \
	${OBJECTDIR}/src/prj_pinout.o \
	${OBJECTDIR}/src/src.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblin1d.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblin1d.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblin1d.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblin1d.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblin1d.a

${OBJECTDIR}/mainnb.o: mainnb.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/mainnb.o mainnb.cpp

${OBJECTDIR}/src/FM1DRE.o: src/FM1DRE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FM1DRE.o src/FM1DRE.cpp

${OBJECTDIR}/src/FM1lin1dFSM.o: src/FM1lin1dFSM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FM1lin1dFSM.o src/FM1lin1dFSM.cpp

${OBJECTDIR}/src/FM1lin1dFSM_CI.o: src/FM1lin1dFSM_CI.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FM1lin1dFSM_CI.o src/FM1lin1dFSM_CI.cpp

${OBJECTDIR}/src/POLDRE.o: src/POLDRE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/POLDRE.o src/POLDRE.cpp

${OBJECTDIR}/src/POLlin1dFSM.o: src/POLlin1dFSM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/POLlin1dFSM.o src/POLlin1dFSM.cpp

${OBJECTDIR}/src/POLlin1dFSM_CI.o: src/POLlin1dFSM_CI.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/POLlin1dFSM_CI.o src/POLlin1dFSM_CI.cpp

${OBJECTDIR}/src/ProjectFunctions.o: src/ProjectFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ProjectFunctions.o src/ProjectFunctions.cpp

${OBJECTDIR}/src/PwmServoCtrl.o: src/PwmServoCtrl.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/PwmServoCtrl.o src/PwmServoCtrl.cpp

${OBJECTDIR}/src/monitor.o: src/monitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/monitor.o src/monitor.cpp

${OBJECTDIR}/src/prj_input.o: src/prj_input.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/prj_input.o src/prj_input.cpp

${OBJECTDIR}/src/prj_output.o: src/prj_output.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/prj_output.o src/prj_output.cpp

${OBJECTDIR}/src/prj_pinout.o: src/prj_pinout.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/prj_pinout.o src/prj_pinout.cpp

${OBJECTDIR}/src/src.o: src/src.ino 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DCFG_VARIANT\ =\ \ CFG_VARIANT_TESTBOX -DDUMMY_COMPILATION -I../dummylib -I../libraries/gatArduinOSEK -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/src.o src/src.ino

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblin1d.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
