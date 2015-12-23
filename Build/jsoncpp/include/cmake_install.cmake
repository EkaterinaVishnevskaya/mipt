# Install script for directory: /Users/ekaterina/Desktop/proga/mipt/jsoncpp/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/json" TYPE FILE FILES
    "/Users/ekaterina/Desktop/proga/mipt/jsoncpp/include/json/assertions.h"
    "/Users/ekaterina/Desktop/proga/mipt/jsoncpp/include/json/autolink.h"
    "/Users/ekaterina/Desktop/proga/mipt/jsoncpp/include/json/config.h"
    "/Users/ekaterina/Desktop/proga/mipt/jsoncpp/include/json/features.h"
    "/Users/ekaterina/Desktop/proga/mipt/jsoncpp/include/json/forwards.h"
    "/Users/ekaterina/Desktop/proga/mipt/jsoncpp/include/json/json.h"
    "/Users/ekaterina/Desktop/proga/mipt/jsoncpp/include/json/reader.h"
    "/Users/ekaterina/Desktop/proga/mipt/jsoncpp/include/json/value.h"
    "/Users/ekaterina/Desktop/proga/mipt/jsoncpp/include/json/version.h"
    "/Users/ekaterina/Desktop/proga/mipt/jsoncpp/include/json/writer.h"
    )
endif()

