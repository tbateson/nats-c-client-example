cmake_minimum_required(VERSION 3.0)
project(NATSClient)

include(ExternalProject)

set(NATS_LIB_DIR ${CMAKE_BINARY_DIR}/NATSLibC-prefix/src)

ExternalProject_Add(NATSLibC
	GIT_REPOSITORY https://github.com/nats-io/nats.c
	GIT_TAG v2.2.0
	STEP_TARGETS build
	EXCLUDE_FROM_ALL TRUE
	CMAKE_ARGS -DNATS_BUILD_WITH_TLS=OFF -DNATS_BUILD_STREAMING=OFF
	UPDATE_COMMAND ""
	INSTALL_COMMAND ""
)

include_directories(${NATS_LIB_DIR}/NATSLibC/src)
link_directories(${NATS_LIB_DIR}/NATSLibC-build/src)

add_executable(NATSClient src/main.cpp)
add_dependencies(NATSClient NATSLibC-build)
target_link_libraries(NATSClient ${NATS_LIB_DIR}/NATSLibC-build/src/libnats_static.a ws2_32)