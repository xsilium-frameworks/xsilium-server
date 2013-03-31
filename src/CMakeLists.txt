find_package(CppUnit REQUIRED)

set(Boost_ADDITIONAL_VERSIONS "1.52.0")
set(BOOST_COMPONENTS thread date_time system signals)
find_package(Boost COMPONENTS ${BOOST_COMPONENTS} QUIET)
	
include_directories(
	${CPPUNIT_INCLUDE_DIR}
	${Boost_INCLUDE_DIR}
)	


add_subdirectory(server)
add_subdirectory(Test)