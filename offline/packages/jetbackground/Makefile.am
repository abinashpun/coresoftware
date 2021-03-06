AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include  \
  -I${G4_MAIN}/include \
  -I`root-config --incdir`

lib_LTLIBRARIES = \
   libjetbackground_io.la \
   libjetbackground.la

AM_CXXFLAGS = \
 -Werror

AM_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib \
  `geant4-config --libs`

libjetbackground_io_la_LIBADD = \
  -lphool

libjetbackground_la_LIBADD = \
  -lfun4all \
  -lcalo_io \
  -lcalo_util \
  -lg4jets \
  -lg4jets_io \
  -lCGAL \
  -lfastjet \
  -lfastjettools \
  -lConstituentSubtractor \
  libjetbackground_io.la

pkginclude_HEADERS = \
  DetermineTowerBackground.h \
  SubtractTowers.h \
  SubtractTowersCS.h \
  RetowerCEMC.h \
  CopyAndSubtractJets.h \
  FastJetAlgoSub.h \
  TowerBackground.h \
  TowerBackgroundv1.h

ROOTDICTS = \
  TowerBackground_Dict.cc \
  TowerBackgroundv1_Dict.cc
if MAKEROOT6
  pcmdir = $(libdir)
  nobase_dist_pcm_DATA = \
    TowerBackground_Dict_rdict.pcm \
    TowerBackgroundv1_Dict_rdict.pcm
else
  ROOT5_DICTS = \
    CopyAndSubtractJets_Dict.cc \
    DetermineTowerBackground_Dict.cc \
    FastJetAlgoSub_Dict.cc \
    RetowerCEMC_Dict.cc \
    SubtractTowers_Dict.cc \
    SubtractTowersCS_Dict.cc

endif

libjetbackground_io_la_SOURCES = \
  $(ROOTDICTS) \
  TowerBackgroundv1.cc

libjetbackground_la_SOURCES = \
  $(ROOT5_DICTS) \
  CopyAndSubtractJets.cc \
  DetermineTowerBackground.cc \
  FastJetAlgoSub.cc \
  RetowerCEMC.cc \
  SubtractTowers.cc \
  SubtractTowersCS.cc

# Rule for generating table CINT dictionaries.
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ -c $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;

################################################
# linking tests
BUILT_SOURCES = testexternals.cc

noinst_PROGRAMS = \
  testexternals_jetbackground_io \
  testexternals_jetbackground


testexternals_jetbackground_io_SOURCES = testexternals.cc
testexternals_jetbackground_io_LDADD = libjetbackground_io.la

testexternals_jetbackground_SOURCES = testexternals.cc
testexternals_jetbackground_LDADD = libjetbackground.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
