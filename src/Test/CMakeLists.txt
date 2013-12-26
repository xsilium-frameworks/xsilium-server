ENABLE_TESTING()

file(GLOB_RECURSE sources_Test ../server/*Test.cpp ../server/*Test.h)


# Unit testing driver
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/src/server/Shared
	${CMAKE_SOURCE_DIR}/src/server/Auth
	${CMAKE_SOURCE_DIR}/src/server/Kingdom
)
set(UnitTests_SRCS 
TestRunnerClient.cpp
)

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage -fPIC")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

add_executable(UnitTester ${UnitTests_SRCS} ${sources_Test} )
TARGET_LINK_LIBRARIES(UnitTester 
	${CPPUNIT_LIBRARY}
	${Boost_LIBRARIES}
	${ENET_LIB}
	SHARED
	KS	
	Auth
	gcov
)

install(TARGETS UnitTester DESTINATION test)