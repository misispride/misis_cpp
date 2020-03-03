file(GLOB SRC_FILES ./*.cpp)

foreach(X ${SRC_FILES})
    get_filename_component(src_file_path "${X}" NAME_WLE)
    add_executable(${src_file_path} ${X})
endforeach()