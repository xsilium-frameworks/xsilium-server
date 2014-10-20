

file(GLOB_RECURSE sources_Database Databases/*.cpp Databases/*.h)

file(GLOB_RECURSE sources_Test *Test.cpp *Test.h)

#
# Build shared sourcelist
#

set(shared_STAT_SRCS
  ${sources_Configuration}
  ${sources_Database}
  ${sources_Logging}
)

list(REMOVE_ITEM shared_STAT_SRCS "${sources_Test}")

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Databases
  ${PQXX_INCLUDE_DIRECTORIES}
)

add_library(SHARED STATIC ${shared_STAT_SRCS})


