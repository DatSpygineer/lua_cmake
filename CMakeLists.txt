cmake_minimum_required(VERSION 3.20)

project(lua)
project(lua_static)

file(GLOB LUA_SOURCES ${CMAKE_CURRENT_LIST_DIR}/core/*.h ${CMAKE_CURRENT_LIST_DIR}/core/*.c)

add_library(lua SHARED ${LUA_SOURCES})
target_compile_definitions(lua PUBLIC -DLUA_BUILD_AS_DLL)
target_compile_definitions(lua PRIVATE -DLUA_LIB)
target_include_directories(lua PUBLIC ${CMAKE_CURRENT_LIST_DIR}/core)

add_library(lua_static STATIC ${LUA_SOURCES})
target_compile_definitions(lua_static PRIVATE -DLUA_LIB)
target_include_directories(lua_static PUBLIC ${CMAKE_CURRENT_LIST_DIR}/core)

add_library(lua::lua ALIAS lua)
add_library(lua::static ALIAS lua_static)