#include <string>

#include "format.h"

using std::string;
using std::to_string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) { 
  int ss, mm, hh;
  
  // Compute hours
  hh = seconds / 3600;
  // Compute minutes
  seconds = seconds % 3600;
  mm = seconds / 60;  
  // Compute seconds
  ss = seconds % 60;
  
  return to_string(hh) + ":" + to_string(mm) + ":" + to_string(ss); 
}