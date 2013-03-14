#include "rule.hpp"
#include <vector>
#include <string>

using namespace std;

/* Wrapper for rule application, test whether or not a rule is applicable.
 * Apply the rule if it is or return an empty vector if it is not 
 */
vector<string> Rule::apply(string& s) {
	vector<string> empty;
	if (!this->canApply(s)) {
		return empty;
	} 
	return this->applyImpl(s);
}
