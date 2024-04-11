<h1 align="center">
	push_swap
</h1>

*<p align="center">This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves.<br>
To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.</p>*

## Description:
#### Sorter:
The Sorter (push_swap) program sorts a list of integers using two stacks, A and B, and a set of commands.  
Initially, all numbers are placed in stack A.  
The goal is to sort stack A in ascending order with the least number of operations.  
This is achieved by strategically applying the following commands to manipulate the stacks:
| Abbr. | Command | Description |
| -- | -- | -- |
| `sa` | swap a | swaps the 2 top elements of stack a |
| `sb` | swap b | swaps the 2 top elements of stack b |
| `ss` | swap a + swap b | `sa` and `sb` |
| `pa` | push a | moves the top element of stack b at the top of stack a |
| `pb` | push b | moves the top element of stack a at the top of stack b |
| `ra` | rotate a | moves the top element of stack a to the bottom |
| `rb` | rotate b | moves the top element of stack b to the bottom |
| `rr` | rotate a + rotate b | `ra` and `rb` |
| `rra` | reverse rotate a | moves the bottom element of stack b to the top |
| `rrb` | reverse rotate b | moves the bottom element of stack b to the top |
| `rrr` | reverse rotate a + reverse rotate b | `rra` and `rrb` |

**Input**: A sequence of integers separated by whitespace.  
**Output**: A series of commands that sorts the input numbers in ascending order.

#### Checker:
After taking integers as arguments, the checker reads instructions from the standard input till `ctrl+d` is pressed.  
If stack A is sorted and stack B is empty after instructions are applied, `OK` is displayed.  
Otherwise, `KO` is displayed.

## Sorting algorithm overview:
1. The `LIS` (longest increasing subsequence) is identified.  
2. All non-LIS numbers are pushed to stack B, using pivots for `quicksort`-like partitioning.  
3. Stack B is pushed back into stack A with `insertion sort`.  
4. Command list is optimized before being displayed.  

## Set-up:
Clone repo, cd into directory, then use any Makefile command.
```
git clone https://github.com/heyitsyosh/42_push_swap.git
cd 42_push_swap/push_swap
```

#### Makefile Commands:
```C
make         //compile executable (./push_swap)
make checker //compile executable (./checker)
make clean   //delete .o
make fclean  //delete .o and executable
make re      //delete .o and executable, recompile push_swap executable
```

## Usage:  
```Java
./push_swap <integers...>
./checker <integers...>
```
