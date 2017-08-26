
cmake_minimum_required(VERSION 3.4.1)
#查找系统库
find_library( log-lib
              log )
#设置一个libs的路径
set(distribution_DIR ../../../../libs)
#添加预编译库的so
add_library( fmod
             SHARED
             IMPORTED )
set_target_properties( fmod
                       PROPERTIES IMPORTED_LOCATION
                       ${distribution_DIR}/${ANDROID_ABI}/libfmod.so )
#添加预编译库的so
add_library( fmodL
             SHARED
             IMPORTED )
set_target_properties( fmodL
                       PROPERTIES IMPORTED_LOCATION
                       ${distribution_DIR}/${ANDROID_ABI}/libfmodL.so )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_library( watervoicer
             SHARED
             src/main/cpp/waterVoicer.cpp)

include_directories(src/main/cpp/inc)

target_link_libraries( watervoicer
                       fmod
                       fmodL
                       ${log-lib})