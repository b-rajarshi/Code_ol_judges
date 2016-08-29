/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void minDepthHelper(struct TreeNode *root, int *min_depth, int current_depth) {
	// We reached a leaf node.
	if (root->left == NULL && root->right == NULL) {
		if (current_depth <= *min_depth) {
			*min_depth = current_depth;
			return;
		}
	}
	if (root->left != NULL) {
		current_depth++;
		minDepthHelper(root->left, min_depth, current_depth);
		current_depth--;
	}
	if (root->right != NULL) {
		current_depth++;
		minDepthHelper(root->right, min_depth, current_depth);
		current_depth--;
	}
	return;

} 


int minDepth(struct TreeNode* root) {

    if (root == NULL) {
    	return 0;
    }
    int min_depth = INT_MAX; // Initialize with the highest integer.
    minDepthHelper(root, &min_depth, 1);
    return min_depth;
    
}