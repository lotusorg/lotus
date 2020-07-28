#!/usr/bin/env bash

scriptdir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

cd ${scriptdir}

mkdir ${scriptdir}/builddir
mkdir ${scriptdir}/bin

meson setup builddir --cross-file x86_64-elf.ini --warnlevel 3

cd builddir
ninja
