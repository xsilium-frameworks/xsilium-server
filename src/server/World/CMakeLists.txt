########### worldserver ###############

file(GLOB sources_localdir *.cpp *.h)



set(worldserver_SRCS
${sources_localdir}
)

include_directories(
	${CMAKE_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/src/server/Shared
	${CMAKE_SOURCE_DIR}/src/server/Kingdom
)


find_library(ENET_LIB enet)
find_library(PQXX_LIB pqxx)


link_libraries(
	SHARED
	KINGDOM
	${OSX_LIBS}
	${PQXX_LIB}
	${ENET_LIB}
	${Boost_LIBRARIES}
)

if( UNIX )
  set(worldserver_LINK_FLAGS "${worldserver_LINK_FLAGS}")
endif()

if( CMAKE_SYSTEM_NAME MATCHES "Darwin" )
  set(worldserver_LINK_FLAGS "${worldserver_LINK_FLAGS}")
endif()


add_executable(worldserveur
  ${worldserver_SRCS}
)

set_target_properties(worldserveur PROPERTIES LINK_FLAGS "${worldserver_LINK_FLAGS}" )

  install(TARGETS worldserveur DESTINATION bin)
  install(FILES  world.config DESTINATION etc)

