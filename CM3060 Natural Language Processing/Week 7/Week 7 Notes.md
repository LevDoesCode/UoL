# Lexical semantics
*The meaning of words*

## NLP Tasks
* Classifications tasks (e.g. spam detection)
* Sequence tasks (e.g. text generation)
* **Meaning** tasks. We study meaning in this section

Useful for:
* Information retrieval
* Question answering
* Topic modeling

What do words mean?
* Look in a **dictionary**

## WordNet

A lexical database:
* Nodes are **synsets** (sets of synonyms)
* Correspond to **abstract concepts**
* **Polyhierarchical** structure, looks like a tree, but is flexible, nodes can have more than one parent.

Using WordNet we can programmatically:
* Identify **hyponyms** (child terms) and **hypernyms** (parent terms, we go up the tree for more general terms)
* Measure **semantic similarity**