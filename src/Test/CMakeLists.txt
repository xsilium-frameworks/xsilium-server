ENABLE_TESTING()

if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    SETUP_TARGET_FOR_COVERAGE_COBERTURA(UnitTester_coverage UnitTester coverage)
endif()

file(GLOB_RECURSE sources_Test ../Server/*Test.cpp ../Server/*Test.h)


# Unit testing driver
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/src/Server/Shared
	${CMAKE_SOURCE_DIR}/src/Server/Auth
	${CMAKE_SOURCE_DIR}/src/Server/Kingdom
)
set(UnitTests_SRCS 
TestRunnerClient.cpp
)

add_executable(UnitTester ${UnitTests_SRCS} ${sources_Test} )
TARGET_LINK_LIBRARIES(UnitTester 
	${CPPUNIT_LIBRARY}
	SHARED
)

if(CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(UnitTester gcov)
endif()


install(TARGETS UnitTester DESTINATION test)
install(FILES  TestConfig.config DESTINATION test)