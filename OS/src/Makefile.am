# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 756 2006-06-26 19:43:41Z ladanyi $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign


########################################################################
#                           libOS  -- Optimization Services Library                               #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
lib_LTLIBRARIES = libOS.la

# List all source files for this library, including headers
libOS_la_SOURCES = 

# This is for libtool (on Windows)
libOS_la_LDFLAGS = $(LT_LDFLAGS)


# We want to have all the OS objects in this library
libOS_la_LIBADD = ./OSUtils/libOSUtils.la \
		./OSCommonInterfaces/libOSCommonInterfaces.la \
		./OSAgent/libOSAgent.la \
		./OSModelInterfaces/libOSModelInterfaces.la \
		./OSParsers/libOSParsers.la \
		./OSSolverInterfaces/libOSSolverInterfaces.la 
# Since automake is not doing this on its own, we need to declare the
# dependencies to the subdirectory libraries here
libOS_la_DEPENDENCIES = $(libOS_la_LIBADD)



# Now we check into which directories to recurse, and which subdirectory
# libraries to include
SUBDIRS =
  SUBDIRS += OSUtils
  SUBDIRS += OSAgent
  SUBDIRS += OSCommonInterfaces
  SUBDIRS += OSModelInterfaces
  SUBDIRS += OSParsers
  SUBDIRS += OSSolverInterfaces




########################################################################
#                    OSSolverService program                               #
########################################################################

LDADD =
ALLLDADD =
LIBS = 
OSSolverService_DEPENDENCIES =

# Name of the executable compiled in this directory.  We want it to be
# installed in the 'bin' directory
bin_PROGRAMS = OSSolverService

# List all source files for this executable, including headers
OSSolverService_SOURCES = OSSolverService.cpp 


if COIN_HAS_COUENNE
     OSSolverService_SOURCES += $(COUENNESRCDIR)/src/main/BonCouenneInfo.cpp $(COUENNESRCDIR)/src/main/BonCouenneInfo.hpp
endif


# List all additionally required COIN libraries

LDADD +=  \
	libOS.la 
	

OSSolverService_DEPENDENCIES += libOS.la

if COIN_HAS_COUENNE
   LDADD += $(COUENNEOBJDIR)/src/libCouenne.la
endif

if COIN_HAS_BONMIN
if COIN_HAS_ASL
LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonminampl.la 
endif
   LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonmin.la \
    	$(BONMINOBJDIR)/src/Interfaces/libbonmininterfaces.la 
endif


if COIN_HAS_IPOPT
if COIN_HAS_ASL
      LDADD += $(IPOPTOBJDIR)/src/Apps/AmplSolver/libamplinterface.la 
endif
  LDADD += $(IPOPTOBJDIR)/src/Interfaces/libipopt.la \
        $(IPOPTOBJDIR)/src/LinAlg/liblinalg.la
  ADDLIBS += `cat $(IPOPTOBJDIR)/src/Interfaces/ipopt_addlibs_cpp.txt`
endif

#  OSSolverService_DEPENDENCIES +=  $(IPOPTOBJDIR)/src/Interfaces/libipopt.la


LDADD +=  $(OSIOBJDIR)/src/OsiCbc/libOsiCbc.la 

if COIN_HAS_SYMPHONY
 LDADD += $(OSIOBJDIR)/src/OsiSym/libOsiSym.la 
 OSSolverService_DEPENDENCIES += $(OSIOBJDIR)/src/OsiSym/libOsiSym.la 
endif

LDADD += $(OSIOBJDIR)/src/OsiClp/libOsiClp.la 
OSSolverService_DEPENDENCIES += $(OSIOBJDIR)/src/OsiClp/libOsiClp.la 

if COIN_HAS_DYLP
 LDADD += $(OSIOBJDIR)/src/OsiDylp/libOsiDylp.la 
 OSSolverService_DEPENDENCIES += $(OSIOBJDIR)/src/OsiDylp/libOsiDylp.la 
endif

if COIN_HAS_VOL
 LDADD += $(OSIOBJDIR)/src/OsiVol/libOsiVol.la 
 OSSolverService_DEPENDENCIES += $(OSIOBJDIR)/src/OsiVol/libOsiVol.la
endif


if COIN_HAS_CPX
 LDADD += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
 OSSolverService_DEPENDENCIES += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
endif

LDADD += $(CBCOBJDIR)/src/libCbcSolver.la 
LDADD += $(CBCOBJDIR)/src/libCbc.la 
ADDLIBS += `cat $(CBCOBJDIR)/cbc_addlibs.txt`
OSSolverService_DEPENDENCIES += $(CBCOBJDIR)/src/libCbc.la

if COIN_HAS_SYMPHONY
 LDADD += $(SYMPHONYOBJDIR)/src/libSym.la 
ADDLIBS += `cat $(SYMPHONYOBJDIR)/sym_addlibs.txt`
OSSolverService_DEPENDENCIES += $(SYMPHONYOBJDIR)/src/libSym.la 
endif

 LDADD += $(CGLOBJDIR)/src/libCgl.la 
ADDLIBS += `cat $(CGLOBJDIR)/cgl_addlibs.txt`
OSSolverService_DEPENDENCIES += $(CGLOBJDIR)/src/libCgl.la 

 LDADD += $(OSIOBJDIR)/src/libOsi.la 
ADDLIBS += `cat $(OSIOBJDIR)/osi_addlibs.txt`
OSSolverService_DEPENDENCIES +=  $(OSIOBJDIR)/src/libOsi.la 

 LDADD += $(CLPOBJDIR)/src/libClp.la 
ADDLIBS += `cat $(CLPOBJDIR)/clp_addlibs.txt`
OSSolverService_DEPENDENCIES +=  $(CLPOBJDIR)/src/libClp.la 

if COIN_HAS_DYLP
 LDADD += $(DYLPOBJDIR)/src/Dylp/libDylp.la 
ADDLIBS += `cat $(DYLPOBJDIR)/dylp_addlibs.txt`
OSSolverService_DEPENDENCIES +=  $(DYLPOBJDIR)/src/Dylp/libDylp.la
endif

if COIN_HAS_VOL
 LDADD += $(VOLOBJDIR)/src/libVol.la 
ADDLIBS += `cat $(VOLOBJDIR)/vol_addlibs.txt`
OSSolverService_DEPENDENCIES +=  $(VOLOBJDIR)/src/libVol.la
endif




if COIN_HAS_GLPK
 LDADD += $(OSIOBJDIR)/src/OsiGlpk/libOsiGlpk.la
 LDADD += $(GLPKLIB)
 OSSolverService_DEPENDENCIES +=  $(OSIOBJDIR)/src/OsiGlpk/libOsiGlpk.la
  OSSolverService_DEPENDENCIES +=  $(GLPKLIB)
endif

LDADD += $(COINUTILSOBJDIR)/src/libCoinUtils.la  
ADDLIBS += `cat $(COINUTILSOBJDIR)/coinutils_addlibs.txt`



########################################################################
#                            Additional flags                          #
########################################################################


# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(COINUTILSOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(CBCSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CBCOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(CLPSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CLPOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(CGLSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CGLOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSIOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCbc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiClp` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSAgent` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSParsers` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSModelInterfaces` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSCommonInterfaces` 

# The -rpath flag is used by libtool to make sure that the shared
# library is found (in the lib install directory) when we are using dynamic
# libraries.
OSSolverService_LDFLAGS = -rpath $(libdir)

if COIN_HAS_DYLP
  AM_CPPFLAGS += \
    -I`$(CYGPATH_W) $(DYLPOBJDIR)/inc` \
    -I`$(CYGPATH_W) $(DYLPSRCDIR)/src/Dylp` \
    -I`$(CYGPATH_W) $(DYLPSRCDIR)/src/DylpStdLib` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiDylp`
endif

if COIN_HAS_SYMPHONY
  AM_CPPFLAGS += \
    -I`$(CYGPATH_W) $(SYMPHONYSRCDIR)/include` \
    -I`$(CYGPATH_W) $(SYMPHONYOBJDIR)/include` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiSym`
endif


if COIN_HAS_VOL
  AM_CPPFLAGS += \
    -I`$(CYGPATH_W) $(VOLSRCDIR)/include` \
 -I`$(CYGPATH_W) $(VOLOBJDIR)/include` \
    -I`$(CYGPATH_W) $(VOLSRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiVol`
endif



if COIN_HAS_CPX
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(CPXINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCpx`
endif




if COIN_HAS_GLPK
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(GLPKINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiGlpk`
endif

 

if COIN_HAS_LINDO
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(LINDOINCDIR)` 
  LDADD += $(LINDOLIB)
endif

if COIN_HAS_IPOPT
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(IPOPTSRCDIR)/src/Interfaces` \
	-I`$(CYGPATH_W) $(IPOPTSRCDIR)/src/LinAlg` \
	-I`$(CYGPATH_W) $(IPOPTSRCDIR)/src/Common` \
	-I`$(CYGPATH_W) $(IPOPTOBJDIR)/inc`
endif


if COIN_HAS_BONMIN
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Interfaces` \
	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Interfaces/Ampl` \
	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Interfaces/Ipopt` \
	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Interfaces/Filter` \
	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Algorithms` \
	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Algorithms/OaGenerators` \
	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Algorithms/QuadCuts` \
	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Algorithms/Ampl` \
	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Algorithms/Branching` \
	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/CbcBonmin` \
	-I`$(CYGPATH_W) $(BONMINOBJDIR)/inc`
endif


if COIN_HAS_COUENNE
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/bound_tightening` \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/branch` \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/convex` \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/disjunctive` \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/expression` \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/main` \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/problem` \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/readnl` \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/standardize` \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/util` \
	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src` \
	-I`$(CYGPATH_W) $(COUENNEOBJDIR)/inc`
endif

if COIN_HAS_KNITRO
  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(KNITROINCDIR)` 
  LDADD += $(KNITROLIB)
if USEMULTIPLYDEFINED
  OSSolverService_LDFLAGS += -multiply_defined suppress
endif
endif


if COIN_HAS_ASL
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(OSSRCDIR)/src/ThirdPartyASL` 
  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
  LDADD += $(ASLLIB) 
endif


# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

ALLLDADD += $(LDADD) 



OSSolverService_LDADD = $(ALLLDADD) $(ADDLIBS)  
########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'install/coin'
includecoindir = $(includedir)/coin
includecoin_HEADERS = \
	OSConfig.h \
	../inc/config_os.h 



#############################################################################
# Create the Config.h file that always defines HAVE_CONFIG_H and install it #
#############################################################################

# You only need to adapt the following line
ConfigHeader = OSConfig.h

install-exec-local:
	echo "#ifndef HAVE_CONFIG_H" >bla
	echo "#define HAVE_CONFIG_H" >>bla
	echo "#endif" >> bla
	cat $(srcdir)/$(ConfigHeader) >> bla
	$(install_sh_DATA) bla $(DESTDIR)$(includecoindir)/$(ConfigHeader)
	rm -f bla

uninstall-local:
	rm -f $(DESTDIR)$(includecoindir)/$(ConfigHeader)