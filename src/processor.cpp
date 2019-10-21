#include "processor.h"
#include "linux_parser.h"
#include <unistd.h> // for usleep

// Return the aggregate CPU utilization
float Processor::Utilization() { 
  totalJiffiesStart = LinuxParser::Jiffies();
  activeJiffiesStart = LinuxParser::ActiveJiffies();
  
  usleep(100000); // microseconds --> 100 milliseconds
  
  totalJiffiesEnd = LinuxParser::Jiffies();
  activeJiffiesEnd = LinuxParser::ActiveJiffies();
  
  long totalDelta = totalJiffiesEnd - totalJiffiesStart;
  long activeDelta = activeJiffiesEnd - activeJiffiesStart;
  
  return float(activeDelta) / float(totalDelta); 
}