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
CC=clang
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-Windows
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
	${OBJECTDIR}/_ext/1445274692/main.o \
	${OBJECTDIR}/_ext/1445274692/modcurse.o \
	${OBJECTDIR}/_ext/1445274692/modveskrl.o \
	${OBJECTDIR}/_ext/1445274692/vutil.o \
	${OBJECTDIR}/_ext/31909533/tinycthread.o


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
LDLIBSOPTIONS=-L../glfw-win32/dist/Debug/CLang-Windows ../glfw-win32/dist/Debug/CLang-Windows/libglfw-win32.a ../glfw-win32/dist/Release/CLang-Windows/libglfw-win32.a -lopengl32 -lgdi32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/veskrl.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/veskrl.exe: ../glfw-win32/dist/Debug/CLang-Windows/libglfw-win32.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/veskrl.exe: ../glfw-win32/dist/Release/CLang-Windows/libglfw-win32.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/veskrl.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/veskrl ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1445274692/main.o: ../../src/main.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../thirdparty/tinycthread -I../../thirdparty/glfw/include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/main.o ../../src/main.c

${OBJECTDIR}/_ext/1445274692/modcurse.o: ../../src/modcurse.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../thirdparty/tinycthread -I../../thirdparty/glfw/include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/modcurse.o ../../src/modcurse.c

${OBJECTDIR}/_ext/1445274692/modveskrl.o: ../../src/modveskrl.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../thirdparty/tinycthread -I../../thirdparty/glfw/include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/modveskrl.o ../../src/modveskrl.c

${OBJECTDIR}/_ext/1445274692/vutil.o: ../../src/vutil.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../thirdparty/tinycthread -I../../thirdparty/glfw/include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/vutil.o ../../src/vutil.c

${OBJECTDIR}/_ext/31909533/tinycthread.o: ../../thirdparty/tinycthread/tinycthread.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/31909533
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../thirdparty/tinycthread -I../../thirdparty/glfw/include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/31909533/tinycthread.o ../../thirdparty/tinycthread/tinycthread.c

# Subprojects
.build-subprojects:
	cd ../glfw-win32 && ${MAKE}  -f Makefile CONF=Debug
	cd ../glfw-win32 && ${MAKE}  -f Makefile CONF=Release

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/veskrl.exe

# Subprojects
.clean-subprojects:
	cd ../glfw-win32 && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../glfw-win32 && ${MAKE}  -f Makefile CONF=Release clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
