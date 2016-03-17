

file(GLOB_RECURSE sources_Service Service/*.cpp Service/*.h)
file(GLOB_RECURSE sources_Manager Manager/*.cpp Manager/*.h)
file(GLOB_RECURSE sources_DAO DAO/*.cpp DAO/*.h)
file(GLOB_RECURSE sources_Model Model/*.cpp Model/*.h)
file(GLOB sources_localdir *.cpp *.h)


#
# Build kingdom sourcelist
#

set(kingdom_STAT_SRCS
  ${sources_Service}
  ${sources_Manager}
  ${sources_DAO}
  ${sources_Model}
)

include_directories(
	${CMAKE_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/src/Server/Shared
)


link_libraries(
	SHARED
)

add_library(KS STATIC ${kingdom_STAT_SRCS})

add_executable(KingdomServer ${sources_localdir})
target_link_libraries(KingdomServer KS)

install(TARGETS KingdomServer DESTINATION bin)
install(FILES  Kingdom.config DESTINATION etc)
