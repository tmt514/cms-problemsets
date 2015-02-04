# Hanoi Towers

## Description

There are $n$ disks and three pegs (numbered by $1, 2, 3$). Initially all the disks are on the peg number 1, sorted from the smallest (number 1) to the largest (number $n$). Now you have to provide the shortest script of disks' movement, each of them is in the form

`Move disk i from A to B.`

where $i$, $A$ and $B$ are corresponding number of disks and pegs, so that after the movements, all disks are moved into the peg number 3.

This is Hanoi Towers, not Huran Towers.

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
