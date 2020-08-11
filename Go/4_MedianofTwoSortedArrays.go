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

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    var n1, n2 = len(nums1), len(nums2)
    var n = n1 + n2
    var nums = make([]int, n)
    for idx, num := range nums1 {
        nums[idx] = num
    }
    for idx, num := range nums2 {
        nums[idx + n1] = num
    }
    sort.Ints(nums);
    if ((n & 1) != 0) {
        return float64(nums[n>>1])
    } else {
        return float64(nums[n>>1] + nums[(n>>1)-1])/2.0
    }
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    var n1, n2 = len(nums1), len(nums2)
    var n = n1 + n2
    var nums = make([]int, n)
    var idx1, idx2 = 0, 0
    for ; idx1 + idx2 < n; {
        if (idx2 == n2 || (idx1 < n1 && nums1[idx1] < nums2[idx2])) {
            nums[idx1 + idx2] = nums1[idx1]
            idx1++
        } else {
            nums[idx1 + idx2] = nums2[idx2]
            idx2++
        }
    }
    if ((n & 1) != 0) {
        return float64(nums[n>>1])
    } else {
        return float64(nums[n>>1] + nums[(n>>1)-1])/2.0
    }
}
