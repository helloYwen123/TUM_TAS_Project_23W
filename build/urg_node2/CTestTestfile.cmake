# CMake generated Testfile for 
# Source directory: /home/group_c/tas2-software/src/urg_node2
# Build directory: /home/group_c/tas2-software/build/urg_node2
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(urg_node2_test "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/group_c/tas2-software/build/urg_node2/test_results/urg_node2/urg_node2_test.gtest.xml" "--package-name" "urg_node2" "--output-file" "/home/group_c/tas2-software/build/urg_node2/ament_cmake_gtest/urg_node2_test.txt" "--command" "/home/group_c/tas2-software/build/urg_node2/urg_node2_test" "--gtest_output=xml:/home/group_c/tas2-software/build/urg_node2/test_results/urg_node2/urg_node2_test.gtest.xml")
set_tests_properties(urg_node2_test PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/group_c/tas2-software/build/urg_node2/urg_node2_test" TIMEOUT "200" WORKING_DIRECTORY "/home/group_c/tas2-software/build/urg_node2" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/group_c/tas2-software/src/urg_node2/CMakeLists.txt;64;ament_add_gtest;/home/group_c/tas2-software/src/urg_node2/CMakeLists.txt;0;")
subdirs("gtest")
