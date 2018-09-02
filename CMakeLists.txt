cmake_minimum_required(VERSION 2.8.3)
project(networktable)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
)

add_compile_options(-std=c++11) #ntcore需要c++11标准。务必写在include_directories之前
include_directories(
  inc/
  include ${catkin_INCLUDE_DIRS}
)

link_directories(/usr/lib/
    lib/linux/x86-64/static #lib文件夹里包含了ntcore和wpiutil的库文件，有不同系统，不同架构的对应库文件自行修改即可
    lib/linux/x86-64/shared
)

add_executable(client
  src/client.cpp
)

add_executable(server
  src/server.cpp
)

add_dependencies(client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(client
  ntcore              #要添加的第三方库文件名，一共有两个，缺一不可
  wpiutil             #要添加的第三方库文件名，一共有两个，缺一不可
  ${catkin_LIBRARIES}
)


target_link_libraries(server
  ntcore              #要添加的第三方库文件名，一共有两个，缺一不可
  wpiutil             #要添加的第三方库文件名，一共有两个，缺一不可
  ${catkin_LIBRARIES}
)