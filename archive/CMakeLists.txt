PROJECT(archive)

add_modules(source Archive ArchiveUtil)
ADD_LIBRARY(archive ${source} include/Allocator.hpp include/Directory.hpp include/File.hpp include/Header.hpp include/HeaderWrapper.hpp include/Meta.hpp include/StreamWrapper.hpp)
TARGET_LINK_LIBRARIES(archive common ${Boost_LIBRARIES})

ADD_EXECUTABLE(archive_test src/Archive.t.cpp)
TARGET_LINK_LIBRARIES(archive_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} archive)
ADD_TEST(NAME archive_test_module COMMAND archive_test)

ADD_EXECUTABLE(archive_main src/Archive.m.cpp)
TARGET_LINK_LIBRARIES(archive_main archive)
