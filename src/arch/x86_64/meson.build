subdir('devices')
subdir('libk')
subdir('gdt')
subdir('interrupts')
subdir('utils')

arch_lib = static_library('arch',
                            ['arch.c'],
                            include_directories : [lotus_include],
                            link_with: [arch_x86_64_devices_lib, arch_x86_64_libk_lib, arch_x86_64_gdt_lib, arch_x86_64_interrupts_lib, arch_x86_64_utils_lib])