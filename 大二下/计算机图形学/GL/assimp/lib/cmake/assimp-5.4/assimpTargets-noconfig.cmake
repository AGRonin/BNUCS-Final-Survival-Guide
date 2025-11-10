#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "assimp::assimp" for configuration ""
set_property(TARGET assimp::assimp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(assimp::assimp PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C;CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libassimp.a"
  )

list(APPEND _cmake_import_check_targets assimp::assimp )
list(APPEND _cmake_import_check_files_for_assimp::assimp "${_IMPORT_PREFIX}/lib/libassimp.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
