#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cstdlib>
#include <queue>
#include <map>

#include "rules.hpp"

using namespace std;

/* Do not produce any strings in MIU longer than this */
const int MAX_STRING_LENGTH = 20;

/* Create a list of rules */
vector<Rule*> initRules() {
	vector<Rule*> rules;
	
	rules.push_back(new Rule1);
	rules.push_back(new Rule2);
	rules.push_back(new Rule3);
	rules.push_back(new Rule4);

	return rules;
}

/* Free memory associated with rules */
void cleanupRules(vector<Rule*>& rules) {
	for (int i = 0; i < rules.size(); i++) {
		delete rules[i];
	}
}

/* Attempt to produce a solution by constructing a tree or aguments
 * to get from source to target in the MIU system 
 */
bool runMIU (string source, string target) {
	
	string start = source;
	vector<Rule*> rules = initRules(); /* A list of the possible rules that we can apply */
	map<string, string> nearestParent; /* Used to avoid duplication and to reconstruct the path */
	map<string, int>    axiom;		   /* determine what step we took to get to a particular state */
	queue<string> waiting;		       /* A queue of states that we have yet to visit */

	/* Apply rules until we have reached our destination */
	while (source != target) {

		/* Try applying each */
		for(int i = 0; i < rules.size(); i++) {
			
			/* Will return a list of strings transformed by rule i.
			   can return an empty vector if rule i is not applicable */
			vector<string> applied = rules[i]->apply(source);
			
			/* Add each processed string to the queue of strings that need to be processed */
			for (int j = 0; j < applied.size(); j++) {
				map<string, string>::iterator it = nearestParent.find(applied[j]);	/* Avoid duplicates */
				if (it == nearestParent.end() && applied[j].size() < MAX_STRING_LENGTH) {
					nearestParent[applied[j]] = source;
					axiom[applied[j]] = i;
					waiting.push(applied[j]);
				}
			}
		}
		if (waiting.empty()) {
			cleanupRules(rules);
			return false; 		/* No more elements to process, we were unable to find a path */
		}
		
		/* Obtain the next string to test */
		source = waiting.front();
		waiting.pop();
	}

	/* Reconstruct the path */
	vector<string> path;
	while (source != start) {
		path.push_back(source);
		source = nearestParent[source];
	}
	path.push_back(source);
	cout << "    " << source << endl;
	for (int i = path.size() - 2; i >= 0; i--) {
		cout << "[" << axiom[path[i]] + 1 << "] " << path[i + 1] << " -> " << path[i] << endl;
	}
	cout << "    " << target << endl;

	cleanupRules(rules);
	return true;

}

int main(int argc, char** argv) {

	if (argc != 3) {
		cerr << "Error: Must supply exactly two (2) arguments in the following form:" << endl;
		cerr << "\t./miu <source> <target>" << endl;
		cerr << "Where source and target are strings consisting of 'M', 'I' or 'U'" << endl;
		exit(1);
	}

	string source = argv[1];
	string target = argv[2];

	if (!runMIU(source, target)) {
		cout << "I could not construct a path from '" << source << "' to '" << target << "'" << endl;
	}

	return 0;
}
