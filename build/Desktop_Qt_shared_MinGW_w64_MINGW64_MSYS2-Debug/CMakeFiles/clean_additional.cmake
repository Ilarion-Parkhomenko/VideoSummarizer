# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\VideoSummarizer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\VideoSummarizer_autogen.dir\\ParseCache.txt"
  "VideoSummarizer_autogen"
  )
endif()
