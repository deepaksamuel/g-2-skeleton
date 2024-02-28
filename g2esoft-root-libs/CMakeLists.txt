cmake_minimum_required(VERSION 3.1)

set(libname g2esoftCommon)
set(dictname g2esoftDict)

file(GLOB dict_include_files include/*.h)
include_directories("g2esoft-root-libs/include")
ROOT_GENERATE_DICTIONARY    (${dictname} ${dict_include_files} LINKDEF LinkDef.h)

aux_source_directory( ./src sources )
add_library( ${libname} SHARED ${sources} ${dictname}.cxx)
target_link_libraries( ${libname} ${ROOT_LIBRARIES} ${ROOT_COMPONENT_LIBRARIES} )

install( TARGETS ${libname} LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib )
install( FILES ${CMAKE_CURRENT_BINARY_DIR}/lib${dictname}_rdict.pcm DESTINATION ${CMAKE_SOURCE_DIR}/lib )