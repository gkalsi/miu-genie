#ifndef __MIU_RULES__
#define __MIU_RULES__

#include "rule.hpp"
#include <vector>
#include <string>

/* Rule 1
 * If the last letter of a string is I you may add a U to the end 
 */
class Rule1 : public Rule {
public:
	virtual std::vector<std::string> applyImpl(std::string& s);
private:
	bool canApply(std::string& s);
};

/* Rule 2
 * If a string is of the form Mx (where x is an arbitrary string), you may replace the string with Mxx
 */
class Rule2 : public Rule {
public:
	virtual std::vector<std::string> applyImpl(std::string& s);
private:
	bool canApply(std::string& s);
};

/* Rule 3
 * If a string has three consecutive I characters (III) you may replace them with U
 */
class Rule3 : public Rule {
public:
	virtual std::vector<std::string> applyImpl(std::string& s);
private:
	bool canApply(std::string& s);
};


/* Rule 4
 * If a string has two consecutive U characters (UU) you may remove them from the string
 */
class Rule4 : public Rule {
public:
	virtual std::vector<std::string> applyImpl(std::string& s);
private:
	bool canApply(std::string& s);
};

#endif /* __MIU_RULES__ */
