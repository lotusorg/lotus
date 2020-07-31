lotus_include = include_directories('.')

subdir('libc')
subdir('mm')
subdir('libk')
subdir('arch')
subdir('utils')

lotus_elf = executable('lotus',
                        ['kernel.c'],
                        include_directories: [lotus_include],
                        c_args : ['-mcmodel=kernel', '-ffreestanding'],
                        link_with: [libc_lib, mm_lib, libk_lib, arch_lib, utils_lib],
                        link_args : ['-T' + meson.current_source_dir() + '/linker.ld', '-nostdlib', '-Wl,-z,max-page-size=0x1000'],
                        link_depends : [meson.current_source_dir() + '/linker.ld'],)