//
//  AstarOpenList.h
//  HW5
//
//  Created by Nathan Sturtevant on 5/11/18.
//  Copyright © 2018 NS Software. All rights reserved.
//

#ifndef AstarOpenList_h
#define AstarOpenList_h

#include <vector>
#include <unordered_map>

const size_t kNoParent = -1;

template <class s>
struct AStarData {
	s state;
	int g;
	int h;
};

template <class s>
class AStarOpenList {
public:
	void Reset();
	void Add(const s &state, int g, int h);
	void Add(const s &state, int g, int h, const s &parent);
	bool Empty();
	AStarData<s> GetNext();
	void GetPath(s state, std::vector<s> &path);
private:
	struct OpenListData {
		s state;
		int g, h;
		size_t openLocation;
		size_t parent;
	};

	void HeapifyUp(size_t loc);
	void HeapifyDown(size_t loc);
	void HeapSwap(size_t loc1, size_t loc2);
	void RemoveMin();
	bool Better(const OpenListData &, const OpenListData &);
	std::unordered_map<s, size_t> hash;
	std::vector<size_t> heap;
	std::vector<OpenListData> data;
};

template <class s>
void AStarOpenList<s>::Reset()
{
	hash.clear();
	heap.clear();
	data.clear();
}

template <class s>
void AStarOpenList<s>::Add(const s &state, int g, int h)
{
	// add to hash lookup
	hash[state] = data.size();
	// add location in data storage to heap
	heap.push_back(data.size());
	// add full data to data storage
	data.push_back({state, g, h, heap.size()-1, kNoParent});
	HeapifyUp(heap.size()-1);
}

template <class s>
void AStarOpenList<s>::Add(const s &state, int g, int h, const s &parent)
{
	auto i = hash.find(state);
	if (i == hash.end()) // not found
	{
		hash[state] = data.size();
		heap.push_back(data.size());
		data.push_back({state, g, h, heap.size()-1, hash[parent]});
		
		HeapifyUp(heap.size()-1);
		return;
	}

	size_t loc = i->second;
	
	if (data[loc].g > g) // new path is shorter
	{
		data[loc].g = g;
		data[loc].parent = hash[parent];
		HeapifyUp(data[loc].openLocation);
	}
}

template <class s>
bool AStarOpenList<s>:: Empty()
{
	return heap.size() == 0;
}

template <class s>
AStarData<s> AStarOpenList<s>::GetNext()
{
	size_t index = heap[0];
	AStarData<s> d = {data[index].state, data[index].g, data[index].h};
	RemoveMin();
	return d;
}

template <class s>
void AStarOpenList<s>::GetPath(s state, std::vector<s> &path)
{
	path.clear();
	size_t index = hash[state];
	while (index != kNoParent)
	{
		path.push_back(data[index].state);
		index = data[index].parent;
	}
}

template <class s>
void AStarOpenList<s>::HeapifyUp(size_t loc)
{
	if (loc == 0)
		return;
	
	size_t parent = (loc-1)/2;
	if (Better(data[heap[loc]], data[heap[parent]]))
	{
		HeapSwap(loc, parent);
		HeapifyUp(parent);
	}
}

template <class s>
void AStarOpenList<s>::HeapifyDown(size_t loc)
{
	size_t child1 = loc*2+1;
	size_t child2 = loc*2+2;
	size_t minChild;
	if (child1 >= heap.size())
		return;
	if (child2 >= heap.size())
		minChild = child1;
	else {
		if (Better(data[heap[child1]], data[heap[child2]]))
			minChild = child1;
		else
			minChild = child2;
	}
	if (Better(data[heap[minChild]], data[heap[loc]]))
	{
		HeapSwap(minChild, loc);
		HeapifyDown(minChild);
	}
}

template <class s>
void AStarOpenList<s>::RemoveMin()
{
	data[heap.back()].openLocation = 0;
	heap[0] = heap.back();
	heap.pop_back();
	HeapifyDown(0);
}

template <class s>
void AStarOpenList<s>::HeapSwap(size_t loc1, size_t loc2)
{
	size_t tmp = heap[loc1];
	heap[loc1] = heap[loc2];
	heap[loc2] = tmp;
	data[heap[loc1]].openLocation = loc1;
	data[heap[loc2]].openLocation = loc2;
}


template <class s>
bool AStarOpenList<s>::Better(const OpenListData &a, const OpenListData &b)
{
	// is a better than b?
	if (a.g+a.h < b.g+b.h)
		return true;
	if (a.g+a.h == b.g+b.h && a.g > b.g)
		return true;
	return false;
}


#endif /* AstarOpenList_h */
