########### authserver ###############

file(GLOB_RECURSE sources_authentication Authentication/*.cpp Authentication/*.h)
file(GLOB_RECURSE sources_realms realms/*.cpp realms/*.h)
file(GLOB sources_localdir *.cpp *.h)

set(authserver_SRCS
  ${authserver_SRCS}	
  ${sources_authentication}
  ${sources_realms}
  ${sources_localdir}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/Shared
  ${CMAKE_SOURCE_DIR}/src/server/Shared/Config
  ${CMAKE_SOURCE_DIR}/src/server/Shared/Databases
  ${CMAKE_SOURCE_DIR}/src/server/Shared/PostgreSQLInterface
  ${CMAKE_SOURCE_DIR}/src/server/Shared/SignalHandler
  ${CMAKE_SOURCE_DIR}/src/server/Shared/Singleton
  ${CMAKE_SOURCE_DIR}/src/server/Shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/Shared/Structure
  ${CMAKE_SOURCE_DIR}/Dep/Raknet
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Authentication
  ${CMAKE_CURRENT_SOURCE_DIR}/realms
  ${PGSQL_INCLUDE_DIR}
  ${shared_STAT_SRCS}
  ${raknet_STAT_SRCS}
)


set(authserver_LINK_FLAGS "-pthread -lpq")





add_executable(authserver
  ${authserver_SRCS}
)

if( UNIX )
  set(authserver_LINK_FLAGS "${authserver_LINK_FLAGS}")
endif()

if( CMAKE_SYSTEM_NAME MATCHES "Darwin" )
  set(authserver_LINK_FLAGS "-framework Carbon ${authserver_LINK_FLAGS} ")
endif()


set_target_properties(authserver PROPERTIES LINK_FLAGS "${authserver_LINK_FLAGS}" )

target_link_libraries(authserver shared raknet ${OSX_LIBS} ${PGSQL_LIBRARIES} )

  install(TARGETS authserver DESTINATION bin)
  #install(FILES  authserver.conf.dist DESTINATION etc)

