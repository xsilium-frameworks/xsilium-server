########### authserver ###############

file(GLOB_RECURSE sources_authentication Authentification/*.cpp Authentification/*.h)
file(GLOB_RECURSE sources_realms ListServeur/*.cpp ListServeur/*.h)
file(GLOB sources_localdir *.cpp *.h)

file(GLOB_RECURSE sources_Test *Test.cpp *Test.h)



set(authserver_SRCS
  ${sources_authentication}
  ${sources_realms}
)

list(REMOVE_ITEM authserver_SRCS ${sources_Test})

include_directories(
	${CMAKE_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/Authentication
	${CMAKE_CURRENT_SOURCE_DIR}/ListServeur
	${CMAKE_SOURCE_DIR}/src/Server/Shared
)


link_libraries(
	SHARED
)

add_library(Auth STATIC ${authserver_SRCS})

add_executable(authserver ${sources_localdir})
target_link_libraries(authserver Auth)

  install(TARGETS authserver DESTINATION bin)
  install(FILES  auth.config DESTINATION etc)

