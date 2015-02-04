# L-Tiling

## Description


\begin{tikzpicture}[scale=0.4]
\draw[fill=red!50!white] (0,0)--(0,2)--(1,2)--(1,1)--(2,1)--(2,0)--cycle;
\end{tikzpicture}

You have a $2^n\times 2^n$ grid, but unfortunately one cell of them is broken.

\begin{tikzpicture}[scale=0.2]
\draw[black] (0,0) grid (8,8);
\fill[color=black] (6,2) rectangle (1,1);
\end{tikzpicture}


## Input

An integer $n$.

## Output

Please output a shortest list of movement in the above format.

## Technical Specifications

* It is guaranteed that $1\le n\le 15$.

## Sample Input 1
```
1
```

## Sample Output 1
```
Move disk 1 from 1 to 3.
```

## Sample Input 2
```
2
```

## Sample Output 2
```
Move disk 1 from 1 to 2.
Move disk 2 from 1 to 3.
Move disk 1 from 1 to 2.
```
