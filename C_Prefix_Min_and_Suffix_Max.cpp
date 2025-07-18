def solve():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    t = int(data[index])
    index += 1
    results = []

    for _ in range(t):
        n = int(data[index])
        index += 1
        a = list(map(int, data[index:index + n]))
        index += n

        left = 0
        while left + 1 < n and a[left] < a[left + 1]:
            left += 1

        right = n - 1
        while right - 1 >= 0 and a[right - 1] > a[right]:
            right -= 1

        result = ['0'] * n
      
