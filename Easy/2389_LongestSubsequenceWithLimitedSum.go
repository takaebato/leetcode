package main

func answerQueries(nums []int, queries []int) []int {
	n := len(nums)
	idx := 0
	var ans []int
	for i := 0; i < n; i++ {
		if nums[i] <= queries[idx] {
			append(ans, nums[i])
			idx++
		}
	}
	return ans
}
