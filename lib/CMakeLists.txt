cmake_minimum_required(VERSION 3.0...3.20)

project(XQCircularProgressBar)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

file(GLOB_RECURSE CPP_FILES src/*.cpp)
file(GLOB_RECURSE HPP_FILES include/*.hpp)

set(PROJECT_SOURCES
    ${CPP_FILES}
    ${HPP_FILES}
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})

set(INTERNAL_LIBRARIES

)

set(EXTERNAL_LIBRARIES
    Qt${QT_VERSION_MAJOR}::Widgets
)

set(LIBRARIES
    ${EXTERNAL_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

# Installation rules
install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION .
)

if (NOT WIN32)
    install(FILES ${HPP_FILES} DESTINATION include/${PROJECT_NAME})
    install(EXPORT ${PROJECT_NAME}Targets
      FILE ${PROJECT_NAME}Config.cmake
      NAMESPACE ${PROJECT_NAME}::
      DESTINATION lib/cmake/${PROJECT_NAME}
    )
endif()
