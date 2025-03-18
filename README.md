# Auto-Complete-System

## 📚 Overview
This project implements an **Auto-Complete System** using the **Trie Data Structure** in C++. It allows users to input a prefix, and the system suggests words that match the given prefix.

---

## 🚀 Key Features
- **Efficient Word Lookup:** Uses Trie for fast word insertion and searching.
- **Auto-Suggestions:** Provides word suggestions based on user input.
- **Scalable Design:** Handles multiple words for quick prefix-based search.

---

## 📂 Project Structure
```
/Auto-Complete-Using-Trie
├── /auto_complete_using_trie.cpp   # Main C++ program
├── /README.md                      # Project documentation
```

---

## 📦 Requirements
- C++ Compiler (G++ recommended)
- Standard C++ Libraries (iostream, vector, etc.)

---

## 📝 How It Works
1. **Trie Data Structure:**
   - Each node represents a character.
   - Children nodes store subsequent characters.
   - Marks the end of words for efficient searching.
2. **Insert Words into Trie:**
   - Preloads a dataset of words.
   - Users can add more words dynamically.
3. **Search and Auto-Suggest:**
   - Given a prefix, the system searches the Trie.
   - Displays all matching words dynamically.

---

## ▶️ Usage
### Compile the program:
```bash
g++ auto_complete_using_trie.cpp -o autocomplete
```
### Run the program:
```bash
./autocomplete
```
### Input:
Enter a prefix to get word suggestions.

### Example:
```
Input: app
Suggestions:
apple
application
appoint
```

---

## 📧 Contact
For any queries or contributions, contact:
**Raj M** - [kit26.aids45@email.com](mailto:kit26.aids45@email.com)
