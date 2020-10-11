class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        import numpy as np
        A = np.array(A)
        B = np.array(B)
        dim = len(A)
        B_padded = np.pad(B, dim-1, mode='constant', constant_values=(0, 0))
        max_overlaps = 0
        for x_shift in range(dim*2 - 1):
            for y_shift in range(dim* 2 - 1):
                # extract a kernel from the padded matrix
                kernel = B_padded[x_shift:x_shift+dim, y_shift:y_shift+dim]
                # convolution between A and kernel
                non_zeros = np.sum(A * kernel)
                max_overlaps = max(max_overlaps, non_zeros)
        return max_overlaps

# to get the list of files that has been chnaged!
# git ls-files --other --modified --exclude-standard
