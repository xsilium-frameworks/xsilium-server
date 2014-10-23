
file(GLOB_RECURSE sources_Singleton Singleton/*.cpp Singleton/*.h)
file(GLOB_RECURSE sources_Database Databases/*.cpp Databases/*.h)
file(GLOB_RECURSE sources_Configuration Configuration/*.cpp Configuration/*.h)

file(GLOB_RECURSE sources_Test *Test.cpp *Test.h)

#
# Build shared sourcelist
#

set(shared_STAT_SRCS
  ${sources_Singleton}
  ${sources_Database}
  ${sources_Configuration}
)

list(REMOVE_ITEM shared_STAT_SRCS "${sources_Test}")

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Databases
  ${CMAKE_CURRENT_SOURCE_DIR}/Databases/Postgresql
  
)

add_library(SHARED STATIC ${shared_STAT_SRCS})


