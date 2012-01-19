
cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED)
qt4_wrap_cpp(MOCS qcmdlineparsertest.h)
include_directories(${QT_QTCORE_INCLUDE_DIR} ${QT_QTTEST_INCLUDE_DIR})
set(SRC qcmdlineparser.cpp qcmdlineoption.cpp qcmdlineparsertest.cpp)
add_executable(qcmdlineparser ${SRC} ${MOCS})
target_link_libraries(qcmdlineparser ${QT_QTCORE_LIBRARY} ${QT_QTTEST_LIBRARY})
