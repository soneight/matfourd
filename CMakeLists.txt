cmake_minimum_required( VERSION 3.14...3.27 )
project( matfourd VERSION 0.0.0 LANGUAGES CXX )

set( SON8PROJ son8__${PROJECT_NAME} )

add_subdirectory( source )
add_library( son8::${PROJECT_NAME} ALIAS ${SON8PROJ} )
target_compile_features( ${SON8PROJ} INTERFACE cxx_std_17 )
target_include_directories( ${SON8PROJ} INTERFACE include )

if ( CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/temp/CMakeLists.txt" )
    add_subdirectory(temp)
endif( )
