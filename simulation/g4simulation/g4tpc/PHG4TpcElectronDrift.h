// this is the new containers version
// it uses the same MapToPadPlane as the old containers version

#ifndef G4TPC_PHG4TpcELECTRONDRIFT_H
#define G4TPC_PHG4TpcELECTRONDRIFT_H

#include <fun4all/SubsysReco.h>
#include <g4main/PHG4HitContainer.h>

#include <phparameter/PHParameterInterface.h>

// rootcint barfs with this header so we need to hide it
#ifndef __CINT__
#include <gsl/gsl_rng.h>
#endif

#include <vector>

class TrkrHitSetContainer;
class TrkrHitTruthAssoc;

class PHG4TPCPadPlane;
class PHG4TPCPadPlaneReadout;
class PHCompositeNode;
class TH1;
class TNtuple;

class PHG4TpcElectronDrift : public SubsysReco, public PHParameterInterface
{
 public:
  PHG4TpcElectronDrift(const std::string &name = "PHG4TpcElectronDrift");
  virtual ~PHG4TpcElectronDrift();
  int Init(PHCompositeNode *topNode);
  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);

  void SetDefaultParameters();

  void Detector(const std::string &d) { detector = d; }
  std::string Detector() const { return detector; }
  void set_seed(const unsigned int iseed);
  //  void Amplify(const double x, const double y, const double z);
  void MapToPadPlane(const double x, const double y, const double z, PHG4HitContainer::ConstIterator hiter, TNtuple *ntpad, TNtuple *nthit);
  //void registerPadPlane(PHG4TPCPadPlaneReadout *padplane);
  void registerPadPlane(PHG4TPCPadPlane *padplane);

 private:
  TrkrHitSetContainer *hitsetcontainer;
  TrkrHitTruthAssoc *hittruthassoc;
  TH1 *dlong;
  TH1 *dtrans;
  TNtuple *nt;
  TNtuple *nthit;
  TNtuple *ntpad;
  std::string detector;
  std::string hitnodename;
  std::string cellnodename;
  std::string seggeonodename;
  unsigned int seed;
  double diffusion_trans;
  double added_smear_sigma_trans;
  double diffusion_long;
  double added_smear_sigma_long;
  double drift_velocity;
  double tpc_length;
  double electrons_per_gev;
  double min_active_radius;
  double max_active_radius;
  double min_time;
  double max_time;
  TrkrHitSetContainer *temp_hitsetcontainer;
  //PHG4TPCPadPlaneReadout *padplane;
  PHG4TPCPadPlane *padplane;

#ifndef __CINT__
  gsl_rng *RandomGenerator;
#endif
};

#endif  // G4TPC_PHG4TpcELECTRONDRIFT_H
