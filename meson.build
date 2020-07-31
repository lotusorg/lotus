project('lotus', 
        'c')

add_project_arguments(  '-pedantic',
                        '-mno-sse',
                        '-mno-sse2',
                        '-mno-mmx',
                        '-mno-80387',
                        '-mno-red-zone',
                        '-DDEBUG=1',
                        language : 'c')

#mlibc_dep =  dependency('mlibc',
#                        default_options : ['static=true', 'headers_only=false'],
#                        fallback : ['mlibc', 'mlibc_ansic_dep'],
#                        include_type : 'system')

printf_dep = dependency('printf', fallback : ['printf', 'printf_dep'])

subdir('src')

lotus_dep = declare_dependency(include_directories: [lotus_include])