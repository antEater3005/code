//C++ Program To Implement Segment Tree
//Minimum Range Query
/* 
	All these four Problems can be solved in three different ways:
	--------------------------------------------------------------
	
	Problem:1 Minimum Range Query
	Problem:2 Maximum Range Query(Use 1D array to prechache
	Program:3 Range Sum Query(Use 1D array to prechache)
	Program:4 Xor Range Query
	Program:5 Multiplication in given Range
	Program:6 Division in given Range
	
	Ways:
	-----
	
	U can use 1D or 2D array to prechache the results.
	Based on your requirement.
	
	Way:1 Brute Force (Costly will take O(N * Q)
	Way:2 By Precaching the required result.(Efficient if frequent operation is Search Query) (O(N^2 + 1*Q) {2D Matrix
	can be used to precache the result)
	Way:3 By Using Segment Tree(Moderate Time Complexity: If update and search query are frequent) (O(N + QlogN)

 */
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

/* 
	Building Segment Tree will take O(N) time. Where N is the number of elements in given list.
	
	Here in buildSegementTree(): minIndex is the index corresponding to segmentation tree(array)
	where node with minimum value(in range rangeStart to rangeEnd) is going to store.
	
	seg_tree[minIndex] = min(arr[rangeStart], arr[rangeStart + 1], .... , arr[rangeEnd]);
 */

int buildSegementTree(int *seg_tree, int *list, int minIndex, int rangeStart, int rangeEnd)
{
    //Base Case
    if (rangeStart > rangeEnd)
        return 0;

    //Base Case : Leaf Node
    if (rangeStart == rangeEnd)
    {
        seg_tree[minIndex] = list[rangeStart];
        return seg_tree[minIndex];
    }

    //Used to devide list into two parts
    int mid = rangeStart + (rangeEnd - rangeStart) / 2;

    int leftMin = buildSegementTree(seg_tree, list, 2 * minIndex + 1, rangeStart, mid);

    int rightMin = buildSegementTree(seg_tree, list, 2 * minIndex + 2, mid + 1, rangeEnd);

    //Update min(leftSubtree, rightSubtree) to current node and return current node to its caller.
    seg_tree[minIndex] = min(leftMin, rightMin);

    return seg_tree[minIndex];
}

void fill(int *seg_tree, int size)
{
    for (int i = 0; i < size; i++)
    {
        //seg_tree[i] = 0;
        seg_tree[i] = INT_MAX;
    }
}

void printSegmentTree(int *seg_tree, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << seg_tree[i] << " ";
    }
    cout << endl;
}

/* 
	Time Complexity: O(logN) Where N is number elements in Original List
	At max we have to traverse segment tree to find out minimum in given range: Equivalent to Height of segment tree.
	
	Segment Tree is full binary tree. It means all the levels are completely filled except the last level.
	
	Last level can be emtpy or filled with infinity.
 */
int minInRange(int *seg_tree, int minIndex, int nodeRangeStart, int nodeRangeEnd, int queryStart, int queryEnd)
{
    /* Three Cases needs to be Handle */
    //CASE : 1 No Overlap (If there is no Intersection between node range and query range)
    //then return infinity
    /* 
		case: A
				
				queryStart				  queryEnd
				   +--------------------------+
													nodeRangeStart				nodeRangeEnd
														 +--------------------------+
														 
		case: B
		
														queryStart				  queryEnd
														   +--------------------------+
				nodeRangeStart				nodeRangeEnd
					 +--------------------------+				
				
	*/
    if ((nodeRangeStart > queryEnd) || (nodeRangeEnd < queryStart))
        return INT_MAX;

    //CASE: 2 Comlete Overlap (If node range completely overlap or lies between query range)
    //then directly return value present at node(Which is nothing but seg_tree[minIndex])
    /* 
		
		case: A
		
				queryStart				          queryEnd
					+--------------------------------+
							
							   +--------------+
						nodeRangeStart    nodeRangeEnd
								
		case: B
		
				queryStart				          queryEnd
					+--------------------------------+
							
					+--------------------------------+
				nodeRangeStart    				 nodeRangeEnd
				
				
		case: C
				
				queryStart				          queryEnd
					+--------------------------------+
							
									  +--------------+
								nodeRangeStart    nodeRangeEnd
								
		case: D
		
				queryStart				          queryEnd
					+--------------------------------+
							
				    +--------------+
			    nodeRangeStart    nodeRangeEnd
				
	*/
    if ((nodeRangeStart >= queryStart) && (nodeRangeEnd <= queryEnd))
        return seg_tree[minIndex];

    //CASE: 3 Partial Overlap (If some of parts of node range overlap with query range but not completely)
    //Then call for both left and right subtree
    /* 
		case: A (queryEnd and nodeRangeStart overlapped)
			
				queryStart				          queryEnd
					+--------------------------------+
							
													 +--------------+
												nodeRangeStart    nodeRangeEnd
	
	
		case: B (queryEnd and nodeRangeEnd overlapped)
							
								queryStart				          queryEnd
									+--------------------------------+
									
					 +--------------+
				nodeRangeStart    nodeRangeEnd
	
	
	
		case: C
				queryStart				          queryEnd
					+--------------------------------+
							
											 +--------------+
				  					 nodeRangeStart    nodeRangeEnd
	
		case: D
							queryStart				          queryEnd
								+--------------------------------+
					
					 +--------------+
			 nodeRangeStart    nodeRangeEnd

	
	*/

    int mid = nodeRangeStart + (nodeRangeEnd - nodeRangeStart) / 2;

    int leftSubtreeMin = minInRange(seg_tree, 2 * minIndex + 1, nodeRangeStart, mid, queryStart, queryEnd);
    int rightSubtreeMin = minInRange(seg_tree, 2 * minIndex + 2, mid + 1, nodeRangeEnd, queryStart, queryEnd);

    return min(leftSubtreeMin, rightSubtreeMin);
}

/* 
	Update given value to at given index.
	
	Time Complexity: O(logN)
 */
int updateAt(int *seg_tree, int minIndex, int nodeRangeStart, int nodeRangeEnd, int atIndex, int toValue)
{

    //No Overlap
    if ((nodeRangeStart > atIndex) || (nodeRangeEnd < atIndex))
    {
        //return INT_MAX;
        return seg_tree[minIndex];
    }

    //Complete Overlap
    //Leaf Node.
    /* 
		We're sure the node which has to update is always a leaf
		node.
	*/
    if (nodeRangeStart == atIndex)
    {
        seg_tree[minIndex] = toValue;
        return seg_tree[minIndex];
    }

    //No Overlap: Call both - Left and right Substree
    int mid = nodeRangeStart + (nodeRangeEnd - nodeRangeStart) / 2;

    int leftMin = updateAt(seg_tree, 2 * minIndex + 1, nodeRangeStart, mid, atIndex, toValue);
    int rightMin = updateAt(seg_tree, 2 * minIndex + 2, mid + 1, nodeRangeEnd, atIndex, toValue);

    //update current node and return it to its caller.
    seg_tree[minIndex] = min(leftMin, rightMin);

    return seg_tree[minIndex];
}

/* 
	Update given range[rangeStart, rangeEnd] by a given value.(toValue)

	update might be changing the value by a new value or adding a value to 
	already existing value on list.
	
	**For this case: Add given value to existing value.
	
	Time Complexity: O(N) for 1 query.
	In Worst case, there might be we need to change entire list.
	
	If there is such a Q query then time complexity for Q queries is: O(N*Q)
	
 */

int updateRange(int *seg_tree, int minIndex, int nodeRangeStart, int nodeRangeEnd, int rangeStart, int rangeEnd, int toValue)
{
    //No overlap
    if ((nodeRangeStart > rangeEnd) || (nodeRangeEnd < rangeStart))
    {
        //return INT_MAX; Blunder
        return seg_tree[minIndex];
    }

    //Complete Overlap
    //Leaf Node.
    //We're sure the node which has to be update is always a leaf node.
    //After all everything start from leaf node.
    if (nodeRangeStart == nodeRangeEnd)
    {
        seg_tree[minIndex] += toValue;
        return seg_tree[minIndex];
    }

    //Partial Overlap
    //Call both sides: left and right subtree
    int mid = nodeRangeStart + (nodeRangeEnd - nodeRangeStart) / 2;

    int leftUpdatedMin = updateRange(seg_tree, 2 * minIndex + 1, nodeRangeStart, mid, rangeStart, rangeEnd, toValue);
    int rightUpdatedMin = updateRange(seg_tree, 2 * minIndex + 2, mid + 1, nodeRangeEnd, rangeStart, rangeEnd, toValue);

    //Update current node and return it to its caller.
    seg_tree[minIndex] = min(leftUpdatedMin, rightUpdatedMin);

    return seg_tree[minIndex];
}

int main()
{

    int list[] = {2, 4, -2, 5, 6, 1};
    int size = sizeof(list) / sizeof(list[0]);
    /* 
		Required Space for segment tree(array) is:
		
		space: 2 * 2 ^ ceil(log(size)) - 1 (last 1 one is not with ceil() function
		
		which is nearly equal to 4 * size + 1 (See proof online: On Wikipedia)
	*/

    /* 
		Since Segment Tree is Full Binary Tree. It means each Internal Nodes has either 0 or 2 Child.
		
		So therefore total number of nodes in ST is: 2 * N - 1
		
		As we know that number of leaf nodes in Full Binary Tree is always one more than number of Internal nodes.
		
		Leaf Nodes = Internal Nodes + 1
		
		Here All the list items are nothing but leaf nodes of Segment Tree.
		
		N = I + 1 --> I = N - 1
		
		So total in any Binary Tree is:
		
		Total = Leaf Nodes + Internal Nodes.
		
		Total = N + N - 1 --> 2 * N - 1
		
		
		So therefore space required for segment tree array is always:
		
		Smallest Power of two >= Total Nodes(2 * N - 1).

			Because nodes are not filled adjacently but in powers of 2 as
				Left Child: 2 * index + 1
				Right Child: 2 * index + 2
			
			So therefor last level can has empty block.
		
		Height of Segment Tree(hmax): ceil(log2(N + 1) --> Here N is nothing but 2 * N - 1(Minimum Possible Nodes)
		Space Required: (2^h - 1) Maximum number of nodes in Full Binary of Height h.
		
		
		In this question: hmax --> 4
		Max Space: 2 ^ hmax - 1 --> 15
		
	*/

    int *seg_tree = new int[4 * size + 1];
    int seg_size = 4 * size + 1;
    fill(seg_tree, seg_size);
    //memset(seg_tree, 0, sizeof(seg_tree)); work properly only for static memory allowcation of array.

    cout << "Minimum value in Segment Tree: " << buildSegementTree(seg_tree, list, 0, 0, size - 1) << endl;

    printSegmentTree(seg_tree, seg_size);
    cout << "Enter number of queries you want" << endl;
    int no_of_queries;
    cin >> no_of_queries;

    //Update original list as well.
    //list[2] = -10;
    //if we re build segement tree then this will take O(N) but
    //updating on segement tree will take O(logN) time.
    updateAt(seg_tree, 0, 0, size - 1, 2, -10);

    updateRange(seg_tree, 0, 0, size - 1, 0, 5, 10);

    while (no_of_queries--)
    {
        cout << "Enter query range to find minimum" << endl;
        int queryStart, queryEnd;
        cin >> queryStart >> queryEnd;
        int minEle = minInRange(seg_tree, 0, 0, size - 1, queryStart, queryEnd);
        cout << "Minimum element in range [" << queryStart << ", " << queryEnd << "] is: " << minEle << endl;
    }

    return 0;
}

/* 
Minimum value in Segment Tree: -2
Enter number of queries you want
4
Enter query range to find minimum
0 5
Minimum element in range [0, 5] is: -2
Enter query range to find minimum
0 1
Minimum element in range [0, 1] is: 2
Enter query range to find minimum
2 3
Minimum element in range [2, 3] is: -2
Enter query range to find minimum
3 5
Minimum element in range [3, 5] is: 1
---------------------------------------
Minimum value in Segment Tree: -2
Enter number of queries you want
5
Enter query range to find minimum
0 0
Minimum element in range [0, 0] is: 2
Enter query range to find minimum
3 3
Minimum element in range [3, 3] is: 5
Enter query range to find minimum
5 5
Minimum element in range [5, 5] is: 1
Enter query range to find minimum
0 5
Minimum element in range [0, 5] is: -2
Enter query range to find minimum
2 3
Minimum element in range [2, 3] is: -2
-----------------------------------------
D:\DS_AND_ALGORITHMAS\DS-IMPLEMENTAION\Tree\SegmentTree>a.exe
Minimum value in Segment Tree: -2
Enter number of queries you want
5
Enter query range to find minimum
1 1
Minimum element in range [1, 1] is: 4
Enter query range to find minimum
0 0
Minimum element in range [0, 0] is: 2
Enter query range to find minimum
5 5
Minimum element in range [5, 5] is: 1
Enter query range to find minimum
0 3
Minimum element in range [0, 3] is: -2
Enter query range to find minimum
3 5
Minimum element in range [3, 5] is: 1
--------------------------------------------------
After update operation
------------------------

Enter number of queries you want
10
Enter query range to find minimum
0 0
Minimum element in range [0, 0] is: 2
Enter query range to find minimum
1 1
Minimum element in range [1, 1] is: 4
Enter query range to find minimum
1 2
Minimum element in range [1, 2] is: -10
Enter query range to find minimum
2 2
Minimum element in range [2, 2] is: -10
Enter query range to find minimum
2 3
Minimum element in range [2, 3] is: -10
Enter query range to find minimum
3 4
Minimum element in range [3, 4] is: 5
Enter query range to find minimum
4 5
Minimum element in range [4, 5] is: 1
Enter query range to find minimum
5 5
Minimum element in range [5, 5] is: 1
Enter query range to find minimum
6 6
Minimum element in range [2, 2] is: -10
Enter query range to find minimum
2 5
Minimum element in range [2, 5] is: -10
-----------------------------------------

After Update range Operation

Enter number of queries you want
10
Enter query range to find minimum
0 5
Minimum element in range [0, 5] is: 8
Enter query range to find minimum
0 0
Minimum element in range [0, 0] is: 12
Enter query range to find minimum
1 1
Minimum element in range [1, 1] is: 14
Enter query range to find minimum
2 2
Minimum element in range [2, 2] is: 8
Enter query range to find minimum
3 3
Minimum element in range [3, 3] is: 15
Enter query range to find minimum
4 4
Minimum element in range [4, 4] is: 16
Enter query range to find minimum
5 5
Minimum element in range [5, 5] is: 11
Enter query range to find minimum
3 5
Minimum element in range [3, 5] is: 11
Enter query range to find minimum
2 3
Minimum element in range [2, 3] is: 8
Enter query range to find minimum
0 1
Minimum element in range [0, 1] is: 12
 */