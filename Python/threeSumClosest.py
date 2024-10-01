def threeSumClosest(nums, target):
    nums.sort()
    result_sum = nums[0] +nums[1] +nums[2]
    min_diff = abs(target-result_sum)
    for i in range(len(nums)-2):
        if result_sum == target:
            break
        cur, left, right = nums[i], i+1, len(nums)-1
        while (left < right):
            newsum = cur + nums[left] + nums[right]
            if newsum < target:
                left += 1
            elif newsum > target:
                right -= 1
            else:
                return target
            if abs(target - newsum) < min_diff:
                result_sum = newsum
                min_diff = abs(target-result_sum)
    return result_sum

if __name__ == "__main__":
    nums ,target = [-1,2,1,-4], 1
    result = threeSumClosest(nums, target)
    print(result)
