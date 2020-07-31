#include this directory as a system header
add_project_arguments(   '-isystem' + join_paths(meson.source_root(), meson.current_source_dir()),
                        language : ['c', 'cpp'])

subdir('stdlib')

libc_lib = static_library('libc',
                            link_with: libc_stdlib_lib)