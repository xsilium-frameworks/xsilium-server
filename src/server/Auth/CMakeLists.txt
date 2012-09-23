########### authserver ###############

file(GLOB_RECURSE sources_authentication Authentification/*.cpp Authentification/*.h)
file(GLOB_RECURSE sources_realms realms/*.cpp realms/*.h)
file(GLOB sources_localdir *.cpp *.h)



set(authserver_SRCS
  ${sources_authentication}
  ${sources_realms}
  ${sources_localdir}
)

include_directories(
	${CMAKE_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/Authentication
	${CMAKE_CURRENT_SOURCE_DIR}/realms
	${CMAKE_SOURCE_DIR}/src/server/Shared
)


find_library(ENET_LIB enet)
find_library(PQXX_LIB pqxx)


link_libraries(
	SHARED
	${OSX_LIBS}
	${PQXX_LIB}
	${ENET_LIB}	
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
  install(FILES  auth.config DESTINATION etc)

