

file(GLOB_RECURSE sources_Chat Chat/*.cpp Chat/*.h)

#
# Build kingdom sourcelist
#

set(kingdom_STAT_SRCS
  ${sources_Chat}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/Shared
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(KINGDOM STATIC ${kingdom_STAT_SRCS})


