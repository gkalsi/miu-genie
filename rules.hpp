#ifndef __MIU_RULES__
#define __MIU_RULES__

#include "rule.hpp"
#include <vector>
#include <string>

class Rule1 : public Rule {
public:
	virtual std::vector<std::string> apply(std::string& s);
private:
	bool canApply(std::string& s);
};

class Rule2 : public Rule {
public:
	virtual std::vector<std::string> apply(std::string& s);
private:
	bool canApply(std::string& s);
};

class Rule3 : public Rule {
public:
	virtual std::vector<std::string> apply(std::string& s);
private:
	bool canApply(std::string& s);
};

class Rule4 : public Rule {
public:
	virtual std::vector<std::string> apply(std::string& s);
private:
	bool canApply(std::string& s);
};

#endif /* __MIU_RULES__ */
