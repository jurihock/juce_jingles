# JUCE Jingles Module

> [!NOTE]
> This is a personal collection of [JUCE](https://juce.com) related utilities.

## CPM.cmake (`juce_jingles.cmake`)

```
CPMAddPackage(
  NAME juce_jingles
  VERSION main
  GIT_TAG main
  GITHUB_REPOSITORY jurihock/juce_jingles
  DOWNLOAD_ONLY YES
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/modules/juce_jingles")
```

## CMake (`modules\CMakeLists.txt`)

```
juce_add_module(juce_jingles)
```

## CMake (`CMakeLists.txt`)

```
option(LOGGING "Enable runtime logs" OFF)
option(CHRONO  "Enable timing logs"  OFF)

if(LOGGING)

  message(STATUS "Defining ENABLE_JINGLE_LOGGER")

  target_compile_definitions(${PROJECT_NAME}
    PRIVATE
      -DENABLE_JINGLE_LOGGER)

endif()

if(CHRONO)

  message(STATUS "Defining ENABLE_JINGLE_CHRONOMETER")

  target_compile_definitions(${PROJECT_NAME}
    PRIVATE
      -DENABLE_JINGLE_CHRONOMETER)

endif()

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    juce_jingles)

target_compile_features(${PROJECT_NAME}
  PRIVATE
    cxx_std_20)
```

## Jingles.cpp

```
#include <JuceHeader.h>

HELLO_JUCE_JINGLES
```

## .gitignore

```
modules/juce_jingles/
```
