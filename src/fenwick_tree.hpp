// Fenwick tree implementation.
// Copyright (C) 2015 Mattias Harrysson

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#ifndef FENWICK_TREE_HPP_INCLUDED
#define FENWICK_TREE_HPP_INCLUDED

#include <vector>

// The responsibility of this class is to represent a Fenwick tree data
// structure (also called binary indexed tree).
template<class T>
class fenwick_tree {
public:
    // Construct a Fenwick tree of specified length.
    fenwick_tree(int length);
    // Add delta value at specified index.
    void add(int i, T delta);
    // Return prefix sum (cumulative sum) for the sequence.
    T sum(int i);
private:
    std::vector<T> tree;
};

template<class T>
fenwick_tree<T>::fenwick_tree(int length)
    : tree(length + 1)
{
}

template<class T>
void fenwick_tree<T>::add(int i, T delta)
{
    // avoid deadlock in the following loop since (0 & -0) is 0 (meaning we
    // have no significant one to add)
    i++;

    while (i < tree.size()) {
        tree[i] = tree[i] + delta;
        i = i + (i & -i);
    }
}

template<class T>
T fenwick_tree<T>::sum(int i)
{
    T sum = tree[0];
    while (i > 0) {
        sum += tree[i];
        i =  i & (i - 1); // simplification of i = i - (i & -i);
    }
    return sum;
}

#endif
