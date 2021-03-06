#ifndef G4HISTOS_G4SNGLTREE_H
#define G4HISTOS_G4SNGLTREE_H

#include "G4EvtTree.h"

#include <g4main/PHG4HitContainer.h>

#include <fun4all/SubsysReco.h>

#include <map>
#include <set>
#include <string>
#include <vector>

// Forward declerations
class Fun4AllHistoManager;
class PHCompositeNode;
class TFile;
class TH1;
class TH2;
class TTree;
class TNtuple;

class G4SnglTree : public SubsysReco
{
 public:
  //! constructor
  G4SnglTree(const std::string &name = "G4SnglTree", const std::string &filename = "G4SnglTree.root");

  //! destructor
  virtual ~G4SnglTree() {}

  //! full initialization
  int Init(PHCompositeNode *);

  //! event processing method
  int process_event(PHCompositeNode *);

  //! hit processing method
  int process_hit(PHG4HitContainer *hits, const std::string &dName, int detid, int &nhits);

  //! end of run method
  int End(PHCompositeNode *);

  void AddNode(const std::string &name, const int detid = 0);

 protected:
  int nblocks;
  //  std::vector<TH2 *> nhit_edep;
  std::string _filename;
  std::set<std::string> _node_postfix;
  std::map<std::string, int> _detid;

  TTree *g4tree;
  G4EvtTree mG4EvtTree;
  TFile *outfile;
};

#endif
