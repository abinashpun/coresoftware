AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libphool.la

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include \
  -I`root-config --incdir`

libphool_la_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib \
  `root-config --libs` \
  -lEvent

ROOTDICTS = \
  PHObject_Dict.cc \
  PHTimeStamp_Dict.cc

if MAKEROOT6
pcmdir = $(libdir)
nobase_dist_pcm_DATA = \
  PHObject_Dict_rdict.pcm \
  PHTimeStamp_Dict_rdict.pcm

else
ROOT5DICTS = \
  PHMessage_Dict.cc \
  PHRandomSeed_Dict.cc \
  PHFlag_Dict.cc \
  PHTimeServer_Dict.cc \
  recoConsts_Dict.cc
endif

libphool_la_SOURCES = \
  $(ROOT5DICTS) \
  $(ROOTDICTS) \
  PHCompositeNode.cc \
  PHFlag.cc \
  PHIOManager.cc \
  PHMessage.cc \
  PHNode.cc \
  PHNodeIOManager.cc \
  PHNodeIntegrate.cc \
  PHNodeIterator.cc \
  PHNodeReset.cc \
  PHObject.cc \
  PHOperation.cc \
  PHRandomSeed.cc \
  PHRawOManager.cc \
  PHTimer.cc \
  PHTimeServer.cc \
  PHTimeStamp.cc \
  recoConsts.cc

pkginclude_HEADERS =  \
  getClass.h \
  PHCompositeNode.h \
  PHDataNode.h \
  PHDataNodeIterator.h \
  PHFlag.h \
  PHIODataNode.h \
  PHIOManager.h \
  PHNode.h \
  PHNodeIOManager.h \
  PHNodeIntegrate.h \
  PHNodeOperation.h \
  PHNodeReset.h \
  PHNodeIterator.h \
  PHObject.h \
  phool.h \
  phooldefs.h \
  PHOperation.h \
  PHRandomSeed.h \
  PHPointerList.h \
  PHPointerListIterator.h \
  PHRawOManager.h \
  PHTimer.h \
  PHTimeServer.h \
  PHTimeStamp.h \
  PHTypedNodeIterator.h \
  recoConsts.h

noinst_PROGRAMS = \
  testexternals

BUILT_SOURCES = \
  testexternals.cc

testexternals_SOURCES = testexternals.cc

testexternals_LDADD = \
  libphool.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ -c $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;

clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
