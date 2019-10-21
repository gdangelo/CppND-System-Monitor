#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// Constructor 
Process::Process(int pid) {
  Process::pid_ = pid;
}

// Return this process's ID
int Process::Pid() { return pid_; }

// Return this process's CPU utilization
float Process::CpuUtilization() { 
  long upTimeStart = LinuxParser::UpTime(pid_);
  long activeJiffiesStart = LinuxParser::ActiveJiffies(pid_);
  
  usleep(100000); // microseconds --> 100 milliseconds
  
  long upTimeEnd = LinuxParser::UpTime(pid_);
  long activeJiffiesEnd = LinuxParser::ActiveJiffies(pid_);
  
  long upTimeDelta = upTimeEnd - upTimeStart;
  long activeDelta = activeJiffiesEnd - activeJiffiesStart;
  
  if (upTimeDelta == 0) {
    return 0.0;
  }
  
  return float(activeDelta) / float(upTimeDelta); 
}

// Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a[[maybe_unused]]) const { return true; }