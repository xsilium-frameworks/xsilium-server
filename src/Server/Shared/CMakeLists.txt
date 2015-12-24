
file(GLOB_RECURSE sources_Utilities Utilities/*.cpp Utilities/*.h)
file(GLOB_RECURSE sources_Singleton Singleton/*.cpp Singleton/*.h)
file(GLOB_RECURSE sources_DAO DAO/*.cpp DAO/*.h)
file(GLOB_RECURSE sources_Manager Manager/*.cpp Manager/*.h)
file(GLOB_RECURSE sources_Service Service/*.cpp Service/*.h)
file(GLOB_RECURSE sources_Model Model/*.cpp Model/*.h)

#
# Build shared sourcelist
#

set(shared_STAT_SRCS
  ${sources_Utilities}
  ${sources_Singleton}
  ${sources_DAO}
  ${sources_Manager}
  ${sources_Service}
  ${sources_Model}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

link_libraries(
${ENET_LIBRARY}
${Boost_LIBRARIES}
${PQXX_LIB}

)

add_library(SHARED STATIC ${shared_STAT_SRCS})


