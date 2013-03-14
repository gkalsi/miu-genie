#ifndef __MIU_RULE__
#define __MIU_RULE__

#include <string>
#include <vector>

class Rule {
public:
	std::vector<std::string> apply(std::string& s); 	/* Apply the current rule to the given string s */
private:
	virtual std::vector<std::string> applyImpl(std::string& s) = 0; /* Driver rule application function implemented by the derived class */
	virtual bool canApply(std::string& s) = 0;						/* Driver rule testing function implemented by the derived class */
};

#endif /* __MIU_RULE__ */
