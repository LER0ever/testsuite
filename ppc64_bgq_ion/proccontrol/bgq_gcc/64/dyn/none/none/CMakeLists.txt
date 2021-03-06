# CMakeLists for proccontrol/bgq_gcc/64/dyn/none/none
set (CMAKE_C_FLAGS "${MUTATOR_DEFINES}  ${CFLAGS} ${MUTATEE_CFLAGS_GNU}   -g -O0 ")
set (CMAKE_C_FLAGS_DEBUG "")
set (CMAKE_C_FLAGS_RELEASE "")
set (CMAKE_C_FLAGS_RELWITHDEBINFO "")
set (CMAKE_C_COMPILER "${M_mpi_cc}")
include_directories("${PROJECT_SOURCE_DIR}/testsuite/src")
include_directories("${PROJECT_SOURCE_DIR}/testsuite/src/proccontrol")
add_definitions(-DSOLO_MUTATEE)
set (CMAKE_EXE_LINKER_FLAGS "${MUTATEE_LDFLAGS_GNU}  -dynamic -Wl,-export-dynamic")
IF (NOT ${M_mpi_cc} MATCHES "NOTFOUND")
CHECK_MUTATEE_COMPILER ("${M_mpi_cc}"
	"${MUTATOR_DEFINES}  ${CFLAGS} ${MUTATEE_CFLAGS_GNU}   -g -O0 "
	"${MUTATEE_LDFLAGS_GNU}  -dynamic -Wl,-export-dynamic"
	"C"
	"mpi_cc 64 dyn"
	MUTATEEmpicc64dynC)

IF (MUTATEEmpicc64dynC MATCHES "1")
include (${PROJECT_SOURCE_DIR}/ppc64_bgq_ion/srclists.cmake)
if(TARGET pcontrol)
add_executable (pc_addlibrary.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_38})
foreach (f ${SOURCE_LIST_38})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_addlibrary.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_addlibrary.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_breakpoint.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_31})
foreach (f ${SOURCE_LIST_31})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_breakpoint.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_breakpoint.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_detach.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_12})
foreach (f ${SOURCE_LIST_12})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_detach.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_detach.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_groups.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_37})
foreach (f ${SOURCE_LIST_37})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_groups.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_groups.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_irpc.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_62})
foreach (f ${SOURCE_LIST_62})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_irpc.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_irpc.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_launch.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_63})
foreach (f ${SOURCE_LIST_63})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_launch.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_launch.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_library.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_26})
foreach (f ${SOURCE_LIST_26})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_library.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_library.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_singlestep.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_28})
foreach (f ${SOURCE_LIST_28})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_singlestep.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_singlestep.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_stat.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_4})
foreach (f ${SOURCE_LIST_4})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_stat.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_stat.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_terminate.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_24})
foreach (f ${SOURCE_LIST_24})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_terminate.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_terminate.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_terminate_stopped.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_46})
foreach (f ${SOURCE_LIST_46})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_terminate_stopped.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_terminate_stopped.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_thread.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_35})
foreach (f ${SOURCE_LIST_35})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_thread.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_thread.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
add_executable (pc_tls.dyn_bgq_gcc_64_none_none ${SOURCE_LIST_52})
foreach (f ${SOURCE_LIST_52})
	get_source_file_property(lang ${f} LANGUAGE)
	if(lang MATCHES "C")
		set_source_files_properties(${f} PROPERTIES LANGUAGE C)
	endif()
	endforeach()
set_target_properties(pc_tls.dyn_bgq_gcc_64_none_none PROPERTIES LINKER_LANGUAGE C)
target_link_libraries (pc_tls.dyn_bgq_gcc_64_none_none ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})


INSTALL (TARGETS
		pc_addlibrary.dyn_bgq_gcc_64_none_none
		pc_breakpoint.dyn_bgq_gcc_64_none_none
		pc_detach.dyn_bgq_gcc_64_none_none
		pc_groups.dyn_bgq_gcc_64_none_none
		pc_irpc.dyn_bgq_gcc_64_none_none
		pc_launch.dyn_bgq_gcc_64_none_none
		pc_library.dyn_bgq_gcc_64_none_none
		pc_singlestep.dyn_bgq_gcc_64_none_none
		pc_stat.dyn_bgq_gcc_64_none_none
		pc_terminate.dyn_bgq_gcc_64_none_none
		pc_terminate_stopped.dyn_bgq_gcc_64_none_none
		pc_thread.dyn_bgq_gcc_64_none_none
		pc_tls.dyn_bgq_gcc_64_none_none
	DESTINATION ${INSTALL_DIR})

ENDIF()
ENDIF()
ENDIF()
