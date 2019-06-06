// cmake的最低版本2.8.3，满足版本以上才编译
cmake_minimum_required(VERSION 2.8.3)
// 工程名字，对应ROS的catkin包名，rosrun CmakeList_example xxx_node
project(CmakeList_example)

## Compile as C++11, supported in ROS Kinetic and newer
// 指定使用c++11进行编译
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
// 寻找包catkin，并生成相应变量${catkin_INCLUDE_DIRS}，${catkin_LIBRARIES}，${catkin_EXPORTED_TARGETS}
find_package(catkin REQUIRED COMPONENTS roscpp someones_pkg)
  /* 将roscpp someones_pkg对应的头文件路径，库文件路径加入到上述变量中
  /* REQUIRED 后面的包，为catkin所必须，如果找不到，便终止编译
  /* COMPONENTS 后面的包，作为catkin组件

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
// 如果当前的ROS包要提供一些Python模块给其他人用，创建一个setup.py文件并调用该语句
catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
// 创建Message1.msg消息，ROS下还需要其他catkin包组件
add_message_files(
   FILES
   Message1.msg
)

## Generate services in the 'srv' folder
// 创建Service1.srv服务，ROS下还需要其他catkin包组件
add_service_files(
   FILES
   Service1.srv
)

## Generate actions in the 'action' folder
// 创建Action.action动作消息，ROS下还需要其他catkin包组件
add_action_files(
   FILES
   Action1.action
)

## Generate added messages and services with any dependencies listed here
// 用于生成消息，服务，动作文件所对应头文件，并添加相关依赖包
generate_messages(
   DEPENDENCIES
   std_msgs  # 消息/服务/动作的生成依赖了std_msgs
)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
// 创建动态参数配置，ROS下还需要相关组件
generate_dynamic_reconfigure_options(
   cfg/DynReconf1.cfg
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
// 主要作用:生成cmake配置文件,将当前包的东西(如:自定义头文件,动态库等)提供给第三方包去使用
// 通俗来讲,就是将下面变量[如:INCLUDE_DIRS]所对应参数[如:pkg_include]放进一些通用变量[如:${catkin_INCLUDE_DIRS}]),让第三包通过使用这些变量找到,链接,并使用
// 特殊说明:A包(当前包),B包(第三方包)
catkin_package(
  INCLUDE_DIRS pkg_include
  LIBRARIES pkg_lib
  CATKIN_DEPENDS other_catkin_pkg
  DEPENDS system_lib
)
INCLUDE_DIRS pkg_include   ## 当B包使用了A包自定义某些头文件时(但不包括生成消息/服务的头文件)，并且B包使用了'find_package()'将A包纳入它的依赖
  /* B包想通过变量${catkin_INCLUDE_DIRS}成功找到A包自定义的头文件时，A包的相关头文件路径位置需要在这里列出
  /* 第三方要使用该包中的头文件，需要提供该头文件路径
LIBRARIES pkg_lib
  /* 同理，当B包想要通过变量${catkin_LIBRARIES}成功找A包所生成的动（静）态库时，
  /* A包的相关库'pkg_lib'应在这里列出，以便第三方可以通过${catkin_LIBRARIES}找到该包中的库'pkg_lib'
  /* 相关库指的是下面add_library生成的库
CATKIN_DEPENDS
  /* 当前包需要依赖的包，一般与find_package后面列出的包一致 
DEPENDS
  /* 当前包需要依赖的系统依赖，boost之类的
###########
## Build ##
###########

// 将catkin_src_variables设为变量，变量值为/home/lxq/catkin_ws/src
set(catkin_src_variables /home/lxq/catkin_ws/src)

// 在catkin打印输出
message(This is variables ${catkin_src_variables})

// 设置非标准链接库的搜索路径
link_directories(/home/lxq/catkin_ws/devel/lib/)

// 设置需要链接的库，add_library下生成的库都与lib1，lib2链接
link_libraries(lib1 lib2)
  /* link_libraries与target_link_libraries的区别，target_link_libraries是有选择地链接
  /* link_libraries是将当前CmakeList下生成的库都需要与该命令中的库进行链接

## Specify additional locations of header files
## Your package locations should be listed before other locations
// 该包的头文件搜索路径
include_directories(
pkg_include
${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
// 该包生成的库文件
add_library(CmakeList_example
  src/CmakeList_example.cpp
)

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
// 明确该包的库文件生成所需要的依赖
// ${catkin_EXPORTED_TARGETS}的意义: 通俗来讲,如果当前包(A包)的动(静)态库需要依赖由第三方包(B包)所生成的消息/服务/操作时,就要加入该变量
// ${${PROJECT_NAME}_EXPORTED_TARGETS}的意义: 通俗来讲,如果当前包(A包)的动(静)态库需要依赖于自己所定义的消息/服务/操作时,就要加入该变量
add_dependencies(CmakeList_example ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
// 该包生成的执行文件
add_executable(CmakeList_example_node src/CmakeList_example.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
// 明确该包执行文件生成所需要的依赖，
// 同理.不过是针对执行文件
add_dependencies(CmakeList_example_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
// 将执行文件与库文件进行链接
target_link_libraries(CmakeList_example_node
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
// 将python脚本或其他运行脚本复制到变量${CATKIN_PACKAGE_BIN_DESTINATION}
install(PROGRAMS  scripts/my_python_script
        DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark executables and/or libraries for installation
// 将库CmakeList_example复制在变量${CATKIN_PACKAGE_LIB_DESTINATION}对应的位置
// 将执行文件CmakeList_example_node复制到变量${CATKIN_PACKAGE_BIN_DESTINATION}对应的位置
install(TARGETS CmakeList_example CmakeList_example_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark cpp header files for installation
// pkg_include位置下的所有头文件全部复制到变量${CATKIN_PACKAGE_INCLUDE_DESTINATION}对应的位置上
// 注意pkg_include 与 pkg_include/ 之间的区别，前者连同文件夹pkg_include也一起复制过去，后者仅复制该目录下的头文件
install(DIRECTORY pkg_include
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
)

## Mark other files for installation (e.g. launch and bag files, etc.)
// 将launch文件夹下的CmakeList_example.launch复制到变量${CATKIN_PACKAGE_SHARE_DESTINATION}对应的位置
install(FILES
   launch/CmakeList_example.launch
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_ll.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
