file(GLOB_RECURSE sources_Raknet Raknet/*.cpp Raknet/*.h)

set(raknet_STAT_SRCS
  ${raknet_STAT_SRCS}
  ${sources_Raknet}
)

add_library(raknet STATIC ${raknet_STAT_SRCS})