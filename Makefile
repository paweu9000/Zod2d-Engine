# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/paweu/Projects/Engine/game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/paweu/Projects/Engine/game

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/paweu/Projects/Engine/game/CMakeFiles /home/paweu/Projects/Engine/game//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/paweu/Projects/Engine/game/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named game

# Build rule for target.
game: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 game
.PHONY : game

# fast build rule for target.
game/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/build
.PHONY : game/fast

src/api/gl_backend.o: src/api/gl_backend.cpp.o
.PHONY : src/api/gl_backend.o

# target to build an object file
src/api/gl_backend.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/api/gl_backend.cpp.o
.PHONY : src/api/gl_backend.cpp.o

src/api/gl_backend.i: src/api/gl_backend.cpp.i
.PHONY : src/api/gl_backend.i

# target to preprocess a source file
src/api/gl_backend.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/api/gl_backend.cpp.i
.PHONY : src/api/gl_backend.cpp.i

src/api/gl_backend.s: src/api/gl_backend.cpp.s
.PHONY : src/api/gl_backend.s

# target to generate assembly for a file
src/api/gl_backend.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/api/gl_backend.cpp.s
.PHONY : src/api/gl_backend.cpp.s

src/api/gl_renderer.o: src/api/gl_renderer.cpp.o
.PHONY : src/api/gl_renderer.o

# target to build an object file
src/api/gl_renderer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/api/gl_renderer.cpp.o
.PHONY : src/api/gl_renderer.cpp.o

src/api/gl_renderer.i: src/api/gl_renderer.cpp.i
.PHONY : src/api/gl_renderer.i

# target to preprocess a source file
src/api/gl_renderer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/api/gl_renderer.cpp.i
.PHONY : src/api/gl_renderer.cpp.i

src/api/gl_renderer.s: src/api/gl_renderer.cpp.s
.PHONY : src/api/gl_renderer.s

# target to generate assembly for a file
src/api/gl_renderer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/api/gl_renderer.cpp.s
.PHONY : src/api/gl_renderer.cpp.s

src/backend/backend.o: src/backend/backend.cpp.o
.PHONY : src/backend/backend.o

# target to build an object file
src/backend/backend.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/backend/backend.cpp.o
.PHONY : src/backend/backend.cpp.o

src/backend/backend.i: src/backend/backend.cpp.i
.PHONY : src/backend/backend.i

# target to preprocess a source file
src/backend/backend.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/backend/backend.cpp.i
.PHONY : src/backend/backend.cpp.i

src/backend/backend.s: src/backend/backend.cpp.s
.PHONY : src/backend/backend.s

# target to generate assembly for a file
src/backend/backend.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/backend/backend.cpp.s
.PHONY : src/backend/backend.cpp.s

src/core/asset_manager.o: src/core/asset_manager.cpp.o
.PHONY : src/core/asset_manager.o

# target to build an object file
src/core/asset_manager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/core/asset_manager.cpp.o
.PHONY : src/core/asset_manager.cpp.o

src/core/asset_manager.i: src/core/asset_manager.cpp.i
.PHONY : src/core/asset_manager.i

# target to preprocess a source file
src/core/asset_manager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/core/asset_manager.cpp.i
.PHONY : src/core/asset_manager.cpp.i

src/core/asset_manager.s: src/core/asset_manager.cpp.s
.PHONY : src/core/asset_manager.s

# target to generate assembly for a file
src/core/asset_manager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/core/asset_manager.cpp.s
.PHONY : src/core/asset_manager.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/types/shader.o: src/types/shader.cpp.o
.PHONY : src/types/shader.o

# target to build an object file
src/types/shader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/types/shader.cpp.o
.PHONY : src/types/shader.cpp.o

src/types/shader.i: src/types/shader.cpp.i
.PHONY : src/types/shader.i

# target to preprocess a source file
src/types/shader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/types/shader.cpp.i
.PHONY : src/types/shader.cpp.i

src/types/shader.s: src/types/shader.cpp.s
.PHONY : src/types/shader.s

# target to generate assembly for a file
src/types/shader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/src/types/shader.cpp.s
.PHONY : src/types/shader.cpp.s

vendor/glad/glad.o: vendor/glad/glad.c.o
.PHONY : vendor/glad/glad.o

# target to build an object file
vendor/glad/glad.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/vendor/glad/glad.c.o
.PHONY : vendor/glad/glad.c.o

vendor/glad/glad.i: vendor/glad/glad.c.i
.PHONY : vendor/glad/glad.i

# target to preprocess a source file
vendor/glad/glad.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/vendor/glad/glad.c.i
.PHONY : vendor/glad/glad.c.i

vendor/glad/glad.s: vendor/glad/glad.c.s
.PHONY : vendor/glad/glad.s

# target to generate assembly for a file
vendor/glad/glad.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/vendor/glad/glad.c.s
.PHONY : vendor/glad/glad.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... game"
	@echo "... src/api/gl_backend.o"
	@echo "... src/api/gl_backend.i"
	@echo "... src/api/gl_backend.s"
	@echo "... src/api/gl_renderer.o"
	@echo "... src/api/gl_renderer.i"
	@echo "... src/api/gl_renderer.s"
	@echo "... src/backend/backend.o"
	@echo "... src/backend/backend.i"
	@echo "... src/backend/backend.s"
	@echo "... src/core/asset_manager.o"
	@echo "... src/core/asset_manager.i"
	@echo "... src/core/asset_manager.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/types/shader.o"
	@echo "... src/types/shader.i"
	@echo "... src/types/shader.s"
	@echo "... vendor/glad/glad.o"
	@echo "... vendor/glad/glad.i"
	@echo "... vendor/glad/glad.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

