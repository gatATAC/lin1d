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
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/DRE.o \
	${OBJECTDIR}/DummyFunctions.o \
	${OBJECTDIR}/ProjectFunctions.o \
	${OBJECTDIR}/lin1dFSM.o \
	${OBJECTDIR}/lin1dFSM_CI.o \
	${OBJECTDIR}/mainnb.o


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

${OBJECTDIR}/DRE.o: DRE.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -DDUMMY_COMPILATION -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DRE.o DRE.c

${OBJECTDIR}/DummyFunctions.o: DummyFunctions.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -DDUMMY_COMPILATION -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DummyFunctions.o DummyFunctions.c

${OBJECTDIR}/ProjectFunctions.o: ProjectFunctions.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -DDUMMY_COMPILATION -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProjectFunctions.o ProjectFunctions.c

${OBJECTDIR}/lin1dFSM.o: lin1dFSM.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -DDUMMY_COMPILATION -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lin1dFSM.o lin1dFSM.c

${OBJECTDIR}/lin1dFSM_CI.o: lin1dFSM_CI.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -DDUMMY_COMPILATION -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lin1dFSM_CI.o lin1dFSM_CI.c

${OBJECTDIR}/mainnb.o: mainnb.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/mainnb.o mainnb.cpp

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
