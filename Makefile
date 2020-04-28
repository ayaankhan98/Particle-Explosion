# makefile for particle fire explosion

#----------------------------------------------------------------
#----------------------------------------------------------------
#----------------------------------------------------------------

# Compiling C++ programs with g++
# -------------------------------

# The base command for the Gnu C compiler is "gcc"
# The base command for the Gnu C++ compiler is "g++"

# Single File Programs
# --------------------

# To compile a program that is in a single file, the easiest compilation
# uses the command format:

#    g++ <filename>

# (where the filename ends with ".cpp").

# Example:
# 	g++ prog1.cpp

# This command will create an executable program called "a.out" (the default
# executable target name when one is not specified).

# ---------------------------------------------------------

# Multiple File Programs
# ----------------------

# To invoke the Compile stage, which translates source code (.cpp files)
# into object code (.o files), use the -c flag.  Format:

#   g++ -c <filename>

# When the -c option is NOT used, the compiler will expect the command to 
# give everything necessary to compile AND link -- to make the executable.

# To name a target (something other than the default filename, use the -o flag.  
# Format:

#   g++ -o <target_name> <remainder of command>

# A few examples:

#   g++ -o yadda.o -c fraction.cpp

# This command invokes just the compile stage on fraction.cpp, but names the 
# object code file "yadda.o" (instead of the default "fraction.o").

#   g++ -o bob.exe circle.o main.o

# This command links the two object code files ("circle.o" and "main.o") 
# into an executable, called "bob.exe" (instead of the default "a.out").

#   g++ -o myProgram thing.cpp main.cpp

# This command compiles and links (since -c not used) the code files 
# "thing.cpp" and "main.cpp" together into the executable program called 
# "myProgram".

# There are other command formats, flags,  and shortcuts, which are not
# listed here.  The above commands are sufficient for basic compilation
# needs.
# ---------------------------------------------------------------------

# Example:
# --------

# The following example is the step by step compilation of the files for
# the fraction class example.

#   To compile the cpp files into object code:
# 					g++ -c frac.cpp
# 					g++ -c main.cpp

#   Now, the object code files frac.o and main.o have been created.

#   To link the object code:		g++ -o frac frac.o main.o

#   This creates the executable "frac"

#   run the program:			frac

#--------------------------------------------------------------------------
#--------------------------------------------------------------------------
#--------------------------------------------------------------------------

# Makefiles
# ---------

# The unix system has what is called a "make" utility.  This allows the
# building of a configuration file to assist in compilation.  Once the
# correct commands are placed in the makefile, the program can be rebuilt at
# any time with the command:   "make".

# There are many flags and parameters that can be used in makefiles, but
# here we will just present the basic format of the makefile.

# First, the filename itself should be either "makefile" or "Makefile".

# The makefile consists of sections, each of which specifies how to make a
# specific target.  This target file is usually the name of an executable
# program or an object code file.  The basic format of a section is:

# <target_name>:  <dependency list>
# 	<commands>

# The target name is a label that specifies what target this section is to
# make.

# The dependency list is used to help the make utility decide whether or not
# the target needs rebuilding.  Specifically, the entire first line of a
# section is saying "If anything in the dependency list has CHANGED since
# the last build, rebuild this target".

# The <commands> part refers to the actual unix commands that are to be
# executed if this section needs rebuilding.  This can consist of multiple
# commands (one per line), and each command must be preceded by a single
# "tab" character.

# Any line that starts with a # character is a comment.
# -------------------------------------------------------------------------

# Sample makefile:
# ----------------

# # This is a comment line
# # Sample makefile for fraction class

# frac: main.o frac.o
# 	g++ -o frac main.o frac.o

# main.o: main.cpp frac.h
# 	g++ -c main.cpp

# frac.o: frac.cpp frac.h
# 	g++ -c frac.cpp

# clean:
# 	rm *.o frac

# --------------------------------------------------------------------------
# The first section specifies "frac" as the target, and it depends on main.o
# and frac.o.  If either of these files changed since the last build, then
# "frac" must be rebuilt.  The command is the linking command for linking
# these two object code files together into a target executable called 
# "frac":
# 	g++ -o frac main.o frac.o

# The next section specifies how to built the target "main.o".  This depends
# on main.cpp and frac.h (if either file changes, main.o must be rebuilt).
# Similarly, the next section does the same for the target "frac.o".  The
# commands for these sections are the normal g++ commands for the compile
# stage (i.e. compile source code into object code):
# 	g++ -c main.cpp
# 	g++ -c frac.cpp

# Any section can be invoked specifically with the command:
# 	make <target_name>

# For instance, to build only the "frac.o" target, use:
# 	make frac.o

# When the make command is used by itself, the utility attempts to make the
# FIRST target listed in the makefile -- this is why we list the executable
# program, "frac", first.  So, using this makefile, the following two
# commands are equivalent:

# 	make frac
# 	make

# --------------------------------

# The last section is a special line, being used to clean up files in the
# directory, rather than build anything.  The target name is "clean", and
# the command is the remove command ("rm").  This target will remove the
# object code files and the executable from the current directory.  This
# part of the makefile is invoked with the command:

# 	make clean

#--------------------------------------------------------------------------
#--------------------------------------------------------------------------
#--------------------------------------------------------------------------


run: main.o screen.o
	g++ -o run screen.o main.o -lSDL2

main.o: main.cpp screen.h
	g++ -c main.cpp

screen.o: screen.cpp
	g++ -c screen.cpp -lSDl2

clean:
	rm *.o run
