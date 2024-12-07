def can_make(i, n, nums, cur):
    if i == len(nums) and cur == n:
        return True
    if cur > n or cur < 0 or i >= len(nums):
        return False
    if can_make(i + 1, n, nums, cur + nums[i]):
        return True
    if can_make(i + 1, n, nums, cur * nums[i]):
        return True
    return False


def check(n, nums):
    return can_make(1, n, nums, nums[0])


def main():
    answer = 0
    with open("input.txt", "r") as f:
        for line in f:
            test_value, numbers = line.split(":")
            test_value = int(test_value.strip())
            nums = list(map(int, numbers.strip().split()))

            if check(test_value, nums):
                answer += test_value

    print(answer)


if __name__ == "__main__":
    main()
