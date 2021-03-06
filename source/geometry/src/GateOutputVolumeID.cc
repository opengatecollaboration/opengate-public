/*----------------------
   GATE version name: gate_v6

   Copyright (C): OpenGATE Collaboration

This software is distributed under the terms
of the GNU Lesser General  Public Licence (LGPL)
See GATE/LICENSE.txt for further details
----------------------*/


#include "GateOutputVolumeID.hh"

#include <iomanip>



// Friend function: inserts (prints) a GateOutputVolumeID into a stream
std::ostream& operator<<(std::ostream& flux, const GateOutputVolumeID& volumeID)    
{
  int w = flux.width();
  for (size_t i=0; i<volumeID.size(); ++i)
      flux << std::setw(w) << volumeID[i] << " ";
  
  return flux;
}




// Check whether the ID is valid, i.e. not empty and with no negative element
G4bool GateOutputVolumeID::IsValid() const
{ 
  if (empty())
    return false;
  for (const_iterator iter=begin(); iter!=end(); ++iter)
    if ((*iter)<0)
      return false;
  return true;
}




// Extract the topmost elements of the ID, down to the level 'depth'
// Returns an ID with (depth+1) elements
GateOutputVolumeID GateOutputVolumeID::Top(size_t maxDepth) const
{
  GateOutputVolumeID topID(maxDepth+1);
  for (size_t depth=0; depth<=maxDepth; ++depth)
    topID[depth] = (*this)[depth];
  return topID;
}

