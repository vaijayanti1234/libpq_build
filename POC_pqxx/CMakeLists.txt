# CMakeList.txt : CMake project for POC_pqxx, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 2.8)

set(PROJECT_NAME "testing")

project(${PROJECT_NAME})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

## TODO: Consider moving these to cap-main
if (CAP_WINDOWS)
    # /wd4800 : Disable c4800 warnings since we get a flood of those from generated protobuf code
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4800")
endif()

set(EXTERNAL_INST_DIR "C:\Users\vsarfare\source\repos\testing_withChanges\dependancies")

if(CAP_WINDOWS)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(LIBPQ_DLL "${EXTERNAL_INST_DIR}/bin/libpq.dll"
                "${EXTERNAL_INST_DIR}/bin/libpqxx.dll")								
    else()
		message("*CHECK PLATFORM*")
    endif()
else()
	message("*CHECK PLATFORM*")
endif()


# Add source to this project's executable.
add_executable (CMakeProject_POC_pqxx "Source.cpp" "Source.h")

# Additional Libraries 

include_directories("${PROJECT_NAME}" "${EXTERNAL_INST_DIR}")
link_directories("${PROJECT_NAME}" "${LIBPQ_DLL}")
