########### authserver ###############

file(GLOB_RECURSE sources_authentication Authentication/*.cpp Authentication/*.h)
file(GLOB_RECURSE sources_realms realms/*.cpp realms/*.h)
file(GLOB sources_localdir *.cpp *.h)

set(authserver_SRCS
  ${sources_authentication}
  ${sources_realms}
  ${sources_localdir}
)

include_directories(
  .
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Authentication
  ${CMAKE_CURRENT_SOURCE_DIR}/realms
  ${PGSQL_INCLUDE_DIR}
  ${shared_STAT_SRCS}
)


find_library(ENET_LIB enet)


link_libraries(
	${OSX_LIBS}
	${PGSQL_LIBRARIES}
	${ENET_LIB}
	${SHARED}	
)


set(authserver_LINK_FLAGS "-pthread")

if( UNIX )
  set(authserver_LINK_FLAGS "${authserver_LINK_FLAGS}")
endif()

if( CMAKE_SYSTEM_NAME MATCHES "Darwin" )
  set(authserver_LINK_FLAGS "${authserver_LINK_FLAGS}")
endif()


add_executable(authserver
  ${authserver_SRCS}
)

set_target_properties(authserver PROPERTIES LINK_FLAGS "${authserver_LINK_FLAGS}" )

  install(TARGETS authserver DESTINATION bin)
  #install(FILES  authserver.conf.dist DESTINATION etc)

