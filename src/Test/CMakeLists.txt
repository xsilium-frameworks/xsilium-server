ENABLE_TESTING()

if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    SETUP_TARGET_FOR_COVERAGE_COBERTURA(UnitTester_coverage UnitTester coverage)
endif()

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

add_executable(UnitTester ${UnitTests_SRCS} ${sources_Test} )
TARGET_LINK_LIBRARIES(UnitTester 
	${CPPUNIT_LIBRARY}
	${Boost_LIBRARIES}
	${ENET_LIB}
	SHARED
)

if(CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(UnitTester gcov)
endif()


install(TARGETS UnitTester DESTINATION test)