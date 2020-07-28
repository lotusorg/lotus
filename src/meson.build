lotus_include = include_directories('.')

subdir('mm')
subdir('libk')
subdir('arch')

lotus_elf = executable('lotus',
                        ['kernel.c'],
                        c_args : ['-mcmodel=kernel', '-ffreestanding'],
                        link_with: [mm_lib, libk_lib, arch_lib],
                        link_args : ['-T' + meson.current_source_dir() + '/linker.ld', '-nostdlib', '-Wl,-z,max-page-size=0x1000'],
                        link_depends : [meson.current_source_dir() + '/linker.ld'],)