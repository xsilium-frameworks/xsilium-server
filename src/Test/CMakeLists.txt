ENABLE_TESTING()

file(GLOB_RECURSE sources_Test ../server/*Test.cpp ../server/*Test.h)


# Unit testing driver
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)
set(UnitTests_SRCS 
TestRunnerClient.cpp
)

add_executable(UnitTester ${UnitTests_SRCS} ${sources_Test} )
TARGET_LINK_LIBRARIES(UnitTester 
	${CPPUNIT_LIBRARY}
	SHARED	
)

install(TARGETS UnitTester DESTINATION test)