# Dynamic Programming Python implementation of Coin Change problem
def count(S, coins, target):
    # We need n+1 rows as the table is consturcted in bottom up
    # manner using the base case 0 value case (n = 0)
    table = [[0 for x in range(coins)] for x in range(target+1)]
 
    # Fill the enteries for 0 value case (n = 0)
    for i in range(coins):
        table[0][i] = 1
 
    # Fill rest of the table enteries in bottom up manner
    for i in range(1, target+1):
        for j in range(coins):
            # Count of solutions including S[j]
            x = table[i - S[j]][j] if i-S[j] >= 0 else 0
 
            # Count of solutions excluding S[j]
            y = table[i][j-1] if j >= 1 else 0
 
            # total count
            table[i][j] = x + y
 
    return table[target][coins-1]
 
# Driver program to test above function

arr = [2,4,6,8]
coins = len(arr) # m
target = 13  # n

print(count(arr, coins, target))
 
# This code is contributed by Bhavya Jain