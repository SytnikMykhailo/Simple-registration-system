# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/my_coding_projects/Simple-registration-system/tests/build/_deps/googletest-src"
  "D:/my_coding_projects/Simple-registration-system/tests/build/_deps/googletest-build"
  "D:/my_coding_projects/Simple-registration-system/tests/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "D:/my_coding_projects/Simple-registration-system/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "D:/my_coding_projects/Simple-registration-system/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "D:/my_coding_projects/Simple-registration-system/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "D:/my_coding_projects/Simple-registration-system/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/my_coding_projects/Simple-registration-system/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/my_coding_projects/Simple-registration-system/tests/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
