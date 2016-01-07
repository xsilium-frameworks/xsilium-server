ENABLE_TESTING()

if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    SETUP_TARGET_FOR_COVERAGE_COBERTURA(UnitTester_coverage UnitTester coverage "--log_format=XML --log_sink=boost-report.xml --log_level=all --report_level=no")
endif()

file(GLOB_RECURSE sources_Test *Test.cpp *Test.h)

set(UnitTests_SRCS 
TestRunnerClient.cpp
)


# Unit testing driver
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/src/Server/Shared
	${CMAKE_SOURCE_DIR}/src/Server/Auth
	${CMAKE_SOURCE_DIR}/src/Server/Kingdom
	${TURTLE_INCLUDE_DIR}
)

add_executable(UnitTester ${UnitTests_SRCS} ${sources_Test} )
TARGET_LINK_LIBRARIES(UnitTester 
	${Boost_LIBRARIES}
	SHARED
)


if(CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(UnitTester gcov)
endif() 


install(TARGETS UnitTester DESTINATION test)
install(FILES  TestConfig.config DESTINATION test)