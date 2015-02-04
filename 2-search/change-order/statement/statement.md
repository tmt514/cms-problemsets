# Tree Traversal Converting

## Description

For a single rooted tree, there are three usual type of travering: Pre-order, In-order and Post-order traversal. Now consider a tree whose vertices are labeled by $1, 2, \cdots, n$. Given its pre-order and in-order, please output its post-order traversal sequence.

## Implementation

In this task you have to implement the following function

```
vector<int> post_order(vector<int> pre_order, vector<int> in_order);
```

which take two permutation of integers, and return another permutation of integers.

Your program will be compiled with our codes, so don't worry about the `main()` function, the only thing that you have to provide is the function mentioned above.

You can utilize the given attached files `change_order_*.cpp`. However, there may be bugs inside!

## Technical Specifications

* For at least 50% test cases, $1\le n\le 1000$.
* For all test cases, $1\le n\le 1000000$.

## Testing

You can test with our judge program on the website. In the testing interface, you can submit a input file consisting of a regular tree representation: first line contains an integer $n$. Next $n-1$ lines contains two integers representing the edges.

The judge's program will NOT check whether the input you provided is a tree or not, so becareful.

## Sample Input 1
```
pre_order = [1, 2, 3, 4, 5, 6, 7]
in_order = [4, 2, 1, 3, 6, 5, 7]
```

## Sample Output 1
```
post_order = [1, 3, 2, 5, 7, 6, 4]
```

## Sample Testing File 1
```
7
2 1
2 3
4 2
4 6
6 5
6 7
```
