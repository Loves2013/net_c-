# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /github

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /github/build

# Include any dependencies generated for this target.
include CMakeFiles/net_c-.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/net_c-.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/net_c-.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/net_c-.dir/flags.make

CMakeFiles/net_c-.dir/Channel.o: CMakeFiles/net_c-.dir/flags.make
CMakeFiles/net_c-.dir/Channel.o: /github/Channel.cpp
CMakeFiles/net_c-.dir/Channel.o: CMakeFiles/net_c-.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/github/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/net_c-.dir/Channel.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/net_c-.dir/Channel.o -MF CMakeFiles/net_c-.dir/Channel.o.d -o CMakeFiles/net_c-.dir/Channel.o -c /github/Channel.cpp

CMakeFiles/net_c-.dir/Channel.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/net_c-.dir/Channel.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /github/Channel.cpp > CMakeFiles/net_c-.dir/Channel.i

CMakeFiles/net_c-.dir/Channel.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/net_c-.dir/Channel.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /github/Channel.cpp -o CMakeFiles/net_c-.dir/Channel.s

CMakeFiles/net_c-.dir/DefaultPoller.o: CMakeFiles/net_c-.dir/flags.make
CMakeFiles/net_c-.dir/DefaultPoller.o: /github/DefaultPoller.cpp
CMakeFiles/net_c-.dir/DefaultPoller.o: CMakeFiles/net_c-.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/github/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/net_c-.dir/DefaultPoller.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/net_c-.dir/DefaultPoller.o -MF CMakeFiles/net_c-.dir/DefaultPoller.o.d -o CMakeFiles/net_c-.dir/DefaultPoller.o -c /github/DefaultPoller.cpp

CMakeFiles/net_c-.dir/DefaultPoller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/net_c-.dir/DefaultPoller.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /github/DefaultPoller.cpp > CMakeFiles/net_c-.dir/DefaultPoller.i

CMakeFiles/net_c-.dir/DefaultPoller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/net_c-.dir/DefaultPoller.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /github/DefaultPoller.cpp -o CMakeFiles/net_c-.dir/DefaultPoller.s

CMakeFiles/net_c-.dir/EPollPoller.o: CMakeFiles/net_c-.dir/flags.make
CMakeFiles/net_c-.dir/EPollPoller.o: /github/EPollPoller.cpp
CMakeFiles/net_c-.dir/EPollPoller.o: CMakeFiles/net_c-.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/github/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/net_c-.dir/EPollPoller.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/net_c-.dir/EPollPoller.o -MF CMakeFiles/net_c-.dir/EPollPoller.o.d -o CMakeFiles/net_c-.dir/EPollPoller.o -c /github/EPollPoller.cpp

CMakeFiles/net_c-.dir/EPollPoller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/net_c-.dir/EPollPoller.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /github/EPollPoller.cpp > CMakeFiles/net_c-.dir/EPollPoller.i

CMakeFiles/net_c-.dir/EPollPoller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/net_c-.dir/EPollPoller.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /github/EPollPoller.cpp -o CMakeFiles/net_c-.dir/EPollPoller.s

CMakeFiles/net_c-.dir/EventLoop.o: CMakeFiles/net_c-.dir/flags.make
CMakeFiles/net_c-.dir/EventLoop.o: /github/EventLoop.cpp
CMakeFiles/net_c-.dir/EventLoop.o: CMakeFiles/net_c-.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/github/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/net_c-.dir/EventLoop.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/net_c-.dir/EventLoop.o -MF CMakeFiles/net_c-.dir/EventLoop.o.d -o CMakeFiles/net_c-.dir/EventLoop.o -c /github/EventLoop.cpp

CMakeFiles/net_c-.dir/EventLoop.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/net_c-.dir/EventLoop.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /github/EventLoop.cpp > CMakeFiles/net_c-.dir/EventLoop.i

CMakeFiles/net_c-.dir/EventLoop.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/net_c-.dir/EventLoop.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /github/EventLoop.cpp -o CMakeFiles/net_c-.dir/EventLoop.s

CMakeFiles/net_c-.dir/InteAddress.o: CMakeFiles/net_c-.dir/flags.make
CMakeFiles/net_c-.dir/InteAddress.o: /github/InteAddress.cpp
CMakeFiles/net_c-.dir/InteAddress.o: CMakeFiles/net_c-.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/github/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/net_c-.dir/InteAddress.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/net_c-.dir/InteAddress.o -MF CMakeFiles/net_c-.dir/InteAddress.o.d -o CMakeFiles/net_c-.dir/InteAddress.o -c /github/InteAddress.cpp

CMakeFiles/net_c-.dir/InteAddress.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/net_c-.dir/InteAddress.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /github/InteAddress.cpp > CMakeFiles/net_c-.dir/InteAddress.i

CMakeFiles/net_c-.dir/InteAddress.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/net_c-.dir/InteAddress.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /github/InteAddress.cpp -o CMakeFiles/net_c-.dir/InteAddress.s

CMakeFiles/net_c-.dir/Logger.o: CMakeFiles/net_c-.dir/flags.make
CMakeFiles/net_c-.dir/Logger.o: /github/Logger.cpp
CMakeFiles/net_c-.dir/Logger.o: CMakeFiles/net_c-.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/github/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/net_c-.dir/Logger.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/net_c-.dir/Logger.o -MF CMakeFiles/net_c-.dir/Logger.o.d -o CMakeFiles/net_c-.dir/Logger.o -c /github/Logger.cpp

CMakeFiles/net_c-.dir/Logger.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/net_c-.dir/Logger.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /github/Logger.cpp > CMakeFiles/net_c-.dir/Logger.i

CMakeFiles/net_c-.dir/Logger.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/net_c-.dir/Logger.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /github/Logger.cpp -o CMakeFiles/net_c-.dir/Logger.s

CMakeFiles/net_c-.dir/Poller.o: CMakeFiles/net_c-.dir/flags.make
CMakeFiles/net_c-.dir/Poller.o: /github/Poller.cpp
CMakeFiles/net_c-.dir/Poller.o: CMakeFiles/net_c-.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/github/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/net_c-.dir/Poller.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/net_c-.dir/Poller.o -MF CMakeFiles/net_c-.dir/Poller.o.d -o CMakeFiles/net_c-.dir/Poller.o -c /github/Poller.cpp

CMakeFiles/net_c-.dir/Poller.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/net_c-.dir/Poller.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /github/Poller.cpp > CMakeFiles/net_c-.dir/Poller.i

CMakeFiles/net_c-.dir/Poller.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/net_c-.dir/Poller.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /github/Poller.cpp -o CMakeFiles/net_c-.dir/Poller.s

CMakeFiles/net_c-.dir/TcpServer.o: CMakeFiles/net_c-.dir/flags.make
CMakeFiles/net_c-.dir/TcpServer.o: /github/TcpServer.cpp
CMakeFiles/net_c-.dir/TcpServer.o: CMakeFiles/net_c-.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/github/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/net_c-.dir/TcpServer.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/net_c-.dir/TcpServer.o -MF CMakeFiles/net_c-.dir/TcpServer.o.d -o CMakeFiles/net_c-.dir/TcpServer.o -c /github/TcpServer.cpp

CMakeFiles/net_c-.dir/TcpServer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/net_c-.dir/TcpServer.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /github/TcpServer.cpp > CMakeFiles/net_c-.dir/TcpServer.i

CMakeFiles/net_c-.dir/TcpServer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/net_c-.dir/TcpServer.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /github/TcpServer.cpp -o CMakeFiles/net_c-.dir/TcpServer.s

CMakeFiles/net_c-.dir/Timestamp.o: CMakeFiles/net_c-.dir/flags.make
CMakeFiles/net_c-.dir/Timestamp.o: /github/Timestamp.cpp
CMakeFiles/net_c-.dir/Timestamp.o: CMakeFiles/net_c-.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/github/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/net_c-.dir/Timestamp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/net_c-.dir/Timestamp.o -MF CMakeFiles/net_c-.dir/Timestamp.o.d -o CMakeFiles/net_c-.dir/Timestamp.o -c /github/Timestamp.cpp

CMakeFiles/net_c-.dir/Timestamp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/net_c-.dir/Timestamp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /github/Timestamp.cpp > CMakeFiles/net_c-.dir/Timestamp.i

CMakeFiles/net_c-.dir/Timestamp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/net_c-.dir/Timestamp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /github/Timestamp.cpp -o CMakeFiles/net_c-.dir/Timestamp.s

# Object files for target net_c-
net_c___OBJECTS = \
"CMakeFiles/net_c-.dir/Channel.o" \
"CMakeFiles/net_c-.dir/DefaultPoller.o" \
"CMakeFiles/net_c-.dir/EPollPoller.o" \
"CMakeFiles/net_c-.dir/EventLoop.o" \
"CMakeFiles/net_c-.dir/InteAddress.o" \
"CMakeFiles/net_c-.dir/Logger.o" \
"CMakeFiles/net_c-.dir/Poller.o" \
"CMakeFiles/net_c-.dir/TcpServer.o" \
"CMakeFiles/net_c-.dir/Timestamp.o"

# External object files for target net_c-
net_c___EXTERNAL_OBJECTS =

libnet_c-.so: CMakeFiles/net_c-.dir/Channel.o
libnet_c-.so: CMakeFiles/net_c-.dir/DefaultPoller.o
libnet_c-.so: CMakeFiles/net_c-.dir/EPollPoller.o
libnet_c-.so: CMakeFiles/net_c-.dir/EventLoop.o
libnet_c-.so: CMakeFiles/net_c-.dir/InteAddress.o
libnet_c-.so: CMakeFiles/net_c-.dir/Logger.o
libnet_c-.so: CMakeFiles/net_c-.dir/Poller.o
libnet_c-.so: CMakeFiles/net_c-.dir/TcpServer.o
libnet_c-.so: CMakeFiles/net_c-.dir/Timestamp.o
libnet_c-.so: CMakeFiles/net_c-.dir/build.make
libnet_c-.so: CMakeFiles/net_c-.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/github/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library libnet_c-.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/net_c-.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/net_c-.dir/build: libnet_c-.so
.PHONY : CMakeFiles/net_c-.dir/build

CMakeFiles/net_c-.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/net_c-.dir/cmake_clean.cmake
.PHONY : CMakeFiles/net_c-.dir/clean

CMakeFiles/net_c-.dir/depend:
	cd /github/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /github /github /github/build /github/build /github/build/CMakeFiles/net_c-.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/net_c-.dir/depend

