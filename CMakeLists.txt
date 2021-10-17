#
# Logics flag
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Require cmake 3.16
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Project LOGICS
project(LOGICS LANGUAGES C CXX)
enable_testing()

# Fetch and include 
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/refs/heads/v1.10.x.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(logics logics.c)
set_target_properties(logics PROPERTIES COMPILE_FLAGS "-Wno-multichar")

add_executable(test_logics test_logics.cc logics.c)
set_target_properties(test_logics PROPERTIES COMPILE_FLAGS "-Wno-multichar -DTESTS")
target_link_libraries(test_logics gtest_main)

add_test(
  NAME unittests
  COMMAND $<TARGET_FILE:test_logics>)
