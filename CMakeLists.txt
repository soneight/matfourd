cmake_minimum_required( VERSION 3.8...3.27 )
project( matfourd VERSION 0.0.0 LANGUAGES CXX )
set( SON8PROJ son8__${PROJECT_NAME} )
option( SON8_MATFOURD_INCLUDE_DEPRECATED "Include deprecated son8::matfourd entities" OFF )
# Private configuration under source directory
add_subdirectory( source )
add_library( son8::${PROJECT_NAME} ALIAS ${SON8PROJ} )
target_compile_features( ${SON8PROJ} INTERFACE cxx_std_17 )
target_compile_options( ${SON8PROJ} INTERFACE $<$<CXX_COMPILER_ID:MSVC>:/utf-8 /permissive- /Zc:__cplusplus> )
target_include_directories( ${SON8PROJ} INTERFACE include )

if ( SON8_MATFOURD_INCLUDE_DEPRECATED )
    target_compile_definitions( ${SON8PROJ} INTERFACE SON8_MATFOURD_INCLUDE_DEPRECATED )
endif( )
