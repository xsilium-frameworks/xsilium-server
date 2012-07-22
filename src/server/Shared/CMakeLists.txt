

file(GLOB_RECURSE sources_Configuration Config/*.cpp Config/*.h)
file(GLOB_RECURSE sources_Database Databases/*.cpp Databases/*.h)
file(GLOB_RECURSE sources_Logging Logging/*.cpp Logging/*.h)
file(GLOB_RECURSE sources_PostgreSQLInterface PostgreSQLInterface/*.cpp PostgreSQLInterface/*.h)
file(GLOB_RECURSE sources_SignalHandler SignalHandler/*.cpp SignalHandler/*.h)
file(GLOB_RECURSE sources_Singleton Singleton/*.cpp Singleton/*.h)
file(GLOB_RECURSE sources_Threading Threading/*.cpp Threading/*.h)
file(GLOB_RECURSE sources_Structure Structure/*.cpp Structure/*.h)
file(GLOB_RECURSE sources_Utilities Utilities/*.cpp Utilities/*.h)

#
# Build shared sourcelist
#

set(shared_STAT_SRCS
  ${sources_Configuration}
  ${sources_Database}
  ${sources_Logging}
  ${sources_PostgreSQLInterface}
  ${sources_SignalHandler}
  ${sources_Singleton}
  ${sources_Structure}
  ${sources_Threading}
  ${sources_Utilities}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Config
  ${CMAKE_CURRENT_SOURCE_DIR}/Databases
  ${CMAKE_CURRENT_SOURCE_DIR}/Logging
  ${CMAKE_CURRENT_SOURCE_DIR}/PostgreSQLInterface
  ${CMAKE_CURRENT_SOURCE_DIR}/SignalHandler
  ${CMAKE_CURRENT_SOURCE_DIR}/Singleton
  ${CMAKE_CURRENT_SOURCE_DIR}/Structure
  ${CMAKE_CURRENT_SOURCE_DIR}/Threading
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities
  ${POSTGRESQL_INCLUDE_DIR}
)

add_library(SHARED STATIC ${shared_STAT_SRCS})


