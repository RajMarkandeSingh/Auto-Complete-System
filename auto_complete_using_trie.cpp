// C++ program to demonstrate auto-complete feature 
// using Trie data structure. 
#include<bits/stdc++.h> 
using namespace std; 

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 

// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

// trie node 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 

	// isWordEnd is true if the node represents 
	// end of a word 
	bool isWordEnd; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 
	pNode->isWordEnd = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 

// If not present, inserts key into trie. If the 
// key is prefix of trie node, just marks leaf node 
void insert(struct TrieNode *root, const string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int level = 0; level < key.length(); level++) 
	{ 
		int index = CHAR_TO_INDEX(key[level]); 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->isWordEnd = true; 
} 

// Returns true if key presents in trie, else false 
bool search(struct TrieNode *root, const string key) 
{ 
	int length = key.length(); 
	struct TrieNode *pCrawl = root; 
	for (int level = 0; level < length; level++) 
	{ 
		int index = CHAR_TO_INDEX(key[level]); 

		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isWordEnd); 
} 

// Returns 0 if current node has a child 
// If all children are NULL, return 1. 
bool isLastNode(struct TrieNode* root) 
{ 
	for (int i = 0; i < ALPHABET_SIZE; i++) 
		if (root->children[i]) 
			return 0; 
	return 1; 
} 

// Recursive function to print auto-suggestions for given 
// node. 
void suggestionsRec(struct TrieNode* root, string currPrefix) 
{ 
	// found a string in Trie with the given prefix 
	if (root->isWordEnd) 
	{ 
		cout << currPrefix; 
		cout << endl; 
	} 

	// All children struct node pointers are NULL 
	if (isLastNode(root)) 
		return; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
	{ 
		if (root->children[i]) 
		{ 
			// append current character to currPrefix string 
			currPrefix.push_back(97 + i); 

			// recur over the rest 
			suggestionsRec(root->children[i], currPrefix); 
		} 
	} 
} 

// print suggestions for given query prefix. 
int printAutoSuggestions(TrieNode* root, const string query) 
{ 
	struct TrieNode* pCrawl = root; 

	// Check if prefix is present and find the 
	// the node (of last level) with last character 
	// of given string. 
	int level; 
	int n = query.length(); 
	for (level = 0; level < n; level++) 
	{ 
		int index = CHAR_TO_INDEX(query[level]); 

		// no string in the Trie has this prefix 
		if (!pCrawl->children[index]) 
			return 0; 

		pCrawl = pCrawl->children[index]; 
	} 

	// If prefix is present as a word. 
	bool isWord = (pCrawl->isWordEnd == true); 

	// If prefix is last node of tree (has no 
	// children) 
	bool isLast = isLastNode(pCrawl); 

	// If prefix is present as a word, but 
	// there is no subtree below the last 
	// matching node. 
	if (isWord && isLast) 
	{ 
		cout << query << endl; 
		return -1; 
	} 

	// If there are are nodes below last 
	// matching character. 
	if (!isLast) 
	{ 
		string prefix = query; 
		suggestionsRec(pCrawl, prefix); 
		return 1; 
	} 
} 

// Driver Code 
int main() 
{ 
	struct TrieNode* root = getNode(); 
	string words[26][10] = {
        {"apple", "ant", "axe", "actor", "arrow", "art", "anchor", "alarm", "album", "arena"},
        {"banana", "boat", "ball", "basket", "breeze", "bottle", "branch", "brave", "bubble", "butter"},
        {"cat", "car", "cycle", "cake", "candle", "castle", "camera", "cartoon", "cheese", "circle"},
        {"dog", "dance", "dollar", "diamond", "drama", "dinosaur", "doctor", "dream", "desk", "dragon"},
        {"elephant", "eagle", "earth", "echo", "energy", "engine", "entire", "entry", "escape", "event"},
        {"fish", "frog", "feather", "forest", "fortune", "festival", "factory", "fiction", "figure", "flame"},
        {"goat", "gold", "garden", "guitar", "growth", "gentle", "globe", "guest", "guide", "grape"},
        {"house", "horse", "honey", "history", "harbor", "hobby", "horizon", "humor", "helmet", "hammer"},
        {"ice", "island", "idea", "insect", "input", "invite", "image", "impact", "instant", "interest"},
        {"jungle", "jacket", "joy", "jump", "jigsaw", "justice", "jewel", "jog", "journey", "jazz"},
        {"kite", "king", "kangaroo", "kitchen", "kid", "knowledge", "kind", "knot", "keyboard", "kernel"},
        {"lion", "lamp", "lake", "laugh", "lesson", "letter", "lizard", "language", "legend", "limit"},
        {"monkey", "moon", "magic", "music", "market", "mountain", "memory", "mirror", "motion", "mystery"},
        {"nest", "night", "nature", "network", "novel", "noble", "needle", "nickname", "notice", "number"},
        {"orange", "ocean", "orbit", "order", "opinion", "option", "owner", "oxygen", "outdoor", "overcome"},
        {"parrot", "piano", "planet", "pencil", "picture", "puppy", "partner", "peace", "process", "protect"},
        {"queen", "question", "quiet", "quote", "quality", "quilt", "quest", "quarter", "quick", "quasar"},
        {"robot", "rain", "river", "rocket", "reading", "rescue", "result", "replay", "respect", "rhythm"},
        {"snake", "sun", "shadow", "soccer", "science", "station", "signal", "spirit", "success", "safety"},
        {"tiger", "tree", "table", "tunnel", "ticket", "trophy", "teacher", "twilight", "trust", "target"},
        {"umbrella", "unicorn", "uniform", "unique", "universe", "update", "upward", "ultimate", "under", "unlock"},
        {"village", "victory", "violin", "volcano", "visitor", "volume", "vision", "vacation", "vehicle", "venture"},
        {"whale", "window", "wizard", "wonder", "whisper", "welcome", "wallet", "witness", "willing", "weather"},
        {"xylophone", "x-ray", "xenon", "xerox", "x-axis", "xenophobia", "xylem", "xenolith", "xyst", "xanthic"},
        {"yellow", "yogurt", "year", "yawn", "yacht", "yoga", "yield", "yesterday", "youth", "yolk"},
        {"zebra", "zoo", "zone", "zero", "zipper", "zigzag", "zephyr", "zenith", "zodiac", "zombie"}
    };
    for (int i = 0; i < 26; i++) { 
        for (int j = 0; j < 10; j++) {
            insert(root, words[i][j]);
        }
    }
	string inp;
	cin >> inp; 
	int comp = printAutoSuggestions(root, inp); 

	if (comp == -1) 
		cout << "No other strings found with this prefix\n"; 

	else if (comp == 0) 
		cout << "No string found with this prefix\n"; 

	return 0; 
}