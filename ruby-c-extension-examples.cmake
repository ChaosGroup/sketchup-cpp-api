set(THIRD_PARTY ${CMAKE_CURRENT_SOURCE_DIR}/tests/ruby-c-extension-examples/ThirdParty)

if(APPLE)
	execute_process(COMMAND uname -m OUTPUT_VARIABLE ARCHITECTURE OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()

set(RUBY_VERSIONS 2.7 3.2)

foreach(VERSION ${RUBY_VERSIONS})
	# version
	string(REGEX MATCH "^([0-9]+)\\.([0-9]+)" _ ${VERSION})
	set(SU_Ruby_${VERSION}_VERSION ${VERSION}.0)
	set(SU_Ruby_${VERSION}_VERSION_MAJOR ${CMAKE_MATCH_1})
	set(SU_Ruby_${VERSION}_VERSION_MINOR ${CMAKE_MATCH_2})
	set(SU_Ruby_${VERSION}_VERSION_PATCH 0)

	# set(SU_Ruby_${VERSION}_EXECUTABLE) # Not applicable

	# includes
	if(WIN32)
		set(SU_Ruby_${VERSION}_INCLUDE_DIRS
			${THIRD_PARTY}/include/ruby/${VERSION}/win32_x64
		)
	elseif(APPLE)
		set(SU_Ruby_${VERSION}_INCLUDE_DIRS
			${THIRD_PARTY}/include/ruby/${VERSION}/mac
			${THIRD_PARTY_INCLUDE}/${VERSION}/mac/${ARCHITECTURE}-darwin
		)
	endif()

	# libs
	if(WIN32)	
		set(SU_Ruby_${VERSION}_LIBRARIES ${THIRD_PARTY}/lib/win32/x64-ucrt-ruby${SU_Ruby_${VERSION}_VERSION_MAJOR}${SU_Ruby_${VERSION}_VERSION_MINOR}0.lib)
	elseif(APPLE)
		set(SU_Ruby_${VERSION}_LIBRARIES ${THIRD_PARTY}/lib/mac/${VERSION}/Ruby.framework/Ruby)
	endif()

	if(EXISTS ${SU_Ruby_${VERSION}_LIBRARIES})
		set(SU_Ruby_${VERSION}_FOUND TRUE)
	endif()
	
endforeach()

# override for exceptions that don't follow naming conventions
if(WIN32)
	set(SU_Ruby_2.7_LIBRARIES ${THIRD_PARTY}/lib/win32/x64-msvcrt-ruby270.lib)
elseif(APPLE)
	set(SU_Ruby_2.7_LIBRARIES ${THIRD_PARTY}/lib/mac/2.7-universal/Ruby.framework/Ruby)
endif()

foreach(VERSION ${RUBY_VERSIONS})
	if(EXISTS ${SU_Ruby_${VERSION}_LIBRARIES})
		set(SU_Ruby_${VERSION}_FOUND TRUE)
	endif()
endforeach()