#ifndef __MIU_RULE__
#define __MIU_RULE__

#include <string>
#include <vector>

class Rule {
public:
	virtual std::vector<std::string> apply(std::string& s) = 0;
};

#endif /* __MIU_RULE__ */
