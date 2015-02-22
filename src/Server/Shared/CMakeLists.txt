
file(GLOB_RECURSE sources_Utilities Utilities/*.cpp Utilities/*.h)
file(GLOB_RECURSE sources_Singleton Singleton/*.cpp Singleton/*.h)
file(GLOB_RECURSE sources_Log Log/*.cpp Log/*.h)
file(GLOB_RECURSE sources_Database Databases/*.cpp Databases/*.h)
file(GLOB_RECURSE sources_Configuration Configuration/*.cpp Configuration/*.h)
file(GLOB_RECURSE sources_Network Network/*.cpp Network/*.h)
file(GLOB_RECURSE sources_Session Session/*.cpp Session/*.h)
file(GLOB_RECURSE sources_Signal Signal/*.cpp Signal/*.h)
file(GLOB_RECURSE sources_Compte Compte/*.cpp Compte/*.h)
file(GLOB_RECURSE sources_IP IP/*.cpp IP/*.h)
file(GLOB_RECURSE sources_Royaume Royaume/*.cpp Royaume/*.h)

file(GLOB_RECURSE sources_Test *Test.cpp *Test.h)

#
# Build shared sourcelist
#

set(shared_STAT_SRCS
  ${sources_Utilities}
  ${sources_Singleton}
  ${sources_Database}
  ${sources_Configuration}
  ${sources_Log}
  ${sources_Network}
  ${sources_Session}
  ${sources_Signal}
  ${sources_Compte}
  ${sources_IP}
  ${sources_Royaume}
)

list(REMOVE_ITEM shared_STAT_SRCS ${sources_Test} )

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


