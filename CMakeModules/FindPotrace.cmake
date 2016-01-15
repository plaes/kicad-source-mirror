# - Try to find the potrace library
#  POTRACE_FOUND
#  POTRACE_LIBRARIES
#  POTRACE_INCLUDE_DIR

find_path(POTRACE_INCLUDE_DIR potracelib.h
   /usr/include
   /usr/local/include
)

find_library(POTRACE_LIBRARIES 
   NAMES  potrace libpotrace
   PATHS
   /usr/lib
   /usr/local/lib
)

include( FindPackageHandleStandardArgs )
find_package_handle_standard_args(potrace
  REQUIRED_VARS
    POTRACE_LIBRARIES
    POTRACE_INCLUDE_DIR
)