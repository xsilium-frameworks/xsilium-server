########### authserver ###############

file(GLOB_RECURSE sources_Service Service/*.cpp Service/*.h)
file(GLOB_RECURSE sources_Manager Manager/*.cpp Manager/*.h)
file(GLOB_RECURSE sources_DAO DAO/*.cpp DAO/*.h)
file(GLOB_RECURSE sources_Model Model/*.cpp Model/*.h)
file(GLOB sources_localdir *.cpp *.h)




set(authserver_SRCS
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

add_library(Auth STATIC ${authserver_SRCS})

add_executable(authserver ${sources_localdir})
target_link_libraries(authserver Auth)

install(TARGETS authserver DESTINATION /usr/bin COMPONENT binaries)
install(FILES auth.config DESTINATION /etc/xsilium COMPONENT config)

