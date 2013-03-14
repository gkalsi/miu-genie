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
void runMIU (string source, string target) {
	
	vector<Rule*> rules = initRules(); /* A list of the possible rules that we can apply */
	map<string, string> nearestParent; /* Used to avoid duplication and to reconstruct the path */
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
				set<string>::iterator it = results.find(applied[j]);	/* Avoid duplicates */
				if (it == results.end() && applied[j].size() < MAX_STRING_LENGTH) {
					results.insert(applied[j]);
					waiting.push(applied[j]);
				}
			}
		}
		if (waiting.empty()) break; /* no more elements left to process */
		
		/* Obtain the next string to test */
		source = waiting.front();
		waiting.pop();
	}
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

	runMIU(source, target);

	return 0;
}
