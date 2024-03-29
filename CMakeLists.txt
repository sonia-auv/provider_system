# \file     CMakeLists.txt
# \author   Marc-Antoine Couture <coumarc9@outlook.com>
# \date     06/10/2016
# \copyright    2017 Club SONIA AUV, ETS. All rights reserved.
# Use of this source code is governed by the GNU GPLv3 license that can be
# found in the LICENSE file.

#===============================================================================
# G L O B A L   P R O J E C T   C O N F I G U R A T I O N

cmake_minimum_required(VERSION 2.8.0)
project(provider_system)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING
            "Choose the type of build, options are: None Debug Release
      RelWithDebInfo MinSizeRel."
            FORCE)
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -O3 -s")

set(provider_system_SRC_DIR "src")

#===============================================================================
# C A T K I N   C O N F I G U R A T I O N


find_package(
        catkin REQUIRED COMPONENTS
        roscpp
        sensor_msgs

)

catkin_package(
        CATKIN_DEPENDS
        roscpp
        sensor_msgs
)



#===============================================================================
# I N C L U D E   F I L E S

file(GLOB_RECURSE provider_system_FILES
        "${provider_system_SRC_DIR}/*.cc"
        "${provider_system_SRC_DIR}/*.h")

list(REMOVE_ITEM provider_system_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/${provider_system_SRC_DIR}/${PROJECT_NAME}/main.cc)

include_directories(
        ${catkin_INCLUDE_DIRS}
        ${provider_system_SRC_DIR}
)

#==========================================================================
# C R E A T E   E X E C U T A B L E

add_executable(${PROJECT_NAME}_node ${provider_system_SRC_DIR}/${PROJECT_NAME}/main.cc ${provider_system_FILES})
target_link_libraries(${PROJECT_NAME}_node
        ${catkin_LIBRARIES}
        yaml-cpp
        )

add_dependencies(${PROJECT_NAME}_node ${catkin_EXPORTED_TARGETS})

#==========================================================================
# U N I T   T E S T S

#if (CATKIN_ENABLE_TESTING)
#    add_subdirectory(test)
#endif ()
