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
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include nb-Makefile.mk

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/mainnb.o \
	${OBJECTDIR}/src/DRE.o \
	${OBJECTDIR}/src/DummyFunctions.o \
	${OBJECTDIR}/src/ProjectFunctions.o \
	${OBJECTDIR}/src/lin1dFSM.o \
	${OBJECTDIR}/src/lin1dFSM_CI.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lin1d.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lin1d.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lin1d ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/mainnb.o: mainnb.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/mainnb.o mainnb.cpp

${OBJECTDIR}/src/DRE.o: src/DRE.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DDUMMY_COMPILATION -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DRE.o src/DRE.c

${OBJECTDIR}/src/DummyFunctions.o: src/DummyFunctions.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DDUMMY_COMPILATION -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DummyFunctions.o src/DummyFunctions.c

${OBJECTDIR}/src/ProjectFunctions.o: src/ProjectFunctions.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DDUMMY_COMPILATION -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ProjectFunctions.o src/ProjectFunctions.c

${OBJECTDIR}/src/lin1dFSM.o: src/lin1dFSM.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DDUMMY_COMPILATION -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/lin1dFSM.o src/lin1dFSM.c

${OBJECTDIR}/src/lin1dFSM_CI.o: src/lin1dFSM_CI.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -DDUMMY_COMPILATION -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/lin1dFSM_CI.o src/lin1dFSM_CI.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lin1d.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
