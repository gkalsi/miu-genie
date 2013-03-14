#include "rules.hpp"

#include <string>
#include <vector>
#include <set>

using namespace std;

/* Some string constants inherent to the puzzle */
const string TRIPLE_I = "III";
const string DOUBLE_U = "UU";
const string U = "U";
const string EMPTY = "";

vector<string> v_empty;

/* Rule 1: If the last character of a string is I */
bool Rule1::canApply(string& s) {
	return s.size() > 0 && s[s.size() - 1] == 'I';
}

/* Rule 2: If the first character of a string is M */
bool Rule2::canApply(string& s) {
	return s.size() > 0 && s[0] == 'M';
}

/* Rule 3: If the string has any 3 consecutive Is */
bool Rule3::canApply(string& s) {
	int l = s.find(TRIPLE_I);
	return l != string::npos;
}

/* Rule 4: If the string has any 2 consecutive Us */
bool Rule4::canApply(string& s) {
	int l = s.find(DOUBLE_U);
	return l != string::npos;
}


/*
 * NOTE: To invoke this function, call vector<string> replaceRunner(...) instead. 
 *       This function is a recursive implementation function that should not be called directly.
 * This function will populate the set v will all the possible replacements from oldStr to newStr.
 */
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

/* 
 * Return a vector with the set of all strings where occurrances of oldStr have been replaced with newStr. 
 * For example for the string MIIIIU called with III as oldStr, and X as new str, this function would return
 * the following:
 * MXIU
 * MIXU
 */
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

/* Add a U to the end of a string */
vector<string> Rule1::applyImpl(string& s) {
	vector<string> result;
	result.push_back(s + 'U');
	return result;
}

/* Repeat the entire string excluding the first character */
vector<string> Rule2::applyImpl(string& s) {
	vector<string> result;
	result.push_back(s + s.substr(1, s.size() - 1));
	return result;
}

/* Replace groups of three Is with a single U */
vector<string> Rule3::applyImpl(string& s) {
	return replaceRule(s, TRIPLE_I, U);
}

/* Replace two Us with the empty string */
vector<string> Rule4::applyImpl(string& s) {
	return replaceRule(s, DOUBLE_U, EMPTY);
}

