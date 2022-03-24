
#ifndef NOT_FOUND_EXCEP_
#define NOT_FOUND_EXCEP_

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error
{
public:
	NotFoundException(const std::string& message = "");
}; // end PrecondViolatedExcep 
#endif
