def solve():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        s = input().strip()
        
        # Count total a's and b's
        total_a = s.count('a')
        total_b = s.count('b')
        
        # If already balanced
        if total_a == total_b:
            print(0)
            continue
        
        # If all characters are same type
        if total_a == 0 or total_b == 0:
            print(-1)
            continue
        
        # If total count is odd, impossible to balance
        if (total_a + total_b) % 2 == 1:
            print(-1)
            continue
        
        # We need to find shortest substring where:
        # count_a_in_substring - count_b_in_substring = total_a - total_b
        target_diff = total_a - total_b
        
        min_length = n + 1
        
        # Try all possible substrings
        for i in range(n):
            count_a = 0
            count_b = 0
            
            for j in range(i, n):
                if s[j] == 'a':
                    count_a += 1
                else:
                    count_b += 1
                
                diff = count_a - count_b
                
                if diff == target_diff:
                    length = j - i + 1
                    min_length = min(min_length, length)
                    break  # Found for this starting position
        
        if min_length == n + 1:
            print(-1)
        else:
            print(min_length)

solve()