libk_srcs = ['panic.c', 'kprintf.c']

libk_lib = static_library('libk',
                            libk_srcs,
                            include_directories : lotus_include,
                            dependencies : [printf_dep])