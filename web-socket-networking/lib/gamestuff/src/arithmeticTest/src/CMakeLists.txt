add_library(arythmTest Arithmetic.cpp)

target_include_directories(arythmTest
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

install(FILES include/Arithmetic.h DESTINATION include)
install(TARGETS arythmTest DESTINATION lib)