

file(GLOB_RECURSE sources_Chat Chat/*.cpp Chat/*.h)
file(GLOB_RECURSE sources_Session Session/*.cpp Session/*.h)
file(GLOB sources_localdir *.cpp *.h)


#
# Build kingdom sourcelist
#

set(kingdom_STAT_SRCS
  ${sources_localdir}
  ${sources_Chat}
  ${sources_Session}
)

include_directories(
	${CMAKE_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/src/server/Shared
)



find_library(ENET_LIB enet)
find_library(PQXX_LIB pqxx)


link_libraries(
	SHARED
	${OSX_LIBS}
	${PQXX_LIB}
	${ENET_LIB}
	${Boost_LIBRARIES}
)

if( UNIX )
  set(worldserver_LINK_FLAGS "${kingdomserver_LINK_FLAGS}")
endif()

if( CMAKE_SYSTEM_NAME MATCHES "Darwin" )
  set(worldserver_LINK_FLAGS "${kingdomserver_LINK_FLAGS}")
endif()

add_executable(KingdomServer ${kingdom_STAT_SRCS})

set_target_properties(KingdomServer PROPERTIES LINK_FLAGS "${kingdomserver_LINK_FLAGS}" )

install(TARGETS KingdomServer DESTINATION bin)
install(FILES  Kingdom.config DESTINATION etc)
