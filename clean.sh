#!/usr/bin/env bash

scriptdir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

rm -rf ${scriptdir}/bin
rm -rf ${scriptdir}/builddir
rm -rf ${scriptdir}/subprojects/mlibc/
rm -rf ${scriptdir}/subprojects/frigg/
rm -rf ${scriptdir}/subprojects/cxxshim/
rm -rf ${scriptdir}/subprojects/printf/