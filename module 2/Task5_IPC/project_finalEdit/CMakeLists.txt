cmake_minimum_required(VERSION 3.10)
project(project)

# Add subdirectories for fh and requester
add_subdirectory(file_handler)
add_subdirectory(request)
add_subdirectory(logger)
add_subdirectory(test_fh)
add_subdirectory(test_req)
