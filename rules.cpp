#include "rules.hpp"

#include <string>
#include <vector>
#include <set>

using namespace std;

const string TRIPLE_I = "III";
const string DOUBLE_U = "UU";
const string U = "U";
const string EMPTY = "";

vector<string> v_empty;

bool Rule1::canApply(string& s) {
	return s.size() > 0 && s[s.size() - 1] == 'I';
}

bool Rule2::canApply(string& s) {
	return s.size() > 0 && s[0] == 'M';
}

bool Rule3::canApply(string& s) {
	int l = s.find(TRIPLE_I);
	return l != string::npos;
}

bool Rule4::canApply(string& s) {
	int l = s.find(DOUBLE_U);
	return l != string::npos;
}

vector<string> Rule1::apply(string& s) {
	vector<string> result;
	if (this->canApply(s)) {
		result.push_back(s + 'U');
	}
	return result;
}

vector<string> Rule2::apply(string& s) {
	vector<string> result;
	if (this->canApply(s)) {
		result.push_back(s + s.substr(1, s.size() - 1));
	}
	return result;
}

void replaceRuleRunner(string& s, set<string>& v, string& oldStr, string& newStr) {
	
	set<string>::iterator it = v.find(s);
	if (it != v.end()) {
		return;
	} else {
		v.insert(s);
	}

	string cpy = s;
	int index = -1;
	while (1) {
		index = s.find(oldStr, index + 1);
		if (index == string::npos) break;
		cpy.replace(index, oldStr.size(), newStr);
		replaceRuleRunner(cpy, v, oldStr, newStr);
		cpy = s;
	}
}

vector<string> replaceRule(string& s, string oldStr, string newStr) {
	set<string> resultsSet;
	vector<string> result;
	replaceRuleRunner(s, resultsSet, oldStr, newStr);
	set<string>::iterator it;
	for (it = resultsSet.begin(); it != resultsSet.end(); it++) {
		if (*it != s) {
			result.push_back(*it);
		}
	}
	return result;
}

vector<string> Rule3::apply(string& s) {
	if (this->canApply(s)) {	
		return replaceRule(s, TRIPLE_I, U);
	}
	return v_empty;
}

vector<string> Rule4::apply(string& s) {
	if (this->canApply(s)) {
		return replaceRule(s, DOUBLE_U, EMPTY);
	}
	return v_empty;
}

