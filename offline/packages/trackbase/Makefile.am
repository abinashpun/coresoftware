##############################################
# please add new classes in alphabetical order

AUTOMAKE_OPTIONS = foreign

# list of shared libraries to produce
lib_LTLIBRARIES = \
  libtrack_io.la

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include  \
  -I$(ROOTSYS)/include \
  -I$(OPT_SPHENIX)/include

AM_LDFLAGS = \
  -L$(libdir) \
  -L$(ROOTSYS)/lib \
  -L$(OFFLINE_MAIN)/lib

pkginclude_HEADERS = \
  TrkrCluster.h \
  TrkrClusterv1.h \
  TrkrClusterContainer.h \
  TrkrClusterHitAssoc.h \
  TrkrDefs.h \
  TrkrHit.h \
  TrkrHitCellAssoc.h \
  TrkrHitTruthAssoc.h \
  TrkrHitSet.h \
  TrkrHitSetContainer.h \
  TrkrTrack.h \
  TrkrTrackContainer.h

ROOTDICTS = \
  TrkrCluster_Dict.cc \
  TrkrClusterv1_Dict.cc \
  TrkrClusterContainer_Dict.cc \
  TrkrClusterHitAssoc_Dict.cc \
  TrkrHit_Dict.cc \
  TrkrHitTruthAssoc_Dict.cc \
  TrkrHitCellAssoc_Dict.cc \
  TrkrHitSet_Dict.cc \
  TrkrHitSetContainer_Dict.cc \
  TrkrTrack_Dict.cc \
  TrkrTrackContainer_Dict.cc

if MAKEROOT6
  pcmdir = $(libdir)
  nobase_dist_pcm_DATA = \
    TrkrCluster_Dict_rdict.pcm \
    TrkrClusterv1_Dict_rdict.pcm \
    TrkrClusterContainer_Dict_rdict.pcm \
    TrkrClusterHitAssoc_Dict_rdict.pcm \
    TrkrHit_Dict_rdict.pcm \
    TrkrHitTruthAssoc_Dict_rdict.pcm \
    TrkrHitCellAssoc_Dict_rdict.pcm \
    TrkrHitSet_Dict_rdict.pcm \
    TrkrHitSetContainer_Dict_rdict.pcm \
    TrkrTrack_Dict_rdict.pcm \
    TrkrTrackContainer_Dict_rdict.pcm
else
  ROOT5_IO_DICTS = \
    TrkrDefs_Dict.cc
endif

# sources for io library
libtrack_io_la_SOURCES = \
  $(ROOTDICTS) \
  $(ROOT5_IO_DICTS) \
  TrkrClusterv1.cc \
  TrkrClusterContainer.cc \
  TrkrClusterHitAssoc.cc \
  TrkrDefs.cc \
  TrkrHitCellAssoc.cc \
  TrkrHitTruthAssoc.cc \
  TrkrHit.cc \
  TrkrHitSet.cc \
  TrkrHitSetContainer.cc

libtrack_io_la_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib

libtrack_io_la_LIBADD = \
  -lphool


# Rule for generating table CINT dictionaries.
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@  -c $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;

################################################
# linking tests

BUILT_SOURCES = testexternals.cc

noinst_PROGRAMS = \
  testexternals_track_io

#testexternals_track_util_SOURCES = testexternals.cc
#testexternals_track_util_LDADD = libtrack_util.la

testexternals_track_io_SOURCES = testexternals.cc
testexternals_track_io_LDADD = libtrack_io.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

################################################

clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
