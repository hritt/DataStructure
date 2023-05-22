cmake_minimum_required(VERSION 3.3)
## project(projectname [CXX] [C] [JAVA])
## 这个执行是用来定义工程的名称的和定义工程支持的语言。这个指令也隐式的定义了两个cmake变量：<projectname>_BINARY_DIR以及<projectname>_SOURCE_DIR
project(DataStructure CXX)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
	## warning C4267: 'argument': conversion from 'size_t' to 'int', possible loss of data
	add_compile_options(/wd4267)
	## warning C4365: 'argument': conversion from 'int' to 'const unsigned __int64', signed/unsigned mismatch
	add_compile_options(/wd4365)
	## warning C4820: 'Node<T>': '4' bytes padding added after data member 'Node<T>::data'
	add_compile_options(/wd4820)
	## warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
	add_compile_options(/wd5045)

	## limits.h(70,5): warning C4668: '__STDC_WANT_SECURE_LIB__' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
	add_definitions(-D__STDC_WANT_SECURE_LIB__=1)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    ## /Wall 启用默认关闭的所有警告
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17 -Wall")
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux" OR CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
endif()

## message([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...)
## 这个指令用于向终端输出用户信息，包含三种类型：(必须大写)
## SEND_ERROR，产生错误，生成过程被跳过。
## STATUS,输出前缀为-的信息。
## FATAL_ERROR，立即终止所有cmake过程。
message(STATUS "The first attempt - CmakeLists.txt.")

## EXECUTABLE_OUTPUT_PATH 生成的可执行文件的路径
#set(EXECUTABLE_OUTPUT_PATH ${DataStructure_BINARY_DIR}/bin)

## set指令是用来显式的定义变量的
# set(SRC_LIST
# 	Main.cpp
# 	String.cpp
# 	Search.cpp
# 	Sort.cpp)

## add_executable(hello ${SRC_LIST})
## 定义了这个工程会生成一个文件名为hello的可执行文件，相关的源文件是SRC_LIST中定义的源文件列表
# add_executable(prog ${SRC_LIST})

file(GLOB files_headers ${PROJECT_SOURCE_DIR}/*.h)
file(GLOB files_sources ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(prog ${files_sources} ${files_headers})

## CMake 在Vision studio上构建的工程（.sln “solution”）包含 三个工程（project），分别是：工程本身；ALL_BUILD；ZERO_CHECK。
## ALL_BUILD是管理整个项目的工程；
## ZERO_CHECK是实时监视CMakeLists.txt文件变化的工程，一旦CMakeLists.txt里的内容发生了任何变化，ZERO_CHECK就会告诉编译器要重新构建整个工程环境。
## 如我们只有一个工程（project）在解决方案（solution）中，那么ALL_BUILD 和 ZERO_CHECK工程可以删除掉。
