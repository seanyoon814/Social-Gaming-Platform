add_library(commandHandle command_reader.cpp)

target_include_directories(commandHandle
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

install(FILES include/command_reader.h DESTINATION include)
install(TARGETS commandHandle DESTINATION lib)