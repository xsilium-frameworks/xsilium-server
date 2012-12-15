find_package(CppUnit REQUIRED)
include_directories(
	${CPPUNIT_INCLUDE_DIR}
)


add_subdirectory(server)
add_subdirectory(Test)