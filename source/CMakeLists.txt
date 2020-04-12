include_directories(${TRON_SOURCE_DIR}/source)
link_directories(${TRON_BINARY_DIR}/source)

# set (RESOURCE_FILES Spoopies.ttf)
# message(STATUS "Resource FILES is: " ${RESOURCE_FILES})

file(GLOB_RECURSE SOURCEFILES "*.cpp")
message(STATUS "Sources are is: " ${SOURCEFILES})
# list (APPEND SOURCEFILES "Spoopies.ttf")

add_executable(${PROJECT_NAME} ${SOURCEFILES})
# message(STATUS "Value is: " ${BOWMANS_SOURCE_DIR})

set(RESOURCE_FILES
  # Spoopies.ttf
  TRON.ttf
  # arcade.ttf
  # UbuntuMono.ttf
  white.png
  # space.png
  # cross2.png
  )
install(FILES ${RESOURCE_FILES} DESTINATION ${TRON_BINARY_DIR}/source)

message(STATUS ${SDL2IMAGE_INCLUDE_DIRS})
# INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(/usr/local/include)

set (SDL2_LIBRARIES /Library/Frameworks/SDL2.framework)
set (SDL2IMAGE_LIBRARIES /Library/Frameworks/SDL2_image.framework)
set (SDL2TTF_LIBRARIES /Library/Frameworks/SDL2_ttf.framework)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})
