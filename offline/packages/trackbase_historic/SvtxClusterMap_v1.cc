#include "SvtxClusterMap_v1.h"

#include "SvtxCluster.h"

using namespace std;

    SvtxClusterMap_v1::SvtxClusterMap_v1()
  : _map()
{
}

SvtxClusterMap_v1::SvtxClusterMap_v1(const SvtxClusterMap_v1& clustermap)
  : _map()
{
  for (ConstIter iter = clustermap.begin();
       iter != clustermap.end();
       ++iter)
  {
    const SvtxCluster* cluster = iter->second;
    _map.insert(make_pair(cluster->get_id(), cluster->Clone()));
  }
}

SvtxClusterMap_v1& SvtxClusterMap_v1::operator=(const SvtxClusterMap_v1& clustermap)
{
  Reset();
  for (ConstIter iter = clustermap.begin();
       iter != clustermap.end();
       ++iter)
  {
    const SvtxCluster* cluster = iter->second;
    _map.insert(make_pair(cluster->get_id(), cluster->Clone()));
  }
  return *this;
}

SvtxClusterMap_v1::~SvtxClusterMap_v1()
{
  Reset();
}

void SvtxClusterMap_v1::Reset()
{
  for (Iter iter = _map.begin();
       iter != _map.end();
       ++iter)
  {
    SvtxCluster* cluster = iter->second;
    delete cluster;
  }
  _map.clear();
}

void SvtxClusterMap_v1::identify(ostream& os) const
{
  os << "SvtxClusterMap_v1: size = " << _map.size() << endl;
  return;
}

const SvtxCluster* SvtxClusterMap_v1::get(unsigned int id) const
{
  ConstIter iter = _map.find(id);
  if (iter == _map.end()) return NULL;
  return iter->second;
}

SvtxCluster* SvtxClusterMap_v1::get(unsigned int id)
{
  Iter iter = _map.find(id);
  if (iter == _map.end()) return NULL;
  return iter->second;
}

SvtxCluster* SvtxClusterMap_v1::insert(const SvtxCluster* clus)
{
  unsigned int index = 0;
  if (!_map.empty()) index = _map.rbegin()->first + 1;
  _map.insert(make_pair(index, clus->Clone()));
  _map[index]->set_id(index);
  return _map[index];
}
