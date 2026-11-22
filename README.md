# 🔍 Simple C++ Search Engine

A console-based mini search engine in C++ demonstrating **class
inheritance**: a base class handles loading and displaying text files, and
a derived class adds keyword-search functionality across those files.

## 📋 Overview

1. **`FileManager`** (base class) — loads the contents of two text files (`file1.txt`, `file2.txt`) into memory and can display them
2. **`SearchEngine`** (derived class, `public` inheritance) — adds a `searchWord()` method that checks whether a given word appears in either loaded file's content
3. **`main()`** — an interactive menu loop (Show File Contents / Search Word / Exit) driven by a `switch` statement

## 🧠 Concepts Demonstrated

| Concept               | Where                                          |
| ----------------------- | ------------------------------------------------- |
| Base class              | `FileManager` (file I/O, protected members)      |
| Derived class           | `SearchEngine : public FileManager`              |
| File reading            | `ifstream` reads each file line-by-line into a string |
| String search           | `string::find()` used to locate a keyword        |
| Interactive menu        | `do...while` loop with `switch` on user choice   |

## 📁 Required Files

This program expects two text files in the **same directory** as the
executable:
- `file1.txt`
- `file2.txt`

If a file is missing, the program prints `Failed to open <filename>` but
continues running (it won't crash).

## ▶️ Running It

```bash
g++ -std=c++17 -o search_engine DTSMAP.cpp
./search_engine
```

**Example session (with sample file contents):**

```
==== Simple C++ Search Engine ====
1. Show File Contents
2. Search Word
0. Exit
Enter choice: 1
Content of file1.txt:
The quick brown fox jumps over the lazy dog

Content of file2.txt:
Hello world this is a search engine test

Enter choice: 2
Enter word to search: fox
Word "fox" found in file1.txt

Enter choice: 2
Enter word to search: missingword
Word "missingword" not found in any file.

Enter choice: 0
Exiting...
```

## 🛠️ Tech Stack

- **C++17**
- Standard Library only (`<iostream>`, `<fstream>`, `<string>`)

## 🚀 Possible Extensions

- Make the search **case-insensitive** (currently exact substring match only)
- Support searching **multiple words at once** or counting occurrences
- Let the user specify filenames instead of hardcoding `file1.txt` / `file2.txt`
- Extend to search across any number of files (not just 2) using a `vector<string>`
