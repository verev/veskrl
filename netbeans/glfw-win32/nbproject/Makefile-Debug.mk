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
	${OBJECTDIR}/_ext/482952869/context.o \
	${OBJECTDIR}/_ext/482952869/init.o \
	${OBJECTDIR}/_ext/482952869/input.o \
	${OBJECTDIR}/_ext/482952869/monitor.o \
	${OBJECTDIR}/_ext/482952869/wgl_context.o \
	${OBJECTDIR}/_ext/482952869/win32_init.o \
	${OBJECTDIR}/_ext/482952869/win32_monitor.o \
	${OBJECTDIR}/_ext/482952869/win32_time.o \
	${OBJECTDIR}/_ext/482952869/win32_tls.o \
	${OBJECTDIR}/_ext/482952869/win32_window.o \
	${OBJECTDIR}/_ext/482952869/window.o \
	${OBJECTDIR}/_ext/482952869/winmm_joystick.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglfw-win32.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglfw-win32.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglfw-win32.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglfw-win32.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglfw-win32.a

${OBJECTDIR}/_ext/482952869/context.o: ../../thirdparty/glfw/src/context.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/context.o ../../thirdparty/glfw/src/context.c

${OBJECTDIR}/_ext/482952869/init.o: ../../thirdparty/glfw/src/init.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/init.o ../../thirdparty/glfw/src/init.c

${OBJECTDIR}/_ext/482952869/input.o: ../../thirdparty/glfw/src/input.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/input.o ../../thirdparty/glfw/src/input.c

${OBJECTDIR}/_ext/482952869/monitor.o: ../../thirdparty/glfw/src/monitor.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/monitor.o ../../thirdparty/glfw/src/monitor.c

${OBJECTDIR}/_ext/482952869/wgl_context.o: ../../thirdparty/glfw/src/wgl_context.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/wgl_context.o ../../thirdparty/glfw/src/wgl_context.c

${OBJECTDIR}/_ext/482952869/win32_init.o: ../../thirdparty/glfw/src/win32_init.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/win32_init.o ../../thirdparty/glfw/src/win32_init.c

${OBJECTDIR}/_ext/482952869/win32_monitor.o: ../../thirdparty/glfw/src/win32_monitor.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/win32_monitor.o ../../thirdparty/glfw/src/win32_monitor.c

${OBJECTDIR}/_ext/482952869/win32_time.o: ../../thirdparty/glfw/src/win32_time.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/win32_time.o ../../thirdparty/glfw/src/win32_time.c

${OBJECTDIR}/_ext/482952869/win32_tls.o: ../../thirdparty/glfw/src/win32_tls.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/win32_tls.o ../../thirdparty/glfw/src/win32_tls.c

${OBJECTDIR}/_ext/482952869/win32_window.o: ../../thirdparty/glfw/src/win32_window.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/win32_window.o ../../thirdparty/glfw/src/win32_window.c

${OBJECTDIR}/_ext/482952869/window.o: ../../thirdparty/glfw/src/window.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/window.o ../../thirdparty/glfw/src/window.c

${OBJECTDIR}/_ext/482952869/winmm_joystick.o: ../../thirdparty/glfw/src/winmm_joystick.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/482952869
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -DBUILD_SHARED_LIBS -D_GLFW_USE_OPENGL -D_GLFW_WGL -D_GLFW_WIN32 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/482952869/winmm_joystick.o ../../thirdparty/glfw/src/winmm_joystick.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglfw-win32.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
