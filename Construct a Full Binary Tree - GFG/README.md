# Construct a Full Binary Tree
## Medium 
<div class="problem-statement">
                <p></p><p style="text-align:justify"><span style="font-size:20px">Given two arrays that represent Preorder traversals of a Full binary tree <strong>preOrder[]</strong> and its mirror tree <strong>preOrderMirror()</strong>, your task is to complete the function&nbsp;<strong>constructBinaryTree()</strong>, that&nbsp;constructs the full binary tree using these two Preorder traversals.</span></p>

<p><span style="font-size:20px">Examples:</span></p>

<pre><span style="font-size:18px">Input :  preOrder[] = {1,2,4,5,3,6,7}
         preOrderMirror[] = {1,3,7,6,2,5,4}

Output :          1
               /    \
              2      3
            /   \   /  \
           4     5 6    7</span>
</pre>

<p style="text-align:justify"><span style="font-size:16px"><strong>Note</strong>: It is not possible to construct a general binary tree using these two traversal. But it is possible to create a full binary tree using the above traversals without any ambiguity. For more details refer to&nbsp;<a href="http://www.geeksforgeeks.org/if-you-are-given-two-traversal-sequences-can-you-construct-the-binary-tree/" target="_blank">this</a>&nbsp;article.</span></p>

<p><span style="font-size:20px"><strong>Input</strong>:<br>
The function takes three arguments as input, first the array&nbsp;that represent Preorder traversals of a Full binary tree <strong>preOrder[], </strong>second the array that represents the preorder traversal of<strong>&nbsp;</strong>its mirror tree <strong>preOrderMirror()&nbsp;</strong>and last the <strong>size</strong> of both the array.<br>
There will be <strong>T&nbsp;</strong>test cases and for each test case the function will be called separately.<br>
<br>
<strong>Output:</strong><br>
For each test case the function must return the root to the new binary tree formed. Ouput will be the inorder traversal of the binary tree.<br>
<br>
<strong>Constraints:</strong><br>
1&lt;=T&lt;=500<br>
1&lt;=N&lt;=10<sup>3</sup><br>
<br>
<strong>Example:<br>
Input:</strong><br>
2<br>
3<br>
0 1 2&nbsp;<br>
0 2 1<br>
7<br>
1 2 4 5 3 6 7<br>
1 3 7 6 2 5 4<br>
<strong>Output:</strong><br>
1 0 2&nbsp;<br>
4 2 5 1 6 3 7&nbsp;</span><br>
&nbsp;</p>
 <p></p>
            </div>