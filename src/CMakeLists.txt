find_package(CppUnit REQUIRED)
find_library(PQXX_LIB pqxx)

set(Boost_ADDITIONAL_VERSIONS "1.52.0")
set(BOOST_COMPONENTS thread date_time system signals serialization)
find_package(Boost COMPONENTS ${BOOST_COMPONENTS} QUIET)
	
include_directories(
	${CPPUNIT_INCLUDE_DIR}
	${Boost_INCLUDE_DIR}
	${ENET_INCLUDE_DIR}
)	

if(CMAKE_COMPILER_IS_GNUCXX)
	SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
endif()


add_subdirectory(Server)
add_subdirectory(Test)
