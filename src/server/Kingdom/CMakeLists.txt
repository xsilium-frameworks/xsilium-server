

file(GLOB_RECURSE sources_Chat Chat/*.cpp Chat/*.h)
file(GLOB_RECURSE sources_Mail Mail/*.cpp Mail/*.h)
file(GLOB_RECURSE sources_Zone Zone/*.cpp Zone/*.h)
file(GLOB sources_localdir *.cpp *.h)

file(GLOB_RECURSE sources_Test *Test.cpp *Test.h)


#
# Build kingdom sourcelist
#

set(kingdom_STAT_SRCS
  ${sources_Chat}
  ${sources_Mail}
  ${sources_Zone}
)

list(REMOVE_ITEM kingdom_STAT_SRCS "${sources_Test}")

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

add_library(KS STATIC ${kingdom_STAT_SRCS})

add_executable(KingdomServer ${sources_localdir})
target_link_libraries(KingdomServer KS)

set_target_properties(KingdomServer PROPERTIES LINK_FLAGS "${kingdomserver_LINK_FLAGS}" )

install(TARGETS KingdomServer DESTINATION bin)
install(FILES  Kingdom.config DESTINATION etc)
