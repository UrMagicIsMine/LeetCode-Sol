/* There are two sorted arrays nums1 and nums2 of size m and n respectively.
*
* Find the median of the two sorted arrays. The overall run time complexity should
* be O(log (m+n)).
*
* Example 1:
* nums1 = [1, 3]
* nums2 = [2]
*
* The median is 2.0
* Example 2:
* nums1 = [1, 2]
* nums2 = [3, 4]
*
* The median is (2 + 3)/2 = 2.5
*/

public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    int N1 = nums1.length, N2 = nums2.length;
    int N = N1 + N2;
    int[] combined = new int[N];
    for (int idx1 = 0, idx2 = 0; idx1 + idx2 < N; ) {
        if (idx2 == N2 || (idx1 < N1 && nums1[idx1] < nums2[idx2])) {
            combined[idx1+idx2] = nums1[idx1++];
        } else {
            combined[idx1+idx2] = nums2[idx2++];
        }
    }
    if ( (N & 1) != 0 ) {
        return combined[N >> 1];
    } else {
        return (combined[N >> 1] + combined[(N >> 1) - 1])/2.0;
    }
}

public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int N1 = nums1.length, N2 = nums2.length;
        int N = N1 + N2;
        int[] combined = new int[N];
        for (int i = 0; i < N1; i++)
            combined[i] = nums1[i];
        for (int i = 0; i < N2; i++)
            combined[N1+i] = nums2[i];
        Arrays.sort(combined);
        if ( (N & 1) != 0 ) {
            return combined[N >> 1];
        } else {
            return (combined[N >> 1] + combined[(N >> 1) - 1])/2.0;
        }
    }
