function(add_modules source)
  if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x" PARENT_SCOPE)
  endif()
  include_directories(SYSTEM include)
  include_directories(SYSTEM ${common_SOURCE_DIR}/include)
  list(LENGTH ARGN len)
  math(EXPR len ${len}-1)
  foreach(val RANGE ${len})
    list(GET ARGN ${val} module)
    list(APPEND modules src/${module}.cpp)
    list(APPEND modules include/${module}.hpp)
  endforeach()
  set(${source} ${modules} PARENT_SCOPE)
endfunction(add_modules)
